#pragma once
#include "pch.h"
#include "presentation_system.h"

namespace intro_lab_2 {

	int task1() {
		std::cout << "Welcome to C++ Programming Language\n";
		std::cout << "this program tests your capability to write a good ";
		std::cout << "program that is out of errors";
		return 2;
	}

	int task2() {
		std::cout << "\n Welcome to \tC++ Programming Language\n";
		std::cout << "I can print One\n Two \n Three\n each at a line.";
		return 0;
	}

	int task3() {
		int n1 = 57,
			n2 = 23,
			n3 = -67;
		int INT_avg = (n1 + n2 + n3) / 3;
		double DOUBLE_AVG = (double)(n1 + n2 + n3) / 3;

		std::cout <<
			"n1 = " << n1 << "\n" <<
			"n2 = " << n2 << "\n" <<
			"n3 = " << n3 << "\n" <<
			"INTGER_avg = " << INT_avg << "\n" <<
			"DOUBLE_avg = " << DOUBLE_AVG << "\n";
		return 0;
	}

	int task4() {
		int x = 12, y = 18;
		int temp = 0;
		char ch = 'B';

		x += 6;

		double d = 13.4;

		temp = x;
		x = y;
		y = temp;

		std::cout << "x = " << x << "\n";

		std::cout << "y = " << y << "\n";

		std::cout << "INT_Expression   :x + 20 / y - 14 = "
			<< x + 20 / y - 14 << "\n";

		std::cout << "DOUBLE_Expression:x + 20 / y - 14 = "
			<< (double)x + 20 / (double)y - 14 << "\n";

		return 0;
	}

	void run_tasks() {
		ps::PresentationSystem<int(*)()> tasks({
			.timer_cfg = {
				.enabled = true,
				.resolution = ps::enResolution::MICROSECONDS
			}});
		tasks.run({
			task1,
			task2,
			task3,
			task4,
			[]() { std::cout << "Temporary Task\n"; return 5; },
			});
	}
}