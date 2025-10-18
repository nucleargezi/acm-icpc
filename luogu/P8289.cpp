#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
vector<string> split(const string &s) {
  vector<string> res;
  string t;
  for (char c : s) {
    if (std::isalnum(c)) t += c;
    else {
      res.ep(t);
      t.clear();
      t += c;
      res.ep(t);
      t.clear();
    }
  }
  if (not t.empty()) res.ep(t);
  return res;
}
map<string, vector<string>> mp;
map<string, int> vis;
string ext(const string &s) {
  string res;
  if (mp.contains(s) and not vis[s]) {
    ++vis[s];
    for (string &t : mp[s]) res += ext(t);
    --vis[s];
  } else {
    res += s;
  }
  return res;
}
void Yorisou() {
  INT(N);
  cin.ignore();
  string s;
  FOR(N) {
    std::getline(std::cin, s);
    if (s[0] == '#') {
      s = s.substr(1);
      vector<string> v = split(s);
      if (v[0] == "define") {
        string ad;
        vector<string> g(v.begin() + 4, v.end());
        mp[v[2]] = g;
      } else {
        mp.extract(v[2]);
      }
      print();
    } else {
      string out;
      vector<string> g = split(s);
      for (string &s : g) {
        vis.clear();
        out += ext(s);
      }
      print(out);
    }
  }
}
#include "YRS/Z_H/main.hpp"