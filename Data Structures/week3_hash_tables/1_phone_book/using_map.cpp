#include <iostream>
#include <vector>
#include <string>
#include <map>
#define int long long
using namespace std;

int32_t main(){
    int n;
    string type;
    cin>>n;
    int number;
    string name;
    map<int,string> mp;
    for(int i=0;i<n;++i){
        cin>>type;
        if(type=="add"){
            cin>>number>>name;
            mp[number]=name;
        }
        else if(type=="find"){
            cin>>number;
            if(mp.find(number)!=mp.end())cout<<mp[number]<<endl;
            else cout<<"not found"<<endl;
        }
        else if(type=="del"){
            cin>>number;
            if(mp.find(number)!=mp.end())mp.erase(number);
        }
    }
}