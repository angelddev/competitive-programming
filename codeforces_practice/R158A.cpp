#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

    if(n == 1) cout << 1 << '\n';
        else if(n == 2) cout << 9 << '\n';
            else if(n == 3) cout << 29 << '\n';
                else if(n == 4) cout << 56 << '\n';
                    else
                        cout << 5*(n*n - n - 1) << '\n';
}

}