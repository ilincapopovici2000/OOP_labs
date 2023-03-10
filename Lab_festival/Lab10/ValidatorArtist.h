#pragma once
#include "Artist.h"

class ValidatorArtist {
public:
	ValidatorArtist();
	~ValidatorArtist();
	void validate_artist(const Artist& a);
};