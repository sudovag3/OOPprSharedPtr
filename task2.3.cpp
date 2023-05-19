#include <iostream>
#include <memory>

// Функция-член swap(): Эта функция обменивает содержимое двух std::shared_ptr, 
// переназначая им владение объектами.

int main() {
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(42);
    std::shared_ptr<int> sharedPtr2 = std::make_shared<int>(10);

    std::cout << "Before swap:" << std::endl;
    std::cout << "sharedPtr1: " << *sharedPtr1 << std::endl; // Выводит 42
    std::cout << "sharedPtr2: " << *sharedPtr2 << std::endl; // Выводит 10

    //Магия!!!
    sharedPtr1.swap(sharedPtr2);

    std::cout << "After swap:" << std::endl;
    std::cout << "sharedPtr1: " << *sharedPtr1 << std::endl; // Выводит 10
    std::cout << "sharedPtr2: " << *sharedPtr2 << std::endl; // Выводит 42

    return 0;
}
