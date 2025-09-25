#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  STR(s);
  map<string, int> m;
  INT(N);
  FOR(N) {
    STR(a, op);
    m[a];
    if (op[0] == 'p') {
      STR(_, b, __);
      pop(b), pop(b);
      m[b];
      if (a == s or b == s) m[a] += 15, m[b] += 15;
    } else if (op[0] == 'c') {
      STR(_, b, __);
      pop(b), pop(b);
      m[b];
      if (a == s or b == s) m[a] += 10, m[b] += 10;
    } else {
      STR(b, _);
      pop(b), pop(b);
      m[b];
      if (a == s or b == s) m[a] += 5, m[b] += 5;
    }
  }
  vector<pair<int, string>> v;
  for (Z &[x, c] : m) {
    if (x != s) v.ep(-c, x);
  }
  sort(v);
  for (Z &[c, s] : v) print(s);
}
#include "YRS/Z_H/main.hpp"