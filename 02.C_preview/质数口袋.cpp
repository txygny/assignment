#include<iostream>
using namespace std;
int main()
{
	int a = 0;
	int input;
	cin >> input;
	int i, n, factorNumber, number, sum, series[1000] = {};

		for (sum = 0, number = 2, factorNumber = 0; sum <= input; number++, factorNumber = 0)
		{
			for (i = 0, n = 1; i < number; i++, n++)
			{
				if (number % n == 0)
				{
				
					factorNumber++;
				}
			}

			if (factorNumber == 2)
			{
				series[a] = number;
				sum = sum + number;
				a++;
			}
		}
		cout << endl;
	for (i = 0; i < a-1; i++)
	{
		cout << series[i] << endl << endl;
	}
	cout << a-1;
	return 0;
}