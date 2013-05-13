//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 10684
// Description: Looking for the maximum winning streak is the same as the
// maximum vector in an array. I found it and if it was greater than zero you
// had a winning streak and if it was not then it was a losing streak. I
// changed the output of your code in the code library.
//*****************************************************************************

#include <iostream>
#include <cassert>

using namespace std;

int vecsum(int v[], int n, int &start, int &end)
{
  int maxval = 0;
  int max_end = 0;
  int max_end_start, max_end_end;
  int i;

  start = max_end_start = 0;
  end = max_end_end = -1;
  for (i = 0; i < n; i++) {
    if (v[i] + max_end >= 0) {
      max_end = v[i] + max_end;
      max_end_end = i;
    } else {
      max_end_start = i+1;
      max_end_end = -1;
      max_end = 0;
    }

    if (maxval < max_end) {
      start = max_end_start;
      end = max_end_end;
      maxval = max_end;
    } else if (maxval == max_end) {
      /* put whatever preferences we have for a tie */
      /* eg. longest subvector, and then the one that starts the earliest */
      if (max_end_end - max_end_start > end - start ||
          (max_end_end - max_end_start == end - start &&
           max_end_start < start)) {
        start = max_end_start;
        end = max_end_end;
        maxval = max_end;
      }
    }
  }
  return maxval;
}

int main(void)
{
  int n;
  int *v;
  int i;
  int sum, start, end;

  while (cin >> n && n > 0) {
    v = new int[n];
    assert(v);
    for (i = 0; i < n; i++) {
      cin >> v[i];
    }
    sum = vecsum(v, n, start, end);
    if(sum > 0) {
       cout << "The maximum winning streak is " << sum << "." << endl;
    } else {
       cout << "Losing streak." << endl;
    }

    delete[] v;
  }

  return 0;
}
