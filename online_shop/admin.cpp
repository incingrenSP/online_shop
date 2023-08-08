

#include "Admin.hpp"
#include <fstream>

Admin::Admin() {}

void Admin::addUser(const User &user)
{
    users.push_back(user);
}

void Admin::addProduct(const Product &product)
{
    products.push_back(product);
}

void Admin::saveDataToFile(const std::string &filename)
{
    std::ofstream file;
    file.open("data.dat", std::ios::binary);
    if (!file)
    {
        std :: cerr << "Error Opening File " <<std:: endl;
    }
    // Write users data to the file
    for (const auto &user : users)
    {
        file.write(reinterpret_cast<const char*>(&user), sizeof(User));
    }

    // Write product data to the file
    for (const auto &product : products)
    {
        file.write(reinterpret_cast<const char*>(&product), sizeof(Product));
    }

    file.close();
}
