#pragma once
#include <iostream>
using namespace std;

class PerformanceException {
private:
	string msg;
public:
	PerformanceException() {};
	PerformanceException(string _msg) :msg(_msg) {};
	string get_msg() {
		return this->msg;
	}
	~PerformanceException() {};
};