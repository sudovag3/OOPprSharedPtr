#include <iostream>
#include <memory>


// Функция-член use_count(): Эта функция возвращает текущее количество 
// std::shared_ptr, владеющих тем же объектом, 
// что и вызывающий std::shared_ptr.

int main() {
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(42);
    std::shared_ptr<int> sharedPtr2 = sharedPtr1;
    std::shared_ptr<int> sharedPtr3 = sharedPtr1;

    std::cout << "sharedPtr1 use count: " << sharedPtr1.use_count() << std::endl; // Выводит 3
    std::cout << "sharedPtr2 use count: " << sharedPtr2.use_count() << std::endl; // Выводит 3
    std::cout << "sharedPtr3 use count: " << sharedPtr3.use_count() << std::endl; // Выводит 3

    return 0;
}
