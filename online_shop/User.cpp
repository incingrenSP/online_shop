#include "User.hpp"

User::User(char* p_username, char* p_password)
	:username(nullptr), password(nullptr)
{
	username = new char[strlen(p_username) + 1];
	strcpy(username, p_username);
	password = new char[strlen(p_password) + 1];
	strcpy(password, p_password);
}

User::~User()
{
	delete[] username;
	delete[] password;
}

char* User::getUsername() const
{
	return username;
}

bool User::loginCheck(const char* passEntered)
{
	return strcmp(passEntered, password);
}

void User::addToCart(Product product)
{
	cart.addToCart(product);
}

void User::removeFromCart(char* productName)
{
	cart.removeFromCart(productName);
}

double User::checkout()
{
	return cart.getTotal();
}

void User::viewCart()
{
	cart.displayCart();
}