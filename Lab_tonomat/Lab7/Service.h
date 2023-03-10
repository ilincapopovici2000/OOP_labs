#pragma once
#include "Repo.h"
#include "Produs.h"
#include "Moneda.h"
#include<iostream>
using namespace std;


class Service {
private:
	Repo<Produs> repository;
	vector<Moneda> bancomat;
public:
	Service();
	Service(const Repo<Produs>&, const vector<Moneda>);
	~Service();
	void add_produs(const Produs&);
	Produs& find_produs(int);
	vector<Produs> get_all();
	int get_size();
	void update_produs(int, string, double);
	Produs delete_produs(int);
	vector<Produs> filtru_produse_pret_mai_mic_decat_nr(double nr);
	bool achizitie_produs(int cod, vector<Moneda> plata, vector<Moneda>& rest);
	bool exista_suma_in_bancomat(double suma, vector<Moneda>& v);
	double get_suma(vector<Moneda> plata);
};