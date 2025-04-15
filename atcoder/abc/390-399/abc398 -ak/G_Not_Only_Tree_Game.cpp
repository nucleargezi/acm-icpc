#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  dsu f(n), g(n << 1);
  FOR(m) {
    INT(x, y);
    f.merge(--x, --y);
    g.merge(x + n, y);
    g.merge(y + n, x);
  }
  vector<int> a(n), b(n);
  FOR(i, n) {
    int fa = f[i];
    if (g[fa] == g[i]) {
      a[fa]++;
    } else {
      b[fa]++;
    }
  }
  int q{}, aa{}, ab{}, bb{};
  FOR(i, n) {
    if (a[i] or b[i]) {
      if (a[i] + b[i] == 1) {
        ++q;
      } else {
        int x {a[i] & 1}, y {b[i] & 1};
        if (x > y) std::swap(x, y);
        if (not x and not y) {
          ++aa;
        } else if (not x) {
          ++ab;
        } else {
          ++bb;
        }
      }
    }
  }
  meion Aoki = [](bool f = true) { UL(f ? "Aoki" : "Takahashi"); };
  meion Takahashi = [](bool f = true) { UL(not f ? "Aoki" : "Takahashi"); };
  if (n & 1) {
    Aoki(m & 1);
  } else {
    if (ab == 1 or ab == 2) iroha Aoki();
    if (not ab) {
      int ls{bb - m & 1};
      if (ls) {
        Takahashi(q % 4);
      } else {
        Aoki(q % 4 == 2);
      }
    } else {
      Aoki(m & 1);
    }
  }
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}