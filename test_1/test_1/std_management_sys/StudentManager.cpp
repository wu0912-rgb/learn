#include "StudentManager.h"
#include<string>
#include<iostream>
StudentManager::StudentManager() :count(0){
	for (int i=0;i < 10;i++)
	{
		students[i] = "";
		scores[i] = 0;
	}
}

//添加学生实现
void StudentManager::addStudent(std::string name, int score) {
	if (count < 10) {
		students[count] = name;
		scores[count] = score;
		count++;
		std::cout << "成功添加学生: " << name <<std:: endl;
	}
	else {
		std::cout<<"学生数量已达上限"<<std::endl;
	}
}
//显示所有学生实现
void StudentManager::showAllStudents() {
	std::cout << "所有学生信息:" << std::endl;
	for (int i = 0;i < count;i++) {
		std::cout << " " << students[i] << " - 成绩:"<< scores[i];
		if (scores[i] >= 90) std::cout << " 优秀";
	}
	std::cout << std::endl;
}

//计算平均分实现
void StudentManager::showAverage() {
	if (count == 0) {
		std::cout << "没有学生数据！" << std::endl;
		return;
	}
	int total = 0; double average = 0;
	for (int i = 0;i < count;i++) {
		total += scores[i];
	}
	average = static_cast<double>(total) / count;
	std::cout <<"班级平均分" << average << std::endl;
}