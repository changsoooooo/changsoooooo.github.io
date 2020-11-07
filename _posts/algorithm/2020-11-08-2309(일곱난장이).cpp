#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
//일곱 난장이 2309
using namespace std;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	vector <int> nums;
	int total = 0;
	
	for (size_t i = 0; i < 9; i++)
	{
		int a;
		cin >> a;
		total += a;
		nums.push_back(a);
	}
	sort(nums.begin(), nums.end());
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = i; j < 9; j++)
		{
			if (total-nums.at(i)-nums.at(j)==100)
			{
				for (size_t k = 0; k < 9; k++)
				{
					if (k!=i&&k!=j)
					{
						cout << nums.at(k) << '\n';
					}
				}
				return 0;
			}
		}
	}
}
