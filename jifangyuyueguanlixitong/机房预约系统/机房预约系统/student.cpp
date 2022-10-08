#include"student.h"
#include<string>
#include<fstream>
#include<iostream>
#include"globalFile.h"
#include"orderFile.h"

Student::Student()
{
}
//�вι��� ���� ��ѧ�� ���� ����
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		//����ȡ����Ϣ���뵽 ������
		vCom.push_back(com);
	}
	ifs.close();

}

//�˵�����
void Student::operMenu()
{
	cout << "��ӭѧ����" << this->m_Name << endl;
	cout << "\t\t-------------------------------------------" << endl;
	cout << "\t\t|                                         |" << endl;
	cout << "\t\t|           1.����ԤԼ                    |" << endl;
	cout << "\t\t|                                         |" << endl;
	cout << "\t\t|           2.�鿴�ҵ�ԤԼ                |" << endl;
	cout << "\t\t|                                         |" << endl;
	cout << "\t\t|           3.�鿴����ԤԼ                |" << endl;
	cout << "\t\t|                                         |" << endl;
	cout << "\t\t|           4.ȡ��ԤԼ                    |" << endl;
	cout << "\t\t|                                         |" << endl;
	cout << "\t\t|           5.�޸���Ϣ                    |" << endl;
	cout << "\t\t|                                         |" << endl;
	cout << "\t\t|           0.ע����¼                    |" << endl;
	cout << "\t\t|                                         |" << endl;
	cout << "\t\t-------------------------------------------" << endl;
	cout << "����������ѡ��" << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "�������ŵ�ʱ��Ϊ��һ������!" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	cout << "0.�˳�" << endl;
	cout << "��ѡ����ҪԤԼ��ʱ�䣺" << endl;

	int select = 0;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		system("cls");
		return;
	}
	cout << "����������ԤԼʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	cout << "0.�˳�" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		system("cls");
		return;
	}

	cout << "��ѡ�������" << endl;
	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != vCom.end(); it++)
	{
		cout << it->m_ComId << "�Ż�������Ϊ��" << it->m_MaxNum << endl;
	}
	cout << "0.�˳�" << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= vCom.size())
		{
			break;
		}
		system("cls");
		return;
	}

	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << " interval:" << interval << " ";
	ofs << " stuId:" << this->m_Id << " ";
	ofs << " stuName:" << this->m_Name << " ";
	ofs << " roomId:" << room << " ";
	ofs << " status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id)
		{
			cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"] << " ";
			cout << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_OrderData[i]["roomId"];
			string status = "״̬��";
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_OrderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_OrderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		//if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id)
		{
			cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"] << " ";
			cout << "������" << of.m_OrderData[i]["stuName"] << " ";
			cout << "ѧ�ţ�" << of.m_OrderData[i]["stuId"] << " ";
			cout << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_OrderData[i]["roomId"];
			string status = "״̬��";
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_OrderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_OrderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int>v;
	int index = 1;

	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id)
		{
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "0")
			{
				v.push_back(i);
				cout << index++ << " ";
				cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"] << " ";
				cout << "������" << of.m_OrderData[i]["stuName"] << " ";
				cout << "ѧ�ţ�" << of.m_OrderData[i]["stuId"] << " ";
				cout << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.m_OrderData[i]["roomId"];
				string status = "״̬��";
				if (of.m_OrderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_OrderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}

	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;

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
				of.m_OrderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������:" << endl;
	}
	system("pause");
	system("cls");
}

void Student::changepwd() //�޸���Ϣ
{
	int id, id_;
	string name, name_;
	string pwd, pwd_;

	cout << "���������ѧ�ţ�" << endl;
	cin >> id_;
	cout << "�������û�����" << endl;
	cin >> name_;
	cout << "���������룺" << endl;
	cin >> pwd_;
	ifstream in("student.txt");//���ļ�
	string s1;
	while (getline(in, s1))//��������
	{
		istringstream sin(s1);//����sin��
		sin >> id >> name >> pwd;
		//ѧ�������֤
		int fId; //���ļ��ж�ȡ��id��
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ����
		ofstream out("student1.txt", ios::app);//���ļ�
		if (id == id_ && name == name_ && pwd == pwd_)
		{
			string n, m, p;
			cout << "�������޸ĺ����Ϣ:" << endl;
			cout << "ѧ�ţ�" << endl;
			cin >> n;
			cout << "������" << endl;
			cin >> m;
			cout << "���룺" << endl;
			cin >> p;
			out << n << "" << m << " " << p << endl;
			cout << "�޸ĳɹ�" << endl;
		}
		else
			out << id << " " << name << "" << pwd << endl;//δ�޸�
		out.close();//�ر��ļ�
	}

	in.close();//�ر�

	ifstream filei("student1.txt");//���ĵ�
	ofstream fileout("student.txt", ios::out);//���ĵ����������

	for (string s; getline(filei, s);)//���޸ĺ������д���ļ���ȥ
	{
		fileout << s << endl;
	}
	filei.close();//�ر��ļ�
	fileout.close();//�ر��ļ�
	system("del student1.txt");//ɾ���ļ�����
	system("pause");
	system("cls");
}
