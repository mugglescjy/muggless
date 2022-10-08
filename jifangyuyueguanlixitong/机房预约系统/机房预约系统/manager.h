#pragma once
#include<iostream>
#include"identity.h"
#include"student.h"
#include "teacher.h"
#include<vector>
#include"computerRoom.h"
using namespace std;
//管理员类设计
class Manager :public Identity
{
public:
	Manager();

	Manager(string name, string pwd);

	//菜单界面
	void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//添加机房
	void addroom();

	//修改密码
	void changepwd();

	//修改机房
	void changeroom();
	//
	void clearorder();
	//初始化容器
	void initVector();

	bool checkRepeat(int id, int type);

	//学生容器
	vector<Student>vStu;

	//教师容器
	vector<Teacher>vTea;

	//机房信息
	vector<ComputerRoom>vCom;
};

