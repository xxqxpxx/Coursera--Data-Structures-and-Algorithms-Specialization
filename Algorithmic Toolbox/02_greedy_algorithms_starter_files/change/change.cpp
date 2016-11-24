#include <iostream>
using namespace std;

int get_change(int m) {
  int x = 0;

  x += (m/10);
  m = m %10;

  x+=(m/5);
  m = m %5;

  x+=(m/1);
  m = m %1;

  return x;
}

int main() {
  int m;
  std::cin >> m;
//  cout << m % 10 << " " << m / 10 << endl;
  std::cout << get_change(m) << '\n';
}
