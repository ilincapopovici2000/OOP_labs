#pragma once
#include <iostream>
using namespace std;
#include <vector>

template<typename Telem>
class IRepo {
public:
	virtual void add_elem(int key,const Telem&) = 0;
	virtual Telem& find_elem(int key) = 0;
	virtual void update_elem(int key, const Telem&) = 0;
	virtual Telem delete_elem(int key) = 0;
	virtual vector<Telem> get_all() = 0;
	virtual int get_size() = 0;
};