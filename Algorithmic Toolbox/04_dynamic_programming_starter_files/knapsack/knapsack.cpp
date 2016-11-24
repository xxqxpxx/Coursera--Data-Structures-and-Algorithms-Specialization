#include <bits/stdc++.h>

using namespace std;
using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;

  for (int i = w.size()-1; i >= 0 ; --i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);

  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }

  sort(w.begin() , w.end());

  std::cout << optimal_weight(W, w) << '\n';
}
