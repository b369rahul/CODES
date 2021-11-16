#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

struct node{
  int val;int ind;
};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      {cin >> jobs_[i];}
   //cout<<"a";
  }
  // void swap1(int *a, int *b){
  //   int *temp;
  //   *temp=*a;
  //   *a=*b;*b=*temp;
  //   return;
  // }
  void shiftdown(vector<node>&when_free,int i){
    int num = num_workers_;
    //cout<<"sd"<<'\n';
    while(2*i+1<num){
      int f=1;
      if(2*i+2>=num){
        if(when_free[2*i+1].val>when_free[i].val)return;
        if(when_free[2*i+1].val==when_free[i].val && when_free[i].ind<when_free[2*i+1].ind){return;}
        //swap1(when_free[2*i+1].val,when_free[i].val);
        node temp=when_free[2*i+1];
        when_free[2*i+1]=when_free[i];
        when_free[i]=temp;
        //cout<<when_free[2*i+1].ind<<" "<<when_free[i].ind<<'\n';
        i=2*i+1;f=0;
      }
      else if(when_free[2*i+1].val<when_free[2*i+2].val ){
      if(when_free[2*i+1].val==when_free[i].val && when_free[i].ind<when_free[2*i+1].ind){return;}
      if(when_free[i].val<when_free[2*i+1].val)return;
        //swap1(when_free[2*i+2].val,when_free[i].val);
        node temp=when_free[2*i+1];
        when_free[2*i+1].ind=when_free[i].ind;
        when_free[2*i+1].val=when_free[i].val;
        when_free[i]=temp;
        i=2*i+1;f=0; 
      }
      else if(when_free[2*i+2].val<when_free[2*i+1].val ){
      if(when_free[2*i+2].val==when_free[i].val && when_free[i].ind<when_free[2*i+2].ind){return;}
      if(when_free[i].val<when_free[2*i+2].val)return;
        //swap1(when_free[2*i+2].val,when_free[i].val);
        node temp=when_free[2*i+2];
        when_free[2*i+2].ind=when_free[i].ind;
        when_free[2*i+2].val=when_free[i].val;
        when_free[i]=temp;
        i=2*i+2;f=0; 
      }
      //
      else if(when_free[2*i+2].val==when_free[2*i+1].val && when_free[2*i+1].ind>when_free[2*i+2].ind ){
        if(when_free[2*i+2].val>when_free[i].val )return;
        if(when_free[2*i+2].val==when_free[i].val && when_free[i].ind<when_free[2*i+2].ind){return;}
        node temp=when_free[2*i+2];
        when_free[2*i+2]=when_free[i];
        when_free[i]=temp;
        i=2*i+2;f=0;
      }
      
      else if(when_free[2*i+1].val==when_free[2*i+2].val &&  when_free[2*i+2].ind>when_free[2*i+1].ind ){
        if(when_free[2*i+1].val>when_free[i].val )return;
        if(when_free[2*i+1].val==when_free[i].val && when_free[i].ind<when_free[2*i+1].ind){return;}
        node temp=when_free[2*i+1];
        when_free[2*i+1]=when_free[i];
        when_free[i]=temp;
        i=2*i+1;f=0;
      }
      //
      // else if(when_free[2*i+2].val==when_free[2*i+1].val && when_free[2*i+2].ind>when_free[2*i+1].ind && when_free[i].ind>when_free[2*i+1].ind  ){
      //   node temp=when_free[2*i+1];
      //   when_free[2*i+1]=when_free[i];
      //   when_free[i]=temp;
      //   i=2*i+1;
      // }
      // else if(when_free[2*i+2].val==when_free[2*i+1].val && when_free[2*i+1].ind>when_free[2*i+2].ind && when_free[i].val>=when_free[2*i+2].val  ){
      //   node temp=when_free[2*i+2];
      //   when_free[2*i+2]=when_free[i];
      //   when_free[i]=temp;
      //   i=2*i+2;
      // }
      else break;
    }
  }
  void buildh(vector<node>&when_free){
    //cout<<"bh"<<'\n';
    for(int i=num_workers_/2;i>=0;--i){
      shiftdown(when_free,i);
    }
  }

  void AssignJobs() {
    //cout<<"DFs";
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    if(jobs_.size()<=num_workers_){
      for (int j = 0; j < jobs_.size(); ++j){
      start_times_[j]=0;
      assigned_workers_[j]=j;
    }  return;
    }//cout<<"fds";
    for (int j = 0; j < num_workers_; ++j){
      start_times_[j]=0;
      assigned_workers_[j]=j;
    }//cout<<"SDfds";
    vector<node>when_free(num_workers_);
    for (int j = 0; j < num_workers_; ++j){
      when_free[j].ind=j;
      when_free[j].val=jobs_[j];
    }
    buildh(when_free);
    for(int i=num_workers_;i<jobs_.size();++i){
      start_times_[i]=when_free[0].val;
      assigned_workers_[i]=when_free[0].ind;
      when_free[0].val+=jobs_[i];
      shiftdown(when_free,0);
    }
  }
 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int32_t main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
