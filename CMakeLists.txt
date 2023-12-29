cmake_minimum_required(VERSION 3.27)
project(Bookstore_manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bookstore_manager main.cpp Book.cpp BookSold.cpp User.cpp)
