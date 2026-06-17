#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  vc<int> c(N);
  for (char &c : s) c = c == 'W';
  FOR(i, 0, N, 2) c[i] = 1;
  int l = N, r = -1;
  FOR(i, N) if (c[i] != s[i]) r = i;
  FOR_R(i, N) if (c[i] != s[i]) l = i;
  if (r == -1) return print(0);
  int rs = r - l + 1;
  FOR(i, N) c[i] ^= 1;
  l = N, r = -1;
  FOR(i, N) if (c[i] != s[i]) r = i;
  FOR_R(i, N) if (c[i] != s[i]) l = i;
  if (r == -1) return print(0);
  chmin(rs, r - l + 1);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}