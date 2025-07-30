# 🛒 Inventory Management - C++ Project (STL)

This project is a simple console application written in C++ that allows managing a product inventory using the Standard Template Library (STL) such as `map`, `string`, `vector`, etc.

## 📋 Features

The application allows:

1. **Adding / Updating a product**:  
   - Add a new product if the ID does not exist.  
   - Update title, author, price, or stock for existing products.

2. **Searching for a product by ID**:  
   - Display complete product details (title, description/author, price, stock).

3. **Updating the stock of a product**:  
   - Modify the current stock quantity for an existing product.

4. **Displaying the entire inventory**:  
   - Show a complete list of registered products with their details.

5. **Exiting the application**:  
   - Cleanly close the program.

## ⚙️ Technologies used

- C++17  
- STL (`std::map`, `std::string`, `std::vector`, `std::set`, `std::algorithm`)  
- I/O using `cin`, `cout`, `getline`

## 🛠️ Requirements to run

- A C++ compiler compatible with C++17 (e.g., `g++`, `clang++`, `MSVC`)  
- Operating system: Windows / Linux / macOS

## ▶️ How to compile and run

### Linux / macOS / WSL

```bash
g++ -std=c++17 -o inventory main.cpp
./inventory
