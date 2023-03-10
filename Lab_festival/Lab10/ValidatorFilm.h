#pragma once
#include "Film.h"

class ValidatorFilm {
public:
	ValidatorFilm();
	~ValidatorFilm();
	void validate_film(const Film& f);
};