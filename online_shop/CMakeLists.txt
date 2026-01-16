cmake_minimum_required(VERSION 3.10)

# 1. Project name and version
project(MyProject VERSION 1.0 LANGUAGES CXX)

# 2. Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Find all .cpp files in the current directory and src/
set(SOURCES
    main.cpp
    src/Cart.cpp
    src/Product.cpp
    src/ShopSystem.cpp
    src/User.cpp
    src/users.txt
    src/products.txt
)

# 4. Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# 5. Enable warnings (Optional but recommended)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
