/*
 * Node.h
 *
 *  Created on: July 31, 2019
 *      Author: Dang Xuan Anh Tran - SFUID: 301354210
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
public:
    Customer c;
    Node* leftchild;
    Node* rightchild;
    Node();      //default constructor
    Node(const Customer& c);         //constructor that take a customer as argument
};

#endif /* NODE_H_ */
