#include<iostream>
using namespace std;
int main()
{
    int input, m;
    int killMan = 0;
    int isFind = 1;
    cin >> input;
    m = input;
    while (isFind==1)
    {
        m++;
        killMan = 0;
        for (int i = 0; i < input; i++)
        {
            killMan = (killMan + m - 1) % (2 * input - i);
            if (killMan < input)
            {
                break;
            }
            if (i +1==input)
            {
                isFind = 0;
            }
        }
    }
    cout << m ;
}