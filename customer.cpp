#include "customer.h"

//int Customer::numberOfC;

Customer::Customer() {
	this->ID = ++numberOfU;
}

Customer::Customer( string nm, string nb, string ad) : name(nm), number(nb), address(ad) {}

Customer::Customer(string str) {
	istringstream issin(str);
	list<string> elements;
	string el;
	int i = 0;

	while (getline(issin, el, '|')) {
		elements.push_back(el);
		i++;
	}
	this->ID = stoi(elements.front());
	elements.pop_front(); // Delete first element
	this->name = elements.front();
	elements.pop_front();
	this->number = elements.front();
	elements.pop_front();
	this->address = elements.front();
	elements.pop_front();
	this->username = elements.front(); elements.pop_front();
	this->password = elements.front(); elements.pop_front();
}

string Customer::toString(){
    string str = to_string(this->ID) + "|" + this->name + "|" + this->number + "|" + this->address + "|" + this->username
				 + "|" + this->password + "\n";
    return str;
}

void Customer::Display(){
	string str;
	str = "    " + to_string(this->ID) + " | " + this->name + " | " + this->number + " | " + this->address + "\n";
	cout << str;
}

void Customer::setName(string nm)
{
     this->name = nm;
}
void Customer::setNumber(string nb)
{
     this->name = nb;
}
void Customer::setAddress(string ad)
{
     this->name = ad;
}
/*void Customer::setNumberOfC(int n){
	this->numberOfC = n;
}*/

string Customer::getName()
{
    return this->name;   
}
string Customer::getNumber()
{
    return this->number;   
}

string Customer::getAddress()
{
    return this->address;   
}

/*int Customer::getNumberOfC(){
	return this->numberOfC;
}*/

// class destructor
Customer::~Customer() {}
