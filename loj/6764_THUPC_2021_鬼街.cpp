#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bina_alarm.hpp"

void Yorisou() {
  INT(N, Q);
  vc<vc<int>> fa(N + 1);
  FOR(i, 2, N + 1) if (fa[i].empty()) {
    FOR(k, i, N + 1, i) fa[k].ep(i);
  }

  bina_alarm<ll> a(N + 1, 32);
  ll ls = 0;
  FOR(Q) {
    LL(op, x, y);
    y ^= ls;
    if (op) {
      a.watch(fa[x], y);
    } else {
      static vc<int> buf;
      buf.clear();
      for (int e : fa[x]) {
        Z v = a.add(e, y);
        buf.insert(ed(buf), all(v));
      }
      sort(buf);
      ls = si(buf);
      for (int &x : buf) ++x;
      print(ls, buf);
    }
  }
}

int main() { Yorisou(); }