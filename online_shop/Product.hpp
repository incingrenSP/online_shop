#pragma once

#include <iostream>
#include <cstring>
using namespace std;

class Product
{
private:
	char* name;
	double price;
	int quantity;
public:
	Product(char*, double, int);
	~Product();
	char* getName();
	double getPrice();
	int getQuantity();
};

