#include "ShopSystem.hpp"

void ShopSystem::addUser(char* username, char* password)
{
	User newUser(username, password);
	users.push_back(newUser);
}

void ShopSystem::addProduct(char* name, double price, double quantity)
{
	Product newProduct(name, price, quantity);
	products.push_back(newProduct);
}

User* ShopSystem::findUser(const char* username, const char* password)
{
	User* findU{ nullptr };
	for (User& user : users) {
		if (!strcmp(user.getUsername(), username)) {
			findU = &user;
			if (user.loginCheck(password)) {
				return findU;
			}
			else {
				findU = nullptr;
			}
		}
	}
	return findU;
}

Product* ShopSystem::findProduct(char* productName)
{
	Product* findProd{ nullptr };
	for (Product& product : products) {
		if (!strcmpi(product.getName(), productName)) {
			findProd = &product;
			return findProd;
		}
	}
	return findProd;
}