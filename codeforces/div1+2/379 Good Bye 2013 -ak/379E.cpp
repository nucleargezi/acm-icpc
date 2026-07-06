#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

using re = ld;
constexpr re eps = 1e-12;

struct seg {
  re l, r;
  int id;
};

void Yorisou() {
  INT(N, K);
  RET(re, y, N, K + 1);
  vc<re> rs(N);
  
  FOR(k, K) {
    vc<seg> a;
    Z ke = [&](int i, re x) { return y[i][k] + (y[i][k + 1] - y[i][k]) * x; };
    FOR(i, N) {
      if (a.empty()) {
        rs[i] += (y[i][k] + y[i][k + 1]) / 2;
        a.ep(0, 1, i);
        continue;
      }
      vc<seg> q;
      Z ad = [&](re l, re r, int id) {
        if (r - l <= eps) return;
        if (not q.empty() and q.back().id == id and
            abs(q.back().r - l) <= eps) {
          q.back().r = r;
        } else {
          q.ep(l, r, id);
        }
      };

      for (var [l, r, k] : a) {
        re dl = ke(i, l) - ke(k, l), dr = ke(i, r) - ke(k, r);
        if (dl <= 0 and dr <= 0) {
          ad(l, r, k);
        } else if (dl >= 0 and dr >= 0) {
          ad(l, r, i);
          rs[i] += (dl + dr) * (r - l) / 2;
        } else {
          re x = l - dl * (r - l) / (dr - dl);
          chmax(x, l), chmin(x, r);
          if (dl > 0) {
            ad(l, x, i), ad(x, r, k);
            rs[i] += dl * (x - l) / 2;
          } else {
            ad(l, x, k), ad(x, r, i);
            rs[i] += dr * (r - x) / 2;
          }
        }
      }
      a.swap(q);
    }
  }
  setp(12);
  for (var x : rs) print(x);
}

int main() {
  Yorisou();
  return 0;
}