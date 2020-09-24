#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include "User.h"
using namespace std;


class Customer : public User {
    private:
	//	int ID;
		string name;
		string number;
		string address;
		
//		static int numberOfC;
	public:
		// class constructor
		Customer();
		Customer(string, string, string);
		Customer(string);
		
		string toString();
		void Display();
		
		void setName(string);
		void setNumber(string);
		void setAddress(string);
	//	void setID(int);
//		void setNumberOfC(int);
		
		string getName();
		string getNumber();
		string getAddress();
//		int getID();
//		int getNumberOfC();
		
		~Customer();
};

#endif // CUSTOMER_H
