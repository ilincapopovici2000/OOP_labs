#include <iostream>
#include "tests.h"
#include "RepoFileTxt.h"
#include "User.h"
#include "Artist.h"
#include "Film.h"
#include "Performance.h"
#include "ServiceArtist.h"
#include "ServiceFilm.h"
#include "ServicePerformance.h"
#include "UI.h"

int main()
{
    tests();
	RepoFileTxt<User> repo_users("Users.txt");
	ServiceUser s_u(repo_users);

	RepoFileTxt<Artist> repo_artists("Artists.txt");
	ServiceArtist s_a(repo_artists);

	Film::service_artist = &s_a;
	RepoFileTxt<Film> repo_films("Films.txt");
	ServiceFilm s_f(repo_films);

	Performance::service_artist = &s_a;
	Performance::service_film = &s_f;
	RepoFileTxt<Performance> repo_performances("Performances.txt");
	ServicePerformance s_p(repo_performances);

	UI ui(s_a, s_f, s_p, s_u);
	ui.console();
    return 0;
}
