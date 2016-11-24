#include <iostream>

using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}


  long long  gcd(  long long   a ,   long long   b)
{
  if (b == 0)
      return a;

  return gcd(b, a % b);
}


int main() {
   long long   a, b;
  std::cin >> a >> b;

  cout << a*b/gcd(a,b) << endl;
  return 0;
}
