#include<iostream>
using namespace std;
int ft(int n);
int main()
{
	int n;
	cin >> n;
	cout << ft(n) << endl;
	return 0;
}
int ft(int n)
{
	if (n == 1)
	{
		return 1;
    }
	else return n * ft(n - 1);
}