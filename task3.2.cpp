#include <iostream>
#include <memory>

class MyClass;
class OtherClass;

class OtherClass {
public:
    std::weak_ptr<MyClass> myClassWeakPtr;

    OtherClass() {
        std::cout << "OtherClass constructor" << std::endl;
    }

    ~OtherClass() {
        std::cout << "OtherClass destructor" << std::endl;
    }
};

class MyClass : public std::enable_shared_from_this<MyClass> {
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
    otherClassPtr->myClassWeakPtr = myClassPtr;

    // При выходе из блока кода, объекты будут корректно удалены.
    
    return 0;
}
