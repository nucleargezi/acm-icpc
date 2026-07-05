#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  int n[2];
  vc<int> a[2];
  FOR(i, 2) {
    IN(n[i]);
    a[i].resize(n[i]);
    IN(a[i]);
  }

  vc<array<int, 2>> f(N, {-1, -1}), c(N, {n[0], n[1]});
  vc<PII> q;
  Z ad = [&](int i, int k, int x) {
    if (f[i][k] != -1) return;
    f[i][k] = x;
    q.ep(i, k);
  };
  ad(0, 0, 0);
  ad(0, 1, 0);
  FOR(t, si(q)) {
    Z [i, j] = q[t];
    int k = j ^ 1;
    if (f[i][j] == 0) {
      for (int x : a[k]) ad((i + N - x) % N, k, 1);
    } else {
      for (int x : a[k]) {
        int e = (i + N - x) % N;
        if (--c[e][k] == 0) ad(e, k, 0);
      }
    }
  }
  
  FOR(k, 2) {
    vc<string> bf;
    FOR(i, 1, N) {
      if (f[i][k] == -1) bf.ep("Loop");
      else if (f[i][k] == 0) bf.ep("Lose");
      else bf.ep("Win");
    }
    print(bf);
  }
}

int main() {
  Yorisou();
  return 0;
}