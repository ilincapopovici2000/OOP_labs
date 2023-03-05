#include <iostream>
#include "tests.h"
#include "RepoFile.h"
#include "Produs.h"
#include "Moneda.h"
#include "Service.h"
#include "UI.h"

int main()
{
	tests();
	Repo<Produs> d;
	Produs p1(3, "ciocolata", 13.2);
	Produs p2(6, "inghetata", 10.17);
	Produs p3(17, "suc", 9.00);
	Produs p4(2, "branzoaica", 7.00);
	Produs p5(5, "bomboane", 10.00);
	d.add_elem(3, p1);
	d.add_elem(6, p2);
	d.add_elem(17, p3);
	d.add_elem(2, p4);
	d.add_elem(5, p5);
	vector<Moneda> bancomat;
	Moneda m1(10.00);
	Moneda m2(50.00);
	Moneda m3(0.50);
	Moneda m4(0.50);
	Moneda m5(1.00);
	Moneda m6(5.00);
	bancomat.push_back(m1);
	bancomat.push_back(m2);
	bancomat.push_back(m3);
	bancomat.push_back(m4);
	bancomat.push_back(m5);
	bancomat.push_back(m6);
	Service s(d, bancomat);
	UI ui(s);
	ui.console();
	return 0;
}