#include <iostream>
#include <memory>

class MyClass;

class OtherClass {
public:
    std::shared_ptr<MyClass> myClassPtr;

    OtherClass() {
        std::cout << "OtherClass constructor" << std::endl;
    }

    ~OtherClass() {
        std::cout << "OtherClass destructor" << std::endl;
    }
};

class MyClass {
public:
    std::shared_ptr<OtherClass> otherClassPtr;

    MyClass() {
        std::cout << "MyClass constructor" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destructor" << std::endl;
    }
};

int main() {
    std::shared_ptr<MyClass> myClassPtr = std::make_shared<MyClass>();
    std::shared_ptr<OtherClass> otherClassPtr = std::make_shared<OtherClass>();

    myClassPtr->otherClassPtr = otherClassPtr;
    otherClassPtr->myClassPtr = myClassPtr;

    // При выходе из блока кода, оба shared_ptr будут уничтожены, но объекты не будут освобождены,
    // так как у них останутся ссылки друг на друга, циклическая ссылка не позволяет счетчику ссылок стать нулем
    // и объекты не будут корректно удалены.

    return 0;
}
