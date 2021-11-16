#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node{
    int size;
    int id=-1;
};
vector<node>element;

int findroot(int id){
    if(element[id].id==id)return id;
    element[id].id=findroot(element[id].id);
    return element[id].id;
}
void table_union(int x,int y){
    int x_id=findroot(x);
    int y_id=findroot(y);
    if(x_id==y_id)return;
    element[x_id].size+=element[y_id].size;
    element[y_id].id=x_id;
    //cout<<"      "<<findroot(x_id)<<" "<<findroot(y_id)<<'\n';
    return;      
}

int main() {
	int n, m;
	cin >> n >> m;
    element.resize(n);
    int s;
    int max_size=0;
    for(int i=0;i<n;i++){
       element[i].id=i;
       cin>>s;
       element[i].size=s;
       max_size=max(max_size,s);
    }
    int des,source;
    for(int i=0;i<m;i++){
        cin>>des>>source;             
        table_union(element[des-1].id,element[source-1].id);   
        max_size=max(max_size,element[findroot(des-1)].size);      
        cout<<max_size<<'\n';
    }

return 0;
}