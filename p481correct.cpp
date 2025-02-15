#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

// https://en.wikipedia.org/wiki/Longest_increasing_subsequence#Efficient_algorithms
// After processing X[i]
//  M[j]: index of smallest X[k] so there is an IS of length j ending at X[k], j<=k<=i
int longestIncreasingSubsequence(const std::vector<long> &X, std::stack<long> &S) {
  int N = (int)(X.size());
  int *P = new int[N]; // Predecessor of IS
  int *M = new int[N+1];
  
  int L = 0; // Longest subsequence observed.
  
  for(int i = 0; i < N; ++i) {
    // Binary search for the largest positive j <= L such that X[M[j]] < X[i]:
    int lo = 1;
    int hi = L;
    while(lo <= hi) {
      int mid = (lo+hi+1)/2;
      if(X[M[mid]] < X[i]) // Notice: '<' => strictly increasing.
        lo = mid+1;
      else
        hi = mid-1;
    }
    // After searching, lo is 1 greater than the length of the longest prefix of X[i]
    int newL = lo;

    // The predecessor of X[i] is the last index of the subsequence of length newL-1
    P[i] = M[newL-1];
    M[newL] = i;

    if(newL > L) // If we found a subsequence longer than any we've found yet, update L:
      L = newL;
  }

  // Reconstruct the longest increasing subsequence
  int k = M[L];
  for(int i = L-1; i >= 0; --i) {
    S.push(X[k]);
    k = P[k];
  }

  delete[] P;
  delete[] M;
  return L;
}

int main() {
  // Read input:
  std::vector<long> v;
  long n;
  // while(std::cin >> n) {
  //   v.push_back(n);
  // }
  //scanf("%ld", &n);
  // while(cin >> n) {
  //  v.push_back(n);
  // }
  // for(int i = 0; i < n; i++) {
  //   int tmp;
  //   scanf("%d", &tmp);
  //   v.push_back(tmp);
  // }

  // Compute:
  std::stack<long> s;
  int best = longestIncreasingSubsequence(v, s);

  // Output:
  std::cout << best << std::endl << '-' << std::endl;
  while(!s.empty()) {
    std::cout << s.top() << std::endl;
    s.pop();
  }

  return 0;
}