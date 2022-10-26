// C++ program to find the
// sum of natural numbers up
// to n using recursion
#include <iostream>
using namespace std;
 
// Returns sum of first
// n natural numbers
int recurSum(int n)
{
    if (n <= 1)
        return n;
    return n + recurSum(n - 1);
}
 
// Driver code
int main()
{
    int n = 5;
    cout << recurSum(n);
    return 0;
}