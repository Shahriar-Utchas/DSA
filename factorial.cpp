#include <iostream>
using namespace std;

int main()
{
        int num, fact;
        cout << "Enter the number for it's factorial: ";
        cin >> num;
        fact = num;
        while (num > 1)
        {
                num--;
                fact = fact * num;
        }
        cout << "Factorial value: " << fact << endl;
        return 0;
}
