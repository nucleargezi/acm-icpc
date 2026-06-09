#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using mint = M99;
void Yorisou() {
  ULL(N, P);
  mint s;
  for (ull te = 1; te <= N; te *= 10) {
    ull c = min(N, te * 10 - 1) - min(N, te - 1);
    ull g = P / gcd(P, te * 10 - 1);
    s += mint(N / g) * c;
  }
  print(s);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}