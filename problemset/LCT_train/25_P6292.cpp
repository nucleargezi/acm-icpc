#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/string/range_dis_substr.hpp"

// #define tests
#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  const int N = len(s);
  for (char &c : s) c -= 'a';
  range_dis_substr g(s);
  INT(Q);
  VEC(PII, q, Q);
  vector<int> in(N);
  for (Z [x, y] : q) ++in[y - 1];
  FOR(i, N) g.v[i].reserve(in[i]);
  for (Z [l, r] : q) {
    --l;
    g.add(l, r);
  }
  for (ll x : g.keis()) print(x);
}
#include "YRS/Z_H/main.hpp"