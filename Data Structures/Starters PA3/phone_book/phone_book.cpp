#include <bits/stdc++.h>

using namespace std;

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            bool was_founded = false;
            // if we already have contact with such number,
            // we should rewrite contact's name
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    contacts[j].name = queries[i].name;
                    was_founded = true;
                    break;
                }
            // otherwise, just add it
            if (!was_founded)
                contacts.push_back(queries[i]);
        } else if (queries[i].type == "del") {
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    contacts.erase(contacts.begin() + j);
                    break;
                }
        } else {
            string response = "not found";
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    response = contacts[j].name;
                    break;
                }
            result.push_back(response);
        }
    return result;
}

void solve()
{
  vector < pair <int , string > > v(10000000 , make_pair(-1 , ""));

  vector <string > res;
  int n , x ;
  string type , name ;

  cin >> n;

  for (int i = 0; i < n ; ++i)
    {
        cin >> type;
        if (type == "add")
            {
              cin >> x >> name;
              v[x] = make_pair(x , name);
            }

        else if (type == "find")
        {
          cin >> x;
          if (v[x].first != -1 )
          {
            res.push_back(v[x].second);
          }
          else
              res.push_back("not found");
        }

        else
        {
          cin >> x;
          v[x].first = -1;
        }

    }

    for (int i = 0 ; i < res.size() ; ++i)
      cout << res[i] << endl;

}
int main() {
  //  write_responses(process_queries(read_queries()));
      solve();
    return 0;
}
