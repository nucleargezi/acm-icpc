#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<ll> c(N);
  for (int &x : a) c[--x] += 1;
  ll s = 0;
  FOR(i, N) s += c[i] * (c[i] - 1) / 2;
  FOR(i, N) {
    ll &x = c[a[i]];
    s -= x * (x - 1) / 2;
    --x;
    print(s + x * (x - 1) / 2);
    ++x;
    s += x * (x - 1) / 2;
  }
}

int main() { Yorisou(); }