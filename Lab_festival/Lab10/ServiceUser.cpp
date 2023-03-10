#include "ServiceUser.h"
#include "ExceptiiRepo.h"

ServiceUser::ServiceUser(IRepo<User>& r) : repo_users(r) {};

ServiceUser::ServiceUser(const ServiceUser& s) : repo_users(s.repo_users) {};

ServiceUser::~ServiceUser() {};

void ServiceUser::register_user(int id, string pass) {
	User u(id, pass);
	this->repo_users.add_elem(id, u);
}

User* ServiceUser::login(int id, string pass) {
	User u(id, pass);
	try {
		User* u = &(this->repo_users.find_elem(id));
		if (u->get_password() == pass)
			return u;
	}
	catch (const ExceptiiRepo & ex) {
		return NULL;
	}
}

void ServiceUser::logout(User* u) {

}

int ServiceUser::get_size() {
	return this->get_size();
}