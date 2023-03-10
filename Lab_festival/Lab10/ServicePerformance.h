#pragma once
#include "IRepo.h"
#include "Performance.h"
#include "ValidatorPerformance.h"
#include<vector>
using namespace std;

class ServicePerformance {
private:
	IRepo<Performance>& repo_performances;
	ValidatorPerformance v;
public:
	ServicePerformance(IRepo<Performance>& repo_performances);
	ServicePerformance(const ServicePerformance& s);
	~ServicePerformance();
	void add_performance(int, const Performance& a);
	void update_performance(int, const Performance& a);
	Performance& delete_performance(int);
	Performance& find_performance(int);
	int get_size();
	vector<Performance> get_all_performances();
	vector<Performance> get_performance_by_date(string date);
};