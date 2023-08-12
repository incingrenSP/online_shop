#include "ShopSystem.hpp"

#include <iostream>
#include <iomanip>
#include <fstream>

namespace Misc {
	void userIP(ShopSystem& shop)
	{
		string name{ " " };
		string password{ " " };
		fstream fuser{ "users.txt", ios::in };
		if (!fuser) {
			cerr << "Couldn't open file | Couldn't find file : users.txt" << endl;
			exit(1);
		}

		while (!fuser.eof()) {
			fuser >> name
				>> password;
			shop.addUser(name, password);
		}
		fuser.close();
	}

	void productIP(ShopSystem& shop)
	{
		string name{ " " };
		double price{ 0 };
		int quantity{ 0 };
		fstream fprod{ "products.txt", ios::in };
		if (!fprod) {
			cerr << "Couldn't open file | Couldn't find file : products.txt" << endl;
			exit(1);
		}

		while (!fprod.eof()) {
			fprod >> name
				>> price
				>> quantity;
			shop.addProduct(name, price, quantity);
		}
		fprod.close();
	}

	void printMiscs(int& choice)
	{
		cout << "1. Browse" << endl;
		cout << "2. View Cart" << endl;
		cout << "3. Billing" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;
	}

	void checkChoice(ShopSystem& shop, int choice) {
		switch (choice) {
		case 1:
			shop.viewProducts();
			break;
		case 2:

			break;
		default:
			exit(2);
		}
	}
};