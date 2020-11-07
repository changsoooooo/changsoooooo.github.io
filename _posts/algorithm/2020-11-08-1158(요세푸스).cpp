#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
//1158 요세푸스문제
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int>cir;
	for (size_t i = 1; i <=n; i++)
	{
		cir.push_back(i);
	}
	
	vector<int>::iterator iter;
	iter = cir.begin();
	if (k==1)
	{
		cout << "<";
		for (size_t i = 0; i < n; i++)
		{
			cout << cir[i];
			if (i!=(n-1))
			{
				cout << ", ";
			}
		}
		cout << ">";
	}
	else {
		cout << "<";
		for (; cir.size() > 0;)
		{
			int t = k - 1;
			for (; t > 0;)
			{
				iter++;
				t--;

				if (iter == cir.end())
				{
					iter = cir.begin();
				}

				if (t == 0 && iter < cir.end())
				{
					cout << *iter;
					iter = cir.erase(iter);
					if (iter == cir.end())
					{
						iter = cir.begin();
					}
				}

			}
			if (cir.size() > 0)
			{
				cout << ", ";
			}
		}
		cout << ">";
	}
}
