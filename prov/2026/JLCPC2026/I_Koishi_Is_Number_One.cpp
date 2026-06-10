#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/run_length.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N << 1);
  Z seg = run_length(a);
  reverse(seg);
  vc<int> g;
  vc<PII> st;
  for (var [a, b] : seg) {
    if (b > 1) {
      st.ep(a, -1);
      FOR(b - 2) g.ep(a);
    } else {
      if (si(g) == 0) return No();
      st.ep(pop(g), a);
    }
  }
  int sz = si(g);
  FOR(i, 0, sz - 1, 2) st.ep(g[i], g[i + 1]);
  sort(st);
  for (Z &[a, b] : st) if (b == -1) b = a;
  vc<int> s(N);
  FOR(i, N) s[i] = st[i].se;
  Yes();
  print(s);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}