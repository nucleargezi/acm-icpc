#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  INT(K);
  constexpr int l = -inf<int>, r = -l;
  vc<T4<int>> f(K + 1, {r, l, r, l});
  f[0] = {0, 0, 0, 0};
  for (char op : s) {
    vc<T4<int>> ff(K + 1, {r, l, r, l});
    FOR(i, K + 1) {
      var [a, b, c, d] = f[i];
      if (a == r or b == l) continue;
      FOR(g, 2) {
        int k = array{i, i + 1}[g];
        if (k > K) continue;
        Z &[aa, bb, cc, dd] = ff[k];
        if ((op == 'F') ^ g) {
          chmin(aa, a - 1);
          chmax(bb, b - 1);
          chmin(cc, c + 1);
          chmax(dd, d + 1);
        } else {
          chmin(aa, c);
          chmax(bb, d);
          chmin(cc, a);
          chmax(dd, b);
        }
      }
    }
    f.swap(ff);
  }
  int rs = 0;
  FOR(i, K + 1) if ((i & 1) == (K & 1)) {
    var [a, b, c, d] = f[i];
    if (a == r or b == l) continue;
    for (int x : {a, b, c, d}) chmax(rs, abs(x));
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}