#include "Film.h"
#include "Utils.h"
#include "ServiceArtist.h"
#include <string>
using namespace std;

ServiceArtist* Film::service_artist = NULL; 

Film::Film() : Performer() {

}

Film::Film(int id, string name) : Performer(id, name) {

}

Film::Film(const Film& f) : Performer(f) {
	for (Artist* a : f.actors)
		this->actors.push_back(a);
}

Film::~Film() {

}

void Film::add_actor( Artist* a) {
	this->actors.push_back(a);
}

vector<Artist*> Film::get_actors() const {
	return this->actors;
}

Film& Film::operator=(const Film& f) {
	this->id = f.id;
	this->name = f.name;
	this->actors.clear();
	for (Artist* a : f.actors)
		this->actors.push_back(a);
	return *this;
}

bool Film::read_txt(istream& is) {
	string line;
	getline(is, line);
	vector<string> elems = splitLine(line, ' ');
	if (elems.size() < 2)
		return false;
	this->id = atoi(elems[0].c_str());
	this->name = elems[1];
	this->actors.clear();
	for (int i = 2; i < elems.size(); i++) {
		Artist* a = new Artist(service_artist->find_artist(atoi(elems[i].c_str())));
		this->actors.push_back(a);
	}
	return true;
}

void Film::write_txt(ostream& os) const {
	os << this->id << " " << this->name;
	for (Artist* a : actors)
		os << " " << a->get_id();
	os << endl;
}

bool Film::read_csv(istream& is) {
	string line;
	getline(is, line);
	vector<string> elems = splitLine(line, ',');
	if (elems.size() < 2)
		return false;
	this->id = atoi(elems[0].c_str());
	this->name = elems[1];
	this->actors.clear();
	for (int i = 2; i < elems.size(); i++) {
		Artist* a = new Artist(service_artist->find_artist(atoi(elems[i].c_str())));
		this->actors.push_back(a);
	}
	return true;
}

void Film::write_csv(ostream& os) const {
	os << this->id << "," << this->name;
	for (Artist* a : actors)
		os << "," << a->get_id();
	os << endl;
}

void Film::write_full(ostream& os) const {
	os << "[" << id << " " << name << " ";
	for (Artist* a : get_actors())
		os << *a;
	os << "]";
}
/*
istream& operator>>(istream& is, Performer& p) {
	int id;
	string name;
	cout << "Dati id-ul: ";
	is >> id;
	p.set_id(id);
	cout << "Dati numele: ";
	is >> name;
	p.set_name(name);
	return is;
}*/