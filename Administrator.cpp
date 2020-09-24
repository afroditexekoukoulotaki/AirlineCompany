#include "Administrator.h"

Administrator::Administrator(){
	this->ID = ++numberOfU;
}

Administrator::Administrator(string str){
	istringstream issin(str);
	list<string> elements;
	string el;
	int i = 0;

	while (getline(issin, el, '|')) {
		elements.push_back(el);
		i++;
	}
	this->ID = stoi(elements.front()); elements.pop_front();
	this->username = elements.front(); elements.pop_front();
	this->password = elements.front(); elements.pop_front();
}

string Administrator::toString(){
    string str = to_string(this->ID) + "|" + this->username + "|" + this->password + "\n";
    return str;
}

//int Administrator::numberOfA;
