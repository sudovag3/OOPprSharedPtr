#include <iostream>
#include <memory>

// Функция-член reset(): Эта функция сбрасывает std::shared_ptr, 
// отрывая его связь с текущим объектом и, 
// при необходимости, присваивает ему новый объект.

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass constructor" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destructor" << std::endl;
    }
};

int main() {
    std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>();

    std::cout << "Before reset" << std::endl;
    std::cout << "sharedPtr1: " << sharedPtr1 << std::endl; // Выводит адрес объекта

    //Магия!!
    sharedPtr1.reset();

    std::cout << "After reset" << std::endl;
    std::cout << "sharedPtr1: " << sharedPtr1 << std::endl; // Выводит nullptr

    return 0;
}
