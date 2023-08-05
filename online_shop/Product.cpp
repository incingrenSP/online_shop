#include "Product.hpp"

Product::Product(char* p_name, double p_price, int p_quantity)
	:name(nullptr), price(p_price), quantity(p_quantity)
{
	name = new char[strlen(p_name) + 1];
	strcpy(name, p_name);
}

Product::~Product()
{
	delete[] name;
}

char* Product::getName()
{
	return name;
}

double Product::getPrice()
{
	return price;
}

int Product::getQuantity()
{
	return quantity;
}