#include <fstream>

#include "Product.hpp"
#include "Cart.hpp"
#include "User.hpp"
#include "ShopSystem.hpp"
#include "Misc.hpp"

int main()
{
	ShopSystem shopSys;
	// Add users and products to the shopping system
	// and so on
	Misc::userIP(shopSys);
	Misc::productIP(shopSys);

	string username;
	string password;


	int choice{ 0 };

	User* currentUser{ nullptr };
reset:

	choice = 1;

	while (choice) {
		system("cls");
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;

		currentUser = shopSys.findUser(username, password);
		if (currentUser == nullptr) {
			//error handling
			cerr << "Username or Password is incorrect." << endl;
			cout << "Try again?[0|1]:";
			cin >> choice;
			if (!choice) {
				exit(1);
			}
		}
		else {
			break;
		}
	}
	// shopping actions - add to cart, view cart, view total
	system("cls");
	while (choice < 4) {
		cout << setfill('/') << setw(50) << "" << endl;
		cout << setfill(' ');
		cout << "User: " << setw(20) << left << username << endl;
		cout << setfill('/') << setw(50) << "" << endl;
		cout << setfill(' ') << endl;
		Misc::printMiscs(choice);
		Misc::checkChoice(shopSys, choice, currentUser);
	}
	if (choice == 4) {
		goto reset;
	}
	return 0;
}
