#pragma once
#include "pch.h"

namespace intro_lab_6 {
	using namespace std;
	
	inline void task1(int num)
	{
		cout << "number:" << num << "\n";
		for (int i = 1; i <= num; i++)
			cout << i << " ";
		cout << "\n\n";
	}

	inline void task2()
	{
		for (int i = 0 ; i <= 20 ; i+=2)
			cout << i << " ";
	}

	inline void task3()
	{
		int sum = 0;
		for (int i = 51 ; i <= 100 ;i+=2 )
			sum += i;
		cout << sum << "\n";
	}

	inline void task4()
	{
		int n = 5;
		for (int i = n; i >= 1;i--)
			cout << "WAIT!!!\n";
		cout << "GO!!!\n";
	}

	inline void task5()
	{
		for (int i = 1;i <= 5;i++)
		{
			for (int j = i; j >= 1; j--)
				cout << "*";
			cout << "\n";
		}
	}

	inline int task6_power(int base,int pow)
	{
		int result = 1;
		for (int i = 1;i<=pow;i++)
			result *= base;
		return result;
	}

	inline void task7()
	{
		int counter = 0;
		while (counter <= 7)
		{
			cout << counter << ",";
			counter++;
		}
		cout << "\ncompleted counter";
	}

	inline void task8()
	{
		double n;
		do {
			cout << "Enter number (0 to end): ";
			cin >> n;
			cout << "You entered: " << n << "\n";
		} while (n != 0.0);
	}

	inline void task9()
	{
		int n = 20;
		while (n <= 80)
		{
			cout << "even\n";
			n += 2;
		}
	}

	inline void task10()
	{
		int odd_count = 0;
		int n = 0;
		do
		{
			cout << "enter a number (zero to end):";
			cin >> n;
			if (n % 2 != 0)odd_count++;
		} while (n != 0);
		cout << "odd count:" << odd_count;
	}

	inline void task11()
	{
		long long fact = 1;
		int n = 1;
		cout << "enter number to calculate factorial:";
		cin >> n;
		while (n > 1)
		{
			fact *= n;
			n--;
		}
		cout << fact << "\n";
	}

	inline void task12()
	{
		//here used the prev task number 6
		cout << task6_power(2, 11) + task6_power(5, 3) + task6_power(6, 4);
		
		////////////////////////////////////////////////////
		int n1 = 2, pow1 = 11,
			n2 = 5, pow2 = 3,
			n3 = 6, pow3 = 4;
		
		int i = 1;
		while (i <= pow1){n1 *= n1;i++;}
		i = 1;
		while (i <= pow2){n2 *= n2;i++;}
		i = 1;
		while (i <= pow3){n3 *= n3;i++;}
		cout << n1 + n2 + n3 << "\n";
	}

	inline void task13()
	{
		int i = 1;
		while (i <= 200)
		{
			if (i % 7 == 0)
				cout << format("{} multiple of 7\n", i);
			i++;
		}
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
			[]
			{
				task1(3);
				task1(7);
				task1(10);
			},
			task2,
			task3,
			task4,
			task5,
			[] { cout << task6_power(10,8); },
			task7,
			task8,
			task9,
			task10,
			task11,
			task12,
			task13,
			});
	}
}