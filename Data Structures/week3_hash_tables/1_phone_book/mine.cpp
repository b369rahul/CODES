#include <iostream>
#include <vector>
#include <string>
#define int long long
using namespace std;

int p= 1e7+19;
int m;

struct list{
    list(string name,int number):
    next(nullptr),name(name),number(number)
    {}
    string name;
    int number;
    list* next;
};

int hash_function(int n){
    return ((n%p)%m);
}

vector<string> read_queries() {
    vector<string> result;
    int n;
    cin >> n;
    m=2*n;
    vector<list*> contacts(m,nullptr);
    string type;
    string name;
    int number;
    for (int i = 0; i < n; ++i) {
        //cout<<"#$2"<<endl;
        cin >> type;
        if (type == "add"){
            cin >> number >> name;
            int h= hash_function(number);
            if(contacts[h]==nullptr){
                list * lis = new list(name,number);
                contacts[h]=lis;
                }
            else{
                list *lis=contacts[h];
                while(lis->next!=nullptr && lis->number!=number){
                    lis=lis->next;
                }
                if(lis->number==number){
                    lis->name=name;continue;
                }
                else{
                list * lisa=new list(name,number);
                lis->next=lisa;
                }
            }
            }
        else{
            cin >> number;
            int h= hash_function(number);
            if(contacts[h]==nullptr){
                if(type=="del")continue;
                else if(type=="find")result.push_back("not found");
            }
            else{
                list * lis= contacts[h];
                if(lis->number==number){
                    if(type=="find")result.push_back(lis->name);
                    else contacts[h]=lis->next;
                }
                else{
                while(lis->next!=nullptr){
                    if(lis->next->number==number)break;
                    lis=lis->next;
                }
                if(lis->next==nullptr){
                    if(type=="find")result.push_back("not found");
                    else continue;
                }
                else if(lis->next->number==number){
                    if(type=="find")result.push_back(lis->next->name);
                    else {
                        lis->next=lis->next->next;
                    }
                }
                }
            }
        }
    }
    return result;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

int32_t main() {
    write_responses(read_queries());
    return 0;
}
