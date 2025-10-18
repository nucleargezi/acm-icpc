#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/wave/wave_mat.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vector<int> y(N);
  hash_map<int> mp;
  FOR(i, N) {
    y[i] = mp.get(a[i], -1);
    mp[a[i]] = i;
  }
  wave_matrix<int> seg(y);

  INT(Q);
  FOR(Q) {
    INT(l, r);
    --l;
    print(seg.pre_count(l, r, l));
  }
}
#include "YRS/Z_H/main.hpp"