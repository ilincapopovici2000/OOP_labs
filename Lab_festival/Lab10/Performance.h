#pragma once
#include "Performer.h"
#include "ServiceArtist.h"
#include "ServiceFilm.h"

class Performance {
protected:
	int id;
	Performer* performer;
	string date;
	string loc;
	int nr_loc_available;
	int nr_loc_sold;
public: 
	static ServiceArtist* service_artist;
	static ServiceFilm* service_film;
public:
	Performance();
	Performance(int, Performer*, string, string, int, int);
	Performance(const Performance&);
	~Performance();
	int get_id() const;
	Performer* get_performer() const;
	string get_date() const;
	string get_loc() const;
	int get_nr_loc_available() const;
	int get_nr_loc_sold() const;
	void set_id(int);
	void set_performer(Performer*);
	void set_date(string date);
	void set_loc(string loc);
	void set_nr_loc_available(int nr);
	void set_nr_loc_sold(int nr);
	void ocupa_locuri(int nr);
	bool operator==(const Performance&);
	Performance& operator=(const Performance&);
	bool read_txt(istream& is);
	void write_txt(ostream& os) const;
	bool read_csv(istream& is);
	void write_csv(ostream& os) const;
	int get_key() const;
	friend ostream& operator<<(ostream& os, const Performance& p);
	friend istream& operator>>(istream& os, Performance& p);
};