#include "Session.h"

Session::Session(){
	//this->connectedUser = 0;
}

void Session::setConnectedUser(User* u){
	this->connectedUser = u;
}

User* Session::getConnectedUser(){
	return this->connectedUser;
}

int Session::login(string username, string password) {
//	for(list<Administrator>::iterator it = administratorList.begin(); it != administratorList.end(); ++it){
//		
//	}
  // look all customers and administrators from company
  // if someone match then
  //  connectedUser = userMatches;
  //  return true;
  // else
  //  return false;
  return 1;
}
