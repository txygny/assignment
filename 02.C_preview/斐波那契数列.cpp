#include<iostream>
using  namespace std;
int main()
{
	int queryTimes, numberOfDigits[30], mainSeries[31] = {};

	cin >> queryTimes;
	int i, n;
	n = queryTimes;
	if (queryTimes > 0)
	{
		for (i = 0; i < n; i++)
		{
			cin >> numberOfDigits[i];
		}
	}
	else exit(-1);

	mainSeries[1] = mainSeries[2] = 1;
	n = 30;
	for (i = 3;i <= n;i++)
	{
		mainSeries[i] = mainSeries[i - 1] + mainSeries[i - 2];
	}
	n = queryTimes;

	for (i = 0; i < n; i++)
	{
		cout << mainSeries[numberOfDigits[i]]
			 << endl;
	}
}