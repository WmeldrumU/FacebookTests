#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

// forward declarations
int getMinProblemCount(int N, vector<int> S);

int main()
{
  int N = 5;
  vector<int> S = {1, 2, 3, 4, 5};

  cout << getMinProblemCount(N, S) << endl;

  return 0;
}

///
/**
 * S can be broken down with all 2's and two 1's, if there is an odd number in S.
 * 
 * @param  {int} N         : 
 * @param  {vector<int>} S : 
 * @return {int}           : 
 */
int getMinProblemCount(int N, vector<int> S)
{
  // Write your code here

  int current, max = S[0];

  int has_odd = 0;

  for (int i = 0; i < N; i++)
  {

    current = S[i];
    if (current % 2 == 1)
      has_odd = 1;

    if (current > max)
      max = current;

    //
  }

  //subtract 2 from max to allow room for two 1's
  if (has_odd)
    max -= 2;

  return max / 2 + 2 * has_odd;
}