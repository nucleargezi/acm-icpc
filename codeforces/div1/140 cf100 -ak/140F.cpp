#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/random/hash.hpp"

using re = double;
void Yorisou() {
  INT(N, K);
  VEC(PII, a, N);
  for (Z &[x, y] : a) x += x, y += y;
  if (K >= N) return print(-1);
  Z f(a);
  unique(f);
  sort(a);
  hashmap<int> mp;
  for (var x : f) mp[hsh(x)] = 1;

  Z ck = [&](int x, int y) -> bool {
    int c = 0;
    for (Z [a, b] : f) {
      a = x + x - a;
      b = y + y - b;
      if (not mp.contains(hsh(PII{a, b}))) ++c;
    }
    return c <= K;
  };
  
  vc<PII> rs;
  FOR(i, K + 1) FOR(k, K + 1) {
    Z [x, y] = a[i];
    Z [xx, yy] = a[N - 1 - k];
    x = (x + xx) >> 1, y = (y + yy) >> 1;
    if (ck(x, y)) rs.ep(x, y);
  }
  unique(rs);
  print(si(rs));
  setp(1);
  for (var [x, y] : rs) print(x / 2.0, y / 2.0);
}

int main() {
  Yorisou();
  return 0;
}