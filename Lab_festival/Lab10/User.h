#pragma once
#include <iostream>
using namespace std;

class User {
private:
	int user_id;
	string password;
public:
	User();
	User(int, string);
	User(const User&);
	~User();
	int get_user_id() const;
	string get_password() const;
	void set_user_id(int);
	void set_password(string);
	bool read_txt(istream& is);
	void write_txt(ostream& os) const;
	bool read_csv(istream& is);
	void write_csv(ostream& os) const;
	int get_key() const;
	User& operator=(const User&);
	bool operator==(const User&);
	friend istream& operator>>(istream& is, User&);
	friend ostream& operator<<(ostream& os, const User&);
};