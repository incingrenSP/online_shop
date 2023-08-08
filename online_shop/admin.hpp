#pragma once
#include <iostream>
#include "User.hpp"
#include "Product.hpp"
#include <vector>

class Admin
{
private:
    std::vector<User> users;
    std::vector<Product> products;

public:
    Admin();

    void addUser(const User &user);
    void addProduct(const Product &product);

    void saveDataToFile(const std::string &filename);
};
