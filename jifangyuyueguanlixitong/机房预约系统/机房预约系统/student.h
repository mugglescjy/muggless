#pragma once
#include<iostream>
#include"identity.h"
#include<vector>
#include"computerRoom.h"
#include<fstream>//ʹ���ļ���
#include<sstream>//ʹ��string��
#include<iomanip>//��ʽ���
using namespace std;
//ѧ����
class Student :public Identity
{
public:

	//Ĭ�Ϲ���
	Student();
	//�вι��� ���� ��ѧ�� ���� ����
	Student(int id, string name, string pwd);

	//�˵�����
	void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//�޸�����
	void changepwd();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;
};

