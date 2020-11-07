#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
//홀수 2576
using namespace std;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	vector<int> nums;
	int total = 0;
	int min = 9999999;
	for (size_t i = 0; i < 7; i++)
	{
		int a;
		cin >> a;
		if (a % 2 == 1) {
			total += a;
			if (a < min) {
				min = a;
			}	
		}
	}
	if (total==0)
	{
		cout << "-1";
	}
	else
	{
		cout << total << '\n' << min;

	}
}
