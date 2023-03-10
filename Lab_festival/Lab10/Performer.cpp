#include "Performer.h"
#include "Utils.h"
#include <string>

Performer::Performer() {
	this->id = -1;
	this->name = "";
}

Performer::Performer(int id, string name) {
	this->id = id;
	this->name = name;
}

Performer::Performer(const Performer& p) {
	this->id = p.id;
	this->name = p.name;
}

Performer::~Performer() {

}

int Performer::get_id() const {
	return this->id;
}

string Performer::get_name() const {
	return this->name;
}

void Performer::set_id(int id) {
	this->id = id;
}


void Performer::set_name(string name) {
	this->name = name;
}

Performer& Performer::operator=(const Performer& p) {
	this->id = p.id;
	this->name = p.name;
	return *this;
}

bool Performer::operator==(const Performer& p) {
	return (this->id == p.id && this->name == p.name);
}

bool Performer::read_txt(istream& is) {
	is >> this->id >> this->name;
	return is.fail() ? false : true;
}

void Performer::write_txt(ostream& os) const {
	os << this->id << " " << this->name << endl;
}

bool Performer::read_csv(istream& is) {
	string line;
	getline(is, line);
	vector<string> elems = splitLine(line, ',');
	if (elems.size() != 2)
		return false;
	this->id = atoi(elems[0].c_str());
	this->name = elems[1];
	return true;
}

void Performer::write_csv(ostream& os) const {
	os << this->id << "," << this->name << endl;
}

void Performer::write_full(ostream& os) const {
	os << "[" << id << " " << name << "]";
}

int Performer::get_key() const {
	return this->id;
}

ostream& operator<<(ostream& os, const Performer& p){
	p.write_full(os);
	return os;
}

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
}