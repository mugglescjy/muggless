#pragma once
#include<iostream>
#include"identity.h"
#include"student.h"
#include "teacher.h"
#include<vector>
#include"computerRoom.h"
using namespace std;
//����Ա�����
class Manager :public Identity
{
public:
	Manager();

	Manager(string name, string pwd);

	//�˵�����
	void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//��ӻ���
	void addroom();

	//�޸�����
	void changepwd();

	//�޸Ļ���
	void changeroom();
	//
	void clearorder();
	//��ʼ������
	void initVector();

	bool checkRepeat(int id, int type);

	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;

	//������Ϣ
	vector<ComputerRoom>vCom;
};

