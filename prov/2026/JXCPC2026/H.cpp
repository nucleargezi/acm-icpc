#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  if (QMAX(a) == 0 or K == 0) return print("Bob");
  int s = 0;
  for (int x : a) s ^= x;
  print((s and (1 << lowbit(s)) <= K) ? "Alice" : "Bob");
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}