#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

int ke(ll x) {
  int s = 0;
  for (; x; x /= 10) s += x % 10 == 4 or x % 10 == 7;
  return s;
}
void Yorisou() {
  LL(a, sz);
  static constexpr int N = 1'000'000;
  vc<ll> pr(N);
  FOR(i, N) pr[i] = ke(i);
  Z ke = [&](int x) { return pr[x % N] + pr[x / N]; };
  Z f = [&](Z &f, int l, int r) -> ll {
    if (r / 10 > l / 10 + 1) return f(f, l / 10, r / 10) * 10 + l % 10;
    for (int x = l + 1; ; ++x) {
      FOR(i, r - l + 1) if (ke(l + i) != ke(x + i)) goto MyGO;
      return x;
      MyGO: ;
    }
  };
  print(f(f, a, a + sz - 1));
}

int main() {
  Yorisou();
  return 0;
}