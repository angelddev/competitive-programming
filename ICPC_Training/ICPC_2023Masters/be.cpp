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



void solve(){
    string s1, s2;
    ll n;
    cin >> n;
    cin >> s1 >> s2;
    vll pref(1005), suf(1005);

    cf(i,1,n){
        pref[i] +=pref[i-1];
        if(s1[i-1] == s2[i-1]) pref[i]++;
    }

    rf(i,n-1,0){
        suf[i] +=suf[i+1];
        if(s1[i] == s2[i]) suf[i]++;
    }

    ll tam = 2, ans=0, a=0, b=0, ant=suf[0], ini, fin;

    // par
    f(i,0,n){
        ini = i;
        fin = ini+tam-1;
        ant=suf[0];
        while(ini >=0 && fin < n){
            ant = ant - pref[ini+1] - suf[fin] + pref[ini] + suf[fin+1] + (s1[ini] == s2[fin]) + (s2[ini] == s1[fin]);
            if(ans < ant){
                ans = ant;
                a = ini;
                b = fin;
            }else{
                if(ans == ant){
                    if((b-a) > (fin-ini)){
                        ans = ant;
                        a = ini;
                        b = fin;
                    }else{
                        if((b-a) == (fin - ini)){
                            if(ini < a){
                                ans = ant;
                                a = ini;
                                b = fin;
                            }
                        }
                    }
                }
            }
            ini--;
            fin++;
        }  
    }

    // impar

    tam = 1;    
     f(i,0,n){
        ini = i;
        fin = ini+tam-1;
        ant=suf[0];
        while(ini >=0 && fin < n){
            ant = ant - pref[ini+1] - suf[fin] + pref[ini] + suf[fin+1] + (s1[ini] == s2[fin]) + (s2[ini] == s1[fin]);
            if(ans < ant){
                ans = ant;
                a = ini;
                b = fin;
            }else{
                if(ans == ant){
                    if((b-a) > (fin-ini)){
                        ans = ant;
                        a = ini;
                        b = fin;
                    }else{
                        if((b-a) == (fin - ini)){
                            if(ini < a){
                                ans = ant;
                                a = ini;
                                b = fin;
                            }
                        }
                    }
                }
            }
            ini--;
            fin++;
        }  
    }
    a++;
    b++;
    cout << suf[0] << " " << ans << " " << a << " " << b << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}

