#ifndef ATM_H_
#define ATM_H_

#include<iostream>
#include<string>
#include<map>
using namespace std;
struct customer
{
	string name;
	string password;
	double money;
};
class ATM
{
private:
	customer *ct;
	map<string, int>exist;//judge the account exist or not
public:
    ATM();
	void create_customer(const string name,const string password);
	void destroy_customer(const string name);
	bool log_in(const string name, const string password);
	void get_money(double m);
	void check_money();
	void store_money(double m);
	void log_out(const string name);

};
#endif
