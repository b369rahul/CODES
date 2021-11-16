
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
        string s;
        cin>>s;
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        cout<<hash % 1<<endl;
        return 0;
    }