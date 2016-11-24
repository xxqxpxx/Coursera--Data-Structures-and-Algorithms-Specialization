#include <bits/stdc++.h>

using namespace std;

using std::vector;
using std::cin;
using std::cout;

typedef pair<long long , long long > P;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  priority_queue< P, vector<P>, greater<P> > mypq;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m , x;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      {
        cin >> jobs_[i];
      }

      for (int i = 0 ; i < num_workers_ ; ++i)
          {
              mypq.push(make_pair(0 , i));
          }
  }


    void AssignJobs1() {

      long long t = 0 , i = 0;

      while (!mypq.empty())
       {
          cout << mypq.top().second << " " << mypq.top().first << endl;
          t = mypq.top().first + jobs_[i++];
          mypq.push( make_pair( t ,  mypq.top().second   ));
          mypq.pop();

          if (i == jobs_.size())
                break;
       }
    }

 public:
  void Solve() {
    ReadData();
  //  AssignJobs();
    AssignJobs1();
//    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
