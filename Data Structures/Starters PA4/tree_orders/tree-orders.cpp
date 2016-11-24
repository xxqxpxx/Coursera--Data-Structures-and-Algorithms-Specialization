#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector<int> key;
  vector<int> left;
  vector<int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void in(int x) {

        if (x == -1)
          return;

      in(left[x]);
      cout << key[x]  << " " ;
      in(right[x]);

  }

   void pre(int x) {

        if (x == -1)
          return;

        cout << key[x]  << " " ;
      pre(left[x]);
      pre(right[x]);

  }

   void post(int x) {

        if (x == -1)
          return;


      post(left[x]);
      post(right[x]);
      cout << key[x]  << " " ;

  }

  vector<int> in_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that

    in(0);
    cout << endl;
    pre(0);
    cout << endl;
    post(0);

    return result;
  }

  vector<int> pre_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that

    return result;
  }

  vector<int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that

    return result;
  }
};

void print(vector<int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  t.in(0);
  cout << endl;
  t.pre(0);
  cout << endl;
  t.post(0);
  return 0;
}
