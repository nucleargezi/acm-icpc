#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/barrett.hpp"

void Yorisou() {
  INT(N, P);
  const barrett M(P);
  STR(s);
  for (char &c : s) c -= '0';
  ull rs = 0, x = 0;
  if (P == 2 or P == 5) {
    FOR(i, N) if (M(s[i]) == 0) rs += i + 1;
    return print(rs);
  }
  
  vc<int> c(P);
  c[0] = 1;
  ull bs = 1;
  FOR_R(i, N) {
    x = M(x + s[i] * bs);
    rs += c[x]++;
    bs = M(bs * 10);
  }
  print(rs);
}

int main() { Yorisou(); }