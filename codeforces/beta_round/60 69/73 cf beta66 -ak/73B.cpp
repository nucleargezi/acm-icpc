#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
  return pair{-a.se, a.fi} < pair{-b.se, b.fi};
}
void Yorisou() {
  INT(N);
  map<string, int> m;
  FOR(N) {
    STR(s);
    INT(x);
    m[s] += x;
  }
  INT(M);
  VEC(int, b, M);
  sort(b, greater());
  b.resize(N, 0);
  STR(s);
  int sc = m[s];
  m.erase(s);
  vector<pair<string, int>> v{m.begin(), m.end()};
  sort(v, cmp);
  vector rv = reversed(v);
  
  int best = binary_search([&](int cnt) -> bool {
    FOR(i, cnt, N - 1)
      if (not cmp({s, sc + b[0]}, {v[i].fi, v[i].se + b[N - i - 1 + cnt]})) 
        return false;
    return true;
  }, N - 1, -1) + 1;
  int worst = N - binary_search([&](int cnt) -> bool {
    FOR(i, cnt, N - 1) 
      if (cmp({s, sc + b[N - 1]}, {rv[i].fi, rv[i].se + b[i - cnt]}))
        return false;
    return true;
  }, N - 1, -1);
  print(best, worst);
}
#include "YRS/Z_H/main.hpp"