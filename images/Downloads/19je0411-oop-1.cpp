#include <bits/stdc++.h>
using namespace std;
class Customer
{
private:
	string address;
	string ph;
	string lic_no;
	long c_n;
	long aP;

public:
	Customer(string res, string tel, string license, long custno);
	bool operator<(Customer cust);
	void updateaP(long amt);
	void resetaP();
	long getaP();
	long gcN();
};

Customer::Customer(string res, string tel, string license, long custno)
{
	address = res;
	ph = tel;
	lic_no = license;
	c_n = custno;
	aP = 0;
}

bool Customer::operator<(Customer cust)
{
	return aP < cust.aP;
}

void Customer::updateaP(long amt)
{
	aP += amt;
	cout << "Check-out successful\n";
	cout << "Annual purchase amt as of now: " << aP << "\n";
}

void Customer::resetaP()
{
	aP = 0;
}

long Customer::getaP()
{
	return aP;
}

long Customer::gcN()
{
	return c_n;
}

class sm
{
private:
	vector<Customer> cus;

public:
	void reg_cus();
	void Check_out();
	void prep_winners();
};

void sm::reg_cus()
{
	string res, tel, license;
	fflush(stdin);
	cout << "Enter address:";
	getline(cin, res);
	cout << "Enter phone number:";
	cin >> tel;
	cout << "Enter license number:";
	cin >> license;
	Customer customer(res, tel, license, cus.size() + 1);
	cus.push_back(customer);
	cout << "Customer registered successfully.\n";
	cout << "c_n : " << customer.gcN() << "\n\n";
}

void sm::Check_out()
{
	long custno, amt;
	cout << "Enter customer number (c_n):";
	cin >> custno;

	int n = cus.size(), idx = -1;
	for (int i = 0; i < n; i++)
	{
		if (cus[i].gcN() == custno)
		{
			idx = i;
			break;
		}
	}
	if (idx == -1)
	{
		cout << "Invalid customer number. Please try again\n\n";
		return;
	}

	cout << "Enter purchase amt:";
	cin >> amt;
	cus[idx].updateaP(amt);
}

void sm::prep_winners()
{
	sort(cus.rbegin(), cus.rend());

	int n = cus.size(), winers = min(10, n);
	cout << "Surprise gift winers:\n";
	for (int i = 0; i < winers; i++)
	{
		cout << cus[i].gcN() << "\n";
	}

	cout << "\nGold Coin winers:\n";
	for (int i = 0; i < n; i++)
	{
		if (cus[i].getaP() > 10000)
		{
			cout << cus[i].gcN() << "\n";
		}
	}

	cout << "\n";

	for (int i = 0; i < n; i++)
		cus[i].resetaP();
}

int main()
{
	sm sm;
	int c;
	cout << "Welcome to sm!";
	while (true)
	{
		cout << "Options:\n";
		cout << "1. Register as a new customer\n";
		cout << "2. Check-out a purchase\n";
		cout << "3. Prepare prize winers' list\n";
		cout << "4. Exit\n";
		cout << "Enter your option:";
		cin >> c;
		switch (c)
		{
		case 1:
			sm.reg_cus();
			break;
		case 2:
			sm.Check_out();
			break;
		case 3:
			sm.prep_winners();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Invalid\n";
			break;
		}
	}
}
