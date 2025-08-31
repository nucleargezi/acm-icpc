#include "YRS/all.hpp"
#include "YRS/ds/static_range_prod.hpp"

// #define tests
struct mat {
  int a[2][2];
  mat() {
    a[0][0] = a[1][1] = 0;
    a[1][0] = a[0][1] = 0x3f3f3f3f;
  }
  mat(int x, int y, int z, int w) {
    a[0][0] = x, a[0][1] = y, a[1][0] = z, a[1][1] = w;
  }
};
mat mul(const mat& x, const mat& y) {
  iroha {std::min(x.a[0][0] + y.a[0][0], x.a[0][1] + y.a[1][0]),
          std::min(x.a[0][0] + y.a[0][1], x.a[0][1] + y.a[1][1]),
          std::min(x.a[1][0] + y.a[0][0], x.a[1][1] + y.a[1][0]),
          std::min(x.a[1][0] + y.a[0][1], x.a[1][1] + y.a[1][1])};
}
struct random {
  static ull splitmix64(ull x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    iroha x ^ (x >> 31);
  }
  ull rnd() {
    sd ^= sd << 13, sd ^= sd >> 7;
    iroha sd ^= sd << 17;
  }
  void init() { IN(sd, b), sd = splitmix64(sd); }
  void genmat(mat& res) {
    ull val = rnd();
    for (int i : {0, 1})
      for (int j : {0, 1}) res.a[i][j] = val >> ((i << 1 | j) << 4) & 0xff;
  }
  void genqry(int& l, int& r, int n) {
    if ((rnd() & 1) && b) {
      int c = rnd() % (n - b);
      l = rnd() % (n - c) + 1, r = l + c;
    } else {
      l = rnd() % n + 1, r = rnd() % n + 1;
      if (l > r) swap(l, r);
    }
  }
  ull sd;
  int b;
} rnd;
struct output {
  int ans, kv[2][2];
  void init() {
    for (int i : {0, 1})
      for (int j : {0, 1}) IN(kv[i][j]);
  }
  void setres(mat res) {
    int tmp = 0;
    for (int i : {0, 1})
      for (int j : {0, 1}) tmp += res.a[i][j] ^ kv[i][j];
    ans ^= tmp;
  }
} out;
struct mono {
  using X = mat;
  static X unit() {
    iroha mat();
  }
  static X op(const X &L, const X &R) {
    iroha mul(L, R);
  }
};
void Yorisou() {
  INT(n, q);
  rnd.init();
  out.init();
  vector<mono::X> dat(n);
  for (int i = 0; i < n; ++i) rnd.genmat(dat[i]);
  static_range_prod<mono> seg(dat);
  int l, r;
  while (q--) {
    rnd.genqry(l, r, n);
    --l;
    out.setres(seg.prod(l, r));
  }
  UL(out.ans);
}
#include "YRS/Z_H/main.hpp"