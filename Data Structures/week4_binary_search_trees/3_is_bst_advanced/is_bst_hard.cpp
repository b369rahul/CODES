#include <algorithm>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};
vector<pair<int,int>>result;
void in_order(const vector<Node>& tree , int i){
  if(tree[i].left==-1){
    result.push_back({tree[i].key,i});
    if(tree[i].right==-1)return;
    in_order(tree,tree[i].right);
    return;
  }
  in_order(tree,tree[i].left);
  result.push_back({tree[i].key,i});

  if(tree[i].right==-1)return;
  in_order(tree,tree[i].right);
  return;
}
bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  in_order(tree,0);
  for(int i=1;i<tree.size();++i){
    //cout<<result[i+1].first<<" "<<result[i+1].second<<endl;
    if(result[i].first<result[i-1].first)return false;
    if(result[i].first==result[i-1].first && tree[result[i].second].left==result[i-1].second)return false;
  }
  return true;
}

int32_t main() {
  int nodes;
  cin >> nodes;
  if(nodes==0){
    cout << "CORRECT" << endl;
    return 0;
  }
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  result.resize(nodes);
  result.clear();
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  }
  else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
