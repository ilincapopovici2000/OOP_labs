#include "ValidatorPerformance.h"

ValidatorPerformance::ValidatorPerformance() {

}

ValidatorPerformance::~ValidatorPerformance() {

}

void ValidatorPerformance::validate_performance(const Performance& p) {
	if (p.get_id() < 0)
		throw "Id-ul trebuie sa fie intreg pozitiv! ";
	if (p.get_date() == "")
		throw "Nume invalid!";
	if (p.get_loc() == "")
		throw "Nume invalid!";
	if (p.get_nr_loc_available() < 0)
		throw "Nr de locuri disponibile trebuie sa fie intreg pozitiv! ";
	if (p.get_nr_loc_sold() < 0)
		throw "Nr de locuri vandute trebuie sa fie intreg pozitiv";
}