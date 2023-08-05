
#ifndef _SHOPSYS_HPP_
#include "Product.hpp"
#include "Cart.hpp"
#include "User.hpp"

class ShopSystem {
private:
	vector<User> users;
	vector<Product> products;
public:
	void addUser(char*, char*);
	void addProduct(char*, double, double);
	User* findUser(char*, char*);
	Product* findProduct(char*);
};
#endif // !_SHOPSYS_HPP_
