#include "User.h"

int User::numberOfU;

string User::getUsername(){
	return this->username;
}

string User::getPassword(){
	return this->password;
}

void User::setUsername(string u){
	this->username = u;
}

void User::setPassword(string p){
	this->password = p;
}

void User::setNumberOfU(int n){
	this->numberOfU = n;
}

int User::getNumberOfU(){
	return this->numberOfU;
}
void User::setID(int id)
{
     this->ID = id;
}
int User::getID() {
    return this->ID;
}
