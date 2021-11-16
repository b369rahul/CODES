#include <iostream>
#define ll long long

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    n=(n%60)+2;
    ll f[n];f[0]=0;f[1]=1;
    for(int i=2;i<n;i++){
        f[i]=(f[i-1]+f[i-2])%10;
    }

    return (f[n-1]*f[n-2]) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
