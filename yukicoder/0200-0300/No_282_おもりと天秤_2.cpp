#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  int sz = 1;
  while (sz < N) sz <<= 1;
  vc<int> a(sz);
  FOR(i, N) a[i] = i + 1;
  FOR(k, 2, sz + 1, k) {
    for (int j = k >> 1; j > 0; j >>= 1) {
      vc<T3<int>> st;
      FOR(i, sz) {
        int l = i ^ j;
        if (l <= i) continue;
        bool o = (i & k) == 0;
        int x = a[i], y = a[l];
        if (x == 0 and y == 0) continue;
        if (x == 0 or y == 0) {
          bool sp = 0;
          if (o) {
            if (x != 0 and y == 0) sp = 1;
          } else {
            if (x == 0 and y != 0) sp = 1;
          }
          if (sp) swap(a[i], a[l]);
        } else {
          st.ep(i, l, o);
        }
      }
      if (not st.empty()) {
        put("?");
        for (Z [x, y, o] : st) put(' ', a[x], ' ', a[y]);
        FOR(i, si(st), N) put(" 0 0");
        cout << endl;
        VEC(char, res, N);
        FOR(i, N) {
          Z [x, y, o] = st[i];
          if (o) {
            if (res[i] == '>') swap(a[x], a[y]);
          } else {
            if (res[i] == '<') swap(a[x], a[y]);
          }
        }
      }
    }
  }
  put("!");
  FOR(i, sz) if (a[i] != 0) put(' ', a[i]);
  cout << endl;
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"