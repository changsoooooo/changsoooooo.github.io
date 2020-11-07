---
layout: post
title:  "10804(카드역배치)"
category: "develop"
date:   2020-11-08
excerpt: "10804(카드역배치)"
project: false
comments: true
---
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
//카드 역배치 10804
using namespace std;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	int arr[21];
	for (size_t i = 1; i <= 20; i++)
	{
		arr[i]=i;
	}
	for (size_t k = 0; k < 10; k++)
	{
		int a, b;
		cin >> a >> b;
		
		for (size_t i = 0; i < (b - a + 1) / 2; i++)
		{
			int temp;
			temp = arr[b - i];
			arr[b - i] = arr[a + i];
			arr[a + i] = temp;
			
		}
	}
	for (size_t i = 1; i <= 20; i++)
	{
		cout << arr[i] << ' ';
	}
}
