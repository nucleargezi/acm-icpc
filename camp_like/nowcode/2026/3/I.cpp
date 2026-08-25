#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using T = array<array<array<array<ll, 2>, 2>, 2>, 2>;
void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  ll s = 0;
  FOR(i, 1, N) s += abs(a[i] - a[i - 1]);
  ll rs = s;
  
  vc<T> L(N);
  FOR(i, N) FOR(j, 2) FOR(k, 2) FOR(c, 2) FOR(d, 2) L[i][j][k][c][d] = -inf<ll> / 16;
  FOR(i, 1, N - 1) {
    ll dt = abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]);
    FOR(x, 2) FOR(y, 2) FOR(c, 2) FOR(d, 2) {
      chmax(L[i][x][y][c][d], (x ? -1 : 1) * a[i - 1] +
                                    (y ? -1 : 1) * a[i + 1] +
                                    (c ? -1 : 1) * a[i] + 
                                    (d ? -1 : 1) * a[i] - 
                                    dt);
    }
  }
  Z R(L);
  FOR(i, 2, N - 1) chmax(L[i], L[i - 1]);
  FOR_R(i, 1, N - 2) chmax(R[i], R[i + 1]);
  FOR(i, 1, N - 1) {
    s -= abs(a[i] - a[i - 1]);
    s -= abs(a[i] - a[i + 1]);
    ll g = 0;
    FOR(k, 2) FOR(j, 2) FOR(c, 2) FOR(d, 2) {
      if (i - 2 > 0) {
        ll ad = L[i - 2][k][j][c][d] + 
               (k ? a[i] : -a[i]) + 
               (j ? a[i] : -a[i]) +
               (c ? a[i - 1] : -a[i - 1]) + 
               (d ? a[i + 1] : -a[i + 1]);
        chmax(g, ad);
      }
      if (i + 2 < N - 1) {
        ll ad = R[i + 2][k][j][c][d] + 
               (k ? a[i] : -a[i]) + 
               (j ? a[i] : -a[i]) +
               (c ? a[i - 1] : -a[i - 1]) + 
               (d ? a[i + 1] : -a[i + 1]);
        chmax(g, ad);
      }
    }
    chmax(rs, s + g);
    s += abs(a[i] - a[i - 1]);
    s += abs(a[i] - a[i + 1]);
  }
  Z sp = [&](int i, int k) {
    if (i) s -= abs(a[i - 1] - a[i]);
    if (i + 1 < N) s -= abs(a[i + 1] - a[i]);
    if (k) s -= abs(a[k - 1] - a[k]);
    if (k + 1 < N) s -= abs(a[k + 1] - a[k]);
    swap(a[i], a[k]);
    if (i) s += abs(a[i - 1] - a[i]);
    if (i + 1 < N) s += abs(a[i + 1] - a[i]);
    if (k) s += abs(a[k - 1] - a[k]);
    if (k + 1 < N) s += abs(a[k + 1] - a[k]);
  };
  FOR(i, 1, N) {
    sp(0, i);
    chmax(rs, s);
    sp(0, i);
  }
  FOR(i, N - 1) {
    sp(i, N - 1);
    chmax(rs, s);
    sp(i, N - 1);
  }
  FOR(i, N - 1) {
    sp(i, i + 1);
    chmax(rs, s);
    sp(i, i + 1);
  }
  print(rs);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}