#include<iostream>
using namespace std;
int main()
{
	int a = 0;
	int input;
	cin >> input;
	int i, n, factorNumber, number, sum,bool_;

	for (sum = 0, number = 2, factorNumber = 0; sum <= input; number++, factorNumber = 0)
	{
		for (i = 0, n = 2; i < number / 2; i++, n++)
		{
			if (number % n == 0)
			{
				bool_ = 0;
				break;
			}
			else
			{
				bool_ = 1;
				
			}
		}
		if (bool_ == 1)
		{
			cout << number << endl;
			sum = sum + number;
			a++;
		}
	}
	cout << a;
}