---
layout: post
title:  "10807(개수세기)"
category: "develop"
date:   2020-11-08
excerpt: "10807(개수세기)"
project: false
comments: true
---
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
//개수 세기 10807
using namespace std;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	int arr[201] = { 0 };
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr[a + 100] += 1;
	}
	int v;
	cin >> v;
	cout << arr[v + 100];
}
