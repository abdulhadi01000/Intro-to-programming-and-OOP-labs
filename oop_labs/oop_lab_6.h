#pragma once
#include "pch.h"
#include "presentation_system.h"

using namespace std;

namespace oop_lab_6
{
	class Transaction;
	class Customer;

	class Customer
	{
	public:
		Customer(int cust_num, double balance_due) :
			balance_due(balance_due), cust_num(cust_num)
		{
		}

		friend inline void applyTransaction(Customer& customer, const Transaction& transaction);

	private:
		double balance_due;
		long long cust_num;
	};

	class Transaction
	{
	public:
		Transaction(int transaction_num, int cust_num, double amount) :
			amount(amount), transaction_num(transaction_num), cust_num(cust_num)
		{
		}

		friend inline void applyTransaction(Customer& customer, const Transaction& transaction);

	private:
		double amount;
		int transaction_num;
		int cust_num;
	};

	inline void applyTransaction(Customer& customer, const Transaction& transaction)
	{
		if (customer.cust_num != transaction.cust_num)
		{
			cout << "TRANSACTION FAILED: This transaction is not for this customer!\n";
			return;
		}
		double old_balance = customer.balance_due;
		customer.balance_due += transaction.amount;

		cout << "OG Balance: " << old_balance << "\n";
		cout << "New Balance: " << customer.balance_due << "\n";
		cout << "Transaction Details: " << "\n"
			"Customer ID: " << transaction.cust_num << "\n"
			"Transaction ID: " << transaction.transaction_num << "\n"
			"Transferred amount: " << transaction.amount << "\n";
	}

	inline void task1()
	{
		//• Create Customer (ID=888, balance=200.00)
		//• Create Transaction(ID = 111, custNum = 888, amount = -150.00)
		//• Apply transaction and display results

		Customer customer(888, 200);
		Transaction transaction(111, 888, -150);
		applyTransaction(customer, transaction);

		cout << "=================================\n";

		Customer customer2(123, 200);
		Transaction transaction2(111, 888, -150);
		applyTransaction(customer2, transaction2);
	}


	class BankAccount
	{
	public:
		BankAccount() :
			account_number("ACC-00000"),
			owner_name("Unknown"),
			balance(0.0),
			interest_rate(0.035)
		{
		}

		BankAccount(
			const string& account_number,
			const string& owner_name,
			const double balance,
			const double interest_rate) :
			account_number(account_number),
			owner_name(owner_name),
			balance(balance),
			interest_rate(interest_rate)
		{
		}

		BankAccount operator+(const BankAccount& other) const
		{
			return BankAccount("ACC-00000", "Unknown", balance + other.balance, interest_rate);
		}

		BankAccount operator+(double amount) const
		{
			return BankAccount(account_number, owner_name, balance + amount, interest_rate);
		}

		friend BankAccount operator+(double amount, const BankAccount& acc)
		{
			return acc + amount;
		}

		BankAccount& operator-(const double amount)
		{
			if (balance - amount > 0)
			{
				balance -= amount;
			}
			else
			{
				cout << "can't perform withdraw!\n";
			}

			return *this;
		}

		bool operator==(const BankAccount& other) const
		{
			return account_number == other.account_number;
		}

		BankAccount& operator=(const BankAccount& other)
		{
			if (this != &other)
			{
				account_number = other.account_number;
				owner_name = other.owner_name;
				balance = other.balance;
				interest_rate = other.interest_rate;
			}
			return *this;
		}

		friend ostream& operator <<(ostream& os, const BankAccount& acc)
		{
			os << "account number: " << acc.account_number <<
				", name: " << acc.owner_name <<
				", balance: " << acc.balance <<
				", interest rate: " << acc.interest_rate << "\n";
			return os;
		}

		friend istream& operator >>(istream& is, BankAccount& acc)
		{
			do
			{
				cout << "enter account_number: ";
				is >> acc.account_number;
			}
			while (!isValidAccountNumber(acc.account_number));

			cout << "enter owner_name:     ";
			is >> acc.owner_name;

			cout << "enter balance:        ";
			is >> acc.balance;

			while (acc.balance < 0)
			{
				cout << "balance can't be below zero! will be set to zero\n";
				acc.balance = 0;
			}

			cout << "enter interest_rate:  ";
			is >> acc.interest_rate;
			if (acc.interest_rate < 0 || acc.interest_rate > 15)
				acc.interest_rate = 0.035;

			return is;
		}

		static int get_transaction_count() { return transaction_count; }

		void applyInterest()
		{
			if (interest_rate < 0 || interest_rate > 15) return;

			balance += (balance * interest_rate);
			transaction_count++;
		}

		static bool isValidAccountNumber(const string& accNum)
		{
			if (accNum.length() == 9 && accNum.substr(0, 4) == "ACC-")
			{
				return true;
			}
			return false;
		}

	private:
		string account_number;
		string owner_name;
		double balance;
		double interest_rate;
		static int transaction_count;
	};

	int BankAccount::transaction_count = 0;

