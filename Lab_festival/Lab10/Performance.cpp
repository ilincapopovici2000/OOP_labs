#include "Performance.h"
#include "ExceptionsPerformance.h"
#include "Utils.h"
#include "Artist.h"
#include <string>
using namespace std;

ServiceArtist* Performance::service_artist = NULL;
ServiceFilm* Performance::service_film = NULL;

Performance::Performance() {
	this->performer = NULL;
};

Performance::Performance(int _id, Performer* _performer, string _date, string _loc, 
	int _nr_loc_available, int _nr_loc_sold) : id(_id), performer(_performer), date(_date), loc(_loc),
	nr_loc_available(_nr_loc_available), nr_loc_sold(_nr_loc_sold) {}

Performance::Performance(const Performance& p) : id(p.id), performer(p.performer), date(p.date), loc(p.loc),
nr_loc_available(p.nr_loc_available), nr_loc_sold(p.nr_loc_sold) {}

Performance::~Performance() {

}

int Performance::get_id() const{
	return  this->id;
}

Performer* Performance::get_performer() const{
	return  this->performer;
}

string Performance::get_date() const{
	return this->date;
}

string Performance::get_loc() const{
	return this->loc;
}

int Performance::get_nr_loc_available() const{
	return this->nr_loc_available;
}

int Performance::get_nr_loc_sold() const{
	return this->nr_loc_sold;
}

void Performance::set_id(int id) {
	this->id = id;
}

void Performance::set_performer(Performer* p){
	this->performer = p;
}

void Performance::set_date(string date) {
	this->date = date;
}

void Performance::set_loc(string loc) {
	this->loc = loc;
}

void Performance::set_nr_loc_available(int nr) {
	this->nr_loc_available = nr;
}

void Performance::set_nr_loc_sold(int nr) {
	this->nr_loc_sold= nr;
}

void Performance::ocupa_locuri(int nr) {
	if (this->nr_loc_available < nr)
		throw PerformanceException("sold out!");
	this->nr_loc_sold += nr;
	this->nr_loc_available -= nr;
}

bool Performance::operator==(const Performance& p) {
	return (this->id == p.id && this->performer->get_id() == p.performer->get_id() &&
		this->date == p.date && this->loc == p.loc
		&& this->nr_loc_available == p.nr_loc_available && this->nr_loc_sold == p.nr_loc_sold);
}

Performance& Performance::operator=(const Performance& p) {
	this->id = p.id;
	this->performer = p.performer;
	this->date = p.date;
	this->loc = p.loc;
	this->nr_loc_available = p.nr_loc_available;
	this->nr_loc_sold = p.nr_loc_sold;
	return *this;
}

bool Performance::read_txt(istream& is) {
	/*
	int id_performer;
	is >> this->id >> id_performer >> this->date >> this->loc >> this->nr_loc_available >>this->nr_loc_sold;
	cout << " id_performer " << id_performer << endl;
	if (id_performer < 100)
		this->performer = new Artist(service_artist->find_artist(id_performer));
	else
		this->performer = new Film(service_film->find_film(id_performer));
	//cout << "performer" << *performer<<endl;
	*/
	string line;
	getline(is, line);
	vector<string> elems = splitLine(line, ' ');
	if (elems.size() != 6)
		return false;
	this->id = atoi(elems[0].c_str());
	int id_performer = atoi(elems[1].c_str());
	if (id_performer < 100)
		this->performer = new Artist(service_artist->find_artist(id_performer));
	else
		this->performer = new Film(service_film->find_film(id_performer));
	this->date = elems[2];
	this->loc = elems[3];
	this->nr_loc_available = atoi(elems[4].c_str());
	this->nr_loc_sold = atoi(elems[5].c_str());
	return true;
}

void Performance::write_txt(ostream& os) const {
	os << this->id << " " << this->performer->get_id() <<" " << this->date << " " << this->loc << " " 
		<< this->nr_loc_available << " " << this->nr_loc_sold << endl;
	//cout << "performer" << *performer<<endl;
}

bool Performance::read_csv(istream& is) {
	string line;
	getline(is, line);
	vector<string> elems = splitLine(line, ',');
	if (elems.size() != 6)
		return false;
	this->id = atoi(elems[0].c_str());
	int id_performer = atoi(elems[1].c_str());
	if (id_performer < 100)
		this->performer = new Artist(service_artist->find_artist(id_performer));
	else 
		this->performer = new Film(service_film->find_film(id_performer));
	this->date = elems[2];
	this->loc = elems[3];
	this->nr_loc_available = atoi(elems[4].c_str());
	this->nr_loc_sold = atoi(elems[5].c_str());
	return true;
}

void Performance::write_csv(ostream& os) const {
	os << this->id << "," << this->performer->get_id() << "," << this->date << "," << this->loc << "," 
		<< this->nr_loc_available << "," << this->nr_loc_sold << endl;
}

int Performance::get_key() const {
	return this->id;
}

ostream& operator<<(ostream& os, const Performance& p) {
	if (p.get_nr_loc_available() == 0)
		os << "\x1B[31m";
	os << p.id << " " << *p.get_performer() << " " << p.date << " ";
	os << p.loc << " " << p.nr_loc_available << " " << p.nr_loc_sold;
	if (p.get_nr_loc_available() == 0)
		os << "\033[0m";
	os << endl;
	return os;
}

istream& operator>>(istream& is, Performance& p) {
	int id;
	int id_performer;
	string date;
	string loc;
	int nr_loc_available;
	int nr_loc_sold;
	cout << "Dati id-ul: ";
	is >> id;
	p.set_id(id);
	cout << "Dati id artistul/filmul: ";
	is >> id_performer;
	if (id_performer < 100)
		p.set_performer(&(Performance::service_artist->find_artist(id_performer)));
	else
		p.set_performer(&(Performance::service_film->find_film(id_performer)));
	cout << "Dati data: ";
	is >> date;
	p.set_date(date);
	cout << "Dati loc: ";
	is >> loc;
	p.set_loc(loc);
	cout << "Dati nr locuri disponibile: ";
	is >> nr_loc_available;
	p.set_nr_loc_available(nr_loc_available);
	cout << "Dati nr locuri vandute: ";
	is >> nr_loc_sold;
	p.set_nr_loc_sold(nr_loc_sold);

	return is;
}