#include <iostream>
#include <algorithm>

using namespace std;

//forward declarations
int getArtisticPhotographCount(int N, string C, int X, int Y);


int main() {
    cout << getArtisticPhotographCount(5, "APABA", 1, 2) << endl;

    return 0;
}


int getArtisticPhotographCount(int N, string C, int X, int Y) {
  // Write your code here
  int max_window_size = 2*Y;
  int num_valid_photos = 0;
  for (int h = 0; h <2; h++) { //loop for forward and reverse search
  for (int i = 0 ; i < C.size(); i++) { //loop for finding P
    if (C[i] != 'P')
      continue;
    char p = C[i];
    for (int j = i; j < C.size() || j < max_window_size; j++) { //loop for finding B, breaks if distance between P and B is 2*Y
      if (C[j] != 'B')
        continue;
       char b = C[j];
      
      for (int k = i; k < j; k++) { //find A between P and B
        char current = C[k];
        bool pa_dist_valid = (k - i) <= Y && (k-i) >= X; //checks if A is within range of P
        bool ab_dist_valid = (j - k) <= Y && (j-k) >= X; //checks if A is within range of B
        if ( current == 'A' &&  pa_dist_valid && ab_dist_valid)
          num_valid_photos++;
      }
    }
  }
  reverse(C.begin(), C.end());
  }
  return num_valid_photos;
}