	inline void task2()
	{
		//1. Create account1 using >> operator (user input)
		BankAccount acc1;
		cin >> acc1;
		//2. Create account2 using parameterized constructor
		BankAccount acc2("ACC-12345", "someone", 212, 12.43);

		//3. Display both accounts using << operator
		cout << "\nacc1: " << acc1 << "\n";
		cout << "acc2: " << acc2 << "\n";

		//4. Test: account3 = account1 + account2(merge balances)
		BankAccount acc3 = acc1 + acc2;
		cout << "acc3: " << acc3 << "\n";

		//5. Test : account4 = account1 + 500.00
		BankAccount acc4 = acc1 + 500;
		cout << "acc4: " << acc4 << "\n";

		//6. Test : account5 = 1000.00 + account2
		BankAccount acc5 = 1000 + acc2;
		cout << "acc5: " << acc5 << "\n";

		//7. Test : account1 - 200.00 (withdraw)
		acc1 = acc1 - 500;
		cout << "acc1: " << acc1 << "\n\n";

		//8. Compare account1 and account2 using ==
		if (acc1 == acc2) cout << "account 1 equal account 2\n";
		else cout << "account 1 dose not equal account 2\n";
	}


	class Matrix
	{
	public:
		Matrix(int r, int c, string n = "Unnamed") : rows(r), cols(c), name(n)
		{
			data = new int*[rows];
			for (int i = 0; i < rows; ++i)
			{
				data[i] = new int[cols]();
			}
		}

		Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), name(other.name + "_copy")
		{
			data = new int*[rows];
			for (int i = 0; i < rows; ++i)
			{
				data[i] = new int[cols];
				for (int j = 0; j < cols; ++j)
				{
					data[i][j] = other.data[i][j];
				}
			}
		}

		~Matrix()
		{
			for (int i = 0; i < rows; ++i) delete[] data[i];
			delete[] data;
		}

		int* operator[](int row) const { return data[row]; }

		int& operator()(int r, int c) const { return data[r][c]; }

		Matrix& operator++()
		{
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < cols; ++j) data[i][j]++;
			return *this;
		}

		Matrix operator++(int)
		{
			Matrix temp(*this);
			++(*this);
			return temp;
		}

		Matrix operator+(const Matrix& other) const
		{
			if (rows != other.rows || cols != other.cols)
				return Matrix(1, 1);

			Matrix result(rows, cols, "Sum");
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < cols; ++j)
					result.data[i][j] = data[i][j] + other.data[i][j];
			return result;
		}

		Matrix operator*(const Matrix& other) const
		{
			if (cols != other.rows)
				return Matrix(1, 1);

			Matrix result(rows, other.cols, "Product");
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < other.cols; ++j)
					for (int k = 0; k < cols; ++k)
						result.data[i][j] += data[i][k] * other.data[k][j];
			return result;
		}

		bool operator==(const Matrix& other) const
		{
			if (rows != other.rows || cols != other.cols) return false;
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < cols; ++j)
					if (data[i][j] != other.data[i][j]) return false;
			return true;
		}

		friend class MatrixCalculator;

		friend ostream& operator<<(ostream& os, const Matrix& m)
		{
			os << format("Matrix: {} ({}x{})\n", m.name, m.cols, m.rows);

			os << "[";
			for (int i = 0; i < m.rows; ++i)
			{
				os << "[";
				for (int j = 0; j < m.cols; ++j)
					os << format("{}, ", m.data[i][j]);
				os << "] ";
			}
			os << "]\n";
			return os;
		}

		friend istream& operator>>(istream& is, Matrix& m)
		{
			for (int i = 0; i < m.rows; ++i)
				for (int j = 0; j < m.cols; ++j) is >> m.data[i][j];
			return is;
		}

	private:
		int** data;
		int rows, cols;
		string name;
	};

	class MatrixCalculator
	{
	public:
		static Matrix transpose(const Matrix& m)
		{
			Matrix res(m.cols, m.rows, "Transposed");
			for (int i = 0; i < m.rows; ++i)
				for (int j = 0; j < m.cols; ++j)
					res.data[j][i] = m.data[i][j];
			return res;
		}

		static double determinant(const Matrix& m)
		{
			if (m.rows != m.cols) return 0.0;
			if (m.rows == 2)
				return (m.data[0][0] * m.data[1][1]) - (m.data[0][1] * m.data[1][0]);
			return 0;
		}

		static bool isSymmetric(const Matrix& m)
		{
			if (m.rows != m.cols) return false;
			for (int i = 0; i < m.rows; ++i)
				for (int j = 0; j < m.cols; ++j)
					if (m.data[i][j] != m.data[j][i]) return false;
			return true;
		}
	};

	inline void task3()
	{
		Matrix A(2, 2, "A");
		cout << "Enter values for 2x2 Matrix A:\n";
		cin >> A;

		Matrix B(2, 2, "B");
		B[0][0] = 1;
		B[1][1] = 1;

		cout << A << "\n";
		cout << B << "\n";

		A[0][0] = 10;
		A(1, 1) = 20;
		cout << "Modified A:\n" << A << "\n\n";

		Matrix C = A + B;
		Matrix D = A * B;
		cout << C << "\n";
		cout << D << "\n";

		cout << "Testing Prefix ++A:\n" << ++A << "\n";
		cout << "Testing Postfix A++ (shows before):\n" << A++ << "\n";
		cout << "After Postfix:\n" << A << "\n";

		cout << "A == B? " << (A == B ? "Yes\n" : "No\n");

		cout << "Transpose of A:\n" << MatrixCalculator::transpose(A) << "\n";
		cout << "Is A Symmetric? " << (MatrixCalculator::isSymmetric(A) ? "Yes" : "No") << "\n";

		Matrix E = A;
		cout << "Copy of A (Matrix E):\n" << E;
	}

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

		ps::PresentationSystem<function<void()>> tasks(taskOp);
		tasks.run({
			task1,
			task2,
			task3,
		});
	}
}
