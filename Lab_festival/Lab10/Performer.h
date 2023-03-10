#pragma once
#include <iostream>
using namespace std;

class Performer {
protected:
	int id;
	string name;
public:
	Performer();
	Performer(int, string);
	Performer(const Performer&);
	virtual ~Performer();
	int get_id() const;
	string get_name() const;
	void set_id(int);
	void set_name(string);
	Performer& operator=(const Performer&);
	bool operator==(const Performer&);
	virtual bool read_txt(istream& is);
	virtual void write_txt(ostream& os) const;
	virtual bool read_csv(istream& is);
	virtual void write_csv(ostream& os) const;
	virtual void write_full(ostream& os) const;
	virtual int get_key() const;
	friend ostream& operator<<(ostream& os, const Performer& c);
	friend istream& operator>>(istream& os, Performer& c);

};