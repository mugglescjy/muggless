#include "teacher.h"
#include<string>
#include"student.h"
#include"orderFile.h"
Teacher::Teacher()
{
}

Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu()
{
	cout << "欢迎教师：" << this->m_Name << endl;
	cout << "\t\t-------------------------------------------" << endl;
	cout << "\t\t|                                         |" << endl;
	cout << "\t\t|           1.查看所有预约                |" << endl;
	cout << "\t\t|                                         |" << endl;
	cout << "\t\t|           2.审核预约                    |" << endl;
	cout << "\t\t|                                         |" << endl;
	cout << "\t\t|           3.修改信息                    |" << endl;
	cout << "\t\t|                                         |" << endl;
	cout << "\t\t|           0.注销登录                    |" << endl;
	cout << "\t\t|                                         |" << endl;
	cout << "\t\t-------------------------------------------" << endl;
	cout << "请输入您的选择：" << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	Student stu;
	stu.showAllOrder();
}

//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中的预约：" << endl;
	vector<int>v;
	int index = 1;

	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << " ";
			cout << "预约日期：周" << of.m_OrderData[i]["date"] << " ";
			cout << "姓名：" << of.m_OrderData[i]["stuName"] << " ";
			cout << "学号：" << of.m_OrderData[i]["stuId"] << " ";
			cout << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.m_OrderData[i]["roomId"];
			string status = "状态：";
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl;
		}
	}

	cout << "请输入通过审核的编号，0代表返回" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果:" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cout << "0.退出" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.m_OrderData[v[select - 1]]["status"] = "2";
					of.updateOrder();
					cout << "已通过" << endl;
				}
				else
				{
					of.m_OrderData[v[select - 1]]["status"] = "-1";
					of.updateOrder();
					cout << "未通过" << endl;
				}
				break;
			}
		}
		cout << "输入有误，请重新输入:" << endl;
	}
	system("pause");
	system("cls");
}
void Teacher::changepwd() //修改信息
{
	int empId, empId_;
	string name, name_;
	string pwd, pwd_;

	cout << "请输入你的职工号：" << endl;
	cin >> empId_;
	cout << "请输入用户名：" << endl;
	cin >> name_;
	cout << "请输入密码：" << endl;
	cin >> pwd_;
	ifstream in("teacher.txt");//打开文件
	string s1;
	while (getline(in, s1))//读入数据
	{
		istringstream sin(s1);//定义sin流
		sin >> empId >> name >> pwd;
		int fId; //从文件中读取的id号
		string fName; //从文件中获取的姓名
		string fPwd; //从文件中获取密码
		ofstream out("teacher1.txt", ios::app);//打开文件
		if (empId == empId_ && name == name_ && pwd == pwd_)
		{
			string n, m, p;
			cout << "请输入修改后的信息:" << endl;
			cout << "职工号 ：" << endl;
			cin >> n;
			cout << "姓名：" << endl;
			cin >> m;
			cout << "密码：" << endl;
			cin >> p;
			out << n << "" << m << " " << p << endl;
			cout << "修改成功" << endl;
		}
		else
			out << empId << " " << name << "" << pwd << endl;//未修改
		out.close();//关闭文件
	}

	in.close();//关闭

	ifstream filei("teacher1.txt");//打开文档
	ofstream fileout("teacher.txt", ios::out);//打开文档并清空内容

	for (string s; getline(filei, s);)//将修改后的内容写到文件中去
	{
		fileout << s << endl;
	}
	filei.close();//关闭文件
	fileout.close();//关闭文件
	system("del teacher1.txt");//删除文件副本
	system("pause");
	system("cls");
}
