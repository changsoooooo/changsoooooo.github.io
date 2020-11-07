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

	vector<int> ve;
	vector<char> v2;
	int n;
	cin >> n;

	int t = 1;
	int top=0;
	int err = 1;

	for (int i = 1; i <= n; i++)
	{
		
		int a;
		cin >> a;
		for (;t<=a;)
		{
			ve.push_back(t);
			top = t;
			v2.push_back('+');
			t++;
		}
		if (a==top)
		{
			v2.push_back('-');
			ve.pop_back();
			if (ve.size()>0)
			{
				top = ve.back();
			}
			else
			{
				top = -1;
			}
			
			
		}
		else {

			err=-1;
		}
	}
	if (err==-1)
	{
		cout << "NO\n";
	}
	else
	{
		for (size_t i = 0; i < v2.size(); i++)
		{
			cout << v2[i] << "\n";
		}
	}

}
