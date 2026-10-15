#pragma once
#include "pch.h"
#include "presentation_system.h"

namespace intro_lab_1 {
	inline int task1() {
		std::cout << "Welcome to C++ Programming Language\n";
		std::cout << "this program tests your capability to write a good ";
		std::cout << "program that is out of errors";
		return 2;
	}

	inline int task2() {
		std::cout << "\n Welcome to \tC++ Programming Language\n";
		std::cout << "I can print One\n Two \n Three\n each at a line.";
		return 0;
	}

	inline int task3() {
		int n1 = 57,
			n2 = 23,
			n3 = -67;
		double DOUBLE_AVG = (double)(n1 + n2 + n3) / 3;
		int INT_avg = (int)DOUBLE_AVG;

		std::cout <<
			"n1 = " << n1 << "\n" <<
			"n2 = " << n2 << "\n" <<
			"n3 = " << n3 << "\n" <<
			"INT_avg    = " << INT_avg << "\n" <<
			"DOUBLE_avg = " << DOUBLE_AVG << "\n";
		return 0;
	}

	inline int task4() {
		int x = 12, y = 18;
		int temp = 0;
		char ch= 'B';
		
		x += 6;
		
		double d = 13.4;
		
		temp = x;
		x = y;
		y = temp;

		std::cout << "x = " << x << "\n";
		
		std::cout << "y = " << y << "\n";
		double double_expressions = (double)x + 20 / (double)y - 14;
		std::cout << "INT_Expression   :x + 20 / y - 14 = " 
			<< (int)double_expressions << "\n";

		std::cout << "DOUBLE_Expression:x + 20 / y - 14 = " 
			<< double_expressions << "\n";

		return 0;
	}

	inline void run_tasks() {
		ps::PresentationSystem<int(*)()> tasks({
			.timer_cfg = {
				.enabled = true,
				.resolution = ps::enResolution::MICROSECONDS
			} });
		
		tasks.run({
			task1,
			task2,
			task3,
			task4,
		});
	}
}