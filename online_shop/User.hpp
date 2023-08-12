
#ifndef _USER_HPP_
#define _USER_HPP_

#include "Product.hpp"
#include "Cart.hpp"
#include <fstream>

class User {
private:
	string username;
	string password;
	Cart cart;
public:
	User(string, string);
	~User();
	string getUsername() const;
	bool loginCheck(const string);
	void addToCart(Product);
	void removeFromCart(string);
	double checkout();
	void viewCart();
};

