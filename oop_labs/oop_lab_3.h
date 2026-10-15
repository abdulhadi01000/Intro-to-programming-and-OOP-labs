#pragma once
#include "pch.h"
#include "presentation_system.h"

namespace oop_lab_3
{
	/*struct person {
	private:
		uint64_t person_id;
	public:
		std::string name;
		uint64_t brith_year;
		uint64_t brith_month;
		uint64_t brith_day;

		std::string getDate() const {
			std::ostringstream s;
			s << brith_year << "-" << brith_month << "-" << brith_day;
			return s.str();
		}
	};*/

	struct student
	{
	private:
		uint64_t id{0};
		std::string name{""};

	public:
		void setId(uint64_t new_id)
		{
			if (new_id > 9999) new_id = 9999;
			id = new_id;
		}

		void setName(const std::string& new_name)
		{
			name = new_name;
		}

		void display() const
		{
			std::cout << "id  : " << id << "\n";
			std::cout << "name: " << name << "\n";
		}

		static void test()
		{
			student stu{};
			stu.setName("abdulhadi mohammad");
			stu.setId(19);
			stu.display();
		}
	};

	struct StudentGPA
	{
	private:
		double GPA = 0;

	public :
		void setGPA(double new_gpa)
		{
			if (new_gpa > 4.0f)new_gpa = 0.0f;
			GPA = new_gpa;
		}

		double getGPA() const
		{
			return GPA;
		}

		void display() const
		{
			std::cout << "\nGPA: " << GPA << "\n";
		}

		static void test()
		{
			StudentGPA stu;
			stu.setGPA(5);
			std::cout << "\ntest getGPA func: " << stu.getGPA() << "\n";
			stu.display();
		}
	};

	struct Car
	{
	private:
		int speed = 0;

	public:
		void setSpeed(int new_speed)
		{
			if (new_speed < 0)new_speed = 0;
			if (new_speed > 200) new_speed = 200;

			speed = new_speed;
		}

		int getSpeed() const
		{
			return speed;
		}

		void display() const
		{
			std::cout << "\nspeed: " << speed << "\n";
		}

		static void test()
		{
			Car car;
			car.setSpeed(201);
			std::cout << "\ntest getSpeed func: " << car.getSpeed() << "\n";
			car.display();
		}
	};


	inline void run_tasks()
	{
		ps::TaskOptions taskOp{
			.task_label = "",
			.header = "",
			.footer = "",
			.timer_cfg{
				.enabled = true,
				.resolution = ps::enResolution::MILLISECONDS
			}
		};

		ps::PresentationSystem<std::function<void()>> tasks(taskOp);
		tasks.run({
			student::test,
			StudentGPA::test,
			Car::test
		});
	}
}
