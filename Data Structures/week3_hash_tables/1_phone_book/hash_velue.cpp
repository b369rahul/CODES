#include <iostream>
#include <vector>
#include <string>
#define int long long
using namespace std;

int p= 1e7+19;
int m=8;

int hash_function(int n){
    return ((n%p)%m);
}

int32_t main(){
    int n;cin>>n;
    cout<<hash_function(n)<<endl;
    return 0;
}