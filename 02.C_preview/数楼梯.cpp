#include<iostream>
using namespace std;
int climb(int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}
	else
	{
		int* p,i;
		p = (int*)calloc(n + 1, sizeof(int));
		*(p + 1) = 1;
		*(p + 2) = 2;
		for (i = 3; i < n + 1; i++)
		{
			*(p + i) = *(p + i - 1) + *(p + i - 2);
			
		}
		return *(p + n);
			free(p);
	}
}
int main()
{
	int n;
	cin >> n;
	cout << climb(n);
}