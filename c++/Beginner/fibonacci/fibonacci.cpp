#include <iostream>
using namespace std;

int fib(int n){
    if (n == 0) //n 0 or 1 in the sequence is 0 and 1 respectively
        return 0; //return 0 or 1 if user inputs 0 or 1;
    if (n == 1)
        return 1;

    return fib(n-1) + fib(n-2); //calling function recursively
}

int main()
{
    int n;
    cout << "Please enter the Nth number in the Fibonacci sequence: ";
    cin >> n; //taking user input and assigning to N
    cout << "The value of " << n << "n is " <<
    fib(n); //passing N to fib function
    return 0;
}


