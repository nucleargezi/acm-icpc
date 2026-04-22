#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

constexpr int B = 1 << 8;
struct ds {
  int of = 0;
  vc<int> a;
  multiset<int> se;
  
  ds(const vc<int> &a) : a(a), se(all(a)) { se.eb(-inf<int>); }

  int f(int x) {
    int s = *prev(se.lower_bound(x - of));
    return s == -inf<int> ? s : s + of;
  }

  int f(int i, int x) {
    i %= B;
    int v = a[i] + of;
    return v < x ? v : -inf<int>;
  }

  void upd(int x) { of += x; }

  void upd(int i, int x) {
    i %= B;
    se.extract(a[i]);
    se.eb(a[i] += x);
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
      while (l < r and (l % B)) g[l / B].upd(l++, x);
      while (l < r and (r % B)) g[r / B].upd(--r, x);
      FOR(i, l / B, r / B) g[i].upd(x);
    } else {
      int s = -inf<int>;
      while (l < r and (l % B)) chmax(s, g[l / B].f(l++, x));
      while (l < r and (r % B)) chmax(s, g[r / B].f(--r, x));
      FOR(i, l / B, r / B) chmax(s, g[i].f(x));
      print(s == -inf<int> ? -1 : s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}