#pragma once

#include "User.hpp"
#include "Product.hpp"
#include <vector>

class Database
{
private:
    std::vector<User> users;
    std::vector<Product> products;

public:
    void addUser(const User &user);
    void addProduct(const Product &product);
    void saveToFile(const std::string &filename) const;
};
