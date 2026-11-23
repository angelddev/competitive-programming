#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define rf(i,s,e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define pb push_back
#define F first
#define S second
#define endl '\n'
using namespace std; 
#define ld long double
const ll MOD = 1e9+7, INF = 1e18;


ll n, m, k; 
ld t; 
ld tot; 
char type; 

void solve(){
    cin>>n>>t; 
    vector<ld> pr, no; 
    f(i, 0, n){
        ld x; 
        cin>>type>>x; 
        if(type == 'P') pr.pb(x);
        else no.pb(x); 
    }

    sort(all(pr)); 
    sort(all(no)); 

    f(i, 0, n){
        if(pr.size() == 0 or no.size() == 0) break; 
        if(pr[0] < no[0]*(ld)3){
            ld time = pr[0]/((ld)3*t/((ld)4 * (ld)pr.size()));
            tot+=time;  
            f(j, 1, pr.size()){
                pr[j]-=pr[0]; 
            }
            f(j, 0, no.size()){
                no[j]-=(t/((ld)4 * (ld)no.size())) * (time); 
            }
            pr.erase(pr.begin()); 
        }
        else{
            ld time = no[0]/((ld)t/((ld)4 * (ld)no.size()));
            tot+=time;
            f(j, 1, no.size()){
                no[j]-=no[0]; 
            }
            f(j, 0, pr.size()){
                pr[j]-=((ld)3*t/((ld)4 * (ld)pr.size())) * (time); 
            }
            no.erase(no.begin()); 
        }
        // cout<<"P: "; 
        // f(i, 0, pr.size()) cout<<pr[i]<<" "; cout<<"\n";
        // cout<<"N: "; 
        // f(i, 0, no.size()) cout<<no[i]<<" "; cout<<"\n";
    }

    while(pr.size() != 0){
        ld time = pr[0]/(t/((ld)pr.size()));
        tot+=time;  
        f(j, 1, pr.size()){
            pr[j]-=pr[0]; 
        }
        pr.erase(pr.begin()); 
    }

    while(no.size() != 0){
        tot+=no[0]/((ld)t/((ld)no.size()));  
        f(j, 1, no.size()){
            no[j]-=no[0]; 
        }
        no.erase(no.begin()); 
    }

    cout<<fixed<<setprecision(10)<<tot<<"\n"; 
}

int main(){
    #ifdef DEBUG 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #else 
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL); 
    #endif

    ll t=1;
    // cin>>t; 
    while(t--){
        solve(); 
    }
}