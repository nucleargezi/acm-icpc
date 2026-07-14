#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  Z f = [&]() {
    ll s = 0;
    FOR(i, N) FOR(k, M) {
      INT(x);
      s += x * (1ll * i * i + 1ll * k * k + 2 * i + 2 * k);
    }
    return s;
  };
  print((f() - f()) / 2);
}

int main() {
  Yorisou();
  return 0;
}