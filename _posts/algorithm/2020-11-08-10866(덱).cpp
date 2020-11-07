---
layout: post
title:  "10866(덱)"
category: "develop"
date:   2020-11-08
excerpt: "10866(덱)"
project: false
comments: true
---
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

	vector<int> qu;
	int t;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		string com;
		cin >> com;

		if (com.compare("push_front")==0)
		{
			int a;
			cin >> a;
			qu.insert(qu.begin(), a);
		}
		else if (com.compare("push_back") == 0)
		{
			int a;
			cin >> a;
			qu.push_back(a);
		}
		else if (com.compare("pop_front")==0)
		{
			if (qu.empty()==1)
			{
				cout << "-1\n";
			}
			else
			{
				cout << qu[0] << "\n";
				qu.erase(qu.begin());
			}
		}
		else if (com.compare("pop_back") == 0)
		{
			if (qu.empty() == 1)
			{
				cout << "-1\n";
			}
			else
			{
				cout << qu[qu.size() - 1] <<"\n";
				qu.pop_back();
			}
		}
		else if (com.compare("front")==0)
		{
			if (qu.empty()==1)
			{
				cout << "-1\n";
			}
			else
			cout<<qu[0]<<"\n";
		}
		else if (com.compare("size")==0)
		{
			cout << qu.size() << "\n";
		}
		else if (com.compare("empty")==0)
		{
			cout << qu.empty() << "\n";
		}
		else if (com.compare("back")==0)
		{
			if (qu.empty() == 1)
				cout << "-1" << "\n";
			else
				cout << qu[qu.size() - 1]<<"\n";
		}
	}

}
