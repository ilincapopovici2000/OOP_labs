#pragma once
#include <iostream>
using namespace std;

class ExceptiiRepo {
private:
	string msg;
public:
	ExceptiiRepo() {};
	ExceptiiRepo(string _msg) :msg(_msg) {};
	string get_msg() {
		return this->msg;
	}
	~ExceptiiRepo() {};
};