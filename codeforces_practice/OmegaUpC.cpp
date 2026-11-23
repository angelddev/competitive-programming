#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t, p;
  cin >> p >> t;

  int arr[12];


  for(int i=0; i<12; i++){
    arr[i]=0;
  }


  int x, k;
  for(int i=0; i<p; i++){
    cin >> x >> k;
    for(int j=x-8; j<k-8; j++){
        arr[j]=1;
    }
  }

  int cont=0;
  for(int i=0; i<12; i++){

    if(arr[i]==0){
        cont++;
    }else cont=0;

    if(cont==t){
        cout << "SI" << "\n";
        return 0;
    }
    
  }

  cout << "NO" << "\n";


  
  return 0;
}