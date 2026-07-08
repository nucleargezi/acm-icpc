#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  map<int, int> mp;
  FOR(i, N) ++mp[a[i]];
  max_heap<PII> q;
  for (var [a, b] : mp) q.eb(b, a);
  vc<T3<int>> rs;
  while (si(q) > 2) {
    vc<PII> v;
    FOR(3) v.ep(pop(q));
    rs.ep(v[0].se, v[1].se, v[2].se);
    for (var [a, b] : v) if (a > 1) q.eb(a - 1, b);
  }
  print(si(rs));
  for (var [a, b, c] : rs) {
    array<int, 3> out{a, b, c};
    sort(out, greater());
    print(out);
  }
}

int main() {
  Yorisou();
  return 0;
}