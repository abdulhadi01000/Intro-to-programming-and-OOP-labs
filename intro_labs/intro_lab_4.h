#pragma once 
#include "pch.h"
#include "presentation_system.h"

namespace intro_lab_4
{
	inline void task1()
	{
		bool found = true;
		int age = 20;
		double hours = 45.30;
		double overTime = 15.0;
		int count = 20;
		char ch = 'B';
		

		std::cout << "\n" << 
			!found << "\n"
			<< (hours > 40.00) << "\n"
			<< !age << "\n"
			<< (!found && (age >= 18)) << "\n"
			<< !(found && (age >= 18)) << "\n"
			<< (hours + overTime <= 75.00) << "\n"
			<< ((count >= 0) && (count <= 100)) << "\n"
			<< ('A' <= ch && ch <= 'Z');
	}

	inline void task2()
	{
		int score = 50;

		std::cout << "with if-else\n";
		if (score >= 90)
			std::cout << "The grade is A.\n";
		else if (score >= 80)
			std::cout << "The grade is B.\n";
		else if (score >= 70)
			std::cout << "The grade is C.\n";
		else if (score >= 60)
			std::cout << "The grade is D.\n";
		else
			if (score>0)
				std::cout << "The grade is F.\n";
			else
				std::cout << "nothing";
	}

	inline void task3()
	{
		double temperature[] = {45,75,95};

		for (auto t:temperature)
		{
			std::cout << "temperature = " << t << "\n";
			if (t >= 50.0)
				if (t >= 80.0)
					std::cout << "Good day for swimming\n";
				else
					std::cout << "Good day for golfing\n";
			else
				std::cout << "Good day to play tennis\n";
		}
	}

	inline void task4()
	{
		int x = 2, y = 3;
		if (x >= 4 && --y < 5)
			std::cout << "Hello\n";
		std::cout << x << " " << y;
		
		std::cout << "\n==========================\n";
		x = 1; y = 4;
		if (x <= 4 || ++y < 5)
			std::cout << "Hello\n";
		std::cout << x << " " << y;

		std::cout << "\n==========================\n";
		x = 1; y = 4;int z = 7;
		if (--z <= 3 && ++x <= 4 || ++y < 5)
			std::cout << "Hello\n";
		std::cout << x << " " << y << " " << z;
	}

	inline void task5() {
		int input = 0.0;
		std::cout << "enter a number: ";
		std::cin >> input;

		std::cout << 
			((input >= 0) ? "positive" : "negative") << " " << 
			((input % 2 == 0) ? "even": "odd");
		
		using namespace std;
		int x = 0.0;cout << "enter num: ";cin >> x;

		if (x >= 0)
			if (x % 2 == 0) cout << "positive even";
			else cout << "positive odd";
		else
			if (x % 2 == 0) cout <<  "negative even";
			else cout << "negative odd";
	}

	inline void task6()
	{
		/* 
		 Task-6: Write a C++ program that: 
		 Asks the user to enter the name of their favorite fruit.
		 Checks the input and prints a message based on 
		 the fruit: If the fruit is "apple", 
		 print "You like apples!"
		 If the fruit is "banana", 
		 print "Bananas are great!" Otherwise, print "Nice choice!" 
		 */
		std::string fruit;std::cout << "enter fruit: ";std::cin >> fruit;
		
		if (fruit == "apple") std::cout << "You like apples!\n";
		else if (fruit == "bananas") std::cout << "Bananas are great!\n";
		else std::cout << "Nice choice!\n";
	}

	inline void task7()
	{
		/*
			Task-7: Write a program that prompts the user 
			to input three numbers. 
			The program should then output
			the numbers in ascending order.
		*/
		using namespace std;
		int n1 = 0, n2 = 0, n3 = 0;
		cin >> n1 >> n2 >> n3;
		if (n1 <= n2 && n1 <= n3) {
			if (n2 <= n3) std::cout << n1 << " " << n2 << " " << n3;
			else std::cout << n1 << " " << n3 << " " << n2;
		}
		else if (n2 <= n1 && n2 <= n3) {
			if (n1 <= n3) std::cout << n2 << " " << n1 << " " << n3;
			else std::cout << n2 << " " << n3 << " " << n1;
		}
		else {
			if (n1 <= n2) std::cout << n3 << " " << n1 << " " << n2;
			else std::cout << n3 << " " << n2 << " " << n1;
		}

	}

	inline void task8() {
		/* Task-8: Write a program that prompts the user to input an
		   integer between 0 and 20. If the number is less
		   than or equal to 9, the program should output the number;
		   otherwise, it should output A for 10, B for 11,
		   C for 12, . . . , and Z for 35.
		   (Hint: Use the cast operator, static_cast<char>(var)
		   for numbers >= 10.) */

		for (int i = 0; i <= 20; i++) {
			if (i <= 9)
				std::cout << i << ", ";
			else
				std::cout << static_cast<char>(i + 55) << ", ";
			if ((i + 1) % 10 == 0) std::cout << "\n";
		}
	}


	inline void task9()
	{
		using namespace std;

		cout << "Enter char: ";
		char ch;cin >> ch;

		if (ch >= '0' && ch <= '9') cout << "number.\n";

		else if ((ch >= 'a' && ch <= 'z') || 
				(ch >= 'A' && ch <= 'Z')) cout << "letter.\n";
		
		else cout << "special character.\n";
	}

	inline void run_tasks()
	{
		ps::TaskOptions taskOp{
			.task_label = "task ",
			.header = "",
			.footer = "",
			.timer_cfg{
				.enabled = true,
				.resolution = ps::enResolution::MILLISECONDS
			}
		};

		ps::PresentationSystem<std::function<void()>> tasks(taskOp);
		tasks.run({
			task1,
			task2,
			task3,
			task4,
			task5,
			task6,
			task7,
			task8,
			task9,
		});
	}
}