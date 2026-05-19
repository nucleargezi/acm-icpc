#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld_mono.hpp"

constexpr int n = 20;
struct MX {
  using X = array<int, n>;
  
  X op(const X &a, const X &b) {
    X c = unit();
    int s = 0, i = 0, k = 0;
    while (s < n and a[i] != -1 and b[k] != -1) c[s++] = (a[i] > b[k] ? a[i++] : b[k++]);
    while (s < n and a[i] != -1) c[s++] = a[i++];
    while (s < n and b[k] != -1) c[s++] = b[k++];
    return c;
  }
  
  static constexpr X unit() {
    X c{};
    c.fill(-1);
    return c;
  }

  static constexpr bool commute = 1;

  static X sing(const multiset<int> &se) {
    int t = 0;
    X c = unit();
    for (int x : views::reverse(se)) {
      if (t < n - 1) c[t++] = x;
      else break;
    }
    return c;
  }
};

void Yorisou() {
  INT(N);
  graph g(N);
  g.sc();
  hld v(g);

  vc<multiset<int>> se(N);
  INT(M);
  VEC(PII, a, M);
  for (Z &[x, i] : a) {
    --i;
    se[i].eb(x);
  }
  hld_mono<int, MX> seg(v, [&](int i) { return MX::sing(se[i]); });
  
  INT(Q, K);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(a, b);
      --a, --b;
      Z ar = seg.prod(a, b);
      int sm = 0;
      FOR(i, K) {
        if (ar[i] == -1) break;
        ++sm;
      }
      if (sm) FOR(i, sm) put(ar[i], " \n"[i + 1 == sm]);
      else print(-1);
    } else if (op == 2) {
      INT(i, t);
      --i, --t;
      Z &[w, f] = a[i];
      se[f].extract(w);
      seg.set(f, MX::sing(se[f]));
      f = t;
      se[f].eb(w);
      seg.set(f, MX::sing(se[f]));
    } else {
      INT(i, x);
      --i;
      Z &[w, f] = a[i];
      se[f].extract(w);
      seg.set(f, MX::sing(se[f]));
      w = x;
      se[f].eb(w);
      seg.set(f, MX::sing(se[f]));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}