#include "User.h"
#include "Utils.h"
#include <string>
#include <vector>
using namespace std;

User::User() {
	//constructor implicit
	this->user_id = -1;
	this->password = "";
}

User::User(int user_id, string password) {
	//constructor cu param
	this->user_id = user_id;
	this->password = password;
}

User::User(const User& u) {
	//constructor de copiere 
	this->user_id = u.user_id;
	this->password = u.password;
}

User::~User() {
	//destructor

}

int User::get_user_id() const {
	//acceseaza user name-ul
	return this->user_id;
}

string User::get_password() const {
	//acceseaza password
	return this->password;
}

void User::set_user_id(int user_n) {
	this->user_id = user_n;
}

void User::set_password(string password) {
	this->password = password;
}

User& User::operator=(const User& u) {
	this->user_id = u.user_id;
	this->password = u.password;
	return *this;
}

bool User::operator==(const User& u) {
	return (u.get_user_id() == this->user_id && u.get_password() == this->password);
}


bool User::read_txt(istream& is) {
	is >> this->user_id >> this->password;
	return is.fail() ? false : true;
}

void User::write_txt(ostream& os) const{
	os << this->user_id << " " << this->password << endl;
}

bool User::read_csv(istream& is) {
	string line;
	getline(is, line);
	vector<string> elems = splitLine(line, ',');
	this->user_id = atoi(elems[0].c_str());
	this->password = elems[1];
	return elems.size() == 2;
}

void User::write_csv(ostream& os) const {
	os << this->user_id << "," << this->password << endl;
}

int User::get_key() const{
	return this->user_id;
}

istream& operator>>(istream& is, User& u) {
	cout << "user: ";
	is >> u.user_id;
	cout << "password: ";
	is >> u.password;
	return is;
}

ostream& operator<<(ostream& os, const User& u) {
	os << "user: " << u.get_user_id() << " password: "<< u.get_password() <<endl;
	return os;
}