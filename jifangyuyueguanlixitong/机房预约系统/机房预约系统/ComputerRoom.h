#pragma once
#include<iostream>
using namespace std;
class ComputerRoom
{
public:

	int m_ComId; //机房编号

	int m_MaxNum; //最大容量

	bool checkRepeat(int id, int type);
};
