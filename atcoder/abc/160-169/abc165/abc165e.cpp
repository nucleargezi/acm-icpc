#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  vc<PII> s;
  if (N & 1) {
    for (int l = 1, r = N - 1; l < r; ++l, --r) s.ep(l, r);
  } else {
    bool f = 0;
    for (int l = 1, r = N - 1; l < r; ++l, --r) {
      if (not f and r - l <= N / 2) --r, f = 1;
      s.ep(l, r);
    }
  }
  FOR(i, M) print(s[i]);
}

int main() { Yorisou(); }