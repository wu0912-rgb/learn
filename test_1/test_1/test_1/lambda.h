#pragma once
using namespace std;

class TestObject {
public:
    int data;
    TestObject(int d) : data(d) {
        cout << "构造函数调用" << endl;
    }
    TestObject(const TestObject& other) : data(other.data) {
        cout << "拷贝构造函数调用" << endl;
    }
};


int order();
int use_mutable();
void comparePassMethods();
int usereference();
int use_capturelist();
void origin_Lambda();
void simulation();
