#include <iostream>

template<typename T>
class ControlBlock {
public:
	T* ptr;
	int ref_count;
	ControlBlock(T* p=nullptr):ptr(p),ref_count(1){}
	~ControlBlock() {
		delete ptr;
	}
};
template<typename T>
class SharedPtr {
private:
	ControlBlock<T>* cb;
	//清理函数
	void cleanup() {
		if (cb) {
			--cb->ref_count;
			if (cb->ref_count == 0) {
				delete cb;
			}
			cb = nullptr;
		}
	}
public:
	//构造函数
	explicit SharedPtr(T* p = nullptr) {
		if (p) {
			cb = new ControlBlock<T>(p);
		}
		else {
			cb = nullptr;
		}
	}
	//拷贝构造函数
	SharedPtr(const SharedPtr& other) :cb(other.cb) {
		if (cb) {
			++cb->ref_count;
		}
	}
	//拷贝赋值运算符
	SharedPtr& operator=(const SharedPtr& other) {
		if (this != &other) {
			cleanup();//清理当前资源
			cb = other.cb;
			if (cb) {
				++cb->ref_count;
			}
		}
		return *this;
	}
	//移动构造函数
	SharedPtr(SharedPtr&& other)noexcept :cb(other.cb) {
		other.cb = nullptr;
	}
	//移动赋值运算符
	SharedPtr& operator=(SharedPtr&& other)noexcept {
		if (this != &other) {
			cleanup();
			cb = other.cb;
			other.cb = nullptr;
		}
		return *this;
	}
	//析构函数
	~SharedPtr() {
		cleanup();
	}
	//操作符重载
	T& operator*()const { return*(cb->ptr); }
	T* operator->()const { return cb->ptr; }
	//实用函数
	T* get()const { return cb ? cb->ptr:nullptr; }
	int use_count()const { return cb ? cb->ref_count : 0; }
	explicit operator bool()const { return cb && cb->ptr; }
};
	class SharedTest {
	public:
		SharedTest(int val) : value(val) {
			std::cout << "SharedTest(" << value << ") constructed\n";
		}
		~SharedTest() {
			std::cout << "SharedTest(" << value << ") destroyed\n";
		}
		void show() const {
			std::cout << "SharedTest value: " << value << std::endl;
		}
	private:
		int value;
	};
	int main() {
		SharedPtr<SharedTest> ptr1(new SharedTest(42));
		std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl; // 1
		{
			SharedPtr<SharedTest>ptr2 = ptr1;//拷贝构造
			std::cout << "ptr1 use_count after ptr2 copy: " << ptr1.use_count() << std::endl; // 2
			ptr2->show();
			SharedPtr<SharedTest>ptr3 = ptr1;//另一个拷贝
			std::cout << "ptr1 use_count after ptr3 copy: " << ptr1.use_count() << std::endl; // 3
		}
		std::cout << "ptr1 use_count after block: " << ptr1.use_count() << std::endl; // 1
		ptr1->show();
		return 0;
	}
