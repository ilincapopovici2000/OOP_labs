#pragma once
#include<iostream>
#include "Performer.h"
using namespace std;


class Artist : public Performer {
public:
	Artist();
	Artist(int id, const string& name);
	Artist(const Artist&);
	~Artist();
};