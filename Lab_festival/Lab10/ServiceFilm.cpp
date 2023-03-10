#include "ServiceFilm.h"

ServiceFilm::ServiceFilm(IRepo<Film>& r) :repo_films(r) {};

ServiceFilm::ServiceFilm(const ServiceFilm& s) :repo_films(s.repo_films) {};

ServiceFilm::~ServiceFilm() {};

void ServiceFilm::add_film(int id, const Film& f) {
	this->v.validate_film(f);
	this->repo_films.add_elem(id, f);
}

void ServiceFilm::update_film(int id, const Film& f) {
	this->v.validate_film(f);
	this->repo_films.update_elem(id, f);
}

Film& ServiceFilm::delete_film(int id) {
	Film a = this->repo_films.find_elem(id);
	this->repo_films.delete_elem(id);
	return a;
}

Film& ServiceFilm::find_film(int id) {
	return this->repo_films.find_elem(id);
}

int ServiceFilm::get_size() {
	return this->repo_films.get_size();
}

vector<Film> ServiceFilm::get_all_films() {
	return this->repo_films.get_all();
}
