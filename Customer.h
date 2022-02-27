/*
 * Customer.h
 *
 *  Created on: July 31, 2019
 *      Author: Dang Xuan Anh Tran - SFUID: 301354210
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>
using namespace std;

class Customer {
public:
	Customer();
	Customer(const string name,const char initial,const int account);		//default constructor
	string getName() const;		//get name
	char getInitial() const;		//get initial
	int getAccount() const;		//get balance
	void setAccount(const int account);		//set balance

	//-----------------------------------------------------------//
	//compare overload function
	bool operator < (const Customer& c) const;
	bool operator <= (const Customer& c) const;
	bool operator > (const Customer& c) const;
	bool operator >= (const Customer& c) const;
	bool operator == (const Customer& c) const;
	bool operator != (const Customer& c) const;
private:
	friend ostream& operator<<(ostream & os,  Customer & c);	  //format to print out the customer info
	string name;
	char initial;
	int account;
};

#endif /* CUSTOMER_H_ */
