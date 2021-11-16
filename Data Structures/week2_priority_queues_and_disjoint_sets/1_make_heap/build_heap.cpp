#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
#define int long long

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  void shiftdown(int i){
    int n=data_.size();
    while(2*i+1<n){
      if(2*i+2>=n){
        if(data_[2*i+1]>=data_[i])break;
        else{
        int temp=data_[2*i+1];
        data_[2*i+1]=data_[i];
        data_[i]=temp;
        swaps_.push_back(make_pair(i,2*i+1));
        //cout<<i<<" "<<2*i+1<<'\n';
        i=2*i+1;}
      }
      else if(data_[2*i+1]<=data_[2*i+2] && data_[2*i+1]<data_[i]){
        int temp=data_[2*i+1];
        data_[2*i+1]=data_[i];
        data_[i]=temp;
        //cout<<i<<" "<<2*i+1<<'\n';
        swaps_.push_back(make_pair(i,2*i+1));
        i=2*i+1;
      }
      
      else if(data_[2*i+1]>data_[2*i+2] && data_[2*i+2]<data_[i]){
        int temp=data_[2*i+2];
        data_[2*i+2]=data_[i];
        data_[i]=temp;
        //cout<<i<<" "<<2*i+1<<'\n';
        swaps_.push_back(make_pair(i,2*i+2));
        i=2*i+2;
      }
      else break;
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    for (int i = data_.size()/2; i>=0; --i){
        shiftdown(i);//cout<<"CHALA"<<'\n';
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int32_t main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
