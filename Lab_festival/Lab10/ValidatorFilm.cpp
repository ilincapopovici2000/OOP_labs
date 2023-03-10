#include "ValidatorFilm.h"

ValidatorFilm::ValidatorFilm() {

}

ValidatorFilm::~ValidatorFilm() {

}

void ValidatorFilm::validate_film(const Film& f) {
	if (f.get_id() < 0)
		throw "Id-ul trebuie sa fie intreg pozitiv! ";
	if (f.get_name() == "")
		throw "Nume invalid!";
}

