#include "Service.h"

Service::Service() {

}

Service::Service(const Repo<Produs>& r, const vector<Moneda> b) {
	this->repository = r;
	this->bancomat = b;
}

Service::~Service() {

}

void Service::add_produs(const Produs& p) {
	this->repository.add_elem(p.get_cod(), p);
}

Produs& Service::find_produs(int cod) {
	return this->repository.find_elem(cod);
}

vector<Produs> Service::get_all() {
	return this->repository.get_all();
}

int Service::get_size() {
	return this->repository.get_size();
}

void Service::update_produs(int cod, string nume, double pret) {
	Produs p(cod, nume, pret);
	this->repository.update_elem(cod, p);
}

Produs Service::delete_produs(int cod) {
	return this->repository.delete_elem(cod);
}

vector<Produs> Service::filtru_produse_pret_mai_mic_decat_nr(double nr) {
	vector<Produs> v;
	for (int i = 0; i < this->repository.get_size(); i++) {
		Produs p = this->repository.get_all()[i];
		if (p.get_pret() < nr)
			v.push_back(p);
	}
	return v;
}

bool Service::achizitie_produs(int cod, vector<Moneda> plata, vector<Moneda>& rest) {
	//intoarce true daca tranzactia are loc, rest va contine restul
	//intoarce false daca tranzactia nu are loc, nu se modifica nimic

	Produs p = this->repository.find_elem(cod);
	double suma_introdusa = get_suma(plata);
	if (p.get_pret() > suma_introdusa)
		return false;
	if (exista_suma_in_bancomat(suma_introdusa - p.get_pret(), rest)) {
		this->repository.delete_elem(cod);
		bancomat.insert(bancomat.end(), plata.begin(), plata.end());
		return true;
	}
	else return false;
}

bool Service::exista_suma_in_bancomat(double suma, vector<Moneda>& v) {
	//intoarce true daca suma exista in monede in bancomat, in v se transfera monedele corespunzatoare
	//intoarce false daca nu
	
	if (suma == 0)
		return true;
	else {
		for (int i = 0; i < this->bancomat.size(); i++) {
			double m = this->bancomat[i].get_val();
			if (m <= suma) {
				v.push_back(this->bancomat[i]);
				bancomat.erase(bancomat.begin() + i);
				if (exista_suma_in_bancomat(suma - m, v))
					return true;
				else {
					Moneda x = v.back();
					v.pop_back();
					this->bancomat.insert(bancomat.begin() + i, x);
				}
			}
		}
	}
	return false;
}

double Service::get_suma(vector<Moneda> plata) {
	double s=0.0;
	for (int i = 0; i < plata.size(); i++)
		s = s + plata[i].get_val();
	return s;
}

