#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/lgv.hpp"

constexpr int P = 998244353;
void Yorisou() {
  INT(K);
  VEC(int, ns, K);
  VEC(int, ms, K - 1);
  int N = ns[0];
  vc<vc<int>> f(N, vc<int>(N));
  FOR(i, N) f[i][i] = 1;
  FOR(i, K - 1) {
    vc<vc<int>> g(ns[i + 1], vc<int>(N));
    int sz = ms[i];
    FOR(k, sz) {
      INT(a, b);
      --a, --b;
      FOR(k, N) {
        g[b][k] += f[a][k];
        if (g[b][k] >= P) g[b][k] -= P;
      }
    }
    f = std::move(g);
  }
  print(lgv(N, [&](int i, int k) { return f[k][i]; }, P));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}