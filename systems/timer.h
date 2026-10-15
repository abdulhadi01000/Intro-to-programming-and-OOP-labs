#pragma once
#include <chrono>

namespace ps {
    enum class enResolution {
        SECONDS,
        MILLISECONDS,
        MICROSECONDS,
        NANOSECONDS
    };

    class Timer {
    public:
        explicit Timer(enResolution resolution = enResolution::MILLISECONDS) : m_Resolution(resolution) {}

        void start() {
            m_isRunning = true;
            m_StartTimePoint = std::chrono::high_resolution_clock::now();
        }

        long long elapsed() {
            using namespace std::chrono;
            auto endTimePoint = high_resolution_clock::now();
            auto duration = endTimePoint - m_StartTimePoint;

            switch (m_Resolution) {
            case enResolution::SECONDS: return duration_cast<seconds>(duration).count();
            case enResolution::MILLISECONDS: return duration_cast<milliseconds>(duration).count();
            case enResolution::MICROSECONDS: return duration_cast<microseconds>(duration).count();
            case enResolution::NANOSECONDS: return duration_cast<nanoseconds>(duration).count();
            default: return duration.count();
            }
        }

        long long stop() {
            auto end = elapsed();
            m_isRunning = false;
            return end;
        }

        std::string get_unit_name() const {
            static constexpr const char* m_UnitName[] = {"s","ms","us","ns"};
            return m_UnitName[static_cast<int>(m_Resolution)];
        }

        std::string stop_and_get_unit_name() {
            return std::format("{0} {1}", stop(), get_unit_name());
        }

    protected:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
        enResolution m_Resolution;
        bool m_isRunning = false;
    };

    class ScopedTimer :public Timer {
    public:
        ScopedTimer(const std::string& name,
            enResolution resolution = enResolution::MILLISECONDS):
            m_Name(name),Timer(resolution) {
            start();
        }

        ~ScopedTimer() {
            if (m_isRunning) {
                std::cout << m_Name << ": " << stop_and_get_unit_name() << "\n";
            }
        }
    private:
        std::string m_Name = "";
    };
}
