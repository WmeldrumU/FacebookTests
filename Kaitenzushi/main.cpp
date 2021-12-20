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
  deque<int>::iterator it;
  int dishes_eaten = 0;
  set<int> lookupSet;
  
  for (int i = 0; i < N; i++) { //loop through Conveyor Belt (D)
    int item = D[i];
    
    
    if (lookupSet.count(item) == 0) { //if not in queue
      if (dq.size() == K)  {
        lookupSet.erase(dq.back());
        dq.pop_back();
      }
      
      
      dq.push_front(item);
      lookupSet.insert(item);
      dishes_eaten++;
    }
  }
  return dishes_eaten;
}