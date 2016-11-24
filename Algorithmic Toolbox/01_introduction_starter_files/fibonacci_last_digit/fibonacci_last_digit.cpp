#include <iostream>
#include <vector>

using namespace std;

vector<int> v(1000001);


int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1 , tmp ;

    for (int i = 1; i < n ; ++i) {
       tmp = current;
        current  = (current + previous) % 10;
        previous =   tmp % 10;
    }

    return current ;
}



int main() {
    int n;

    std::cin >> n;
    cout << get_fibonacci_last_digit_naive(n) << endl;

    return 0;
    }
