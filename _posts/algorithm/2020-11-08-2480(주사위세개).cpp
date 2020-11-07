#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	vector<int> dice;
	for (size_t i = 0; i < 3; i++)
	{
		int a;
		cin >> a;
		dice.push_back(a);
	}
	sort(dice.begin(), dice.end());
	if (dice.at(0)==dice.at(2)&&dice.at(2)==dice.at(1))
	{
		cout << 10000 + dice.at(0) * 1000;
	}
	else if (dice.at(0) != dice.at(1) && dice.at(1) != dice.at(2) && dice.at(0) != dice.at(2)) {
		cout << dice.at(2) * 100;

	}
	else
	{
		cout << 1000 + dice.at(1) * 100;
	}
}
