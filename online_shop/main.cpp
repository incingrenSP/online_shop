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
	int choice{ 1 };

	while (choice) {
		system("cls");
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;

		User* currentUser = shopSys.findUser(username, password);
		if (currentUser == nullptr) {
			//error handling
			cerr << "Username or Password is incorrect." << endl;
			cout << "Try again?[0|1]:";
			cin >> choice;
		}
		else {
			break;
		}
	}
	// shopping actions - add to cart, view cart, view total
	system("cls");
	cout << setw(20) << right << username << endl << endl;
	Misc::printMiscs(choice);
	Misc::checkChoice(shopSys, choice);
	return 0;
}
