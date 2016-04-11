#include<iostream>
#include"ATM.h"

using namespace std;

ATM::ATM()
{
	ct = new customer;
	ct->name = "none";
	ct->password = "000000";
	ct->money = 0;
}
//create a new account
void ATM::create_customer(const string name,const string password)
{
	ct = new customer;
	ct->name = name;
	ct->password = password;
	ct->money = 10000;
	exist[name] = 1;
}
//destroy a account
void ATM::destroy_customer(const string name)
{
	if (!exist[name])
	{
		cout << "The username isn't exist!" << endl;
	}
	else if(exist[name] == 2)
	{
		cout << "The username has logged in!" << endl;
	}
	else
	{
		exist[name] = 0;
		delete ct;
		cout << "The account has been destroyed." << endl;
	}
}
//login and judge 
bool ATM::log_in(const string name, const string password)
{
	if (!exist[name])//isn't exist
	{
		cout << "The username isn't exist!" << endl;
		return false;
	}
	else if (exist[name] == 2)//has logged in
	{
		cout << "The username has logged in!" << endl;
		return false;
	}
	else
	{
		if (password == ct->password)
		{
			cout << "Holle! " << name << endl;
			exist[name] = 2;
			return true;
		}
		else//password wrong
		{
			cout << "The password is wrong!" << endl;
			return false;
		}
	}
}
//store money
void ATM::store_money(double m)
{
	if ((ct->money + m) > 100000)//maximize
	{
		cout << "The money you store is maximizing!" << endl;
	}
	else
	{
		ct->money += m;
		cout << "You have stored " << m << " yuan." << endl;
	}
}
//get money
void ATM::get_money(double m)
{
	if (ct->money < m)//not enough
	{
		cout << "Not sufficient funds!" << endl;
	}
	else
	{
		ct->money -= m;
		cout << "You have got " << m << " yuan." << endl;
	}
}
//check money
void ATM::check_money()
{
	cout << "You have " << ct->money << " on your account." << endl;
}
//log out and judge
void ATM::log_out(const string name)
{
	if (!exist[name])//isn't exist
	{
		cout << "The username isn't exist!" << endl;
	
	}
	else if (exist[name] == 2)// logged out
	{
		cout << "The username has logged out!" << endl;
		exist[name] = 1;
	}
	else//doesn't log in
	{
		cout << "The username doesn't log in" << endl;
	}
}

int main()
{
	string Name, Password;
	ATM Customer;
	double get_money, store_money;
	char command;
	cout << "If you want to create an account,please enter C." << endl;
	cout << "If you want to destroy an account,please enter D." << endl;
	cout << "If you want to log in,please enter I." << endl;
	cout << "If you want to quit,please enter Q." << endl;

	cin >> command;
	while (command != 'Q')
	{
		switch (command)
		{
		case'C':cout << "Enter the username: "; cin >> Name;
			cout << "Enter the password: "; cin >> Password;
			Customer.create_customer(Name, Password);
			break;
		case'D':cout << "Enter the username: "; cin >> Name;
			Customer.destroy_customer(Name);
			break;
		case'I':cout << "Enter the username: "; cin >> Name;
			cout << "Enter the password: "; cin >> Password;
			if (Customer.log_in(Name, Password))//have logged in
			{
				cout << "If you want to store money,please enter S." << endl;
				cout << "If you want to get money,please enter G." << endl;
				cout << "If you want to check money,please enter K." << endl;
				cout << "If you want to log out,please enter O." << endl;
				cin >> command;
				while (command != 'O')
				{
				switch (command)
				{
				case'S':cout << "How much do you want to store: ";
					cin >> store_money;
					Customer.store_money(store_money);
					break;
				case'G':cout << "How much do you want to get: ";
					cin >> get_money;
					Customer.get_money(get_money);
					break;
				case'K':Customer.check_money();
					break;
				
				default:
					break;
				}
				cin >> command;
			}
		    cout << "Enter the username: ";
			cin >> Name;
			Customer.log_out(Name);
		
			}
		default:
			break;
		}
		cout << "If you want to create an account,please enter C." << endl;
		cout << "If you want to destroy an account,please enter D." << endl;
		cout << "If you want to log in,please enter I." << endl;
		cout << "If you want to quit,please enter Q." << endl;
		cin >> command;
	}
	return 0;
}