/*
 * Node.cpp
 *
 *  Created on: July 31, 2019
 *      Author: Dang Xuan Anh Tran - SFUID: 301354210
 */

#include "Node.h"

Node::Node() {      //default constructor
    this->leftchild=NULL;
    this->rightchild=NULL;
}

Node::Node(const Customer& c) {     //constructor that take a customer as argument
    this->c=c;
    this->leftchild=NULL;
    this->rightchild=NULL;
}
