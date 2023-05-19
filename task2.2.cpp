#include <iostream>
#include <memory>

// Функция-член unique(): Эта функция возвращает true, если вызывающий std::shared_ptr 
// является единственным владельцем объекта 
// (т.е. счетчик ссылок равен 1), и false в противном случае.

int main() {
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(42);
    std::shared_ptr<int> sharedPtr2 = std::make_shared<int>(10);

    std::cout << "sharedPtr1 unique: " << sharedPtr1.unique() << std::endl; // Выводит true (1)
    std::cout << "sharedPtr2 unique: " << sharedPtr2.unique() << std::endl; // Выводит true (1)

    return 0;
}
