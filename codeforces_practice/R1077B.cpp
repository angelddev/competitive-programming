#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll> 
#define vll vector<ll>
#define vpl vector<pll>
#define f(i,s,e) for(ll i=s;i<e;i++)
#define cf(i,s,e) for(ll i=s;i<=e;i++)
#define F first
#define S second
#define pb push_back
using namespace std; 

void solve(){

    int n;cin>>n;
    string s;cin>>s;

    int ones=count(s.begin(),s.end(),'1');
    if(ones==0){
        cout<<(n+2)/3<<'\n';
        return;
    }

    int ans=ones;

    int first=s.find('1');
    int last=s.rfind('1');

    int pref= first;
    ans+= (pref+1) /3;

    int suf=n-1-last;
    ans+=(suf+1) / 3;

    for(int i=first;i<=last;i++){
        if(s[i]=='0'){
            int j=i;
            while(j <=last&&s[j]=='0')j++;
            int len=j-i;
            ans+= len /3;
            i=j-1;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;cin>>t;
    while(t--)
        solve();
}
