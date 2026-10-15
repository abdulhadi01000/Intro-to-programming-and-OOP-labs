#pragma once
#include "pch.h"
#include "presentation_system.h"

using namespace std;
namespace intro_lab_7
{
	inline void task1()
	{
		int array[] = { 8, 3, 7,
		9,11 };
		int n, result = 0;
		for (n = 0; n < 5; n++)
		{
			result += array[n];
		}
		cout << "Total = " << result;
	}

	inline void task2()
	{
		int array[4];
		int n, m;
		for (n = 0; n < 4; n++)
			cin >> array[n];
		for (m = 3; m >= 0; m--)
			cout << array[m];
	}

	inline void task3()
	{
		//Task - 3: Write a C++ program that displays a 
		//histogram based on the values stored in an 
		//array.Each value in the array is represented 
		//by a number of stars(*) equal to its value.

		const int size = 5;
		int arr[size] = {1,4,10,5,3,};

		for (int i = 0 ; i< size ;i++)
		{
			for (int j = 1;j<=arr[i];j++)
			{
				cout << "*";
			}
			cout << "\n";
		}
	}

	inline void task4()
	{
		//Task-4: Write C++ program to read 6 students IdNo, 
		//Name, grade1, grade2, gender then find 
		//: the total grade for each student and find the 
		//class average. (use arrays)
		struct student
		{
			int IdNo;
			std::string name;
			int grade1, grade2;
			string gender;
		};

		const int size = 6;
		student arr[size] =
		{
			{1,"Mohammad", 70,60, "Male"},
			{2,"Ahmed", 86,23, "Male"},
			{3,"Abdulhadi", 43,87, "Male"},
			{4,"Ali", 83,92, "Male"},
			{5,"Omar", 34,76, "Male"},
			{6,"Jamel", 67,75, "Male"}
		};

		int sum = 0;
		for (int i = 0 ; i< size;i ++) {
			sum += arr[i].grade1 + arr[i].grade2;
			cout << format("ID: {}, Name: {}, Grade1: {}, Grade2: {}, Total: {}, Gender: {}\n",arr[i].IdNo,arr[i].name,arr[i].grade1,arr[i].grade2,arr[i].grade1 + arr[i].grade2,arr[i].gender);
		}
		cout << "Class Total Score: " << static_cast<double>(sum)/ size << endl;
	}

	inline void task5()
	{
		int i, j;
		char array[3][2] = { {'a','b'},{'c','d'},{'e','f'} };
		//print array
		
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 2; j++) {
				cout << array[i][j] << " ";
			}
			cout << endl;
		}
	}

	inline void task6()
	{
		int i, j, sum = 0; int array[4][4];
		for (i = 0; i <= 3; i++)
			for (j = 0; j <= 2; j++) cin >> array[i][j];
		for (i = 0; i <= 3; i++)
		{
			for (j = 0; j <= 2; j++)
				cout << array[i][j] << " "; cout << endl;
		}
		for (i = 0; i <= 3; i++)
			for (j = 0; j <= 2; j++) sum += array[i][j];
		cout << endl << "Sum= " << sum; 

	}

	inline void task7()
	{
		//Task - 7 :Write a program to read two square 
		//arrays and print output arrays 
		//summation in a new square array.

		const int s = 2;
		int arr1[s][s]{ {9,8},{1,2} };
		int arr2[s][s]{ {3,2},{4,5} };
		int op[s][s];

		for (int i = 0 ; i< s;i++) {
			for (int j = 0;j < s;j++) {
				op[i][j] = arr1[i][j] + arr2[i][j];
				cout << op[i][j] << " ";
			}
			cout << "\n";
		}
	}

	inline void task8()
	{
		//Task - 8 :Write program to read square array 
		//and print elements main diagonal and secondary 
		//diagonal and other elements change of space " " .
		const int s = 3;
		int a[s][s]{ {1,2,5},{6,7,9}, {5,8,4} };

		for (int i = 0 ; i< s ;i++) {
			for (int j = 0;j<s;j++) {
				if (i == j || i + j == s - 1) 
					cout << a[i][j] << " ";
				else
					cout << " ";
			}
			cout << "\n";
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
			task1,
			task2,
			task3,
			task4,
			task5,
			task6
			});
	}
}