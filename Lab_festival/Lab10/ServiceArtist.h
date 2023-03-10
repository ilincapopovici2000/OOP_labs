#pragma once
#include "IRepo.h"
#include "Artist.h"
#include "ValidatorArtist.h"
#include <vector>
using namespace std;

class ServiceArtist {
private:
	IRepo<Artist>& repo_artists;
	ValidatorArtist v;
public:
	ServiceArtist(IRepo<Artist>& repo_artists);
	ServiceArtist(const ServiceArtist& s);
	~ServiceArtist();
	void add_artist(int, const Artist& a);
	void update_artist(int, const Artist& a);
	Artist& delete_artist(int);
	Artist& find_artist(int);
	int get_size();
	vector<Artist> get_all_artists();
};