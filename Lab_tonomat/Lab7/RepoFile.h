#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <string>
#include <assert.h>
#include "ExceptiiRepo.h"
#include "RepoAbstract.h"
#include "Repo.h"
using std::vector;
using std::unordered_map;
using std::string;
using std::ifstream;
using std::ofstream;

template<typename Telem> class RepoFile : public Repo<Telem> {
private:
	string file_name;
	void load_from_file();
	void save_to_file();
public:
	RepoFile(string _file_name) :file_name{ _file_name }, Repo<Telem>() {};
	~RepoFile() {};
	virtual void add_elem(int, const Telem&) override;
	virtual Telem& find_elem(int) override;
	virtual vector<Telem> get_all() override;
	virtual int get_size() override;
	virtual void update_elem(int, const Telem&) override;
	virtual Telem delete_elem(int) override;
};

template <typename Telem>
void RepoFile<Telem>::load_from_file() {
	//citeste din fisier
	this->elemente.clear();
	ifstream f(this->file_name);
	assert(f);
	Telem e;
	while (!f.eof()) {
		f >> e;
		this->elemente.insert({ e.get_cod(), e });
	}
	f.close();
}

template <typename Telem>
void RepoFile<Telem>::save_to_file() {
	//scrie in fisier
	ofstream f(this->file_name);
	vector<Telem> v = Repo<Telem>::get_all();
	for (int i = 0; i < v.size(); i++)
		//f << v[i];
		f << v[i].get_cod() << " " << v[i].get_nume() << " " << v[i].get_pret() <<std::endl;
	f.close();
}

template <typename Telem>
void RepoFile<Telem>::add_elem(int cod, const Telem& e) {
	this->load_from_file();
	Repo<Telem>::add_elem(cod, e);
	this->save_to_file();
}

template <typename Telem>
Telem& RepoFile<Telem>::find_elem(int cod) {
	this->load_from_file();
	return Repo<Telem>::find_elem(cod);
}

template <typename Telem>
vector <Telem> RepoFile<Telem>::get_all() {
	this->load_from_file();
	return Repo<Telem>::get_all();
}

template <typename Telem>
int RepoFile<Telem>::get_size() {
	this->load_from_file();
	return Repo<Telem>::get_size();
}

template <typename Telem>
void RepoFile<Telem>::update_elem(int cod, const Telem& e) {
	this->load_from_file();
	Repo<Telem>::update_elem(cod, e);
	this->save_to_file();
}

template <typename Telem>
Telem RepoFile<Telem>::delete_elem(int cod) {
	this->load_from_file();
	Telem e = Repo<Telem>::delete_elem(cod);
	this->save_to_file();
	return e;
}