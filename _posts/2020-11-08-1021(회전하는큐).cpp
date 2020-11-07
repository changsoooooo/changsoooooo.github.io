#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <list>

using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	vector<int> ::iterator iter;
	int n,m;
	cin >> n>>m;
	
	for (size_t i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	int turn = 0;
	iter = v.begin();
	for (size_t i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		vector<int>::iterator iter2;
		iter2 = iter;
		int t1, t2;
		t1 = 0, t2 = 0;

		for (; *iter != t;) {
			iter++;
			t1++;
			if (iter==v.end())
			{
				iter = v.begin();
			}
		}
		iter = iter2;
		for (; *iter != t;) {
			
			if (iter==v.begin())
			{
				iter = v.end();
				iter--;
				t2++;
			}
			else
			{
				iter--;
				t2++;
			}
			
		}
		if (t2>t1)
		{
			turn += t1;
			iter = v.erase(iter);
			if (iter==v.end())
			{
				iter = v.begin();
			}
		}
		else
		{
			turn += t2;
			iter = v.erase(iter);
			if (iter == v.end())
			{
				iter = v.begin();
			}
		}
	}
	cout << turn;
}
