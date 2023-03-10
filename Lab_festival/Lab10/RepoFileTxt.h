#pragma once
#include "RepoFile.h"
using namespace std;

template<typename Telem>
class RepoFileTxt : public RepoFile<Telem> {
private:
	virtual bool read_elem(Telem&, istream&) override;
	virtual void write_elem(const Telem&, ostream&) override;
public:
	RepoFileTxt(string _file_name) :RepoFile<Telem>(_file_name) {};
	~RepoFileTxt() {};
};

template<typename Telem>
bool RepoFileTxt<Telem>::read_elem(Telem& e, istream& f) {
	return e.read_txt(f);
}

template<typename Telem>
void RepoFileTxt<Telem>::write_elem(const Telem& e, ostream& f) {
	e.write_txt(f);
}