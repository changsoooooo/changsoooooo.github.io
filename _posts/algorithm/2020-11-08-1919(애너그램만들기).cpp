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

	string a, b;
	cin >> a >> b;
	int i, j;
	int er=0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (i=0,j=0; i < a.length()&&j<b.length(); )
	{
		if (a.at(i)>b.at(j))
		{
			j++;
			er++;
		}
		else if (a.at(i) < b.at(j)) {
			i++;
			er++;
		}
		else
		{
			i++;
			j++;
		}
	}
	if (i < a.length()) {
		er += a.length() - i;
	}
	else
	{
		er += b.length() - j;
	}
	cout << er;

}
