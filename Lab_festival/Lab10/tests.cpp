#include "tests.h"
#include "assert.h"
#include "User.h"
#include "Repo.h"
#include "Artist.h"
#include "Film.h"
#include "Performance.h"
#include "RepoFile.h"
#include "ExceptiiRepo.h"
#include "RepoFileTxt.h"
#include "ServiceArtist.h"
#include "ServiceFilm.h"
#include "ServicePerformance.h"

void tests_user() {

	cout << "tests_user" << endl;

	User u(26, "abc");
	assert(u.get_user_id() == 26 && u.get_password() == "abc");
	u.set_password("xyz");
	assert(u.get_password() == "xyz");
	u.set_user_id(78);
	assert(u.get_user_id() == 78);
	User u2(456, "amd");
	u = u2;
	assert(u.get_user_id() == 456 && u.get_password() == "amd");

	cout << "tests_user successful" << endl;
}

void tests_repo_user() {

	cout << "testst_repo_user" << endl;

	Repo<User> r;
	User u1(26, "abc");
	User u2(456, "amd");
	User u3(6, "lmd");
	User u(26, "h");
	User u4(1, "hi");

	//add
	r.add_elem(26, u1);
	r.add_elem(456, u2);
	r.add_elem(6, u3);
	try {
		r.add_elem(26, u);
		assert(false);
	}
	catch (ExceptiiRepo & e) {
			assert(e.get_msg() == "repo::add: replicated key");
	}

	//get_size
	assert(r.get_size() == 3);

	//find
	assert(r.find_elem(6) == u3);
	try {
		r.find_elem(100);
		assert(false);
	}
	catch (ExceptiiRepo & e) {
		assert(e.get_msg() == "repo::find: unknown key");
	}

	//update
	r.update_elem(456, u3);
	assert(r.find_elem(456) == u3);
	try {
		r.update_elem(4, u3);
		assert(false);
	}
	catch (ExceptiiRepo & e) {
		assert(e.get_msg() == "repo::update: unknown key");
	}

	//delete
	r.delete_elem(26);
	assert(r.get_size() == 2);
	try {
		r.delete_elem(79);
		assert(false);
	}
	catch (ExceptiiRepo & e) {
		assert(e.get_msg() == "repo::delete: unknown key");
	}

	cout<<"tests_repo_user successful" << endl;

}

void tests_repo_file_user_txt() {

	cout << "tests_repo_file_user_txt" << endl;

	RepoFileTxt<User> f("users_tests.txt");
	assert(f.get_size() == 4);
	User u1(26, "abc");
	//add
	f.add_elem(26, u1);
	cout << "aici1";
	//find
	assert(f.find_elem(26) == u1);
	cout << "aici2";
	//update
	User u8(26, "qwe");
	f.update_elem(26, u8);
	cout << "aici3";
	assert(f.find_elem(26) == u8);
	cout << "aici4";
	//delete
	f.delete_elem(9);
	assert(f.get_size() == 4);

	cout << "tests_repo_file_user_txt successful" << endl;
}

void tests_repo_file_user_csv() {

	cout << "tests_repo_file_user_scv" << endl;

	RepoFileTxt<User> f("users_tests.csv");
	assert(f.get_size() == 4);
	User u1(26, "abc");
	//add
	f.add_elem(26, u1);
	cout << "aici1";
	//find
	assert(f.find_elem(26) == u1);
	cout << "aici2";
	//update
	User u8(26, "qwe");
	f.update_elem(26, u8);
	cout << "aici3";
	assert(f.find_elem(26) == u8);
	cout << "aici4";
	//delete
	f.delete_elem(9);
	assert(f.get_size() == 4);

	cout << "tests_repo_file_user_csv successful" << endl;
}

