#pragma once

#include "Product.hpp"
#include "Cart.hpp"

class User {
private:
	char* username;
	char* password;
	Cart cart;
public:
	User(char*, char*);
	~User();
	char* getUsername() const;
	bool loginCheck(const char*);
	void addToCart(Product);
	void removeFromCart(char*);
	double checkout();
	void viewCart();
};

