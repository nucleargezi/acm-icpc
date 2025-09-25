#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  int x = 0, y = 0;
  map<string, int> c;
  map<string, set<string>> se;
  string s;
  while (IN(s)) {
    vector<int> ed;
    const int N = len(s);
    FOR(i, N) if (s[i] == '\\') {
      ed.ep(i);
    }
    string fa = s.substr(0, ed[1]);
    FOR(i, 2, len(ed)) {
      se[fa].eb(s.substr(0, ed[i]));
    }
    chmax(x, len(se[fa]));
    chmax(y, ++c[fa]);
  }
  print(x, y);
}
#include "YRS/Z_H/main.hpp"