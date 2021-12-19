#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long getMaxAdditionalDinersCount(long long, long long, int, vector<long long>);

int main() {
    cout << "Hello" << endl;

    //case 1
    long long N = 10;
    long long K = 1;
    int M =  3;
    vector<long long> S = {1, 3, 5};

    cout << getMaxAdditionalDinersCount(N, K, M, S ) << endl;


    return 0;
}


long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
    
  //iterate through empty sections on row
  sort(S.begin(), S.end());
  long long left_bound = 1;
  long long right_bound = S[0];
  long long additional_seats = 0;
  
  long long range = right_bound - left_bound;
  additional_seats += range / (K + 1);
  
  //right side
  left_bound = S[M-1];
  right_bound = N;
  range = right_bound - left_bound;
  additional_seats += range / (K+1);

   long long i = 0;
   while ( i <= M-2) { //while one away from last element
      left_bound = S[i];
      right_bound = S[i+1];
        range = right_bound - left_bound -1; //i.e. r = 8, l = 5, only 6 and 7 are avail. 8 - 5 - 1 = 2 seats avail
        additional_seats += range / (2*K + 1); //2*k for space on both sides, + 1 for the seat that will be taken
      i++;
    }
  
  cout << "hello" << endl;
  return additional_seats;
}