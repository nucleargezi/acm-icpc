#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

constexpr int B = 1 << 8;
struct ds {
  vc<int> a;
  int mx;
  ll s;
  
  ds(const vc<int> &a) : a(a), mx(QMAX(a)), s(SUM<ll>(a)) {}

  ll f() { return s; }

  ll f(int i) { return a[i % B]; }

  void upd() {
    if (mx <= 1) return;
    for (int &x : a) s -= x, x = sqrtl(x), s += x;
    mx = QMAX(a);
  }

  void upd(int i) {
    i %= B;
    s -= a[i];
    a[i] = sqrtl(a[i]);
    s += a[i];
  }
};
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<ds> g;
  FOR(i, 0, N, B) {
    g.ep(vc<int>{bg(a) + i, bg(a) + min(i + B, N)});
  }
  
  FOR(N) {
    INT(op, l, r, x);
    --l;
    if (op == 0) {
      while (l < r and (l % B)) g[l / B].upd(l++);
      while (l < r and (r % B)) g[r / B].upd(--r);
      FOR(i, l / B, r / B) g[i].upd();
    } else {
      ll s = 0;
      while (l < r and (l % B)) s += g[l / B].f(l++);
      while (l < r and (r % B)) s += g[r / B].f(--r);
      FOR(i, l / B, r / B) s += g[i].f();
      print(s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}