#include <iostream>
#include <vector>
using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
   int refils=0;int trav=0;
   int i=0;int j=0;
   if((stops[0]>tank || dist-stops[stops.size()-1]>tank) && stops.size()>0)return -1;
   if(stops.size()==0 && dist>tank)return -1;
   if(stops.size()==0 && dist<=tank)return -1;
   for(int p=1;p<stops.size();p++){
       if(stops[p]-stops[p-1]>tank)return -1;
   }
   while(dist-trav>tank){
    while(stops[i]-trav<=tank && i<stops.size()-1){i++;}
    if(!(stops[i]-trav<=tank)){trav=stops[i-1];
    refils++;
    stops[i-1]=-1;}
    else if(i==stops.size()-1){
    trav=stops[i];
    refils++;
    stops[i]=-1;
    }
    //if(stops[i-1]==-1)i++;
    //if(i>=stops.size()){return -1;}
   }
    return refils;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
