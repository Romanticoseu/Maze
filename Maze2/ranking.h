#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include<map>
#include<string>
class ranking
{
public:
	ranking();
	~ranking();

	//�����������������
	void update_ranking(std::pair<int, std::string> record);
	//��ӡ����
	void print_ranking();
private:
	std::map<int, std::string, std::greater<int> > my_ranking;
};
