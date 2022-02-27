/*
 * Customer.cpp
  *
 *  Created on: July 31, 2019
 *      Author: Dang Xuan Anh Tran - SFUID: 301354210
 */

#include "Customer.h"

Customer::Customer() {      //default constructor
    this->name="";
    this->initial=0;
    this->account=0;
}

Customer::Customer(const string name, const char initial, const int account) {      //constructor
    this->name=name;
    this->initial=initial;
    this->account=account;
}

string Customer::getName() const {      //return name
    return this->name;
}

char Customer::getInitial() const {      //return initial
    return this->initial;
}

int Customer::getAccount() const {      //return balance
    return this->account;
}

void Customer::setAccount(int account) {         //set balance
    this->account=account;
}

bool Customer::operator < (const Customer& c) const {       //compare base on name, then initial
    if(this->name < c.name)     
        return true;
    else if(this->name == c.name) {     //if name equal then compare initial
        if(this->initial < c.initial)
            return true;
        else 
            return false;
    }
    else 
        return false;
}

bool Customer::operator <= (const Customer& c) const {
    if(this->name <= c.name)
        return true;
    else if(this->name == c.name) {
        if(this->initial <= c.initial)
            return true;
        else 
            return false;
    }
    else 
        return false;
}

bool Customer::operator > (const Customer& c) const {
    if(this->name > c.name)
        return true;
    else if(this->name == c.name) {
        if(this->initial > c.initial)
            return true;
        else 
            return false;
    }
    else 
        return false;
}

bool Customer::operator >= (const Customer& c) const {
    if(this->name >= c.name)
        return true;
    else if(this->name == c.name) {
        if(this->initial >= c.initial)
            return true;
        else 
            return false;
    }
    else 
        return false;
}

bool Customer::operator == (const Customer& c) const {
    if(this->name == c.name) {
        if(this->initial==c.initial)
            return true;
        else 
            return false;
    }
    else 
        return false;
}

bool Customer::operator != (const Customer& c) const{
    if(this->name != c.name) {
        if(this->initial!=c.initial)
            return true;
        else 
            return false;
    }
    else 
        return false;
}

ostream& operator<<(ostream & os,  Customer & c) {      //format to print out the customer info
    os<<c.name<<", "<<c.initial<<". ("<<c.account<<")";
}
