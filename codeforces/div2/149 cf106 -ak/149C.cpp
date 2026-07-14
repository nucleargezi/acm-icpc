#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> ls, rs;
  ll s = 0, ss = 0;
  FOR(i, N >> 1) {
    ll x = i << 1, y = i << 1 | 1;
    if (a[x] > a[y]) swap(x, y);
    if (s < ss) ls.ep(y), rs.ep(x), s += a[y], ss += a[x];
    else ls.ep(x), rs.ep(y), s += a[x], ss += a[y];
  }
  if (N & 1) (s < ss ? ls : rs).ep(N - 1);
  for (int &x : ls) ++x;
  for (int &x : rs) ++x;
  print(si(ls));
  print(ls);
  print(si(rs));
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}