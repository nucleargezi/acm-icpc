#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(N, K);
  if (N + N <= K or (K & 1)) return print(-1);
  if (K <= N) return print(3);
  ll a = N, b = K - N, c = b, d = N;
  ll g = abs(a - c) + abs(b - d);
  print((g >= K and (~(g - K) & 1)) ? 3 : -1);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}