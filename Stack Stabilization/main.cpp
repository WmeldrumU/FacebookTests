#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

// forward declarations
int getMinimumDeflatedDiscCount(int N, vector<int> R);

int main()
{
  int N = 5;
  vector<int> R = {5,4,3,2,1};

  cout << getMinimumDeflatedDiscCount(N, R) << endl;

  return 0;
}

/**
 * Looks at two adjacent elements at a time, sliding from "bottom" to 
 * "top" of the stack. Deflates the upper disc if it is >= than the one below it.
 * @param  {int} N         : Size of R
 * @param  {vector<int>} R : Stack
 * @return {int}           : -1 if not possible, otherwise returns # of deflations needed
 */
int getMinimumDeflatedDiscCount(int N, vector<int> R) {
  // Write your code here
  int num_deflations = 0;
  for (int i = 0; i < N - 1; i++) {
    int below = R[N -1 -i];
    int above = R[N-2 -i ];
    cout << "above: " << above << endl;
      cout << "below: " << below << "\n" << endl;
    
    if (above >= below) {
      
      if (below -1 < 1)
        return -1;
      R.at(N -2 -i) = below -1;
      
      num_deflations++;
    }
    
    
  }
  return num_deflations;
}