#include <iostream>
using namespace std;
int main()
{
    int num, count = 0;
    cout << "Input the number: ";
    cin >> num;
    for (int i = 2; i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
    }
    if (count == 1)
    {
        cout << num << " Number is prime " << endl;
    }
    else
    {
        cout << num << " Number is not prime " << endl;
    }
}