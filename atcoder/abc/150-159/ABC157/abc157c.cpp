#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, Q);
  string s(N, 0);
  FOR(Q) {
    INT(i, x);
    --i;
    if (s[i] and s[i] != x + '0') return print(-1);
    if (i == 0 and x == 0 and N > 1) return print(-1);
    s[i] = x + '0';
  }
  if (not s[0] and N > 1) s[0] = '1';
  if (not s[0] and N == 1) s[0] = '0';
  FOR(i, 1, N) if (not s[i]) s[i] = '0';
  print(s);
}

int main() { Yorisou(); }