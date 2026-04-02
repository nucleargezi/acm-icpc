#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/hashmap.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, S);
  VEC(int, a, N);
  hash_map<vc<int>> me;
  vc<int> L(begin(a), begin(a) + N / 2), R{begin(a) + N / 2, end(a)};
  int sl = len(L);
  FOR(s, 1 << sl) {
    uint w = 0;
    FOR(i, sl) if (s >> i & 1) w += L[i];
    me[w].ep(s);
  }
  vc<vc<int>> ans;
  int sr = len(R);
  FOR(s, 1 << sr) {
    uint w = 0;
    FOR(i, sr) if (s >> i & 1) w += R[i];
    if (me.contains(S - w)) {
      for (int m : me[S - w]) {
        vc<int> v;
        FOR(i, sl) if (m >> i & 1) v.ep(i + 1);
        FOR(i, sr) if (s >> i & 1) v.ep(i + 1 + sl);
        ans.ep(v);
      }
    }
  }
  sort(ans);
  for (Z &v : ans) print(v);
}
#include "YRS/aa/main.hpp"