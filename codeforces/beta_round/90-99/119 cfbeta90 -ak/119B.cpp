#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

using re = ld;
void Yorisou() {
  INT(N, K);
  int sz = N / K;
  VEC(int, a, N);
  INT(Q);
  retsu<int> q(Q, sz);
  IN(q);
  vc<char> vis(N);
  for (int &x : q.a) vis[--x] = 1;
  re mx = -inf<re>, mn = -mx;
  FOR(i, Q) {
    re s = 0;
    FOR(k, sz) {
      s += a[q[i][k]];
    }
    chmax(mx, s / sz);
    chmin(mn, s / sz);
  }
  vc<int> st;
  FOR(i, N) if (not vis[i]) st.ep(a[i]);
  sort(st);
  if (si(st) - N % K >= sz) {
    re s = 0;
    FOR(i, sz) s += st[i];
    chmin(mn, s / sz);
    reverse(st);
    s = 0;
    FOR(i, sz) s += st[i];
    chmax(mx, s / sz);
  }
  print(mn, mx);
}

int main() {
  Yorisou();
  return 0;
}