#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/SA/string_cmp.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  string s;
  VEC(string, so, N);
  vc<PII> v(N);
  FOR(i, N) {
    int l = len(s);
    s += so[i];
    v[i] = {l, len(s)};
  }
  str_cmp sa(s);
  vc<int> I(N);
  iota(all(I), 0);
  sort(I, [&](int i, int k) {
    return sa.cmp_list({v[i], v[k]}, {v[k], v[i]}) == 1;
  });
  s.clear();
  for (int i : I) s += so[i];
  print(s);
}
#include "YRS/aa/main.hpp"