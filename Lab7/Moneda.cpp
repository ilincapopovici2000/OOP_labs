#include "Moneda.h"
#include <iostream>
#include <string.h>
using namespace std;

Moneda::Moneda() {
	this->val = 0;
}

Moneda::Moneda(double val) {
	this->val = val;
}

Moneda::Moneda(const Moneda& b) {
	this->val = b.val;
}

Moneda::~Moneda() {
}

double Moneda::get_val() const {
	return this->val;
}

void Moneda::set_val(double val) {
	this->val = val;
}

istream& operator>>(istream& is, Moneda& m) {
	cout << "Dati valoarea: ";
	is >> m.val;
	return is;
}

ostream& operator<<(ostream& os, const Moneda& m) {
	os << "valoarea este: " << m.val;
	return os;
}