#include <iostream>
#define ll long long

long long fibonicci_period(ll m){
    ll a=0,b=1,c;ll i=2;
    while(1){
        c=(a+b)%m;
        a=b;
        if(c%m==1 && b%m==0){
            return (i-1);
        }
        b=c;i++;
    }
    return -1;
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1){ return n;}

    int p = fibonicci_period(m);
    n=n%p;
    ll f[n+1]; f[0]=0;f[1]=1;
    for(int i=2;i<=n;++i){
        f[i]=(f[i-1]+f[i-2])%m;
    }
    return f[n]%m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n,m) << '\n';
}
