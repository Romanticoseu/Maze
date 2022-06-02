#include"ranking.h"
using namespace std;

ranking::ranking()
{
	ifstream ranking_file("ranking.txt", ios::in);
	if (!ranking_file)
	{
		ranking_file.close();
		ofstream temp_file("ranking.txt");
		temp_file.close();
		ifstream ranking_file("ranking.txt", ios::in);
	}
	char raw_data[30];
	int times = 0;
	while (ranking_file.getline(raw_data, 30))//¶ÁÈ¡ÎÄ¼þ
	{
		char* ptr = NULL;
		char* buf = raw_data; 
		ptr = strtok_s(raw_data, "\t", &buf);
		char score[100] = {};
		for (int i = 0;ptr[i] != NULL;i++)
			score[i] = ptr[i];
		ptr = strtok_s(NULL, "\t", &buf);
		string name = ptr;
		int new_score = atoi(score);
		pair<int, string> record(new_score, name);
		my_ranking.insert(record);

		times++;
	}
	for (;times < 10;++times)
	{
		pair<int, string> record(0, "XXX");
		my_ranking.insert(record);
	}
	ranking_file.close();
}

ranking::~ranking()
{
	ofstream ranking_file("ranking.txt", ios::out);
	if (!ranking_file)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	auto temp = my_ranking.begin();
	for (int i=0; i<10; i++)
	{
		ranking_file << temp->first << '\t' << temp->second << endl;
		temp++;
		if (temp == my_ranking.end())
			break;
	}
	ranking_file.close();
}

void ranking::update_ranking(pair<int, string> record)
{
	auto i = my_ranking.begin();
	for (int a = 0;a < 10;a++)
	{
		if (record.first == i->first)
		{
			cout << "Congratulations!\nYou are in the TOP 10!" << endl;
			i->second = record.second;
			return;
		}
		if (record.first > i->first)
		{
			cout << "Congratulations!\nYou are in the TOP 10!" << endl;
			my_ranking.insert(record);
			return;
		}
		i++;
	}
	cout << "Sorry...\nYou are not in the TOP 10..." << endl;
}

void ranking::print_ranking()
{
	cout.setf(ios::left);
	cout << endl;
	cout << setw(16) << "Name" << "Scores" << endl;
	cout << "======================" << endl;
	auto temp = my_ranking.begin();
	for (int i = 0; i <10; i++)
	{
		cout << setw(16) << temp->second << temp->first << endl;
		temp++;
		if (temp == my_ranking.end())
			break;
	}
	cout << endl;
}
