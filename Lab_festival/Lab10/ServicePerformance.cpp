#include "ServicePerformance.h"

ServicePerformance::ServicePerformance(IRepo<Performance>& r) :repo_performances(r) {};

ServicePerformance::ServicePerformance(const ServicePerformance& s) :repo_performances(s.repo_performances) {};

ServicePerformance::~ServicePerformance(){}

void ServicePerformance::add_performance(int id, const Performance& p) {
	this->v.validate_performance(p);
	this->repo_performances.add_elem(id, p);
}

void ServicePerformance::update_performance(int id, const Performance& p) {
	this->v.validate_performance(p);
	this->repo_performances.update_elem(id, p);
}

Performance& ServicePerformance::delete_performance(int id) {
	Performance a = this->repo_performances.find_elem(id);
	this->repo_performances.delete_elem(id);
	return a;
}

Performance& ServicePerformance::find_performance(int id) {
	return this->repo_performances.find_elem(id);
}

int ServicePerformance::get_size() {
	return this->repo_performances.get_size();
}

vector<Performance> ServicePerformance::get_all_performances() {
	return this->repo_performances.get_all();
}

vector<Performance> ServicePerformance::get_performance_by_date(string date) {
	vector<Performance> v;
	for (Performance p : this->repo_performances.get_all())
		if (p.get_date() == date)
			v.push_back(p);
	return v;
}
