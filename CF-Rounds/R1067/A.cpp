#include <bits/stdc++.h>
using namespace std;


void solve(){

    int n, y, r;
    cin >> n >> y >> r;

    y=y/2;

    int m = n - y - r;

    if(m<0)
        cout << n << "\n";
    else cout << y+r << "\n";
  

}



int main(){

	ios::sync_with_stdio(0);
    cin.tie(0);	
	
	int n;
	cin >> n;

	while(n-->0)
		solve();
}
