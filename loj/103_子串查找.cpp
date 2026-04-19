#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/hs.hpp"

void Yorisou() {
  STR(s, t);
  int N = si(s), M = si(t);
  s += t;
  hash_t hs(s);
  int rs = 0;
  const Z cp = hs.get(N, N + M);
  FOR(i, N - M + 1) {
    rs += hs.get(i, i + M) == cp;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}