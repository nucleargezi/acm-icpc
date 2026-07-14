#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s, t);
  int c[26]{}, d[26]{};
  for (int ch : t) ++c[ch - 'a'];
  int N = si(s), M = si(t), rs = 0;
  FOR(i, N) {
    if (i >= M and s[i - M] != '?') --d[(int)s[i - M] - 'a'];
    if (s[i] != '?') ++d[(int)s[i] - 'a'];
    if (i >= M - 1) {
      bool f = 1;
      FOR(i, 26) f &= c[i] >= d[i];
      rs += f;
    }
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}