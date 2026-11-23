#include <bits/stdc++.h>

#define ll long long 
#define endl '\n'
#define all(a) begin(a), end(a)
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpl vector<pll>
#define F first
#define S second
#define pb push_back
using namespace std;

void solve(){
    ll r, s, p;
    cin >> r >> s >> p;

    vll ans_vector;

    // We define a block: 1 winner needs 2 neighbors.
    // The number of winners is min(target_count, (neighbor_count + 1) / 2)
    // Actually, based on your logic: winner_count = min(target, neighbors / 2)
    
    // sim 1: R wins with S, S wins with P, P wins with R
    ll r1 = r, s1 = s, p1 = p;
    ll ans1 = 0;
    ll m1 = min(r1, s1 / 2); ans1 += m1; s1 -= 2 * m1;
    ll m2 = min(s1, p1 / 2); ans1 += m2; p1 -= 2 * m2;
    ll m3 = min(p1, r1 / 2); ans1 += m3; r1 -= 2 * m3;
    ans_vector.pb(ans1);

    // sim 2: R wins with S, P wins with R, S wins with P
    ll r2 = r, s2 = s, p2 = p;
    ll ans2 = 0;
    m1 = min(r2, s2 / 2); ans2 += m1; s2 -= 2 * m1;
    m2 = min(p2, r2 / 2); ans2 += m2; r2 -= 2 * m2;
    m3 = min(s2, p2 / 2); ans2 += m3; p2 -= 2 * m3;
    ans_vector.pb(ans2);

    // sim 3: S wins with P, R wins with S, P wins with R
    ll r3 = r, s3 = s, p3 = p;
    ll ans3 = 0;
    m1 = min(s3, p3 / 2); ans3 += m1; p3 -= 2 * m1;
    m2 = min(r3, s3 / 2); ans3 += m2; s3 -= 2 * m2;
    m3 = min(p3, r3 / 2); ans3 += m3; r3 -= 2 * m3;
    ans_vector.pb(ans3);

    // sim 4: S wins with P, P wins with R, R wins with S
    ll r4 = r, s4 = s, p4 = p;
    ll ans4 = 0;
    m1 = min(s4, p4 / 2); ans4 += m1; p4 -= 2 * m1;
    m2 = min(p4, r4 / 2); ans4 += m2; r4 -= 2 * m2;
    m3 = min(r4, s4 / 2); ans4 += m3; s4 -= 2 * m3;
    ans_vector.pb(ans4);

    // sim 5: P wins with R, R wins with S, S wins with P
    ll r5 = r, s5 = s, p5 = p;
    ll ans5 = 0;
    m1 = min(p5, r5 / 2); ans5 += m1; r5 -= 2 * m1;
    m2 = min(r5, s5 / 2); ans5 += m2; s5 -= 2 * m2;
    m3 = min(s5, p5 / 2); ans5 += m3; p5 -= 2 * m3;
    ans_vector.pb(ans5);

    // sim 6: P wins with R, S wins with P, R wins with S
    ll r6 = r, s6 = s, p6 = p;
    ll ans6 = 0;
    m1 = min(p6, r6 / 2); ans6 += m1; r6 -= 2 * m1;
    m2 = min(s6, p6 / 2); ans6 += m2; p6 -= 2 * m2;
    m3 = min(r6, s6 / 2); ans6 += m3; s6 -= 2 * m3;
    ans_vector.pb(ans6);

    ll mx = 0;
    for(ll res : ans_vector) mx = max(mx, res);
    cout << mx << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t; cin >> t;
    while(t--) solve();
}