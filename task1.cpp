#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass constructor" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destructor" << std::endl;
    }

    void DoSomething() {
        std::cout << "Doing something..." << std::endl;
    }
};

int main() {
    // Создание shared_ptr и передача ему нового экземпляра MyClass
    std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>();

    // Создание второго shared_ptr, владеющего тем же объектом MyClass
    std::shared_ptr<MyClass> sharedPtr2(sharedPtr1);

    // Вызов метода на одном из shared_ptr
    sharedPtr1->DoSomething();

    // Вызов метода на другом shared_ptr
    sharedPtr2->DoSomething();

    // Вывод информации о количестве владельцев
    std::cout << "sharedPtr1 use count: " << sharedPtr1.use_count() << std::endl;
    std::cout << "sharedPtr2 use count: " << sharedPtr2.use_count() << std::endl;

    return 0;
}
