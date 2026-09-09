#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/zeta_mobius.hpp"

void Yorisou() {
  LL(N);
  int M = sqrtl(N), K = sqrtl(N / 2);
  vc<ll> a(M + 1);
  FOR(i, 1, M + 1) {
    ll n = N / i / i, l = K / i;
    a[i] = l * (l - 1) / 2;
    FOR(k, l + 1, M / i + 1) a[i] += n / k - k;
  }
  multi_mobius(a);
  print(a[1] * 2 + (N >= 2));
}

int main() { Yorisou(); }