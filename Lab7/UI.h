#pragma once
#include "Service.h"

class UI {
private:
	Service s;
	void add();
	void find();
	void get_all();
	void update();
	void erase();
	void filtrare();
	void achizitie_produs();
public:
	UI();
	UI(Service&);
	void console();
	~UI();
};
