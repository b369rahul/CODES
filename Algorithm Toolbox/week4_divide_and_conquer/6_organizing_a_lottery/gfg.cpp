#include<bits/stdc++.h>
using namespace std;
 
// Function to print an array
void PrintArray(int n,int arr[])
{
     for(int i = 0; i < n; i++)
     {
         cout<<arr[i]<<" ";
     }
}
 
// Function prints number of segments
// covering by each points
void NumberOfSegments(vector<pair<int,int> >segments,
                      vector<int>points, int s, int p)
{
   vector< pair<int, int> >pts, seg;
     
   // Pushing points and index in
   // vector as a pairs
   for(int i = 0; i < p; i++)
   {
      pts.push_back({points[i], i});;
   }
     
   for(int i = 0; i < s; i++)
   {
      // (l,+1)
      seg.push_back({segments[i].first, 1});
      // (r+1,-1)
      seg.push_back({segments[i].second+1, -1});
   }
     
   // Sort the vectors
   sort(seg.begin(), seg.end(),
        greater<pair<int,int>>());
   sort(pts.begin(),pts.end());
     
   int count = 0;
   int ans[p];
     
   for(int i = 0; i < p; i++)
   {
        int x = pts[i].first;
        
        while(!seg.empty() &&
              seg.back().first <= x)
        {
            count+= seg.back().second;
            seg.pop_back();
        }
        ans[pts[i].second] = count;
   }
     
   // Print the answer
   PrintArray(p, ans);
   
}
 
//Driver code
int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  vector<pair<int,int>> seg(n);
  for(int i=0;i<n;++i){
    seg[i].first=starts[i];
    seg[i].second=ends[i];
  }
  //use fast_count_segments
  NumberOfSegments(seg, points,n,m);
  

  return 0;
}

