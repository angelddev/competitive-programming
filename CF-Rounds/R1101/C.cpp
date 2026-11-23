#include <bits/stdc++.h>

#define ll long long 
#define endl '\n'
#define all(a) begin(a), end(a)
#define f(i, s, e) for(ll i=s; i<e; i++)

using namespace std;

const ll INF = 1e18;

void solve(){
    ll n, x, s; 
    cin >> n >> x >> s;

    vector<char> ppl(n);
    f(i,0,n) cin >> ppl[i];

    ll av=0,ans=0, ts=x;
    ll rt = 0;

    f(i, 0, n){
        if(ppl[i]=='I'){
            if(ts>0){
                ts--;
                av+= (s-1);
                ans++;
            }
        }
        else if(ppl[i]=='E'){
            if(av>0){
                av--;
                ans++;
            } else if(ts>0&&rt>0){
                rt--;
                ts--;
                av+= s-1;
                ans++;
            }
        }
        else{
            if(av>0){
                av--;
                ans++;
                rt++;
            }
            else if(ts>0){
                ts--;
                av+=s-1;
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
}