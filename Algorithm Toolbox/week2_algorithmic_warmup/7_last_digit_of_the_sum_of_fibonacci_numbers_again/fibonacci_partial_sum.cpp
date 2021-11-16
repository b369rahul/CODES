#include <iostream>
#include <vector>
#define ll long long

long long fast_fib0(ll n){
    ll q=n%60;
    if(q==0)return 0;
    if(q==1)return 1;
    ll f[q+1];f[0]=0;f[1]=1;ll sum=1;
    for(int i=2;i<q+1;i++){
        f[i]=(f[i-1]+f[i-2])%10;
        sum=(sum+f[i])%10;
    }
    return sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    if(from>0){
    ll ans=fast_fib0(to)-fast_fib0(from-1)+10;
    
    std::cout << (ans)%10 << '\n';}
    else {
        std::cout << (fast_fib0(to))%10 << '\n';
    }
}
