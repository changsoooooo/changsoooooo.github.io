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

	int t;
	cin >> t;
	for (size_t j = 0; j < t; j++)
	{
		string p;
		int n;
		string x;
		int arr[100001] = { 0 };
		int top = 0;
		int bottom = 0;
		int err = 0;
		cin >> p;
		cin >> n;
		cin >> x;
		
		int o = 0;
		for (size_t i = 1; i < x.length(); i++)
		{
			if (x.at(i)>='0'&&x.at(i)<='9')
			{
				o = o * 10 + x.at(i) - '0';
			}
			else if(n!=0)
			{
				arr[top++] = o;
				o = 0;
			}
		}
		int R = 1;
		for (size_t i = 0; i < p.length(); i++)
		{
			
			if (p.at(i)=='R')
			{
				R = R * -1;
			}
			else if (p.at(i)=='D')
			{
				if (top>bottom&&R==1)
				{
					bottom++;
				}
				else if (top > bottom && R == -1) {
					top--;
				}
				else 
				{
					i = p.length();
					err = 1;
				}
			}
		}
		if (err==1)
		{
			cout << "error\n";
		}
		else
		{
			cout << "[";
			if (R==1)
			{
				for (int i = bottom; i <top; i++)
				{
					cout << arr[i];
					if (i != top-1)
					{
						cout << ",";
					}
				}
			}
			else
			{
				
				for (int i = top-1; i >=bottom; i--)
				{
					cout <<arr[i];
					if (i !=bottom)
					{
						cout << ",";
					}
				}
			}
			
			cout << "]\n";
		}
	}
}
