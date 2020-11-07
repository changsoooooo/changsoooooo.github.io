#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
//1475 방번호
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[10] = { 0 };
	string room;
	cin >> room;

	for (size_t i = 0; i < room.length(); i++)
	{
		arr[room.at(i)-48]++;
	}
	if ((arr[6]+arr[9])%2==1)
	{
		arr[6] = (arr[6] + arr[9]) / 2 + 1;
		arr[9] = arr[6];
	}
	else
	{
		arr[6] = (arr[6] + arr[9]) / 2;
		arr[9] = arr[6];
	}
	int high=-1;
	for (size_t i = 0; i < 10; i++)
	{
		if (high<arr[i])
		{
			high = arr[i];
		}
	}
	cout << high;
}
