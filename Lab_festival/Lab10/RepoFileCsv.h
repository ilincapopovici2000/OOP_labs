#pragma once
#include "RepoFile.h"
using namespace std;

template<typename Telem>
class RepoFileCsv : public RepoFile<Telem> {
private:
	virtual bool read_elem(Telem&, istream&) override;
	virtual void write_elem(const Telem&, ostream&) override;
public:
	RepoFileCsv(string _file_name) :RepoFile(_file_name) {};
	~RepoFileCsv() {};
};

template<typename Telem>
bool RepoFileCsv<Telem>::read_elem(Telem& e, istream& f) {
	return e.read_csv(f);
}

template<typename Telem>
void RepoFileCsv<Telem>::write_elem(const Telem& e, ostream& f) {
	e.write_csv(f);
}