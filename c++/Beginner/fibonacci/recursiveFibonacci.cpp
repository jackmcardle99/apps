#include <iostream>
#include <Windows.h> //used for sleep function

using namespace std;

/*This program will infinitely print the fibonacci sequence, it uses recursion by calling
itself indefinitely*/


void recursiveFib(int x, int y)
{
    cout << x+y << endl; //printing out the sum of the previous two entries
    Sleep(1000); //sleeping output by 1 second
    recursiveFib(y, x+y); //recursively calling the function and passing new numbers in sequence
}


int main()
{
    recursiveFib(0,1);
    return 0;
}




