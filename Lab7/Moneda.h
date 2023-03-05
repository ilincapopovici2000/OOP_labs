#pragma once
#include <iostream>
#include <string.h>
using namespace std;
#include <ostream>
#include <istream>

class Moneda {
private:
	double val;
public:
	Moneda();
	Moneda(double);
	Moneda(const Moneda&);
	~Moneda();
	double get_val() const;
	void set_val(double);

	friend istream& operator>>(istream& is, Moneda&);
	friend ostream& operator<<(ostream&, const Moneda&);
};