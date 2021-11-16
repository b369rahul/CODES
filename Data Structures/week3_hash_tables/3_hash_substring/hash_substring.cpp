#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define int long long

class solve{
string p;
string t;
public:
solve(string p,string t): p(p),t(t)  {}

static const size_t multiplier = 37;
static const size_t cardinality=101;
static const size_t prime = 1000007;

int hash_func(const string& s) {
        int hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + (int32_t (s[i]))) % prime;
        return hash;
}

bool are_equal(int ind){
        for(int i=ind;i<ind+p.size();++i ){
            if(p[i-ind]!=t[i]){return 0;}
        }
        return 1;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

vector<int> get_indexes(){
    vector<int>ans;
    int hvp=hash_func(p);
    int xs=1;
    for(int i=0;i<p.size();++i){
        xs=(xs*multiplier)%prime;
    }
    int hvt=hash_func(t.substr(t.size()-p.size(),p.size()));
    if(hvp==hvt && are_equal(t.size()-p.size()))ans.push_back(t.size()-p.size());
    cout<<hvp<<" "<<hvt<<endl;
    for(int i = t.size()-p.size()-1;i>=0;--i){
        hvt= ((((multiplier*hvt)+(int32_t(t[i]))-((int32_t(t[i+p.size()]))*xs))%prime)+prime)%prime;
        cout<<"  $$  "<<hvt<<endl;
        if(hvt!=hvp)continue;
        else if(are_equal(i)){ans.push_back(i);}
    }
    reverse(ans.begin(),ans.end());
    //cout<<"Dfs";
    return ans;
}
void process(){
        print_occurrences(get_indexes());
        return;
    }
};
int32_t main() {
    string p,t;
    cin>>p>>t;
    solve obj(p,t);
    obj.process();
    return 0;
}
