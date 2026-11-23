#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
 
#define endl '\n'
#define ll long long
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vpl vector<pll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i,s,e) for(ll i=s;i>=e;i--)
#define F first
#define S second
#define pb push_back
#define popb pop_back
using namespace std; 
bool comp(const pll &a, const pll &b){
    if(a.F == b.F) return a.S > b.S;
    return a.F < b.F;
}
 
void solve(){
    ll n,x;cin>>n>>x;
    vpl v;
    f(i,0,n){
        ll num;cin>>num;
        v.pb({num,i+1});
 
    }
    sort(v.begin(),v.end());

    ll izq=0,der=n-1,mid=1;
    while(izq<der-1){
        ll sum=v[izq].F+v[der].F;
        
        if(v[izq].F+v[der].F+v[mid].F==x){
            cout<<v[izq].S<<" "<<v[mid].S<<" "<<v[der].S<<endl;
            return;
        }
        if(sum+v[mid].F<x){
            bool cond=false;
            f(i,izq+1,der){
                    mid=i;
                    if(sum+v[mid].F>x)break;
                    if(sum+v[mid].F==x){
                        cond=true;break;
                    }
            }

            if(!cond){izq++;mid=izq+1;}
        }
        else der--;        
    }
    if(izq>=der-1)
        cout<<"IMPOSSIBLE"<<endl;

}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t=1;
   while(t--){
    solve();
   }
}