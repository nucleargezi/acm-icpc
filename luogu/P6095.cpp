#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/SA.hpp"

void Yorisou() {
  INT(N, K);
  int sz = ceil(N, K);
  STR(s);
  s += s;
  SA sa(s);
  var rk = sa.rk;
  int l = bina([&](int lm) -> bool {
    FOR(i, sz) {
      int c = 0;
      FOR(k, K) c += sz - (rk[(i + c) % N] > lm);
      if (c >= N) return 1;
    }
    return 0;
  }, (N << 1) - 1, -1);
  string rs;
  FOR(i, sz) rs += s[sa.sa[l] % N + i];
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}