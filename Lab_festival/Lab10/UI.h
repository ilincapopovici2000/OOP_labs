#pragma once
#include "ServiceArtist.h"
#include "ServiceFilm.h"
#include "ServicePerformance.h"
#include "ServiceUser.h"

class UI {
private:
	ServiceArtist service_artist;
	ServiceFilm service_film;
	ServicePerformance service_performance;
	ServiceUser service_user;
	User* user;
	void add_artist();
	void add_film();
	void add_performance();
	void delete_artist();
	void delete_film();
	void delete_performance();
	void update_artist();
	void update_film();
	void update_performance();
	bool login_user();
	void logout_user();
	void show_artists();
	void show_films();
	void show_performances();
	void find_performance_by_date();
	void buy_tickets();
public:
	UI(const ServiceArtist& s_artist, const ServiceFilm& s_film, const ServicePerformance& s_performance,
		const ServiceUser& s_user);
	UI(const UI& ui);
	~UI();
	void console();
	void show_menu();
};