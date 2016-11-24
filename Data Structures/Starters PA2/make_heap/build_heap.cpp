#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using namespace std;

class HeapBuilder {
public:
  vector<int> data_;
  vector< pair<int, int> > swaps_;
  int x = 0;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

int parent(int i )
{
  return floor((i-1)/2);
}

int left(int i )
{
  return (2 * i) + 1;
}


int right(int i )
{
  return (2 * i)  +2;
}

void siftup(int i )
{
  while ( i >= 1 && data_[parent(i)] > data_[i] )
      {
        swap (data_[parent(i)] , data_[i]);
        swaps_.push_back(make_pair(parent(i) , i));
          i = parent(i);
      }


}

void siftdown(int i)
{
//  cout << data_[i] << endl;
  int max = i;
  int l = left(i);


  if (l <= data_.size()-1 && data_[l] < data_[max])
      max = l;

      int r = right(i);

  if (r <= data_.size()-1 && data_[r] < data_[max])
    max = r;

//  cout << l << " " << r << " " << max << endl;
  if (i != max){


    swap (data_[i] , data_[max]);
    swaps_.push_back(make_pair(i, max));

    siftdown(max);
    //    siftup(max);5

  }
}

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap,
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
  }

  void build()
  {
    int n = data_.size();

    for (int i = floor(n/2) ; i >= 0 ; i--)
      siftdown (i);
  }


 public:
  void Solve() {
    ReadData();
    build();
  //  GenerateSwaps();
    WriteResponse();

  //  sortt();

  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
