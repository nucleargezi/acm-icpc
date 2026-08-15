#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

struct Seg {
  int N, n, sz;
  vc<ll> a;
  void upd(int i) { a[i] = a[i << 1] + a[i << 1 | 1]; }
  Seg(const vc<int> &v) : N(v.size()) {
    for (n = 0; 1 << n < N; ++n);
    sz = 1 << n;
    a.assign(sz << 1, 0);
    FOR(i, N) a[i + sz] = v[i];
    FOR_R(i, 1, sz) upd(i);
  }
  void add(int i, int x) {
    for (a[i += sz] += x; i >>= 1;) upd(i);
  }
  ll prod(int l, int r) {
    ll s = 0;
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if (l & 1) s += a[l++];
      if (r & 1) s += a[--r];
    }
    return s;
  }
};

void Yorisou() {
  int N, Q;
  IN(N, Q);
  vc<int> a(N);
  IN(a);

  Seg seg(a);
  FOR(Q) {
    int op, i, x, l, r;
    IN(op);
    if (op == 1) IN(i, x), seg.add(i - 1, x);
    else IN(l, r), print(seg.prod(l - 1, r));
  }
}

int main() {
  Yorisou();
  return 0;
}