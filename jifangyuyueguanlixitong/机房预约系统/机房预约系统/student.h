#pragma once
#include<iostream>
#include"identity.h"
#include<vector>
#include"computerRoom.h"
#include<fstream>//使用文件流
#include<sstream>//使用string流
#include<iomanip>//格式输出
using namespace std;
//学生类
class Student :public Identity
{
public:

	//默认构造
	Student();
	//有参构造 参数 ：学号 姓名 密码
	Student(int id, string name, string pwd);

	//菜单界面
	void operMenu();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//修改密码
	void changepwd();

	//学生学号
	int m_Id;

	//机房容器
	vector<ComputerRoom> vCom;
};

