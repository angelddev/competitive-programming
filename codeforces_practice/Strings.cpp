/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{

    int n, i, m;
    cin >> n;
    string word;
    vector<string> arr;
    string temp;
    
    for (i=0;i<n;i++)
    {
        cin >> word;
        
        m = word.length();
        if(m>10)
        {
            temp = string(1, word[0]) + to_string(m-2);
            temp = temp + string(1, word[m-1]);
        }else temp=word;
        
        
        arr.push_back(temp);
    }
    
     for(i=0; i<n; i++)
        {
            cout << arr[i] << "\n";
        }
    
    return 0;
}