#include<iostream>
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"
using namespace std;

//����ѧ���Ӳ˵�����
void studentMenu(Identity* student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;
		cin >> select; //�����û�ѡ��

		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)  //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}
		else if (select == 5)
		{
			stu->changepwd();
		}
		else
		{
			delete student;
			cout << "�˳���¼��" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//�����ʦ�Ӳ˵�����
void teacherMenu(Identity* teacher)
{
	while (true)
	{
		//���ý�ʦ�Ӳ˵�
		teacher->operMenu();

		Teacher* stu = (Teacher*)teacher;
		int select = 0;
		cin >> select; //�����û�ѡ��

		if (select == 1) //����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 2)  //�鿴����ԤԼ
		{
			stu->validOrder();
		}
		else if (select == 3)
		{
			stu->changepwd();
		}
		else
		{
			delete teacher;
			cout << "�˳���¼��" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//�������Ա�Ӳ˵�����
void managerMenu(Identity* manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();
		//������ָ�� תΪ����ָ�룬���������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;
		if (select == 1) //����˺�
		{
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			man->showComputer();
		}
		else if (select == 4) {
			man->changeroom();
		}
		else if (select == 5)
		{
			man->changepwd();
		}
		else if (select == 6)
		{
			man->addroom();
		}
		else if (select == 7)
		{
			man->clearorder();
		}
		else
		{
			delete manager;  //���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//��¼���� ����1 �����ļ��� ����2 �����������
void LoginIn(string fileName, int type)
{
	//����ָ�룬����ָ���������
	Identity* person = NULL;
	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId; //���ļ��ж�ȡ��id��
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ����
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("cls");

				person = new Student(id, name, pwd);
				//��ȥѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fId; //���ļ��ж�ȡ��id��
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ����
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("cls");

				person = new Teacher(id, name, pwd);
				//��ȥ��ʦ��ݵ��Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ����
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("cls");

				person = new Manager(name, pwd);
				//��ȥ����Ա��ݵ��Ӳ˵�

				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	int select = 0;
	while (true)
	{
		cout << "\t\t----------------------------------" << endl;
		cout << "\t\t|    ��ӭʹ�û���ԤԼ����ϵͳ    |" << endl;
		cout << "\t\t----------------------------------" << endl;
		cout << "\t\t|                                |" << endl;
		cout << "\t\t|            1.ѧ��              |" << endl;
		cout << "\t\t|            2.��ʦ              |" << endl;
		cout << "\t\t|            3.����Ա            |" << endl;
		cout << "\t\t|            0.�˳�              |" << endl;
		cout << "\t\t|                                |" << endl;
		cout << "\t\t----------------------------------" << endl;
		cout << "��ѡ��������ݣ�" << endl;

		cin >> select;//�����û�ѡ��

		switch (select)
		{
		case 1: //ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;

		case 2: //��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;

		case 3: //����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;

		case 0:
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			exit(0);
			break;

		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
