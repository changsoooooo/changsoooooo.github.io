#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	vector<int> arr;
	for (size_t i = 0; i < 3; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr.at(i) << ' ';
	}
}
