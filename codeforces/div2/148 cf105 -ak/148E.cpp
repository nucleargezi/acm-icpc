#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

vc<int> conv(var a, var b) {
  int n = si(a), m = si(b);
  vc<int> f(n, 0);
  FOR(i, n) FOR(k, m) if (i + k < n) chmax(f[i + k], a[i] + b[k]);
  return f;
}

void Yorisou() {
  INT(N, M);
  vc<int> f(M + 1);
  FOR(N) {
    INT(n);
    VEC(int, a, n);
    vc<int> b(n + 1), c(n + 1);
    int s = 0;
    FOR(i, n) s += a[i], b[i + 1] = s;
    s = 0;
    FOR_R(i, n) s += a[i], c[n - i] = s;
    f = conv(f, conv(b, c));
  }
  print(QMAX(f));
}

int main() {
  Yorisou();
  return 0;
}