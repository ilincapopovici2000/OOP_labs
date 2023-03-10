#pragma once
#include <iostream>

class ExceptiiRepo {
private:
	std::string mesaj;
public:
	ExceptiiRepo() {}
	ExceptiiRepo(const std::string& m) :mesaj(m) {} //constructor cu parametrii
	std::string gestionare_mesaj() {
		return this->mesaj;
	}
	~ExceptiiRepo() {}
};
