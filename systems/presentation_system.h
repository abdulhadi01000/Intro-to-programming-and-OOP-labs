#pragma once
#include "pch.h"
#include "timer.h"

namespace ps {
    struct TimerConfig {
        bool enabled = false;
        enResolution resolution = enResolution::MILLISECONDS;
    };

    struct TaskOptions {
        std::string task_label = "TASK NUMBER ";
        std::string header = "STARTING TASKS";
        std::string footer = "END OF ALL TASKS\n";
        char exit_key = 'e';
        TimerConfig timer_cfg;
    };

    template <typename T>
    concept Streamable = requires(std::ostream & os, T value) {
        { os << value } -> std::convertible_to<std::ostream&>;
    };

    template<typename T>
    class PresentationSystem {
    public:
        explicit PresentationSystem(TaskOptions options = {})
            : m_Options(std::move(options)), m_Timer(m_Options.timer_cfg.resolution) {
        }

        void run(const std::vector<T>& tasks) {
            int task_count = 1;
            for (const auto& task : tasks) {
                if (!task)
                {
                    task_count++;
	                continue;
                }

                clear_screen();

                print_header(task_count);

                execute_and_measure(task);

                if (should_exit(task_count)) break;
                task_count++;
            }
            finalize();
        }

    private:
        TaskOptions m_Options;
        Timer m_Timer;
        std::string Masured= "";

    private:
        void execute_and_measure(const T& task) {
            if (m_Options.timer_cfg.enabled) {
                m_Timer.start();
            }

            using ReturnType = std::invoke_result_t<T>;
            if constexpr (std::is_void_v<ReturnType>) {
                task();
            }
            else {
                auto result = task();
                if constexpr (Streamable<ReturnType>) {
                    std::cout << "\n\n[Return Value]: " << result << "\n";
                }
            }

            if (m_Options.timer_cfg.enabled) {
                Masured = std::format("[Execution Time]: {}", m_Timer.stop_and_get_unit_name());
            }
        }

        void print_header(int count) const {
            if (!m_Options.header.empty())
                std::cout << m_Options.header << "\n";
            if (!m_Options.task_label.empty())
                std::cout << m_Options.task_label <<": "<< count << "\n";
        }

        bool should_exit(int count) const {
            std::cout << "\n------------------------------------";
            if (m_Options.timer_cfg.enabled) {
                std::cout << "\n" + Masured;
            }
            std::cout << "\nEnd of task " << count;
            std::cout << "\nPress Enter to continue, or '" << m_Options.exit_key << "' to skip: ";


            if (std::cin.peek() == '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            std::string input;
            if (!std::getline(std::cin, input)) {
                return false;
            }

            if (input.empty()) {
                return false;
            }

            char trigger = static_cast<char>(std::tolower(static_cast<unsigned char>(m_Options.exit_key)));
            char user_input = static_cast<char>(std::tolower(static_cast<unsigned char>(input[0])));

            return user_input == trigger;
        }

        static void clear_screen() {
        	//std::cout << "\033[2J\033[1;1H";
            system("cls");
        }

        void finalize() const {
            clear_screen();
            std::cout << m_Options.footer;
        }
    };
}