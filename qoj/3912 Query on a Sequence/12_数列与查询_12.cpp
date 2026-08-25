#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/ds/range/range_dist_d.hpp"

struct MX {
  using X = array<M17, 3>;
  static X unit() { return {}; }
  static X op(X a, const X &b) {
    FOR(i, 3) a[i] += b[i];
    return a;
  }
  static X inv(X a) {
    FOR(i, 3) a[i] = -a[i];
    return a;
  }
  static X sing(M17 x) {
    M17 y = x * x;
    return {x, y, y * x};
  }
  static constexpr bool commute = 1;
};

struct Q {
  int op, x = 0, y = 0;
  int l = -1, r = -1, id = -1;
};

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  INT(M);
  vc<Q> qs(M);
  vc<int> cp = a, p;
  int K;
  {
    seq_offline s(N);
    for (Z &q : qs) {
      IN(q.op);
      if (q.op == 1 or q.op == 5) {
        IN(q.x, q.y);
        --q.x;
        q.l = s.get(q.x);
        q.r = s.get(q.y - 1);
      } else if (q.op == 2) {
        IN(q.x, q.y);
        --q.x;
        q.id = s.get(q.x);
        cp.ep(q.y);
      } else if (q.op == 3) {
        IN(q.x);
        --q.x;
        q.id = s.erase(q.x);
      } else {
        IN(q.x, q.y);
        q.id = s.insert(q.x);
        cp.ep(q.y);
      }
    }
    p = s.order();
    K = s.nodes();
  }
  unique(cp);
  range_dist_d<MX> ds(K, si(cp));
  vc<int> typ;
  typ.reserve(M);

  Z ins = [&](int id, int x) { ds.insert(p[id], lb(cp, x), MX::sing(x)); };
  FOR(i, N) ins(i, a[i]);
  for (var q : qs) {
    if (q.op == 1 or q.op == 5) {
      ds.prod(p[q.l], p[q.r] + 1);
      typ.ep(q.op);
    } else if (q.op == 2) {
      ds.set(p[q.id], lb(cp, q.y), MX::sing(q.y));
    } else if (q.op == 3) {
      ds.erase(p[q.id]);
    } else {
      ins(q.id, q.y);
    }
  }
  Z ans = ds.solve();
  FOR(i, si(ans)) {
    Z [cnt, b] = ans[i];
    if (typ[i] == 5) {
      print(cnt);
    } else {
      print((b[0] * b[0] * b[0] - b[0] * b[1] * 3 + b[2] * 2) / 6);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}