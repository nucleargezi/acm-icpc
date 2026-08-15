#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/nt/bigint/big.hpp"
#include "YRS/fps/inv.hpp"

string gen() {
  using ll = bigint;
  LL(a, b);
  return (a / b).to_string();
}

using T = M99;
void Yorisou() {
  string s = gen();
  int n = si(s);
  fps f(n);
  FOR(i, n) f[i] = s[i] - '0';
  reverse(f);
  print(inv(f));
}

int main() {
  Yorisou();
  return 0;
}