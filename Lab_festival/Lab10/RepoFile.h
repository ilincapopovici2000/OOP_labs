#pragma once
#include "Repo.h"
#include <fstream>
#include <iostream>
using namespace std;

template<typename Telem>
class RepoFile : public Repo<Telem>{
protected:
	string file_name;
	void read_from_file();
	void save_to_file();
	virtual bool read_elem(Telem&, istream&) = 0;
	virtual void write_elem(const Telem&, ostream&) = 0;
public:
	RepoFile(string _file_name) :file_name(_file_name) {};
	~RepoFile() {};
	virtual void add_elem(int key, const Telem&) override;
	virtual Telem& find_elem(int key) override;
	virtual void update_elem(int key, const Telem&) override;
	virtual Telem delete_elem(int key) override;
	virtual vector<Telem> get_all() override;
	virtual int get_size()override;
};

template<typename Telem>
void RepoFile<Telem>::read_from_file() {
	this->elemente.clear();
	ifstream f(this->file_name);
	//assert(f);
	Telem e;
	while (!f.eof()) {
		if(read_elem(e, f))
			this->elemente.insert({ e.get_key(), e });
	}
	f.close();
}

template<typename Telem>
void RepoFile<Telem>::save_to_file() {
	ofstream f(this->file_name);
	vector<Telem> v = Repo<Telem>::get_all();
	for (int i = 0; i < v.size(); i++)
		write_elem(v[i],f);
	f.close();
}

template<typename Telem>
void RepoFile<Telem>::add_elem(int key, const Telem& e){
	read_from_file();
	Repo<Telem>::add_elem(key,e);
	save_to_file();
}

template<typename Telem>
Telem& RepoFile<Telem>::find_elem(int key) {
	read_from_file();
	return Repo<Telem>::find_elem(key);
}

template<typename Telem>
void RepoFile<Telem>::update_elem(int key, const Telem& e) {
	read_from_file();
	Repo<Telem>::update_elem(key, e);
	save_to_file();
}

template<typename Telem>
Telem RepoFile<Telem>::delete_elem(int key) {
	read_from_file();
	Telem e = Repo<Telem>::delete_elem(key);
	save_to_file();
	return e;
}

template<typename Telem>
vector<Telem> RepoFile<Telem>::get_all() {
	read_from_file();
	return Repo<Telem>::get_all();
}


template<typename Telem>
int RepoFile<Telem>::get_size() {
	read_from_file();
	return Repo<Telem>::get_size();
}