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

User* ShopSystem::findUser(char* username, char* password)
{
	/*
	* searches through the vector users
	* returns a pointer to the user if found
	* else returns nullptr
	*/
}

Product* ShopSystem::findProduct(char* productName)
{
	/*
	* searches through the vector products
	* returns a pointer to the product if found
	* else returns nullptr
	*/
}