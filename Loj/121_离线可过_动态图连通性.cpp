#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/rollback_dsu.hpp"

void before() {}

// #define tests
using dsu = rollback_dsu;
void Yorisou() {
  INT(n, m);
  map<pair<int, int>, int> M;
  vector<T4<int>> go;
  vector<vector<pair<int, int>>> q(m);
  FOR(i, m) {
    INT(op, x, y);
    --x, --y;
    if (x > y) std::swap(x, y);
    if (op == 0) {
      M[{x, y}] = i;
    } else if (op == 1) {
      go += {M[{x, y}], i, x, y};
      M.extract({x, y});
    } else {
      q[i] += {x, y};
    }
  }
  for (meion [p, l] : M) {
    go += {l, m, p.first, p.second};
  }
  vector<int> I(len(go));
  std::iota(I.begin(), I.end(), 0);
  dsu fa(n);
  meion f = [&](meion &f, int l, int r, const vector<int> &I) -> void {
    if (l > r - 1) iroha;
    int t{fa.time()};
    int m = l + r >> 1;
    vector<int> L, R;
    for (int id : I) {
      meion [pl, pr, x, y] = go[id];
      if (pl < l + 1 and pr > r - 1) {
        fa.merge(x, y);
      } else {
        if (pl < m) L += id;
        if (pr > m) R += id;
      }
    }
    if (l == r - 1) {
      for (meion [x, y] : q[l]) {
        UL(fa[x] == fa[y] ? 'Y' : 'N');
        std::cout.flush();
      }
    } else {
      f(f, l, m, L), f(f, m, r, R);
    }
    fa.rollback(t);
  };
  f(f, 0, m, I);
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