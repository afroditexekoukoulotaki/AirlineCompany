#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>

using namespace std;

class Employee {
    protected:
		string firstName;
		string lastName;
		string address;
		string number;
		int ID;
		
		static int numberOfE;
    public:
		Employee();
		~Employee();
		Employee(string fn, string ln, string ads, string nb);
		
		void setNumberOfE(int n);
		int getNumberOfE();
		void setFirstName(string);
		string getFirstName ();
		void setLastName(string);
		string getLastName();
		void setAddress(string);
		string getAddress();
		void setNumber(string);
		string getNumber();
		void setID(int);
		int getID();
		virtual void Display();
		virtual string toString();
};


#endif // EMPLOYEE_H
