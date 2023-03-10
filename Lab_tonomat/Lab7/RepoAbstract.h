#pragma once
#include<vector>
using std::vector;

template<typename Telem> class RepoAbstract {
public:
	virtual void add_elem(int, const Telem&) = 0;
	virtual Telem& find_elem(int) = 0;
	virtual vector<Telem> get_all() = 0;
	virtual int get_size() = 0;
	virtual void update_elem(int, const Telem&) = 0;
	virtual Telem delete_elem(int) = 0;
};