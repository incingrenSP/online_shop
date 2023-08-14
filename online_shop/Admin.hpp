#include <fstream>
#include <iostream>
#include <string>

#include "ShopSystem.hpp"

//ADMIN PRIVILEGES

namespace Admin {
	bool checkLogin(User* current, string password) 
	{
		if (current->getUsername() == "Admin" && current->loginCheck(password))
			return true;
		return false;
	}

	void printMiscs(int& choice)
	{
		cout << "1. Add Products" << endl;
		cout << "2. Add Users" << endl;
		cout << "3. Remove Products" << endl;
		cout << "4. Remove Users" << endl;
		cout << "5. View Products" << endl;
		cout << "6. View Users" << endl;
		cout << "7. Logout" << endl;
		cout << "8. Exit" << endl;
		cin >> choice;
	}

	void addProducts(ShopSystem& shop)
	{
		fstream fprod("products.txt", ios::app | ios::ate);
		if (!fprod) {
			cerr << "Couldn't open file | File doesn't exist" << endl;
			exit(1);
		}
		shop.viewProducts();
		string name;
		double price{};
		int num{};
		cout << "Enter product name: ";
		cin.ignore(100, '\n') >> name;
		cout << "Enter price: ";
		cin >> price;
		cout << "Enter quantity: ";
		cin >> num;
		fprod << endl
			<< name << '\t'
			<< price << '\t'
			<< num;
		fprod.close();
		shop.addProduct(name, price, num);
	}

	void addUsers(ShopSystem& shop)
	{
		fstream fuser("users.txt", ios::app | ios::ate);
		if (!fuser) {
			cerr << "Couldn't open file | File doesn't exist" << endl;
			exit(1);
		}
		string name;
		string pass;
		cout << "Enter Username: ";
		cin.ignore(100, '\n') >> name;
		cout << "Enter Password: ";
		cin.ignore(100, '\n') >> pass;
		fuser << endl
			<< name << '\t'
			<< pass;
		fuser.close();
		shop.addUser(name, pass);
	}

	void removeProducts(ShopSystem& shop)
	{
		fstream fprod("products.txt", ios::in | ios::binary);
		if (!fprod) {
			cerr << "Couldn't open file | File doesn't exist" << endl;
			exit(1);
		}
		fstream ftmp("temp.txt", ios::out | ios::binary);
		if (!ftmp) {
			cerr << "Error creating temporary file" << endl;
			exit(1);
		}
		string name;
		string temp;
		string temp2;
		string pass;
		cout << "Enter product to remove: ";
		cin >> name;
		cout << "Confirm password[ADMIN]: ";
		cin >> pass;
		if (!shop.findUser("Admin", pass)) {
			cerr << "Wrong password\nPlease try again" << endl;
			fprod.close();
			ftmp.close();
			return;
		}
		else {
			if (!shop.findProduct(name)) {
				cerr << "Couldn't find product" << endl;
				fprod.close();
				ftmp.close();
				return;
			}
			else {
				shop.removeProduct(name);
				while (getline(fprod, temp)) {
					cout << temp;
					fprod >> temp2;

				}
				fprod.close();
				ftmp.close();
				remove("products.txt");
				rename("temp.txt", "products.txt");
			}
		}
	}

	void removeUsers(ShopSystem& shop)
	{
		fstream fuser("users.txt", ios::app);
		if (!fuser) {
			cerr << "Couldn't open file | File doesn't exist" << endl;
			exit(1);
		}
		string user;
		string pass;
		cout << "Enter user to remove: ";
		cin.ignore(100, '\n') >> user;
		cout << "Confirm password[ADMIN]: ";
		cin.ignore(100, '\n') >> pass;
		if (!shop.findUser("Admin", pass)) {
			cerr << "Wrong password\nPlease try again" << endl;
		}
		else {
			if (!shop.findUser(user, pass)) {
				cerr << "Couldn't find user" << endl;
			}
			else {
				shop.removeUser(user);
			}
		}
	}

	void checkChoice(ShopSystem& shopSys, int choice, User* user) {
		system("cls");
		switch (choice) {
		case 1:
			addProducts(shopSys);
			break;
		case 2:
			addUsers(shopSys);
			break;
		case 3:
			shopSys.viewProducts();
			removeProducts(shopSys);
			break;
		case 4:
			shopSys.viewUsers();
			removeUsers(shopSys);
		case 5:
			shopSys.viewProducts();
			break;
		case 6:
			shopSys.viewUsers();
			break;
		case 7:
			break;
		case 8:
			exit(0);
			break;
		default:
			exit(2);
		}
	}
};