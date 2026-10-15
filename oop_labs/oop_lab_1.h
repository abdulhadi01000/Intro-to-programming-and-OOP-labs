#pragma once
#include "pch.h"
#include "presentation_system.h"

namespace oop_lab_1 {
    int calculateSquare(int number);

    inline void printHeader() {
        std::cout << "--- C++ Function Demonstration ---\n";
    }

    void displayMessage(std::string msg) {
        std::cout << "Message: " << msg << "\n";
    }

    void incrementByValue(int a) {
        a = a + 1;
    }

    void incrementByReference(int& a) {
        a = a + 1;
    }

    int calculateSquare(int number) {
        return number * number;
    }

	void run_tasks() {
        ps::PresentationSystem<std::function<void()>> tasks({
        .timer_cfg = {
            .enabled = true,
            .resolution = ps::enResolution::MICROSECONDS
        }});

        tasks.run({
                []() {printHeader(); },
                []() {displayMessage("HI"); },
                []() {int a = 32; std::cout << "before " << a << "\n";  incrementByValue(a); std::cout << "after " << a << "\n"; },
                []() {int a = 32; std::cout << "before " << a << "\n";  incrementByReference(a); std::cout << "after " << a << "\n"; },
                []() {std::cout <<"square of 9: " << calculateSquare(9) << "\n"; }
        });
	}
}