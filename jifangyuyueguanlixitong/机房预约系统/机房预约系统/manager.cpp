#include"manager.h"
#include<string>
#include<fstream>
#include"globalFile.h"

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	ifstream ifs;  //ifsΪifstream�Ķ���
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//�˵�����
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << endl;
	cout << "\t\t-----------------------------------------" << endl;
	cout << "\t\t|                                       |" << endl;
	cout << "\t\t|             1.����˺�                |" << endl;
	cout << "\t\t|             2.�鿴�˺�                |" << endl;
	cout << "\t\t|             3.�鿴����                |" << endl;
	cout << "\t\t|             4.�޸Ļ���                |" << endl;
	cout << "\t\t|             5.�޸���Ϣ                |" << endl;
	cout << "\t\t|             6.��ӻ���                |" << endl;
	cout << "\t\t|             7.���ԤԼ                |" << endl;
	cout << "\t\t|             0.ע����¼                |" << endl;
	cout << "\t\t|                                       |" << endl;
	cout << "\t\t-----------------------------------------" << endl;
	cout << "���������ѡ��" << endl;
}

//����˺�
void Manager::addPerson()
{
	cout << "����������˺�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	cout << "0.�˳�" << endl;

	string fileName; //�����ļ���
	string tip;  //��ʾid��
	string errorTip;
	ofstream ofs; //�ļ���������

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "��ѧ���Ѿ�ʹ�ã�";
	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "�˹����Ѿ�ʹ�ã�";
	}
	else
	{
		system("cls");
		return;
	}
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	while (true)
	{
		cout << tip << endl;
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret) //���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
	ofs.close();
}

//�鿴�˺�
void Manager::showPerson()
{
	initVector();
	cout << "��ѡ��Ҫ���ҵ�����" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;
	cout << "0.�˳�" << endl;
	cout << "���������ѡ��";
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "ѧ����Ϣ���£�" << endl;
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			cout << "ѧ�ţ�" << it->m_Id << " ������" << it->m_Name << " ���룺" << it->m_Pwd << endl;
		}
	}
	else if (select == 2)
	{
		cout << "��ʦ��Ϣ���£�" << endl;
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			cout << "���ţ�" << it->m_EmpId << " ������" << it->m_Name << " ���룺" << it->m_Pwd << endl;
		}
	}
	else
	{
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << " ����������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//��ӻ���
void Manager::addroom()
{
	cout << "��ѡ����Ŀ��" << endl;
	cout << "1.��ӻ���" << endl;
	cout << "0.�˳�" << endl;
	string fileName; //�����ļ���
	string tip;  //��ʾid��
	string errorTip;
	ofstream ofs; //�ļ���������
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = COMPUTER_FILE;
		tip = "�����������ţ�";
		errorTip = "�˻����Ѿ�ʹ��,����������!";
	}
	else
	{
		system("cls");
		return;
	}
	ofs.open(fileName, ios::out | ios::app);
	int id_;
	int num_;
	while (true)
	{
		cout << tip << endl;
		cin >> id_;
		bool ret = checkRepeat(id_, select);
		if (ret) //���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "������������������" << endl;
	cin >> num_;
	ofs << id_ << " " << num_ << endl;
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
	ofs.close();
	initVector();  //���ó�ʼ�������ӿڣ����»�ȡ�ļ��е����ݡ�
}
//��֤ѧ�Ź����Ƿ��ظ�
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}

	return false;
}

//��ʼ������
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ   ѧ������ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	ifs.close();

}
void Manager::changepwd() //�޸���Ϣ
{
	string name, name_;
	string pwd, pwd_;

	cout << "�������û�����" << endl;
	cin >> name_;
	cout << "���������룺" << endl;
	cin >> pwd_;
	ifstream in("admin.txt");//���ļ�
	string s1;
	while (getline(in, s1))//��������
	{
		istringstream sin(s1);//����sin��
		sin >> name >> pwd;
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ����
		ofstream out("admin1.txt", ios::app);//���ļ�
		if (name == name_ && pwd == pwd_)
		{
			string  m, p;
			cout << "�������޸ĺ����Ϣ:" << endl;
			cout << "�˺ţ�" << endl;
			cin >> m;
			cout << "���룺" << endl;
			cin >> p;
			out << m << " " << p << endl;
			cout << "�޸ĳɹ�" << endl;
		}
		else
			out << name << "" << pwd << endl;//δ�޸�
		out.close();//�ر��ļ�
	}

	in.close();//�ر�

	ifstream filei("admin1.txt");//���ĵ�
	ofstream fileout("admin.txt", ios::out);//���ĵ����������
	for (string s; getline(filei, s);)//���޸ĺ������д���ļ���ȥ
	{
		fileout << s << endl;
	}
	filei.close();//�ر��ļ�
	fileout.close();//�ر��ļ�
	system("del admin1.txt");//ɾ���ļ�����
	system("pause");
	system("cls");
}
void Manager::changeroom() //�޸Ļ�����Ϣ
{
	string mid, mid_;
	string num, num_;

	cout << "�����������ţ�" << endl;
	cin >> mid_;
	cout << "���������������" << endl;
	cin >> num_;
	ifstream in("computerRoom.txt");//���ļ�
	string s1;
	while (getline(in, s1))//��������
	{
		istringstream sin(s1);//����sin��
		sin >> mid >> num;
		string m_ComId; //���ļ��л�ȡ�Ļ������
		string m_MaxNum; //���ļ��л�ȡ�������
		ofstream out("computerRoom1.txt", ios::app);//���ļ�
		if (mid == mid_ && num == num_)
		{
			string  x, y;
			cout << "�������޸ĺ����Ϣ:" << endl;
			cout << "������ţ�" << endl;
			cin >> x;
			cout << "���������" << endl;
			cin >> y;
			out << x << " " << y << endl;
			cout << "�޸ĳɹ�" << endl;
		}
		else
			out << mid << "" << num << endl;//δ�޸�
		out.close();//�ر��ļ�
	}
	in.close();//�ر�
	ifstream filei("computerRoom1.txt");//���ĵ�
	ofstream fileout("computerRoom.txt", ios::out);//���ĵ����������
	for (string s; getline(filei, s);)//���޸ĺ������д���ļ���ȥ
	{
		fileout << s << endl;
	}
	filei.close();//�ر��ļ�
	fileout.close();//�ر��ļ�
	system("del computerRoom1.txt");//ɾ���ļ�����
	system("pause");
	system("cls");
}

void Manager::clearorder()     //���ԤԼ
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.clear();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}
