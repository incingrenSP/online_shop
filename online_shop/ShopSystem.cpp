#include "ShopSystem.hpp"

void ShopSystem::addUser(string username, string password)
{
	User newUser(username, password);
	users.push_back(newUser);
}

void ShopSystem::addProduct(string name, double price, int quantity)

{
	Product newProduct(name, price, quantity);
	products.push_back(newProduct);
}

void ShopSystem::viewProducts()
{
	cout << setw(30) << left << "Product"
		<< setw(10) << "Price"
		<< setw(10) << "Quantity" << endl;
	cout << setfill('-') << setw(50) << "" << endl;
	cout << setfill(' ');
	for (Product& prod : products) {
		cout << setw(30) << left << prod.getName()
			<< setw(10) << prod.getPrice()
			<< setw(10) << prod.getQuantity() << endl;
	}
	cout << setfill('-') << setw(50) << "" << endl;
	cout << setfill(' ');
}

User* ShopSystem::findUser(const string username, const string password)
{
	User* findU{ nullptr };
	for (User& user : users) {
		if (user.getUsername() == username) {
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

Product* ShopSystem::findProduct(string productName)
{
	Product* findProd{ nullptr };
	for (Product& product : products) {
		if (product.getName() == productName) {

			findProd = &product;
			return findProd;
		}
	}
	return findProd;
}