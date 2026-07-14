#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"

ll pw(ll a, ll b) {
  static constexpr int p = 1'000'000'000 + 7;
  ll s = 1;
  for (; b; b >>= 1, a = a * a % p) {
    if (b & 1) s = s * a % p;
  }
  return s;
}

void Yorisou() {
  INT(N, M, K);
  dsu g(N);
  FOR(l, N - K + 1) FOR(i, l, l + K) {
    g.merge(i, l + K + l - 1 - i);
  }
  print(pw(M, g.c));
}

int main() {
  Yorisou();
  return 0;
}