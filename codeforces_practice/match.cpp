/**
 This problem goes over the beautiful esence of problem solving, while at first it looks really messy, if you look at it
 from a general view, considering a single case, the answer is as simple as 1 line
 https://codeforces.com/problemset/problem/2155/A
 */

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n;

    for(int i=0; i<n;i++)
    {
        cin >> m;
        cout << 2*(m-1) << "\n";
    }

}