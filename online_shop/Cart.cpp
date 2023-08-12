#include "Cart.hpp"

void Cart::addToCart(Product product) {
	items.push_back(product);
}

void Cart::removeFromCart(string productName) {
	int index{ 0 };
	for (Product product : items) {
		if (productName == product.getName()) {
			items.erase(items.begin() + index);
		}
		index++;
	}
}

double Cart::getTotal() {
	double total{ 0.0 };
	for (Product product : items) {
		total += product.getPrice();
	}
	return total;
}
void Cart::displayCart() {
	cout << setw(10) << "Product:" << "\tPrice:" << "\tQuantity:" << endl;
	for (Product product : items) {
		cout << setw(20) << product.getName() 
			<< setw(10) << product.getPrice()
			<< setw(10) << product.getQuantity() << endl;
	}
}