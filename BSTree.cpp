/*
 * BSTree.cpp
 *
 *  Created on: July 31, 2019
 *      Author: Dang Xuan Anh Tran - SFUID: 301354210
 */

#include "BSTree.h"


BSTree::BSTree() {
	this->root=NULL;
}

BSTree::BSTree(const BSTree & rbt) {
	this->root=copyHelper(rbt.root);
}

BSTree::~BSTree() {
	Destroy(root);
}

bool BSTree::insert(string x, char y, int z) {
	Customer c(x,y,z);
	this->root=insertHelp(root,c);
	if(search(x,y))			//search if the customer is presence or not for the bool statement
		return true;
	return false;
}

bool BSTree::remove(string x, char y) {
	Customer c(x,y,0);
	if(search(x,y)) {		//search if the customer is presence or not
		this->root=removeHelp(this->root, c);		//delete if the customer is found
		return true;
	}
	return false;
}

bool BSTree::search(string x, char y) {
	Node* temp=root;
	Customer c(x,y,0);
	while(temp!=NULL) {  //go through the tree
		if(temp->c==c)
			return true;
		else if(c<temp->c)
			temp=temp->leftchild;		//go to left node
		else
			temp=temp->rightchild;		//go to right node
	}
	delete temp;
	return false;
}

vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) {
	vector<Customer> range; 
	Customer c1(x,y,0);
	Customer c2(z,a,0);
	rangeSearchHelp(range,this->root,c1,c2);
	return range;
}

void BSTree::inOrderPrint() {
	inOrder(this->root);
}

Node* BSTree::copyHelper(const Node* root) {		//helper function to make copy recursive
	if(root==NULL)		//condition
		return NULL;
	Node* temp=new Node;
	temp->c=root->c;
	temp->leftchild=copyHelper(temp->leftchild);		//recursive left side
	temp->rightchild=copyHelper(temp->rightchild);		//recursive right side
	return temp;
}

Node* BSTree::Destroy(Node* root) {		//helper function to make destructor recursive
	if(root) {
		Destroy(root->rightchild);
		Destroy(root->leftchild);
		delete root;
	}
}

Node* BSTree::insertHelp(Node* root, Customer& c) {		//helper function to make insert recursive
	if(root == NULL) 
		return new Node(c);
	if(c<root->c) 
		root->leftchild=insertHelp(root->leftchild,c);
	else 
		root->rightchild=insertHelp(root->rightchild,c);
	return root;
}

void BSTree::inOrder(Node* root) {		//inorder traversal
	if(root!=NULL) {
		inOrder(root->leftchild);
		cout<<root->c<<endl;
		inOrder(root->rightchild);
	}
}

Node* BSTree::removeHelp(Node* root, Customer& c) {		//helper function to make remove recursive
	if(root==NULL)		//return condition
		return root;
	if(c<root->c)
		root->leftchild=removeHelp(root->leftchild, c);
	else if(c>root->c)
		root->rightchild=removeHelp(root->rightchild, c);
	else {
		if(root->leftchild ==NULL) {		//delete node with no left child
			Node* temp=root->rightchild;
			delete root;
			return temp;
		}
		else if(root->rightchild==NULL) {		//delete node with no right child
			Node* temp=root->leftchild;
			delete root;
			return temp;
		}
		Node* temp=root->rightchild;
		while(temp&&temp->leftchild!=NULL)
			temp=temp->leftchild;
		root->c=temp->c;
		root->rightchild=removeHelp(root->rightchild, temp->c);
	}
	return root;
}

void BSTree::rangeSearchHelp(vector<Customer> &range, Node* root, Customer& c1, Customer& c2) {		//helper function to make search in a range recursive
	if(root==NULL)
		return;
	if(c1<root->c)
		rangeSearchHelp(range,root->leftchild,c1,c2);
	if(c1<=root->c&&c2>=root->c)
		range.push_back(root->c);
	if(c2>root->c)
		rangeSearchHelp(range,root->rightchild,c1,c2);
}