#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t, k;
  cin >> t >> k;

  if(k%t==0){
    cout << 0 << "\n";
  }else
  cout << t-(k%t) << "\n";
  

  return 0;
}