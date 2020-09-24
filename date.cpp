#include "date.h" // class's header file

// class constructor
Date::Date() {}

Date::Date(unsigned int d, unsigned int m, unsigned int y) : day(d), month(m), year(y) {}

// 22/12/2016
Date::Date(string str){
	while (str.length() != 10 || str.at(2) != '/' || str.at(5) != '/' || 
			stoi(str.substr(0,2)) < 0 || stoi(str.substr(0,2)) > 31 || stoi(str.substr(3,2)) < 0 || stoi(str.substr(3,2)) > 12 || 
			stoi(str.substr(6,4)) < 2000 ){
			 	
		cout << "    Enter valid date (--/--/----): ";
		cin >> str;
	}
	this->day = stoi(str.substr(0,2));
	this->month = stoi(str.substr(3,2));
	this->year = stoi(str.substr(6,4));
}
void Date::setDate(string str){
	while (str.length() != 10 || str.at(2) != '/' || str.at(5) != '/' || 
			stoi(str.substr(0,2)) < 0 || stoi(str.substr(0,2)) > 31 || stoi(str.substr(3,2)) < 0 || stoi(str.substr(3,2)) > 12 || 
			stoi(str.substr(6,4)) < 2000 ){
			 	
		cout << "    Enter valid date (--/--/----): ";
		cin >> str;
	}
	this->day = stoi(str.substr(0,2));
	this->month = stoi(str.substr(3,2));
	this->year = stoi(str.substr(6,4));
}

string Date::getDate(){
	string str, d, m, y;
	str = to_string(this->day);
	if(this->day < 10)
		d = '0' + str;
	else
		d = str;
	str = to_string(this->month);
	if(this->month < 10)
		m = '0' + str;
	else
		m = str;
	str = to_string(this->year);
	y = str;
	str = d + '/' + m + '/' + y;
	return str;
}

void Date::setDay(unsigned int d){
    this->day = d;
}
void Date::setMonth(unsigned int m){
    this->month = m;
}
void Date::setYear(unsigned int y){
    this->year = y;
}

unsigned int Date::getDay()
{
    return this->day;
}
unsigned int Date::getMonth()
{
    return this->month;
}
unsigned int Date::getYear()
{
    return this->year;
}

// class destructor
Date::~Date() {}
