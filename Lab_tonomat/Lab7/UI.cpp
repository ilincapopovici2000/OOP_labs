#include "UI.h"

UI::UI() {

}

UI::UI(Service& s) {
	this->s = s;
}

UI::~UI() {

}

void show_menu() {
	cout << "1. Afisati produsele" << endl;
	cout << "2. Adaugati un produs" << endl;
	cout << "3. Stergeti un produs" << endl;
	cout << "4. Modisficati un produs" << endl;
	cout << "5. Cautati produsul" << endl;
	cout << "6. Filtrare produse cu pretul mai mic decat un nr dat" << endl;
	cout << "7. Achizitionarea unui produs" << endl;
	cout << "0. Iesire program" << endl;
}

void UI::get_all() {
	vector<Produs> v = this->s.get_all();
	for (int i = 0; i < v.size(); i++)
		cout << "Produsul " << i << v[i] << endl;
}

void UI::add() {
	Produs p;
	cout << "Dati produsul: ";
	cin >> p;
	this->s.add_produs(p);
	cout << "Produsul a fost adaugat!" << endl;
}

void UI::erase() {
	int cod;
	cout << "Dati codul produsului pe care doriti sa il stergeti: ";
	cin >> cod;
	cout << "Produsul " << this->s.delete_produs(cod) << " a fost sters!" << endl;
}

void UI::update() {
	int cod;
	string nume;
	double pret;
	cout << "Dati codul produsului pe care doriti sa il modificati: ";
	cin >> cod;
	cout << "Dati numele noului produs: ";
	cin >> nume;
	cout << "Dati pretul noului produs: ";
	cin >> pret;
	this->s.update_produs(cod, nume, pret);
	cout << "Produsul a fost modificat!" << endl;
}

void UI::find() {
	int cod;
	cout << "Dati codul produsului pe care doriti sa-l gasiti: ";
	cin >> cod;
	cout << "Produsul pe care-l cautati este: " << this->s.find_produs(cod) << endl;
}

void UI::filtrare() {
	double nr;
	cout << "Dati numarul: ";
	cin >> nr;
	vector<Produs> v = this->s.filtru_produse_pret_mai_mic_decat_nr(nr);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}

void UI::achizitie_produs() {
	Moneda m;
	vector<Moneda> plata;
	vector<Moneda> rest;
	int cod, n;
	cout << "Dati codul produsului pe care doriti sa-l achizitionati: ";
	cin >> cod;
	cout << "Dati numarul de monezi pe care doriti sa le introduceti in tonomat: ";
	cin >> n;
	cout << "Dati monezile pe care doriti sa le introduceti in tonomat: ";
	for (int i = 0; i < n; i++) {
		cin >> m;
		plata.push_back(m);
	}

	if (this->s.achizitie_produs(cod, plata, rest)) {
		cout << "Tranzactia a avut loc cu succes!";

		cout << "Restul primit este: ";
		for (int i = 0; i < rest.size(); i++)
			cout << rest[i];
	}
	else cout << "Tranzactia nu s-a putut realiza...sorry" << endl;
}

void UI::console() {
	int op;
	show_menu();
	cout << "Dati optiunea: ";
	cin >> op;
	while (true) {
		if (op == 1)
			get_all();
		if (op == 2)
			add();
		if (op == 3)
			erase();
		if (op == 4)
			update();
		if (op == 5)
			find();
		if (op == 6)
			filtrare();
		if (op == 7)
			achizitie_produs();
		if (op == 0)
			break;
		cout << "Dati urmatoarea optiune: ";
		cin >> op;
	}
}