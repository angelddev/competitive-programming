#include <bits/stdc++.h>
using namespace std;
     
void solve(){

    int n;
    cin >> n;

    if (n == 0) {          
        cout << "YES\n";
        return;
    }

    deque<int> b1;
    deque<int> b2;
    
    while (n > 0) {
        b1.push_front(n % 2);
        b2.push_back(n % 2);

        n=n>>1;
    }

    if(b2[0]==0){
        b2.push_back(0);
        b1.push_front(0);
    }
    
    

    if(b1.size()%2)
        if(b1[(b1.size()/2)]==1){
            cout << "NO\n";
            return;
        }

    if(b1==b2)
    cout << "YES\n";

    else
        cout << "NO\n"; 

}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    while(n--)
        solve();
}