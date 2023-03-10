#pragma once
#include <iostream>
#include <string.h>
using namespace std;
#include <ostream>
#include <istream>


class Produs {
private:
	int cod;
	string nume;
	double pret;
public:
	Produs();
	Produs(int, string, double);
	Produs(const Produs&);
	~Produs();
	int get_cod() const;
	string get_nume() const;
	double get_pret() const;
	void set_cod(int);
	void set_nume(string);
	void set_pret(double);
	Produs& operator=(const Produs&);
	bool operator==(const Produs&);
	friend ostream& operator<<(ostream& os, const Produs&);
	friend istream& operator>>(istream& is, Produs&);
};