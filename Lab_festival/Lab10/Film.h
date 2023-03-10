#pragma once
#include "Artist.h"
#include "ServiceArtist.h"
#include <vector>

class Film : public Performer{
private:
	vector<Artist*> actors;
public:
	static ServiceArtist* service_artist;
public:
	Film();
	Film(int, string);
	Film(const Film&);
	~Film();
	void add_actor(Artist* a);
	vector<Artist*> get_actors() const;
	virtual bool read_txt(istream& is);
	virtual void write_txt(ostream& os) const;
	virtual bool read_csv(istream& is);
	virtual void write_csv(ostream& os) const;
	virtual void write_full(ostream& os) const;
	Film& operator=(const Film&);
	//friend istream& operator>>(istream& os, Film& f);
};