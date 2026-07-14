#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

bool ok(int x) {
  string s(to_string(x));
  for (char c : s) if (c != '4' and c != '7') return 0;
  return 1;
}

using mint = M11;
binom<mint> X;
void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  map<int, int> mp;
  int c = 0;
  for (int x : a) {
    if (ok(x)) ++mp[x];
    else ++c;
  }

  int n = si(mp) + 1;
  vc<mint> f(n), ff;
  f[0] = 1;
  for (var [_, x] : mp) {
    ff = f;
    FOR_R(i, n - 1) ff[i + 1] += f[i] * x;
    f.swap(ff);
  }
  mint s;
  FOR(i, n) s += f[i] * X(c, K - i);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}