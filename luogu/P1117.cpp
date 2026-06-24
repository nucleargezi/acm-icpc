#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/runs.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  vc<int> L(N + 1), R(N + 1);
  for (Z [l, r, p] : runs(s)) {
    for (int k = 1; 2 * k * p <= r - l; ++k) {
      int sz = 2 * k * p;
      ++L[l + sz - 1], --L[r];
      ++R[l], --R[r - sz + 1];
    }
  }
  FOR(i, N) L[i + 1] += L[i];
  FOR(i, N) R[i + 1] += R[i];
  ll rs = 0;
  FOR(i, 1, N) rs += 1ll * L[i - 1] * R[i];
  print(rs);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}