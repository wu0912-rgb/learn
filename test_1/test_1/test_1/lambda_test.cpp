#include<iostream>
#include <vector>
#include<algorithm>
#include"lambda.h"
#include <string>
int order() {
	std::vector<int>nums = { 3,1,4,1,5,9,2,6 };
	std::sort(nums.begin(), nums.end(),
		[](int a, int b) {
			return a < b;
		});
    for (int n : nums) {
        std::cout << n << " ";
    }

	return 0;
};

int use_capturelist(){
    
    std::vector<int>nums = { 3,1,4,1,5,9,2,6 };
    auto isinrange = [](int x)->bool {
        return x >= 2 && x <= 5;
        };
    auto count = std::count_if(nums.begin(), nums.end(), isinrange);
    std::cout << "count=" << count << std::endl;
    return 0;
};
int use_mutable() {
    int counter = 0;
    auto incrementer = [counter]()mutable {
        counter++;
        std::cout << "counter=" << counter << std::endl;
        };
    incrementer();
    incrementer();
    std::cout << "External counter: " << counter << std::endl; // 输出：External counter: 0 (未被修改)
    return 0;
};

int usereference() {
    int ex = 10;
    auto refCapturer = [&ex]() {
        ex *= 2;
        };
    refCapturer();
    std::cout << "ex=" <<ex << std::endl; 
    return 0;
}

void comparePassMethods() {
    cout << "=== 参数传递方式对比 ===" << endl;

    TestObject obj(100);

    // 值传递：调用拷贝构造函数，创建完整副本
    auto byValue = [](TestObject o) {
        cout << "值传递 - 对象数据: " << o.data << endl;
        };

    // 引用传递：不创建副本，直接操作原对象
    auto byReference = [](TestObject& o) {

        cout << "引用传递 - 对象数据: " << o.data << endl;
        o.data = 200;
        };

    // 指针传递：传递地址，不创建对象副本
    auto byPointer = [](TestObject* o) {
        cout << "指针传递 - 对象数据: " << o->data << endl;
        o->data = 300;
        };

    cout << "值传递测试:" << endl;
    byValue(obj);

    cout << "引用传递测试:" << endl;
    byReference(obj);

    cout << "指针传递测试:" << endl;
    byPointer(&obj);
    cout << "obj.data:" << obj.data << endl;
    
}
//手写lambda匿名类
void origin_Lambda() {
    int base = 100;
    std::string name = "hello";
    auto myLambda = [base, &name](int multiplier)mutable->auto {
        base *= multiplier;
        name += " World";
        return name + ":" + std::to_string(base);

        };
    auto Result = myLambda(2);
    std::cout << "Result: " << Result << std::endl;
    std::cout << "External name:" << name << std::endl;
    std::cout << "External base:" << base << std::endl;
    std::cout << "------------:" << std::endl;
}
//创建一个名为MyFunctor的类来模拟编译器生成的匿名类
void simulation() {
    class MyFunctor {
    private:
        //1. 创造成员变量
        int base_;
        std::string& name_;
    public:
        //2. 构造函数：初始化捕获来的变量
        MyFunctor(int base, std::string& name) :base_(base), name_(name) {

        }
        std::string operator()(int multiplier) {
            base_ *= multiplier;
            name_ += " World";
            return name_ + ":" + std::to_string(base_);
        }
    };
    int base = 100;
    std::string name= "hello";
    auto Result = MyFunctor(base, name)(2);
    std::cout << "Result: " << Result << std::endl;
    std::cout << "External name:" << name << std::endl;
    std::cout << "External base:" << base << std::endl;
}