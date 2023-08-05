#ifndef _USER_HPP_
#include "Product.hpp"
#include "Cart.hpp"

class User {
private:
	char* username;
	char* password;
	Cart cart;
public:
	User(char* username, char* password);
	~User();
	bool loginCheck(char* passEntered);
	void addToCart(Product product);
	void removeFromCart(char* productName);
	double checkout();
	void viewCart();
};
#endif // !_USER_HPP_
