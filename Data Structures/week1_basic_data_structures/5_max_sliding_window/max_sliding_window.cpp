#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stacky{
    stacky(int val,int max):
    val(val),
    max(max)
    {}
    int val;
    int max;
};
void insert(vector<stacky>&stack1,int val){
    if(!stack1.empty()){
        stack1.push_back(stacky(val,max(val,stack1.back().max)));
    }
    else{
        stack1.push_back(stacky(val,val));
    }return;
}
void delt(vector<stacky>&stack1,vector<stacky>&stack2){
    if(!stack2.empty()){
        stack2.pop_back();
    }
    else{
        while(!stack1.empty()){
            insert(stack2,stack1.back().val);
            stack1.pop_back();
            
        }stack2.pop_back();
    }
    return;
}

void max_sliding_window_naive(vector<int> const & A, int m) {
    vector<stacky> stack1;
    vector<stacky> stack2;
    vector<int>ans;
    for(int i=0;i<m;i++){
        insert(stack1,A[i]);
    }
    ans.push_back(stack1.back().max);
    if(A.size()>m){
    for(int i=m;i<A.size();i++){
        delt(stack1,stack2);
        insert(stack1,A[i]);
        int as=-1;
        stack2.back().max;
        if (!stack2.empty()){as=max(as,stack2.back().max);};
        if (!stack1.empty()){as=max(as,stack1.back().max);};
        ans.push_back(as);
    }}
    for(int i=0;i<=A.size()-m;++i){
        cout<<ans[i]<<" ";
    }


}


// void max_sliding_window_naive(vector<int> const & A, int m) {
//     vector <int> sorted;
    
//     for(int i=0;i<m;i++){
//     sorted.push_back(A[i]);
//     }
//     sort(sorted,sorted+m);
// }


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int m = 0;
    cin >> m;

    max_sliding_window_naive(A, m);

    return 0;
}
