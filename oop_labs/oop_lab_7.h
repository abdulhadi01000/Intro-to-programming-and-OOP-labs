#pragma once
#include "pch.h"
#include "presentation_system.h"
using namespace std;

namespace oop_lab_7
{
    class Person {
    public:
        void setPerson(const string& n, int a) {
            name = n;
            age = a;
        }

        void displayPerson() const { cout << format("Name: {}, Age: {}\n", name, age); }
    protected:
        string name;
        int age = 0;
    };

    class Student : public Person {
    public:
        void setStudent(const string& name, int age, int id) {
            setPerson(name, age);
            studentId = (id > 9999) ? 9999 : id;
        }

        void displayStudent() {
            displayPerson();
            cout << format("Student ID: {}\n", studentId);
        }

        void InitStudentInfo()
        {
            name = "";
            age = 0;
            studentId = 0;
        }
    private:
        int studentId = 0;
    };

    class Employee {
    public:
        Employee(int id, double s) : empId(id), salary(s) {}
        void display() { cout << format("Employee ID: {}, Salary: {}", empId, salary); }
    protected:
        int empId;
        double salary;
    };

    class Manager : public Employee {
    public:
        Manager(int id, double s, double b) : Employee(id, s), bonus(b) {}

        void display() {
            Employee::display();
            cout << "\nBonus: " << bonus << "\n";
        }
    private:
        double bonus;
    };

    class Animal {
    public:
        Animal() { cout << "Animal constructor called" << endl; }
        ~Animal() { cout << "Animal destructor called\n\n\n\n\n\n\n" << endl; }

        static void testAnimal()
        {
            Animal animal{};
        }
    };

    class Mammal : public Animal {
    public:
        Mammal() { cout << "Mammal constructor called" << endl; }
        ~Mammal() { cout << "Mammal destructor called" << endl; }
        static void testMammal()
        {
            Mammal mammal{};
        }
    };

    class Dog : public Mammal {
    public:
        Dog() { cout << "Dog constructor called" << endl; }
        ~Dog() { cout << "Dog destructor called" << endl; }
        static void testDog()
        {
            Dog dog{};
        }
    };

    inline void testAnimals()
    {
        Animal::testAnimal();
        Mammal::testMammal();
        Dog::testDog();

        cout << "you can also call the methods from the dog class since it derived from mammal that also derived from animal\n";
        Dog::testAnimal();
        Dog::testMammal();
        Dog::testDog();
    }

    class Vehicle {
    public:
        void setVehicle(const string& m, double mpg) { make = m; milesPerGallon = mpg; }
        void displayVehicle() const { cout << format("Make: {}, MPG: {}\n", make, milesPerGallon); }
    protected:
        string make;
        double milesPerGallon;
    };

    class Dwelling {
    public:
        void setDwelling(int b, int sq) { bedrooms = b; squareFeet = sq; }
        void displayDwelling() const {cout << format("Bedrooms: {}, sqFt: {}", bedrooms, squareFeet);}
    protected:
        int bedrooms, squareFeet;
    };

    class RV : public Vehicle, public Dwelling {
    public:
        void displayRV() const {
            displayVehicle();
            displayDwelling();
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
		[]()
			{
	            Student s;
				s.setStudent("Abdulhadi", 19, 12345);
				s.displayStudent();
			},
            testAnimals,
		});
	}
}