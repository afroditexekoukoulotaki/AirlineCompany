#ifndef SESSION_H
#define SESSION_H
#include <string>
#include "User.h"
using namespace std;

class Session
{
	public:
		Session();
		int login(string username, string password);
		void setConnectedUser(User*);
		User* getConnectedUser();
	protected:
	private:
		User* connectedUser;
};

#endif
