#include "ServiceArtist.h"

ServiceArtist::ServiceArtist(IRepo<Artist>& r) :repo_artists(r) {};

ServiceArtist::ServiceArtist(const ServiceArtist& s) :repo_artists(s.repo_artists) {};

ServiceArtist::~ServiceArtist() {};

void ServiceArtist::add_artist(int id, const Artist& a) {
	this->v.validate_artist(a);
	this->repo_artists.add_elem(id, a);
}

void ServiceArtist::update_artist(int id, const Artist& a) {
	this->v.validate_artist(a);
	this->repo_artists.update_elem(id, a);
}

Artist& ServiceArtist::delete_artist(int id) {
	Artist a = this->repo_artists.find_elem(id);
	this->repo_artists.delete_elem(id);
	return a;
}

Artist& ServiceArtist::find_artist(int id) {
	return this->repo_artists.find_elem(id);
}

int ServiceArtist::get_size() {
	return this->repo_artists.get_size();
}

vector<Artist> ServiceArtist::get_all_artists() {
	return this->repo_artists.get_all();
}
