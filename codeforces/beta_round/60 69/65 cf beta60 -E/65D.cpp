#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  INT(N);
  STR(s);
  vector<char> a;
  for (char c : s) {
    if (c == '?') a.emplace_back(-1);
    else a.emplace_back(c == 'G' ? 0 : c == 'H' ? 1 : c == 'R' ? 2 : 3);
  }
  vector<array<int, 4>> q, nq;
  q.push_back({0, 0, 0, 0});
  for (char x : a) {
    nq.clear();
    for (Z s : q) {
      if (x == -1) {
        int mn = QMIN(s);
        FOR(i, 4) if (s[i] == mn) {
          ++s[i];
          nq.push_back(s);
          --s[i];
        }
      } else {
        ++s[x];
        nq.push_back(s);
      }
    }
    unique(nq);
    q.swap(nq);
  }
  bool vis[4]{};
  for (Z s : q) {
    int min = QMIN(s);
    FOR(i, 4) if (s[i] == min) vis[i] = 1;
  }
  string r[4]{"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};
  FOR(i, 4) if (vis[i]) print(r[i]);
}
#include "YRS/Z_H/main.hpp"