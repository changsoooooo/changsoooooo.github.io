---
layout: post
title:  "11328(Strfry)"
category: "develop"
date:   2020-11-08
excerpt: "11328(Strfry)"
project: false
comments: true
---
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
//11328 Strfry
using namespace std;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	int t;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		string a,b;
		cin >> a >> b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a.compare(b)==0)
		{
			cout << "Possible"<<'\n';
		}
		else
		{
			cout << "Impossible"<<"\n";
		}
	}
}
