#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    string bin = "0011";
    double length = 4;
    int sum;
    for (int i = 0; i < 4; i++)
    {
        length -=1;
        int curr = int(bin.at(i));
        cout << "\n" + to_string(curr);
        int calc = pow((curr * 2), length);
        sum = sum + calc;
    }
    cout << "\n" + to_string(sum);
    return 0;
}

