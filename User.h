#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
	public:
		void setUsername(string);
		void setPassword(string);
		string getUsername();
		string getPassword();
		
		void setNumberOfU(int n);
		int getNumberOfU();
		
		void setID(int);
		int getID();
	protected:
		string username;
		string password;
		static int numberOfU;
		int ID; //Customer has already ID
};

#endif
