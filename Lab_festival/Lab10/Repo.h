#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include "ExceptiiRepo.h"
#include "IRepo.h"
using namespace std;

template<typename Telem>
class Repo : public IRepo<Telem>{
protected:
	map<int, Telem> elemente;
public:
	Repo();
	~Repo();
	virtual void add_elem(int key, const Telem&) override;
	virtual Telem& find_elem(int key) override;
	virtual void update_elem(int key, const Telem&) override;
	virtual Telem delete_elem(int key) override;
	virtual vector<Telem> get_all() override;
	virtual int get_size() override;
};

template<typename Telem>
Repo<Telem>::Repo(){
	//constructor implicit
}

template<typename Telem>
Repo<Telem>::~Repo() {
	//destructor
}

template<typename Telem>
void Repo<Telem>::add_elem(int key, const Telem& elem) {
	auto it = this->elemente.find(key);
	if (it != this->elemente.end())
		throw ExceptiiRepo("repo::add: replicated key");
	this->elemente.insert({ key, elem });
}

template<typename Telem>
Telem& Repo<Telem>::find_elem(int key) {
	auto it = this->elemente.find(key);
	if (it == this->elemente.end())
		throw ExceptiiRepo("repo::find: unknown key");
	return it->second;
}

template<typename Telem>
void Repo<Telem>::update_elem(int key, const Telem& elem) {
	auto it = this->elemente.find(key);
	if (it == this->elemente.end())
		throw ExceptiiRepo("repo::update: unknown key");
	it->second = elem;
}

template<typename Telem>
Telem Repo<Telem>::delete_elem(int key) {
	auto it = this->elemente.find(key);
	if (it == this->elemente.end())
		throw ExceptiiRepo("repo::delete: unknown key");
	Telem e = it->second;
	this->elemente.erase(key);	
	return e;
}

template<typename Telem>
vector<Telem> Repo<Telem>::get_all() {
	vector<Telem> v;
	auto it = this->elemente.begin();
	while (it != this->elemente.end()) {
		v.push_back(it->second);
		it++;
	}
	return v;
}

template<typename Telem>
int Repo<Telem>::get_size() {
	return this->elemente.size();
}