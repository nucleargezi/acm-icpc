#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

bool ok(ll x) {
  if (x == 0) return 0;
  for (; x; x /= 10) if (x % 10 != 4 and x % 10 != 7) return 0;
  return 1;
}
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int t = -1;
  FOR(i, N) if (ok(a[i])) t = i;
  if (t == -1) return print(is_sorted(all(a)) ? 0 : -1);
  vc<int> I = argsort(a), to(N), pos(N);
  FOR(i, N) to[I[i]] = i;
  FOR(i, N) pos[to[i]] = i;
  vc<PII> st;
  int g = to[t], c = t;
  Z sp = [&](int x, int y) {
    if (x == y) return;
    st.ep(x, y);
    swap(to[x], to[y]);
    pos[to[x]] = x;
    pos[to[y]] = y;
    if (c == x) c = y;
    else if (c == y) c = x;
  };
  Z go = [&]() {
    while (c != g) sp(c, pos[c]);
  };
  go();
  FOR(i, N) if (to[i] != i) sp(c, i), go();
  print(si(st));
  for (var [a, b] : st) print(a + 1, b + 1);
}

int main() {
  Yorisou();
  return 0;
}