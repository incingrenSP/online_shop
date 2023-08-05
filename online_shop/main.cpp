#include "Product.hpp"
#include "Cart.hpp"
#include "User.hpp"
#include "ShopSystem.hpp"

int main()
{
	ShopSystem shopSys;

	// Add users and products to the shopping system
	// and so on
	
	User* currentUser = shopSys.findUser("username", "password");

	if (currentUser != nullptr) {
		// shopping actions - add to cart, view cart, view total
	}
	else {
		cout << "Username or Password is incorrect." << endl;
		//choice to create new account
		// error handling
	}
	return 0;

}
