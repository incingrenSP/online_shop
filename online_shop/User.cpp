#include "User.hpp"

User::User(string p_username, string p_password)
	:username(p_username), password(p_password)
{}

User::~User()
{}

string User::getUsername() const
{
	return username;
}

bool User::loginCheck(const string passEntered)
{
	return (passEntered == password);
}

void User::addToCart(Product product)
{
	cart.addToCart(product);
}

void User::removeFromCart(string productName)
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