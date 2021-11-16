#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
long long MaxPairwiseProduct(std::vector<ll>& numbers) {
    ll max_product = 0;
    int n = numbers.size();
    ll temp;int a=2;
    while(a--){
    for (int i = 0; i < n-1; ++i) {
        if(numbers[i]>numbers[i+1]){
            temp=numbers[i];
            numbers[i]=numbers[i+1];
            numbers[i+1]=temp;
        }}}

    return numbers[n-1]*numbers[n-2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<ll> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
