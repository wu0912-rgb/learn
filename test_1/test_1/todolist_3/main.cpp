#include<iostream>
#include"TodoManager.h"
using namespace std;
int main()
{
	try {
		TodoManager manager;
		manager.run();
	}
	catch (const exception& e) {
		cerr << "程序发生异常：" << e.what() << endl;
		return 1;
	}
	return 0;
}