void tests_domain() {
	cout << "tests_domain" << endl;

	//Performer
	Performer p(1, "Billie Eilish");
	assert(p.get_id() == 1 && p.get_name() == "Billie Eilish");
	p.set_name("Martin Garrix");
	assert(p.get_name() == "Martin Garrix");
	
	//Artist
	Artist a(6, "Kygo");
	assert(a.get_id() == 6 && a.get_name() == "Kygo");
	a.set_name("David Guetta");
	assert(a.get_name() == "David Guetta");

	//Filme
	Film f(8, "Divergent");
	assert(f.get_id() == 8 && f.get_name() == "Divergent");
	f.set_name("The Maze Runner");
	assert(f.get_name() == "The Maze Runner");
	Artist a1(4, "Dylan O'Brian");
	Artist a2(5, "Kaya Scodelario");
	f.add_actor(&a1);
	f.add_actor(&a2);
	assert(f.get_actors().size());
	for (auto a : f.get_actors())
		cout << a->get_name() << " " << endl;

	//Performance
	Performance performance(5, &a, "13.05.2020", "Cluj Arena", 5000, 100);
	assert(performance.get_id() == 5 && performance.get_performer() == &a);
	assert(performance.get_date() == "13.05.2020" && performance.get_loc() == "Cluj Arena");
	assert(performance.get_nr_loc_available() == 5000 && performance.get_nr_loc_sold() == 100);
	
	cout << "tests_domain successful" << endl;
}

void tests_services() {
	cout << "tests_service" << endl;

	//Artists
	Repo<Artist> r;
	Artist a1(14, "Selena Gomez");
	Artist a2(2, "Shawn Mendes");
	Artist a3(7, "Ariana Grande");
	Artist a4(14, "Zara Larsson");
	r.add_elem(14, a1);
	r.add_elem(2, a2);
	ServiceArtist s(r);
	assert(s.find_artist(14) == a1);
	assert(s.find_artist(2) == a2);
	s.add_artist(7, a3);
	assert(s.find_artist(7) == a3);
	s.update_artist(14, a4);
	assert(s.find_artist(14) == a4);
	s.delete_artist(7);
	assert(s.get_size() == 2);

	//Films
	Film::service_artist = &s;
	Repo<Film> repo_film;
	Film f1(16, "The hunger games");
	Film f2(13, "The giver");
	Film f3(5, "The heat");
	Film f4(13, "22 Jump Street");
	repo_film.add_elem(16, f1);
	repo_film.add_elem(13, f2);
	ServiceFilm sf(repo_film);
	assert(sf.find_film(16) == f1);
	assert(sf.find_film(13) == f2);
	sf.add_film(5, f3);
	assert(sf.find_film(5) == f3);
	sf.update_film(13, f4);
	assert(sf.find_film(13) == f4);
	sf.delete_film(5);
	assert(sf.get_size() == 2);

	//Performance
	Performance::service_artist = &s;
	Performance::service_film = &sf;
	Repo<Performance> repo_performance;
	Film f(16, "The hunger games");
	Artist a(2, "Shawn Mendes");
	Artist a8(5, "Meghan Trainor");
	Performance p1(5, &a, "13.07.2020", "Cluj Arena", 5000, 100);
	Performance p2(6, &f, "14.07.2020", "Cluj Arena", 5000, 100);
	Performance p3(5, &a, "15.07.2020", "Cluj Arena", 5000, 100);
	repo_performance.add_elem(5, p1);
	ServicePerformance sp(repo_performance);
	assert(sp.find_performance(5) == p1);
	sp.add_performance(6, p2);
	assert(sp.find_performance(6) == p2);
	sp.update_performance(5, p3);
	assert(sp.find_performance(5) == p3);
	sp.delete_performance(6);
	assert(sp.get_size() == 1);

	cout << "tests_service successful" << endl;
}


void tests() {
	tests_user();
	tests_repo_user();
	//tests_repo_file_user_txt();
	//tests_repo_file_user_csv();
	tests_domain();
	tests_services();
}