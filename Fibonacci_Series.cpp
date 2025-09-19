#include <iostream>
using namespace std;

int Fib(int n)
{
    static int t1 = 0, t2 = 1, nextTerm;
    
    if(n>0)
    {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        cout<< nextTerm << " , ";
        Fib(n-1); // recursive call
    }
    return 0;
}

int main()
{
    int n = 15;
    cout<< "Next terms after 0 and 1 are" << endl;
    Fib(n);

    return 0;
}