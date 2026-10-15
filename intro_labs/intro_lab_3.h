#pragma once 
#include "pch.h"
#include "presentation_system.h"

namespace intro_lab_3 {
	inline void task1() {
		int a, b = 4;
		char c = 'c';
		const int f = 3;
		a = 9;
		b = 5;
		a = b;
		//f = a;
		std::cout << "a: " << a << "\n";
		std::cout << "f: " << f << "\n";
		std::cout << "b: ";
		std::cout << b;
	}

	inline void task2() {
		const int F = 2;
		int a, b;
		a = b = 6;
		a = b % 3 * 10 + 5;
		std::cout << "a :=" << a << "\n";
		b += a * (5 + F);
		std::cout << "b :=" << b << "\n";

		double num = 3.6;
		int c = 67;
		std::cout << "num = " << num << " c = " << c << "\n";

		// Original values
		std::cout << "Original values: " << c << " " << num << std::endl;
		// Convert double to int
		std::cout << "num as int using static_cast<int>: " << 
			static_cast<int>(num) << std::endl;
		// Convert int to char
		std::cout << "c as char using static_cast<char>: " <<
			static_cast<char>(c) << std::endl;
		// Show original values again to confirm no change
		std::cout << "Original values again: " 
			<< c << " " << num << std::endl;
		char s = '#';
		std::cout << "The integer value of the character \'" 
			<< s << "\'is " << static_cast<int>(s) << std::endl;
	}

	inline void task3() {
		double C = 20.0;
		std::cout << (9.0 / 5.0) * C + 32 << "\n";
		std::cout << "ascii value for \'+\' = "
			<< static_cast<int>('+') << "\n";
		
		double feet = 5.9;
		double fromFeetToInches = 12 * feet;
		double inches = 6;
		double totalInches = fromFeetToInches + inches;
		std::cout << "Total Inches: " <<
			totalInches << "\n";

		int i = 0;
		i = i + 1;
		std::cout << "i = " << i << "\n";
	}

	inline void task4() {
		double x = 2.5, t = 3.04, n = 5, r = 5.0;
		double y = x * x - 2 * x + 7;
		double v = 4 / 3*(3.14*r*3);
		double h = (n * n * n) - ((t + x) / 2) + 5;


		std::cout << "x = " << x << " t = " << t <<
			" n = " << n << " r = " << r << "\n";
		std::cout << "x * x - 2 * x + 7 = " << y << "\n";
		std::cout << "4 / 3*(3.14*r*3) = " << v << "\n";
		std::cout << "(n * n * n) - ((t + x) / 2) + 5 = " << h << "\n";
	}

	inline void task5() {
		int a = 25, b = 20;
		double c = 5.0f;
		std::cout << "a = " << a << " b = " << b << " c = " << c << "\n";
		std::cout <<"a * 2 * b  =  "<< a * 2 * b << std::endl;
		std::cout << "a + b / 2.0 + 1.5 * c  =  "<< a + b / 2.0 + 1.5 * c << std::endl;
		std::cout << "a / static_cast<double>(b)  =  "<< a / static_cast<double>(b) << std::endl;
		std::cout << "62 % 28 + a / c  =  "<< 62 % 28 + a / c << std::endl;
		std::cout << "static_cast<int>(c) % 3 + 8  =  "<< static_cast<int>(c) % 3 + 8 << std::endl;
		std::cout << "22.5 / 2 + 14.0 * 3.5 + 28  =  "<< 22.5 / 2 + 14.0 * 3.5 + 28 << std::endl;
		std::cout << "10 / (c - static_cast<double>(c + 1.2))  =  "<< 10 / (c - static_cast<double>(c + 1.2)) << std::endl;
	}



	inline void run_tasks() {
		ps::TaskOptions taskOp{
			//.task_label = "",
			//.header = "",
			//.footer = "",
			.timer_cfg {
				.enabled = true,
				.resolution = ps::enResolution::MICROSECONDS
			}
		};

		ps::PresentationSystem<std::function<void()>> tasks(taskOp);
		tasks.run({
			task1,
			task2,
			task3,
			task4,
			task5

		});

	}
}	