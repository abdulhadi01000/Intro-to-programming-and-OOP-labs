#pragma once
#include "pch.h"
#include "presentation_system.h"
	
namespace oop_lab_2 {
	void Pointers_task1() {
		//Assigning addresses to pointers.
		//Using the address-of operator (&).
		int magicNumber = 348323232;
		int* INT_POINTER = &magicNumber;
		std::cout << "magicNumber value: " << magicNumber << "\n";
		std::cout << "pointer value: " << *INT_POINTER << "\n";
	}
	void Pointers_task2() {
		//Accessing values using the dereference operator
		//Using the address-of operator (&).
		int magicNumber = 348323232;
		int* INT_POINTER = &magicNumber;
		*INT_POINTER = 1;
		std::cout << "magicNumber value:" << magicNumber << "\n";
		std::cout<< "pointer value: " << *INT_POINTER << "\n";
	}
	void Pointers_task3() {
		//Using pointers with arrays
		const int size = 4;
		std::string arrNames[size] = {
			"Mohammad",
			"Ali",
			"AbdulHadi",
			"Hasan",
		};

		std::string* pointer_to_names = arrNames;

		std::cout << "printing array from pointer:\n";
		for (int i = 0; i < size; i++) {
			std::cout << "Index: " << i << " ,Value: " << *(pointer_to_names + i) <<
				" ,Adress:" << (pointer_to_names + i) << "\n";
		}
		std::cout << "\n";
	}
	void swap(int * idk, int* idk2) {
		int temp = *idk;
		*idk = *idk2;
		*idk2 = temp;
	}
	void Pointers_task4() {
		//Passing variables to functions using pointers
		int magic_Number = 1234567890;
		int magic_Number2 = 987654321;
		std::cout << "before swap -> First Num:" << magic_Number << " ,Second Num: " << magic_Number2 << "\n";
		swap(&magic_Number,&magic_Number2);
		std::cout << "After  swap -> First Num:" << magic_Number << " ,Second Num: " << magic_Number2 << "\n";
	}

	void string_task1() {
		//• Declaring variables of type string.
		//• Reading strings using cin and getline().
		std::string read("hi");

		std::cout << "Enter: ";
		std::cin >> read;
		std::cout <<"cin value: " << read << "\n";

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Enter: ";
		std::getline(std::cin, read);
		std::cout << "getline value: " << read << "\n";
	}
	void string_task2() {
		//• Concatenating strings using + operator.
		std::string first_name("Ali");
		std::string last_name("mohammad");
		std::cout << first_name + "  " + last_name << "\n";
	}
	void string_task3() {
		//• Comparing strings using relational operators(== , <, >).
		std::string first_name("Ali");
		std::string last_name("mohammad");

		std::cout << first_name + " " + last_name << "\n";
		std::cout << ((first_name > last_name) ? first_name : last_name) << "\n";
		std::cout << ((first_name < last_name) ? first_name : last_name) << "\n";
		std::cout << ((first_name == last_name) ? 
			first_name + last_name + " are Equal": 
			first_name + last_name + " are NOT Equal\n");
	}
	void string_task4() {
		//• Accessing characters using string[index].
		std::string idk = "SADFGHJKWERTYUIOZXCVBN";
		for (int i = 0; i < idk.length(); i++) {
			std::cout << idk[i] << " ";
		}
		std::cout << "\n\n";
	}
	void string_task5() {
		//• Using string functions such as :
		//  ➢ lengthf()
		//	➢ substr()
		//	➢ replace()
		//	➢ insert()
		std::string idk = "SADFGHJKWERTYUIOZXCVBN";
		std::cout <<"idk length ["<<  idk.length() << "]\n";
		std::cout << "idk from index 4 to more 10 charchters: " << idk.substr(4, 10) << "\n";
		std::string pizza = "I'm eating pizza right now";
		std::cout << pizza.replace(11, 5, "pasta") << "\n";
		std::cout << idk.insert((idk.length() / 2), " " + pizza + " ") << "\n\n";
	}


	void struct_tasks() {
		using namespace std;
		//• Declaring struct types.
		struct person {
			string name = "";
			string race = "";
			int age = 0;
		};
		
		//• Creating variables of structure types.
		person ahmed;
		//• Accessing structure members using the dot operator (.).
		ahmed.name = "Ahmed mohammed ali";
		ahmed.race = "arab";
		ahmed.age = 2389;
		//• Using structures inside structures.
		struct student {
			person person_info{};
			int stu_id = 0;
		};
		struct car
		{
		public:
			string model = "";
			string made_in = "";
			int model_year = 0;

			struct wheels {
				string color = "";
				int sizeInInche = 0;
			};
			wheels wheels_type{};
		};
		//• Creating arrays of structures.
		const int size = 100;
		car ikea[size] = {};
		for (int i = 0; i < size; i++) {
			ikea[i].made_in = "jordan";
			ikea[i].model = "Y3";
			ikea[i].model_year = 20000;
			ikea[i].wheels_type.color = "black";
			ikea[i].wheels_type.sizeInInche = 200;
		}

		for (int i = 0; i < size; i++) {
			cout <<
				ikea[i].made_in <<
				ikea[i].model <<
				ikea[i].model_year <<
				ikea[i].wheels_type.color <<
				ikea[i].wheels_type.sizeInInche << "\n";
		}
	}



	void run_tasks() {
		ps::PresentationSystem<std::function<void()>> tasks({
			.timer_cfg = {
				.enabled = true,
				.resolution = ps::enResolution::MICROSECONDS
			} });

		tasks.run({
			Pointers_task1,
			Pointers_task2,
			Pointers_task3,
			Pointers_task4,
		});

		tasks.run({
			string_task1,
			string_task2,
			string_task3,
			string_task4,
			string_task5
		});
	}
}