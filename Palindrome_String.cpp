#include<iostream>
using namespace std;

bool checkPalindrome(string str)
{
    int s = 0;
    int e = str.size() - 1;

    while(s < e)
    {
        
        if(str[s] != str[e])
        {
            return false;
        }
        
            s++;
            e--;  
    }
    return true;
}
int main()
{
    string s = "namak";
    if(checkPalindrome(s))
    {
        cout<< "Palindrome"<< endl;
    }
    else{
        cout<< "Not Palindrome"<< endl;
    }
}