#include "Artist.h"
#include "Utils.h"
#include <string>
using namespace std;

Artist::Artist() : Performer(){

}

Artist::Artist(int id, const string &name) : Performer(id, name) {

}

Artist::Artist(const Artist& a) : Performer(a) {

}

Artist::~Artist() {

}
