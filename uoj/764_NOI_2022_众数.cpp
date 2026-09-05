#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segd_sp.hpp"
#include "YRS/al/m/add.hpp"
#include "YRS/ds/swag.hpp"
#include "YRS/ds/basic/deque.hpp"

struct MX {
  using X = pair<int, ll>;
  static X op(X a, X b) {
    if (a.fi == b.fi) return {a.fi, a.se + b.se};
    ll d = min(a.se, b.se);
    a.se -= d, b.se -= d;
    return a.se > b.se ? a : b;
  }
  static X unit() { return {0, 0}; }
};

using X = MX::X;
using Seg = segd_sp<Add<int>>;
using np = Seg::np;

void Yorisou() {
  INT(N, Q);
  vc<deque<int>> v(N + Q);
  vc<swag_deque<MX>> q(N + Q);
  vc<np> t(N + Q);
  Seg seg(0, N + Q);
  FOR(i, N) {
    INT(sz);
    FOR(sz) {
      INT(x);
      v[i].ep(--x), q[i].ep(x, 1);
      t[i] = seg.add(t[i], x, 1);
    }
  }
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x, y);
      --x, --y;
      v[x].ep(y);
      q[x].ep(y, 1);
      t[x] = seg.add(t[x], y, 1);
    } else if (op == 2) {
      INT(x);
      --x;
      int y = v[x].back();
      v[x].pop_back();
      q[x].pop_back();
      t[x] = seg.add(t[x], y, -1);
    } else if (op == 3) {
      INT(sz);
      VEC(int, id, sz);
      X r = MX::unit();
      for (int &i : id) r = MX::op(r, q[--i].prod());
      int x = r.fi;
      ll s = 0, al = 0;
      for (int i : id) al += si(v[i]), s += seg.get(t[i], x);
      print(s * 2 > al ? x + 1 : -1);
    } else {
      INT(x, y, z);
      --x, --y, --z;
      if (si(v[x]) > si(v[y])) {
        while (si(v[y])) {
          int e = v[y].front();
          v[y].pop_front();
          v[x].ep(e);
          q[x].ep(e, 1);
        }
        seg.enum_all(t[y], [&](int i, int c) { t[x] = seg.add(t[x], i, c); });
        // seg.clear(t[y]);
        swap(t[x], t[z]);
        swap(v[x], v[z]);
        swap(q[x], q[z]);
      } else {
        while (si(v[x])) {
          int e = v[x].back();
          v[x].pop_back();
          v[y].emplace_front(e);
          q[y].emplace_front(e, 1);
        }
        seg.enum_all(t[x], [&](int i, int c) { t[y] = seg.add(t[y], i, c); });
        // seg.clear(t[x]);
        swap(t[y], t[z]);
        swap(v[y], v[z]);
        swap(q[y], q[z]);
      }
    }
  }
}

int main() { Yorisou(); }