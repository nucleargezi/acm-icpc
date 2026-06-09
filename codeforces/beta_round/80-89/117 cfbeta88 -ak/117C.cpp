#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using bs = bitset<5'000>;
void Yorisou() {
  INT(N);
  vc<bs> a(N), b(N); // outo x, into x
  FOR(i, N) {
    STR(s);
    FOR(k, N) if (s[k] == '1') a[i].set(k), b[k].set(i);
  }
  bs t;
  FOR(i, N) {
    t.reset();
    FOR(k, N) if (a[i][k]) t |= a[k];
    if ((t & b[i]).any()) {
      int j = (t & b[i])._Find_first();
      FOR(k, N) if (a[i][k] and a[k][j]) {
        return print(i + 1, k + 1, j + 1);
      }
    }
  }
  print(-1);
}

int main() {
  Yorisou();
  return 0;
}