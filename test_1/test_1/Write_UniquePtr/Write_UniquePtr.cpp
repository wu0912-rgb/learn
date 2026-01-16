#include <iostream>
template<typename T>
class UniquePtr {
private:
	T* ptr;
public:
	//显示构造函数
	explicit UniquePtr(T* p=nullptr):ptr(p){}
	//析构函数
	~UniquePtr() {
		delete ptr;
	}
	//删除拷贝构造和拷贝赋值
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;

	//移动构造函数
	UniquePtr(UniquePtr&& other) noexcept:ptr(other.ptr) {
		other.ptr = nullptr;
	}

	//
	UniquePtr& operator=(UniquePtr&& other) noexcept {
		if (this != &other) {
			delete ptr;   //释放当前资源
			ptr = other.ptr;  //接管资源
			other.ptr = nullptr;  //置空原指针

		}
		return *this;
	}
	//操作符重载
	T& operator*()const { return *ptr; }
	T* operator->()const { return ptr; }
	//实用函数
	T* get() const { return ptr; }
	explicit operator bool()const { return ptr != nullptr; }
	//释放所有权
	T* release() {
		T* temp = ptr;
		ptr = nullptr;
		return temp;
	}
	//重置
	void reset(T* p = nullptr) {
		delete ptr;
		ptr = p;
	}
};
//测试手写UniquePtr
class TestClass {
public:
	TestClass(int val) :value(val) {
		std::cout << "TestClass(" << value << ")constructed\n";
	}
	~TestClass(){
		std::cout << "TestClass(" << value << ") destroyed\n";
	}
	void print()const {
		std::cout << "Value: " << value << std::endl;
	}
private:
	int value;
};


int main() {
	UniquePtr<TestClass>ptr1(new TestClass(100));
	ptr1->print();
	//UniquePtr<TestClass> ptr2(ptr1); // 错误：拷贝构造被删除
	UniquePtr<TestClass> ptr3(std::move(ptr1));//正确：移动构造
	if (!ptr1) {
		std::cout << "ptr1 is now empty after move" << std::endl;
	}
	ptr3->print();
	return 0;
}