#include <iostream>
#define ll long long

int fibonacci_sum_naive(long long n, ll m) {       // sum of modullo first 60 terms is 0 for m=10
    if (n <= 1)
        return n;

    ll f[n];f[0]=0;f[1]=1;ll sum=1;
    for(int i=2;i<n;i++){
        f[i]=(f[i-1]+f[i-2])%m;
        sum=(sum+f[i])%m;
    }

    return sum;
}

long long fibonicci_period(ll m){            // period for m=10 is 60
    ll n=m*m;
    ll f[n+2];
    f[0]=0;f[1]=1;
    for(ll i=2;i<n+2;i++){
        f[i]=f[i-1]+f[i-2];
        if(f[i-1]%m==0 && f[i]%m==1){
            return (i-1);
        }
    }
    return n;
}

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
    long long n = 0;
    std::cin >> n;
    std::cout << fast_fib0(n)<<'\n';
}
