#pragma once

#include "Product.hpp"
#include "Cart.hpp"
#include "User.hpp"

class ShopSystem {
private:
	vector<User> users;
	vector<Product> products;
public:
	void addUser(char*, char*);
	void addProduct(char*, double, int);
	User* findUser(const char*, const char*);
	Product* findProduct(char*);
};

