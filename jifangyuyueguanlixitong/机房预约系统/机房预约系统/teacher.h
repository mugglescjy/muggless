#pragma once
#include<iostream>
using namespace std;
#include"identity.h"


//��ʦ�����
class Teacher :public Identity
{
public:

	Teacher();

	Teacher(int empId, string name, string pwd);

	//�˵�����
	void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//�޸�����
	void changepwd();

	//ְ����
	int m_EmpId;


};

