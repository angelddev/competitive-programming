#include <bits/stdc++.h>

#define ll long long 
#define endl '\n'
#define all(a) begin(a), end(a)
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpl vector<pll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define F first
#define S second
#define pb push_back
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 +7;
const int LOG = 30;

void solve(){

    ll n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    ll best = 0, a = 0, b = 0;


    vll pfx(n+1);
    vll sfx(n+1);

    pfx[0]=(s1[0]==s2[0]);
    f(i,1,n){
        pfx[i]=pfx[i-1];
        if(s1[i]==s2[i]) pfx[i]++;
    }

    sfx[n-1]=(s1[n-1]==s2[n-1]);
    rf(i,n-2,0){
        sfx[i]=sfx[i+1];
        if(s1[i]==s2[i]) sfx[i]++;
    }

    // starting check
    ll temp = 0;
    for(int i = 0; i < n; i++){
        if(s1[i]==s2[i]){
            temp++;
        }
    }
    cout << temp << " ";
    best = temp; 

    //impar check
    for(int i = 1; i < n-1; i++){
        ll l=i-1, r=i+1, temp = (s1[i]==s2[i]);
        while(l>=0&&r<n){

            ll pf;
            if(l==0) pf = 0; 
            else pf = pfx[l-1];
            ll sf;
            if(r == n-1) sf = 0;
            else sf = sfx[r+1]; 
            ll temp2 = pf+sf;

            if(s1[l]==s2[r]) temp++;
            if(s1[r]==s2[l]) temp++;
            
            if(temp+temp2 == best){
                if((r-l+1)<(b-a+1)){
                    a = l, b = r;
                }
            }
            if(temp+temp2>best){
                best = temp+temp2;
                a = l, b = r;
            } 
            l--, r++;
        }
    }

    //par check
    for(int i = 0; i<n; i++){
        ll l = i, r = i+1, temp = 0;
        while(l>=0&&r<n){

            ll pf;
            if(l==0) pf = 0; 
            else pf = pfx[l-1];
            ll sf;
            if(r == n-1) sf = 0;
            else sf = sfx[r+1]; 
            ll temp2 = pf+sf;

            if(s1[l]==s2[r]) temp++;
            if(s1[r]==s2[l]) temp++;

            if(temp+temp2 == best){
                if((r-l+1)<(b-a+1)){
                    a = l, b = r;
                }
            }

            if(temp+temp2>best){
                best = temp+temp2;
                a = l, b = r;
            }
            l--, r++;
        }
    }

    //individual check
    for(int i = 0; i < n; i++){
        if(s1[i]==s2[i]){
            if(best==1){
                a = 0, b = 0;
                break;
            }
        }
    }

    if(best==0){
        cout << "0 1 1\n";
        return;
    }
    cout << best << " " << a+1 << " " << b+1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

