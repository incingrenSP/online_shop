#ifndef _USER_HPP_
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
	char* getUsername();
	bool loginCheck(char*);
	void addToCart(Product);
	void removeFromCart(char*);
	double checkout();
	void viewCart();
};
#endif // !_USER_HPP_
