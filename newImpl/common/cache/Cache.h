#include <map>
#include <vector>
#include <utility>
#include<iostream>
#include<algorithm>

using namespace std;

class Cache {
  private:
    map<int, vector<pair<int, int>>> data;

  public:
    Cache(){ }
    ~Cache(){ }

    int size() {
      return data.size();
    }

    void Sort() {
      for(auto & entry : data)
      {
        std::sort(entry.second.begin(), entry.second.end(),
            [](const pair<int, int>& p1, const pair<int, int>& p2)->bool {
              return p1.second > p2.second;
            });
      }
    }

    //Inserts the ints with ints of all possible overlap
    void put(const int& a, const int& b, const int& value) {
      data[a].push_back(make_pair(b, value));
    }

    //Returns the cached value for a to b.
    pair<int, pair<int, int>> get() {
      pair<int, pair<int, int>> p = make_pair(-1, make_pair(-1, -1));

      for(auto & entry : data) {
         if(entry.second.front().second > p.second.second) {
           p = make_pair(entry.first, entry.second.front());
         }
      }
      return p;
    }

    void insertNewOverlap(const int& a, const int& b, const int& ab) {
      /*
       *Remove entry key "a" from map
       *Replace entry key "b" with "ab"
       *Remove entry key "b"
       *Replace "a" with "ab" througout the value vectors
       *Remove entry where "b" points to "a"
       */
      data.erase(a);

      auto it = data.find(b);
      if(it != data.end()) {
        //data[ab] = std::move(data[b]);
        //data.erase(b);

        for(auto it = data[ab].begin(); it != data[ab].end(); ++it) {
          if(it->first == a) {
            data[ab].erase(it);
            --it;
          }
        }
      //std::remove_if(data[ab].begin(), data[ab].end(), [&](const pair<int, int> &entry)->bool{ return (entry.first == a); });
      }

      for (auto & entry : data) {
        if (entry.first != ab) {
          for(auto it = entry.second.begin(); it != entry.second.end(); ++it){
            if(it->first == b){
              entry.second.erase(it);
              --it;
            }
          }
          for (auto & v : entry.second) {
            if (v.first == a)
              v.first = ab;
          }
        }
      }
    }

    friend ostream& operator<<(ostream& os, Cache& cache) {
      for(auto& entry : cache.data) {
        os << entry.first << endl;
        for(auto& v : entry.second) {
          os << "\t" << v.first << " -- " << v.second << endl;
        }
      }
      return os;
    }

};
