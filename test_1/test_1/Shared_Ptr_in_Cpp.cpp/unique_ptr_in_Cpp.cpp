#include <memory>
#include <iostream>
using namespace std;
class MyClass {
public:
    MyClass(int value) : data(value) {
        std::cout << "MyClass constructed: " << data << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destroyed: " << data << std::endl;
    }
    void doSomething() {
        std::cout << "Doing something with: " << data << std::endl;
    }
private:
    int data;
};

int main() {
    // 1. 创建 unique_ptr
    std::unique_ptr<MyClass> ptr1(new MyClass(10));
    // 推荐使用 std::make_unique (C++14)
    auto ptr2 = std::make_unique<MyClass>(20);

    // 2. 使用指针
    ptr1->doSomething();
    /*(*ptr2).doSomething();*/
    ptr2->doSomething();

    // 3. 所有权转移
    unique_ptr<MyClass> ptr3 = move(ptr1); // ptr1 现在为 nullptr
    if (!ptr1) {
        std::cout << "ptr1 is now empty" << std::endl;
    }

    // 4. 重置和释放
    ptr2.reset(); // 主动释放对象，ptr2 变为 nullptr
    MyClass* rawPtr = ptr3.release(); // 释放所有权，返回原生指针，但不销毁对象
    // 现在必须手动管理 rawPtr
    delete rawPtr;
    //所以使用release是危险的，我们强烈推荐使用reset

    // 离开作用域时，剩余的所有智能指针会自动管理其生命周期
    return 0;
}