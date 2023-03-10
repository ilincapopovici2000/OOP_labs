#include "UI.h"
#include "ExceptiiRepo.h"


UI::UI(const ServiceArtist& s_artist, const ServiceFilm& s_film,
	const ServicePerformance& s_performance, const ServiceUser& s_user)
	: service_artist(s_artist), service_film(s_film),
	service_performance(s_performance), service_user(s_user) {
	user = NULL;
};

UI::UI(const UI& ui)
	: service_artist(ui.service_artist), service_film(ui.service_film),
	service_performance(ui.service_performance), service_user(ui.service_user) {
	user = ui.user;
};

UI::~UI() {};

bool UI::login_user()
{	
	cout << "-Login-" << endl;
	int id;
	string password;
	cout << "Id: ";
	cin >> id;
	cout << "Password: ";
	cin >> password;
	//service_user.register_user(id, password);
	user = service_user.login(id, password);
	return user != NULL;
}

void UI::logout_user()
{
	service_user.logout(user);
	user = NULL;
}

void UI::show_artists() {
	for (Artist& a : service_artist.get_all_artists())
		a.write_txt(cout);
}

void UI::show_films() {
	for (Film& f : service_film.get_all_films())
		f.write_txt(cout);
}

void UI::show_performances() {
	for (Performance& p : service_performance.get_all_performances())
		p.write_txt(cout);
}

void UI::add_artist() {
	Artist a;
	cout << "Dati artistul: ";
	cin >> a;
	try {
		this->service_artist.add_artist(a.get_id(), a);
		cout << "Artistul a fost adaugat." << endl;
	}
	catch (ExceptiiRepo ex) {
		cout << "Eroare: " << ex.get_msg() << endl;
	}
}

void UI::add_film() {
	Film f;
	cout << "Dati filmul: ";
	cin >> f;
	try {
		this->service_film.add_film(f.get_id(), f);
		cout << "Filmul a fost adaugat." << endl;
	}
	catch (ExceptiiRepo ex) {
		cout << "Eroare: " << ex.get_msg() << endl;
	}
}

void UI::add_performance() {
	Performance p;
	cout << "Dati spectacolul: ";
	cin >> p;
	try {
		this->service_performance.add_performance(p.get_id(), p);
		cout << "Spectacolul a fost adaugat." << endl;
	}
	catch (ExceptiiRepo ex) {
		cout << "Eroare: " << ex.get_msg() << endl;
	}
}

void UI::delete_artist() {
	int id;
	cout << "Dati id-ul artistului: ";
	cin >> id;
	try {
		this->service_artist.delete_artist(id);
		cout << "Artistul cu id-ul dat a fost sters." << endl;
	}
	catch (ExceptiiRepo ex) {
		cout << "Eroare: " << ex.get_msg() << endl;
	}
}

void UI::delete_film() {
	int id;
	cout << "Dati id-ul filmului: ";
	cin >> id;
	try {
		this->service_film.delete_film(id);
		cout << "Filmul cu id-ul dat a fost sters." << endl;
	}
	catch (ExceptiiRepo ex) {
		cout << "Eroare: " << ex.get_msg() << endl;
	}
}

void UI::delete_performance() {
	int id;
	cout << "Dati id-ul spectacolului: ";
	cin >> id;
	try {
		this->service_performance.delete_performance(id);
		cout << "Spectacolul cu id-ul dat a fost sters." << endl;
	}
	catch (ExceptiiRepo ex) {
		cout << "Eroare: " << ex.get_msg() << endl;
	}
}

void UI::update_artist() {
	Artist a;
	int id;
	cout << "Dati id-ul artistului: ";
	cin >> id;
	cout << "Dati artistul nou: ";
	cin >> a;
	try {
		this->service_artist.update_artist(id, a);
	}
	catch (ExceptiiRepo ex) {
		cout << "Eroare: " << ex.get_msg() << endl;
	}
}

void UI::update_film() {
	Film f;
	int id;
	cout << "Dati id-ul filmului: ";
	cin >> id;
	cout << "Dati filmul nou: ";
	cin >> f;
	try {
		this->service_film.update_film(id, f);
	}
	catch (ExceptiiRepo ex) {
		cout << "Eroare: " << ex.get_msg() << endl;
	}
}

void UI::update_performance() {
	Performance p;
	int id;
	cout << "Dati id-ul spectacolului: ";
	cin >> id;
	cout << "Dati spectacolul nou: ";
	cin >> p;
	try {
		this->service_performance.update_performance(id, p);
	}
	catch (ExceptiiRepo ex) {
		cout << "Eroare: " << ex.get_msg() << endl;
	}
}

void UI::find_performance_by_date() {
	string date;
	cout << "Dati data: ";
	cin >> date;
	vector<Performance> v = this->service_performance.get_performance_by_date(date);
	for (Performance p : v)
		cout << p;
}

void UI::buy_tickets() {
	int id_spectacol;
	cout << "Dati id-ul spectacolului: ";
	cin >> id_spectacol;
	int nr;
	string name;
	cout << "Dati numele: ";
	cin >> name;
	cout << "Dati numarul de locuri: ";
	cin >> nr;
	try {
		Performance p = this->service_performance.find_performance(id_spectacol);
		p.ocupa_locuri(nr);
		this->service_performance.update_performance(id_spectacol, p);
	}
	catch (ExceptiiRepo ex) {
		cout << "Eroare: " << ex.get_msg();
	}
}

void UI::show_menu() {
	cout << "1. Afisarea artistilor" << endl;
	cout << "2. Afisarea filmelor" << endl;
	cout << "3. Afisarea spectacolelor" << endl;
	cout << "4. Adaugarea unui artist" << endl;
	cout << "5. Adaugarea unui film" << endl;
	cout << "6. Adaugarea unui spectacol" << endl;
	cout << "7. Stergerea unui artist" << endl;
	cout << "8. Stergerea unui film" << endl;
	cout << "9. Stergerea unui spectacol" << endl;
	cout << "10. Modificarea unui artist" << endl;
	cout << "11. Modificarea unui film" << endl;
	cout << "12. Modificarea unui spectacol" << endl;
	cout << "13. Cautare spectacol intr-o anumita zi" << endl;
	cout << "14. Cumparare bilete" << endl;
	cout << "0. Logout " << endl;
}

void UI::console()
{
	while(true) {
		if (login_user()) {
			cout <<"\x1B[31mWelcome "<< user->get_user_id()<<"!\033[0m"<< endl;
			show_menu();
			int op;
			cout << "Dati optiunea: " << endl;
			cin >> op;
			while (true) {

				if (op == 1)
					show_artists();

				if (op == 2)
					show_films();

				if (op == 3)
					show_performances();

				if (op == 4)
					add_artist();

				if (op == 5)
					add_film();

				if (op == 6)
					add_performance();

				if (op == 7)
					delete_artist();

				if (op == 8)
					delete_film();

				if (op == 9)
					delete_performance();

				if (op == 10)
					update_artist();

				if (op == 11)
					update_film();

				if (op == 12)
					update_performance();

				if (op == 13)
					find_performance_by_date();

				if (op == 14)
					buy_tickets();

				if (op == 0)
				{	
					cout << "Bye " << user->get_user_id() << endl;
					logout_user();
					break;
				}

				cout << "Dati urmatoarea optiune: ";
				cin >> op;
			}
		}
	}
}