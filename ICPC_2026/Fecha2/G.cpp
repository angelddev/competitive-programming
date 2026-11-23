#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(a) begin(a), end(a)
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpl vector<pll>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define rf(i,s,e) for(ll i=s; i>=e; i--)
#define F first
#define S second
#define pb push_back
using namespace std;

ll t, n, m, q, a, b, c, tot;
string s;

ll sz[100005];
ll lnk[100005];


ll find(ll a) {
    if (lnk[a] == a) return a;
    return lnk[a] = find(lnk[a]); 
}

bool same(ll a, ll b){
    return find(a) == find(b);
}

void unite(ll a, ll b){
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(sz[a]>sz[b]) swap(a, b);
    lnk[a]=b;
    sz[b]+=sz[a];
}



void solve(){
    cin >> n >> m;

    f(i,0,n){
        lnk[i]=i;
        sz[i]=1;
    }
    ll x, y;
    f(i,0,m){
        cin >> x >> y;
        unite(x, y);
    }

    vll representantes(n+1, 0);
    f(i,0,n){
        ll rep = find(i);
        representantes[rep]=sz[rep];
    }



    vll IDS(n+1);
    ll cont=0;
    f(i,0,n){
        if(representantes[i]>0){
            IDS[i]=cont;
            cont++;
        }
    }

    vector<deque<ll>> groups(n+1);
    f(i,0,n){
        ll x=find(i);
        groups[IDS[x]].pb(i);
    }


    // f(i,0,n){
    //       if(groups[i].size()>0){
    //      cout << "DEL GRUPO " << i << " ESTAN: " << "\n";
    //             for(ll nums : groups[i]){
    //                 cout << nums << " ";
    //             }
    //           cout << "\n";
    //     }
    //   }
    //  cout << "\n";


    //  vll restantes;
    //  vpl ans;
    //  ll pairs=0, g1, g2;
    //  f(i,0,n){
    //      if(pairs==0){
    //          if(groups[i].size()>0){
    //              g1=i;
    //               pairs++;
    //          }
            
    //      } else if(pairs==1) {
    //          if(groups[i].size()>0){
    //              g2=i;
    //               pairs++;
    //          }
    //      }

    //      if(pairs==2){
    //          if(groups[g1].size()>=groups[g2].size()){
    //              ll i;
    //              for(i = 0; i<groups[g2].size(); i++){
    //                  ans.pb({groups[g2][i], groups[g1][i]});
    //              }
    //              for(; i<groups[g1].size(); i++){
    //                  restantes.pb(groups[g1][i]);
    //              }
    //          } else {
    //              ll i;
    //              for(i = 0; i<groups[g1].size(); i++){
    //                  ans.pb({groups[g1][i], groups[g2][i]});
    //              }
    //              for(; i<groups[g2].size(); i++){
    //                  restantes.pb(groups[g2][i]);
    //              }
    //          }
    //          if(restantes.size()>0){
    //             pairs=1;
    //          } else 
    //          pairs=0;
    //      }
    //  }





    //  for(ll i = 1; i<restantes.size() ; i+=2){
    //     ans.pb({restantes[i], restantes[i-1]});
    //  }

    //  deque<ll> restantes;
     vpl ans;
    //  ll pairgroups[e.S].pop_front();s=0, g1, g2, i=0;
    //  while(i!=n){
    //     if(groups[i].size()>0){
    //         if(restantes.size()==0){
    //             f(j,0,groups[i].size()){
    //                 restantes.pb(groups[i][j]);
    //             }
    //             i++; continue;
    //         }
    //         else if(restantes.size()>groups[i].size()){
    //             ll j=0;
    //             for(; j<groups[i].size(); j++){
    //                 ans.pb({groups[i][j], restantes[j]});
    //             }
    //             for(ll k = 0; k<j; k++){
    //                 restantes.pop_front();
    //             }
    //             i++;
    //         } else {
    //             f(j,0,restantes.size()){
    //                 ans.pb({restantes[j], groups[i][j]});
    //             }
    //             restantes.clear();
    //             i++;
    //         }
    //     } else i++;
        
    //  }



    priority_queue<pll> pq; 
    f(i,0,n){
        if(groups[i].size()>0){
            pq.push({groups[i].size(), i});
        }
    }

    while(!pq.empty()){
        pll e = pq.top();
        pq.pop();
        if(pq.empty()) break;
        pll t = pq.top();
        pq.pop();
        ans.pb({groups[e.S][0], groups[t.S][0]});
        groups[e.S].pop_front();
        groups[t.S].pop_front();

        if(e.F!=1)
        pq.push({e.F-1, e.S});
        if(t.F!=1)
        pq.push({t.F-1, t.S});

    }


     cout << ans.size() << "\n";
     f(i,0,ans.size()){
         cout << ans[i].F << " " << ans[i].S << "\n";
     }

}

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    solve(); 

}