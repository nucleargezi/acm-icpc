#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/mo/mo.hpp"

struct DS {
  int N, sz, n;
  vc<int> a, b;
  
  DS(int N) : N(N), sz(max<int>(1, sqrtl(N))), n(ceil(N, sz)), a(N), b(n) {}

  void ad(int x) { ++a[x], ++b[x / sz]; }

  void rm(int x) { --a[x], --b[x / sz]; }

  int f() {
    FOR_R(i, n) if (b[i]) {
      FOR_R(k, i * sz, min(i * sz + sz, N)) {
        if (a[k]) return k;
      }
    }
    return 0;
  }
};

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  for (int &x : a) --x;
  INT(Q);
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;

  DS B(N);
  vc<deque<int>> v(K);

  Z al = [&](int i) {
    int x = a[i];
    if (si(v[x])) B.rm(v[x].back() - v[x].front());
    v[x].emplace_front(i);
    B.ad(v[x].back() - i);
  };
  Z ar = [&](int i) {
    int x = a[i];
    if (si(v[x])) B.rm(v[x].back() - v[x].front());
    v[x].emplace_back(i);
    B.ad(i - v[x].front());
  };

  Z rl = [&](int i) {
    int x = a[i];
    B.rm(v[x].back() - v[x].front());
    v[a[i]].pop_front();
    if (si(v[x])) B.ad(v[x].back() - v[x].front());
  };
  Z rr = [&](int i) {
    int x = a[i];
    B.rm(v[x].back() - v[x].front());
    v[a[i]].pop_back();
    if (si(v[x])) B.ad(v[x].back() - v[x].front());
  };

  Mo mo(q);
  vc<int> rs(Q);
  mo.f(al, ar, rl, rr, [&](int i) { rs[i] = B.f(); });
  for (int x : rs) print(x);
}

int main() {
  Yorisou();
  return 0;
}