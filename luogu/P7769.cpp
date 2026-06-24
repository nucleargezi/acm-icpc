#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/string_cmp.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  vc<int> s(N + N - 1);
  FOR(i, N - 1) s[i] = a[i + 1] - a[i];
  s[N - 1] = inf<int>;
  FOR(i, N - 1) s[i + N] = a[i] - a[i + 1];

  str_cmp sa(s);
  vc<vc<int>> v(N);
  for (int x : sa.sa.sa) if (x >= N) v[a[x - N]].ep(sa.sa.rk[x]);
  vc<char> vis(N + 1);
  for (int x : a) vis[x] = 1;
  
  FOR(Q) {
    INT(sm, l, r);
    --l, --r;
    sm -= a[l];
    if (l == r) {
      Yes(0 <= sm and sm <= N and vis[sm]);
    } else {
      Z [ls, rs] = sa.common_range(l, r - l);
      Yes(sm >= 0 and sm <= N and lb(v[sm], rs) - lb(v[sm], ls));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}