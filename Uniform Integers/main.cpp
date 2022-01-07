#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

// forward declarations
int getUniformIntegerCountInInterval(long long A, long long B);

int main()
{
  long long A = 1;
  long long B = 999;

  cout << getUniformIntegerCountInInterval(A, B) << endl;

  return 0;
}
/**
 * 
 * @param  {long} long : 
 * @param  {long} long : 
 * @return {int}       : 
 */
int getUniformIntegerCountInInterval(long long A, long long B) {
  // Write your code here
  int count = 0;
  
  //convert both A and B to strings
  string sA = to_string(A);
  string sB = to_string(B);
  
  int min_digits = sA.length();
  int max_digits = sB.length();
  //cout << min_digits << endl;
  //cout << max_digits << endl;
  
  string s_ones = "";
  for (long long i = min_digits; i <= max_digits; i++) { //for each digit-length
    s_ones = "";
    
    for (long long j = 0; j < i; j++) //create string of all ones, to be converted later
      s_ones.append("1");
    long long ones = stoll(s_ones); // string to long long
    long long counter = ones; // this will be a multiple of ones i.e. counter 777 where ones = 111
    
    for (int j = 0; j < 9; j++) { //loop nine times i.e. 11 thru 99
      //cout << counter << endl;
      if (counter >= A && counter <= B) //if between our pass range of A and B
        count++;
      counter += ones; // i.e. 11 becomes 22
    }
    
  }
  
  
  return count;
}