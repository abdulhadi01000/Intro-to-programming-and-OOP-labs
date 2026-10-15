#pragma once
#include "pch.h"
#include "presentation_system.h"

namespace oop_lab_5
{
using namespace std;
class BankAccount
{
public://Constructor and Destructor
	
	//o Default : accountNumber = "0000", balance = 0.0, ownerName = "Unknown"
	BankAccount()
	{
		accountNumber = "0000";
		balance = 0.0;
		ownerName = "Unknown";
	}
	
	//o Parameterized(2 args) : accountNumber, ownerName(balance = 0.0)
	BankAccount(const string& accountNumber, const string& ownerName)
	{
		this->accountNumber = accountNumber;
		balance = 0.0;
		this->ownerName = ownerName;
	}
	
	//o Parameterized(3 args) : accountNumber, ownerName, balance
	BankAccount(const string& accountNumber,const double balance, const string& ownerName)
	{
		this->accountNumber = accountNumber;
		this->balance = balance;
		this->ownerName = ownerName;
	}

	//• Prints "Account [number] closed."
	~BankAccount() { cout << format("Account [{}] closed.\n", accountNumber); }
public://Public methods
	
	//o  - adds to balance(validate : amount > 0)
	void deposit(const double amount)
	{
		if (amount < 0) return;
		balance += amount;
	}
	
	//o withdraw(double) - subtracts from balance(validate : sufficient funds)
	void withdraw(double amount)
	{
		if (amount > balance)return;
		balance -= amount;
	}
	
	//o display() - shows account info
	string display()
	{
		return format("accountNumber: {}, balance: {}, ownerName: {}", accountNumber, balance, ownerName);
	}

private://private members
	string accountNumber;
	double balance;
	string ownerName;
};

inline void task1()
{
	BankAccount acc1{};
	BankAccount acc2{"0001","Mohammed"};
	BankAccount acc3{ "0002",1000.93,"Mohammed ali hasan" };

	cout << "account1: " << acc1.display() << "\n";
	cout << "account2: " << acc2.display() << "\n";
	cout << "account3: " << acc3.display() << "\n";
}

class InventoryItem
{
public:
	InventoryItem(int stockNum = 0,double price = 0.0)
	:stockNum(stockNum),price(price){}	 

	string display()
	{
		return format("stockNum: {}, price: {}\n", stockNum, price);
	}

private:
	int stockNum;
	double price;
};

class Salesperson
{
public:
	Salesperson(int id,const string& name):id_num(id),name(name){}

	string display()
	{
		return format("ID: {}, Name: {}\n", id_num, name);
	}

private:
	int id_num;
	string name;
};

class Transaction
{
public:
	Transaction(
		int transNum,
		int Item_number,
		double Price,
		int Salesperson_ID,
		const string& Salesperson_name):
	transNum(transNum),
	itemSold(Item_number, Price),
	seller(Salesperson_ID, Salesperson_name)
	{}

	string display()
	{
		return format("Transaction number: {}\n"
				"Item Info:\n{}"
				"Seller Info:\n{}",
			transNum,
			itemSold.display(),
			seller.display()
		);
	}
	
private:
	int transNum;
	InventoryItem itemSold;
	Salesperson seller;
};

inline void task2()
{
	Transaction transaction1(1, 10, 100.3, 1,"the best seller");
	cout << transaction1.display();
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
		task2
		});
}



}