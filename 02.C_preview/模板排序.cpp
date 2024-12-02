#include<iostream>
using namespace std;


int main() 
{
	int totalNumber,*p;
	cin >> totalNumber;
	p = (int*)calloc(totalNumber ,sizeof(int));
	int i,a;
	for (i = 0; i < totalNumber; i++)
	{
		cin >>  *(p + i);
		if (i > 0)
		{
			for (a = 0; a < i; a++)
			{
				int c = 0;
				if (*(p+i) < *(p+a))
				{
					c = *(p+i);
					*(p+i) = *(p+a);
					*(p+a) = c;
					
				}
			}
		}
	}
	for (i = 0; i < totalNumber; i++)
	{
		cout << *(p + i)
			 << " ";
	}
	cout << endl;
	free(p);
}