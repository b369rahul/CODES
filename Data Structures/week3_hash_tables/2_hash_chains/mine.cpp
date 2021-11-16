#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Query {
    Query(string st): s(st),next(nullptr) {}
    string s;
    Query* next;
};

class QueryProcessor {
    int bucket_count;
    vector<Query*>queries;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}

    void processQueries() {
    int n;
    cin >> n;
    queries.resize(bucket_count,nullptr);
    for (int i = 0; i < n; ++i){
    string type,str;int ind;
    cin>>type;
    if(type=="add" || type=="del" || type=="find"){
    cin>>str;
    int hv = hash_func(str);
    //cout<<" "<<hv<<endl;
    Query*qv=queries[hv];
    if(qv==nullptr){
        
      //  cout<<"$$NULL"<<endl;

        if(type=="find"){cout<<"no"<<endl; continue;}
        if(type=="del")continue;
        if(type=="add"){
            Query* nq= new Query(str);
            queries[hv]=nq;continue;
        }
    }
    else if(qv->next==nullptr){

       // cout<<"###"<<endl;

        if(type=="find"){
            if(qv->s==str){cout<<"yes"<<endl;continue;}
            else {cout<<"no"<<endl;continue;}
        }
        if(type=="del"){
            if(qv->s==str){queries[hv]=nullptr;continue;}
            else continue;
        }
        if(type=="add"){
            if(qv->s==str)continue;
            else{
                Query * nq=new Query(str);
                nq->next=queries[hv];
                queries[hv]=nq;
                continue;
            }
        }
    }
    else{
       // cout<<"@@@"<<endl;

        if(qv->s==str){
            if(type=="find"){cout<<"yes"<<endl;continue;}
            if(type=="del"){queries[hv]=qv->next;continue;}
            if(type=="add")continue;
        }
        else{
        while(qv->next->next!=nullptr && qv->next->s!=str){
            qv=qv->next;
        }
        if(qv->next->s==str){
            if(type=="find"){cout<<"yes"<<endl;continue;}
            if(type=="del"){qv->next=qv->next->next;continue;}
            if(type=="add")continue;
        }
        else{
            if(type=="find"){cout<<"no"<<endl;continue;}
            if(type=="del")continue;
            if(type=="add"){
                Query *nq=new Query(str);
                nq->next=queries[hv];
                queries[hv]=nq;
                continue;
            }
        }}
    }
    }
    else if(type=="check"){
        cin>>ind;
        if(queries[ind]==nullptr){cout<<endl;continue;}
        else if(queries[ind]->next==nullptr){cout<<queries[ind]->s<<endl;continue;}
        else{//cout<<"####";
        Query * qv= queries[ind];
        cout<<queries[ind]->s<<" ";
        while(qv->next!=nullptr){
            cout<<qv->next->s<<" ";
            qv=qv->next;
        }
        cout<<endl;continue;
        }
    }
    }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
