#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;
int height(int *h,int a[],int t){
    if(a[t]==-1){h[t]=1; return h[t];}
    else if(h[a[t]]!=0){h[t]=h[a[t]]+1;return h[t];}
    else{
        h[t]=height(h,a,a[t])+1;return h[t];
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];int *h=new int[n];
    for(int i=0;i<n;i++){h[i]=0;cin>>a[i];}
    for(int i=0;i<n;i++){
        if(a[i]==-1){h[i]=1;continue;}
        else if(h[a[i]]!=0)h[i]=h[a[i]]+1;
        else {
            h[i]=height(h,a,i);
        }}
    cout<<*max_element(h, h + n)<<'\n';
    
}