// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "include/math_dll.h"
#include"include/math_dll_c.h"
int main()
{
    MathHandle handle = NULL;
    int result_int;
    //创建句柄
    MathHandleErrorCode error = math_handle_create(&handle);
    if (error != MATH_HANDLE_SUCCESS) {
        fprintf(stderr, "Failed to create math handle: %d\n", error);
        return 1;
    }
    error = math_handle_add(handle, 10, 20, &result_int);
    std::cout<<"MathLibrary::Add(10, 20):"<< result_int<< std::endl;
    //销毁句柄
    error = math_handle_destroy(handle);
}

