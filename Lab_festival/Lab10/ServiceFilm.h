#pragma once
#include "IRepo.h"
#include "Film.h"
#include "ValidatorFilm.h"
#include<vector>
using namespace std;

class ServiceFilm {
private:
	IRepo<Film>& repo_films;
	ValidatorFilm v;
public:
	ServiceFilm(IRepo<Film>& repo_films);
	ServiceFilm(const ServiceFilm& s);
	~ServiceFilm();
	void add_film(int, const Film& a);
	void update_film(int, const Film& a);
	Film& delete_film(int);
	Film& find_film(int);
	int get_size();
	vector<Film> get_all_films();
};