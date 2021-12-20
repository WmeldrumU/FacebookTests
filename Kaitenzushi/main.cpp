#include <bits/stdc++.h>

using namespace std;

//forward declarations
int getMaximumEatenDishCount(int N, vector<int> D, int K);


int main() {
    int N = 0;
    vector<int> D = {};
    int K = 0;

    cout << getMaximumEatenDishCount(N, D, K) << endl;

    return 0;
}


int getMaximumEatenDishCount(int N, vector<int> D, int K) {
  // Write your code here
  deque<int> dq;
  int dishes_eaten = 0;
  set<int> lookupSet;
  
  for (int i = 0; i < N; i++) { //loop through Conveyor Belt (D)
    int item = D[i];
    
    
    if (lookupSet.count(item) == 0) { //if not eaten
      if (dq.size() == K)  { //if queue is full
        lookupSet.erase(dq.back());
        dq.pop_back();
      }
      
      
      dq.push_front(item); //update both lookupSet and dq
      lookupSet.insert(item);
      dishes_eaten++;
    }
  }
  return dishes_eaten;
}