
#include "Database.hpp"
#include <fstream>
 
void Database::addUser(const User &user)
{
    users.push_back(user);
}

void Database::addProduct(const Product &product)
{
    products.push_back(product);
}

void Database::saveToFile(const std::string &filename) const
{

 std::ofstream file;
    file.open("data.dat",std::ios::binary);
    if(!file)
    {
    file<<"Error Opening File "<<std::endl;
    }
    //write users data to file
    for (const auto& user : users) {
    file.write(reinterpret_cast<const char*>(&user), sizeof(User));
}

// Write product data to the file
for (const auto& product : products) {
    file.write(reinterpret_cast<const char*>(&product), sizeof(Product));
}




    file.close();
}
