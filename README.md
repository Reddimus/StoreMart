# StoreMart

StoreMart is an Object-Oriented Programming (OOP) project designed to simulate a simple store system. It serves as a practice project for learning and applying OOP principles and building a C++ project that’s more complex than a simple script.

## Features

- Implements core OOP concepts such as classes, inheritance, and polymorphism.
- Simulates different product categories including books, clothing, and electronics.
- Demonstrates effective use of CMake for project configuration and build management.

## Project Structure

- `CMakeLists.txt`: Defines the build system and project setup.
- `main.cpp`: Contains the main logic for running the StoreMart simulation.
- `Product.h`: Base class for all product types.
- `Book.h`: Derived class representing book products.
- `Clothing.h`: Derived class representing clothing products.
- `Electronic.h`: Derived class representing electronic products.

## Getting Started

### Prerequisites

- CMake 3.10 or higher
- C++ compiler supporting C++23

### Building the Project

1. Clone the repository:

    ```bash
    git clone https://github.com/Reddimus/StoreMart.git
    cd StoreMart
    ```

2. Follow the CMake build process [here](docs/Configure_CMake.md) and run the compiled executable.
