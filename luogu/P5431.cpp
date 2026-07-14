#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mod_inv.hpp"

void inv_all(vc<int> &a, int P) {
  int N = si(a);
  vc<int> c(N + 1, 1);
  FOR(i, N) {
    c[i + 1] = c[i];
    if (a[i]) c[i + 1] = 1ll * c[i + 1] * a[i] % P;
  }
  int t = mod_inv(c[N], P);
  FOR_R(i, N) if (a[i]) {
    int x = a[i];
    a[i] = 1ll * c[i] * t % P, t = 1ll * t * x % P;
  }
}

void Yorisou() {
  INT(N, P, K);
  VEC(int, a, N);
  inv_all(a, P);
  int rs = 0;
  for (ll s = K; int &x : a) {
    x = x * s % P;
    s = s * K % P;
    rs += x;
    if (rs >= P) rs -= P;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}