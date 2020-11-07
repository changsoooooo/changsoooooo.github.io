#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
//대표값2 2587
using namespace std;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	vector <int> nums;
	int total = 0;
	for (size_t i = 0; i <5; i++)
	{
		int a;
		cin >> a;
		total += a;
		nums.push_back(a);
	}
	sort(nums.begin(), nums.end());
	cout << total / 5 << '\n' << nums.at(2);
}
