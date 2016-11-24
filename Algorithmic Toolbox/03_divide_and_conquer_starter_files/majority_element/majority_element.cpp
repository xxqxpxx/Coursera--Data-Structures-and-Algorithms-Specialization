#include <bits/stdc++.h>

using namespace std;
using std::vector;

/*
if (boundary conditions)
   return appropriately;
mid = left + (right-left) / 2
majorLeft = getMajorityElement(...);
majorRight = getMajorityElement(...);
// if left and right elements obtained above are equal, return it.
// figure which one of the two occurs greater than mid+1 and return it.

To solve it using divide-and-conquer split the input array A into two halves.
 It is not difficult to see that if x is the majority element of A, then it is also the majority element in at least one of the halves.
 */



int main() {
  int n , max = 0;
  std::cin >> n;
  vector<int> a(n);
  unordered_map<int,int> arr;
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
    arr[a[i]]++;

    if (max < arr[a[i]] )
        max = arr[a[i]];
  }

  if (max > n/2)
      cout << 1 << endl;
else
    cout << 0 << endl;
    return 0 ;
}
