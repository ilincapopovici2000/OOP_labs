#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <string>
#include "ExceptiiRepo.h"
#include "RepoAbstract.h"
using std::vector;
using std::unordered_map;
using std::string;
using std::ifstream;
using std::ofstream;


template<typename Telem> class Repo: public RepoAbstract<Telem> {
protected:
	unordered_map<int, Telem> elemente;
public:
	Repo();
	~Repo();
	//C
	virtual void add_elem(int, const Telem&) override;
	//R
	virtual Telem& find_elem(int) override;
	virtual vector<Telem> get_all() override;
	virtual int get_size() override;
	//U
	virtual void update_elem(int, const Telem&) override;
	//D
	virtual Telem delete_elem(int) override;
};


template <typename Telem>
Repo<Telem>::Repo() {
	//constructor implicit
}

template<typename Telem>
Repo<Telem>::~Repo() {
	//Destructor
}

template<typename Telem>
void Repo<Telem>::add_elem(int cheie, const Telem& elem) {
	//Adauga un element in dictionar
	auto it = this->elemente.find(cheie);
	if (it != this->elemente.end())
		throw ExceptiiRepo("Nu exista elementul cu cheia data\n");
	this->elemente.insert({ cheie, elem });
}

template<typename Telem>
Telem& Repo<Telem>::find_elem(int cheie) {
	auto it = this->elemente.find(cheie);
	if (it == this->elemente.end())
		throw ExceptiiRepo("Nu exista elementul cu cheia data\n");
	return it->second;
}

template<typename Telem>
vector<Telem> Repo<Telem>::get_all() {
	vector<Telem> v;
	std::for_each(
		this->elemente.begin(),
		this->elemente.end(),
		[&v](const auto& elemente)
		{
			v.push_back(elemente.second);
		}
	);
	return v;
}

template<typename Telem>
int Repo<Telem>::get_size() {
	//Acceseaza lungimea dictionarului
	return this->elemente.size();
}

template<typename Telem>
void Repo<Telem>::update_elem(int cheie, const Telem& elem) {
	auto it = this->elemente.find(cheie);
	if (it == this->elemente.end())
		throw ExceptiiRepo("Nu exista elementul cu cheia data\n");
	it->second = elem;
}

template<typename Telem>
Telem Repo<Telem>::delete_elem(int cheie) {
	//Sterge un elem din dictionar
	auto it = this->elemente.find(cheie);
	if (it == this->elemente.end())
		throw ExceptiiRepo("Nu exista elementul cu cheia data\n");
	Telem e = it->second;
	this->elemente.erase(cheie);
	return e;
}


