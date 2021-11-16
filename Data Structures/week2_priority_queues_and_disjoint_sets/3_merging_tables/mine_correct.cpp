#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node{
    // node(node *parent,int size,int rank)    :
    // size(size),parent(parent),rank(rank)
    // {}
    int size;
    node *parent;
    // vector<node*>child;
    // int rank;
};


node* findroot(node* element){
    if(element->parent==element)return element;
    element->parent=findroot(element->parent);
    return element->parent;
}
void table_union(node *x,node *y){
    int t=0;
    node *px;node *py;
    px=findroot(x);
    py=findroot(y);
    if(px==py)return;
    px->size+=py->size;
    py->parent=px;
    return;      
}


int main() {
	int n, m;
	cin >> n >> m;
    vector<node>element(n);
    int s;
    int max_size=0;
    for(int i=0;i<n;i++){
       element[i].parent=&element[i];
       cin>>s;
       element[i].size=s;
       max_size=max(max_size,s);
    }
    int des,source;
    for(int i=0;i<m;i++){
        cin>>des>>source;              
        table_union(&element[des-1],&element[source-1]);    
        max_size=max(max_size,findroot(&element[des-1])->size);       
        cout<<max_size<<'\n';
    }

return 0;
}
