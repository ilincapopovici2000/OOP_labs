#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> splitLine(string line, char delim)
{

	stringstream ss(line);
	string item;
	vector<string> elems;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}