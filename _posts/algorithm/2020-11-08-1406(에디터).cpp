//STL link이용 연결리스트 문제 
#include <iostream>
#include <list>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	list <char>:: iterator iter;
	list <char> lt;
	string str;
	cin >> str;
	for (size_t i = 0; i < str.length(); i++)
	{
		lt.push_back(str.at(i));
	}
	
	int tr;
	cin >> tr;
	iter = lt.end();
	for (size_t i = 0; i < tr; i++)
	{
		char m;
		cin >> m;
		if (m=='P')
		{
			char t;
			cin >> t;
			lt.insert(iter, t);
		}
		else if (m=='L')
		{
			if (iter!=lt.begin())
			{
				iter--;
			}
			
		}
		else if (m == 'B') {
			if (iter != lt.begin())
			{
				iter--;
				iter=lt.erase(iter);
				
			}
		}
		else if (m == 'D') {
			if (iter != lt.end())
			{
				iter++;
			}
			
		}
	}
	for (iter = lt.begin(); iter!=lt.end(); iter++)
	{
		cout << *iter;
	}
}
