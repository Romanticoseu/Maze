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

	//添加新排名并输出语句
	void update_ranking(std::pair<int, std::string> record);
	//打印排名
	void print_ranking();
private:
	std::map<int, std::string, std::greater<int> > my_ranking;
};
