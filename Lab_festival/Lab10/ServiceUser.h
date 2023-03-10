#pragma once
#include "IRepo.h"
#include "User.h"

class ServiceUser {
private:
	IRepo<User>& repo_users;
public:
	ServiceUser(IRepo<User>& repo_users);
	ServiceUser(const ServiceUser&);
	~ServiceUser();
	User* login(int, string);
	void logout(User*);
	void register_user(int, string);
	int get_size();
};