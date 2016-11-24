#include <bits/stdc++.h>
using namespace std;
using std::vector;

double get_optimal_value(int capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;

  vector<pair <double , int > > v;

  for (int i = 0 ; i < weights.size() ; ++i)
        v.push_back(make_pair((double)values[i]/weights[i] , i) );

  sort(v.rbegin() , v.rend());

  for (int i = 0 ; i < weights.size() ; ++i)
      {
      //      cout << weights[v[i].second] << endl;
            if (capacity-weights[v[i].second] >= 0){
                  value+=values[v[i].second];
                  capacity -= weights[v[i].second];
                }

            else if (capacity > 0 )
                {
                      while (capacity > 0)
                      {
                          value+=v[i].first;
                          --capacity;
                      }
                      break;
                }

        //        cout << value << " " << capacity << endl;
      }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
//  cout <<<< endl;
  std::cout << optimal_value << std::endl;
  return 0;
}
