#include <bits/stdc++.h>
using namespace std;
#define all(a) begin(a), end(a)
#define ll long long
#define pll pair<ll>
#define vll vector<ll>
#define vvl vector<vll>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define pb push_back()
#define F first
#define S second
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define MAXN 100004
ll t[4 * MAXN];
vll a;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = t[v*2] ^ t[v*2+1];
    }
}
int XOR(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return XOR(v*2, tl, tm, l, min(r, tm))
           ^ XOR(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] ^ t[v*2+1];
    }
}

void solve(){

    ll n, q; cin >> n >> q;

    a.assign(n+1, 0);
    cf(i,1,n){
        cin >> a[i];
    }

    build(1, 1, n);
    char type;
    ll l, r, u, k;
    f(i,0,q){
        cin >> type;
        if(type=='P'){
            cin >> l >> r;
            if(XOR(1, 1, n, l, r)==0) cout << "JUAN\n"; else 
            cout << "FRANK\n";
        } else {
            cin >> k >> u;
            a[k]+=u;
            update(1, 1, n, k, a[k]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //ll t; cin >> t; while(t--)
    solve();
}