#pragma once
#include "Performance.h"

class ValidatorPerformance {
public:
	ValidatorPerformance();
	~ValidatorPerformance();
	void validate_performance(const Performance& p);
};