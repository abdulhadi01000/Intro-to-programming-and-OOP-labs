#pragma once
#include "pch.h"

namespace oop_lab_4 
{
	using namespace std;
	class student
	{
	private:
		uint64_t id{ 0 };
		string name{ "" };

	public:
		void setId(uint64_t new_id)
		{
			if (new_id > 9999) new_id = 9999;
			id = new_id;
		}

		void setName(const string& new_name)
		{
			name = new_name;
		}

		void display() const
		{
			cout << "id  : " << id << "\n";
			cout << "name: " << name << "\n";
		}

		static void test() {
			student stu{};

			string name;
			cout << "Enter student name: ";
			getline(cin, name);
			stu.setName(name);

			uint64_t ID;
			cout << "Enter student ID: ";
			cin>> ID;
			stu.setId(ID);

			stu.display();
		}
	};

	class StudentGPA
	{
	private:
		double GPA = 0;
		
	public:
		void setGPA(double new_gpa)
		{
			if (new_gpa > 4.0)new_gpa = 0.0;
			GPA = new_gpa;
		}

		double getGPA() const
		{
			return GPA;
		}

		void display() const { cout << "\nGPA: " << GPA << "\n"; }

		static void test() {
			StudentGPA stu;

			double gpa;
			cout << "Enter you GPA: ";
			cin >> gpa;
			stu.setGPA(gpa);
			
			cout << "\ntest getGPA func: " << stu.getGPA() << "\n";
			stu.display();
		}
	};

	class Car {
	private:
		int speed = 0;

	public:
		void setSpeed(int new_speed) {
			if (new_speed < 0)new_speed = 0;
			if (new_speed > 200) new_speed = 200;

			speed = new_speed;
		}

		int getSpeed() const { return speed; }

		void display() const { cout << "\nspeed: " << speed << "\n"; }

		static void test() {
			Car car;

			int speed;
			cout << "Enter car speed: ";
			cin >> speed;

			car.setSpeed(speed);
			cout << "\ntest getSpeed func: " << car.getSpeed() << "\n";
			car.display();
		}
	};

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

		ps::PresentationSystem<function<void()>> tasks(taskOp);
		tasks.run({
			student::test,
			StudentGPA::test,
			Car::test
		});
	}

}