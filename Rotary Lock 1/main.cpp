#include <bits/stdc++.h>

using namespace std;

//forward declarations
long long getMinCodeEntryTime(int N, int M, vector<int> C);


int main() {
    int N = 5;
    int M = 5;
    vector<int> C = {1, 2 ,3 ,4, 5};

    cout << getMinCodeEntryTime(N, M, C) << endl;

    return 0;
}


long long getMinCodeEntryTime(int N, int M, vector<int> C) {
  // Write your code here
  long long time_taken = 0;
  int pointing_to = 1;
  for (int i = 0; i < M; i++) {
    int current_element = C[i];
    
    if ( pointing_to != current_element) {
      int abs_dist = abs(current_element - pointing_to);
      
      time_taken += min(abs_dist, N- abs_dist);  
      pointing_to = current_element;
    }
    
  }
  return time_taken;
}