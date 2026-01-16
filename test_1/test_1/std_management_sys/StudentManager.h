#pragma once
#include<string>
#include<iostream>
class StudentManager
{
public:
	StudentManager();
	void addStudent(std::string name, int score);
	void showAllStudents();
	void showAverage();
private:
	int count;
	std::string students[10];
	int scores[10];
};

