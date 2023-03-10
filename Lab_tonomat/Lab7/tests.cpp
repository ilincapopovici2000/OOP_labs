#include "Produs.h"
#include "RepoFile.h"
#include "Service.h"
#include "assert.h"

void tests_domain() {
	cout << "domain" << endl;
	//constructori
	Produs* p1 = new Produs;
	assert(p1->get_cod() == 0 && p1->get_nume() == "" && p1->get_pret() == 0);
	Produs* p2 = new Produs(3, "ciocolata", 13.34);
	assert(p2->get_cod() == 3 && p2->get_nume() == "ciocolata" && p2->get_pret() == 13.34);
	//set / get
	Produs* p3 = new Produs;
	p3->set_cod(2);
	p3->set_nume("bomboane");
	p3->set_pret(25.90);
	assert(p3->get_cod() == 2 && p3->get_nume() == "bomboane" && p3->get_pret() == 25.90);
	//=
	p3 = p2;
	assert(p3->get_cod() == 3 && p3->get_nume() == "ciocolata" && p3->get_pret() == 13.34);
	// == 
	assert(p3 == p2);
	if (p1 != NULL) {
		delete p1;
		p1 = NULL;
	}
	if (p2 != NULL) {
		delete p2;
		p2 = NULL;
	}
	/*
	if (p3 != NULL) {
		delete p3;
		p3 = NULL;
	}*/
	cout << "Yay";
}

void tests_repo() {
	cout << "teste repo" << endl;
	//constructori
	Repo<Produs> d;
	Produs p1(3, "ciocolata", 13.2);
	Produs p2(6, "inghetata", 10.17);
	Produs p3(17, "suc", 9);
	Produs p4(2, "branzoaica", 7.00);
	//add
	d.add_elem(3, p1);
	d.add_elem(6, p2);
	d.add_elem(17, p3);
	assert(d.get_size() == 3);
	//find
	assert(p2 == d.find_elem(6));
	//delete
	assert(d.delete_elem(17) == p3);
	assert(d.get_size() == 2);
	//update
	d.update_elem(3, p4);
	assert(p4 == d.find_elem(3));
	cout << "Yay" << endl;
}

void tests_service() {
	cout << "service" << endl;
	Repo<Produs> d;
	vector<Moneda> b;
	Produs p1(3, "ciocolata", 13.2);
	d.add_elem(3, p1);
	Produs p2(6, "inghetata", 10.17);
	Produs p3(17, "suc", 9);
	Produs p4(2, "branzoaica", 7.00);
	Service s(d, b);
	//add
	s.add_produs(p2);
	s.add_produs(p3);
	s.add_produs(p4);
	assert(s.get_size() == 4);
	//find
	assert(p2 == s.find_produs(6));
	//delete
	assert(s.delete_produs(17) == p3);
	assert(s.get_size() == 3);
	//update
	s.update_produs(2, "bomboana", 14.99);
	assert(p4 == s.find_produs(2));
	//filtrare
	//vector<Produs> v = s.filtru_produse_pret_mai_mic_decat_nr(10);
	//assert(v[0] == p3);
	cout << "Yay" << endl;

}

void tests_repofile() {
	cout << "teste repofile" << endl;
	//constructori
	RepoFile<Produs> r("produse.txt");    
	assert(r.get_size() == 3);
	Produs p1(18, "ciocolata", 13.2);
	Produs p2(6, "inghetata", 10.17);
	Produs p3(17, "suc", 9);
	Produs p4(2, "branzoaica", 7.00);
	//add
	r.add_elem(3, p1);
	r.add_elem(6, p2);
	r.add_elem(17, p3);
	r.add_elem(2, p4);
	assert(r.get_size() == 7);
	vector<Produs> v = r.get_all();
	assert(v[3] == p4);
	//find
	assert(v[1] == r.find_elem(6));
	//delete
	assert(r.delete_elem(17) == p3);
	assert(r.get_size() == 3);
	//update
	r.update_elem(3, p4);
	assert(p4 == r.find_elem(3));
	cout << "Yay" << endl;
}

/*
void tests_repofile0() {
	cout << "teste repofile" << endl;
	//constructori
	RepoFile<Produs> r("produse.txt");
	cout<<r.get_size();
}*/

void tests() {
	tests_domain();
	tests_repo();
	tests_service();
	//tests_repofile();
}