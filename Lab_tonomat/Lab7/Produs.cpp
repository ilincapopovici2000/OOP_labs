#include "Produs.h"
#include <iostream>
using namespace std;

Produs::Produs() {
	//constructor implicit
	//in: -
	//out:un produs
	this->cod = 0;
	this->nume = "";
	this->pret = 0.0;
}

Produs::Produs(int cod, string nume, double pret) {
	//constructor cu param
	//in: atributele unui produs
	//out:un produs
	this->cod = cod;
	this->nume = nume;
	this->pret = pret;
}

Produs::Produs(const Produs& p) {
	//constructor de copiere
	//in: un produs
	//out:un produs
	this->cod = p.cod;
	this->nume = p.nume;
	this->pret = p.pret;
}

Produs::~Produs() {
	/*destructor*/
}

int Produs::get_cod() const {
	/*Acceseaza codul produsului
	In: -
	Out: codul
	*/
	return this->cod;
}

string Produs::get_nume() const {
	/*Acceseaza numele produsului
	In: -
	Out: numele
	*/
	return this->nume;
}

double Produs::get_pret() const {
	/*Acceseaza pretul produsului
	In: -
	Out: pretul
	*/
	return this->pret;
}

void Produs::set_cod(int cod) {
	/*Seteaza codul unui produs
	In: codul
	Out: -
	*/
	this->cod = cod;
}

void Produs::set_nume(string nume) {
	/*Seteaza numele unui produs
	In: numele
	Out: -
	*/
	this->nume = nume;
}

void Produs::set_pret(double pret) {
	/*Seteaza pretul unui produs
	In: pretul
	Out: -
	*/
	this->pret = pret;
}

Produs& Produs::operator=(const Produs& p) {
	/*Incarca operatorul de atribuire pentru produs
	In: produs
	Out: -
	*/
	this->set_cod(p.cod);
	this->set_nume(p.nume);
	this->set_pret(p.pret);
	return *this;
}

bool Produs::operator==(const Produs& p) {
	/*Verifica daca doua produse sunt egale
	In: produs
	Out: true/false
	*/
	return (this->cod == p.cod);
}

ostream& operator<<(ostream& os, const Produs& p) {
	os << "codul: " << p.cod << " numele: " << p.nume << " pretul: " << p.pret << endl;
	return os;
}

istream& operator>>(istream& is, Produs& p) {
	cout << "Dati codul: ";
	is >> p.cod;
	cout << "Dati numele: ";
	is >> p.nume;
	cout << "Dati pretul: ";
	is >> p.pret;
	return is;
}