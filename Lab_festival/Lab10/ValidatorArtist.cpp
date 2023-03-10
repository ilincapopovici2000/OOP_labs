#include "ValidatorArtist.h"

ValidatorArtist::ValidatorArtist() {
}

ValidatorArtist::~ValidatorArtist() {
}

void ValidatorArtist::validate_artist(const Artist& a) {
	if (a.get_id() < 0)
		throw "Id-ul trebuie sa fie intreg pozitiv! ";
	if (a.get_name() == "")
		throw "Nume invalid!";
}
