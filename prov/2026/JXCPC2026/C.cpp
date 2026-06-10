#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

constexpr int in = inf<int>;
using T = retsu<int>;
T ml(const T &a, const T &b) {
  int N = a.N;
  T c(N, N, in);
  FOR(i, N) FOR(j, N) FOR(k, N) chmin(c[i][j], max(a[i][k], b[k][j]));
  return c;
}
T pw(T a, ll k) {
  int N = a.N;
  T s(N, N, in);
  FOR(i, N) s[i][i] = 0;
  for (; k; k >>= 1, a = ml(a, a)) {
    if (k & 1) s = ml(s, a);
  }
  return s;
}
void Yorisou() {
  INT(N, M);
  T a(N, N, in);
  FOR(M) {
    INT(f, t);
    --f, --t;
    a[f][t] = 0;
  }
  T b = a;
  INT(K);
  VEC(PII, es, K);
  for (int i = 0; Z [f, t] : es) {
    --f, --t;
    chmin(a[f][t], ++i);
  }
  INT(Q, W);
  a = pw(a, W);
  FOR(Q) {
    INT(f, t);
    --f, --t;
    if (a[f][t] == in) print(-1);
    else print(a[f][t]);
  }
}

int main() {
  Yorisou();
  return 0;
}