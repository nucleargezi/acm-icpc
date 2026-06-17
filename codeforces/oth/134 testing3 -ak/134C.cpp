#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, s);
  VEC(int, a, N);
  max_heap<PII> q;
  FOR(i, N) if (a[i]) q.eb(a[i], i);
  vc<PII> st, buf;
  while (si(q)) {
    Z [w, i] = pop(q);
    if (w > si(q)) return No();
    FOR(w) {
      Z [c, k] = pop(q);
      if (c > 1) buf.ep(c - 1, k);
      st.ep(i + 1, k + 1); 
    }
    while (si(buf)) q.eb(pop(buf));
  }
  Yes();
  print(si(st));
  for (var x : st) print(x);
}

int main() {
  Yorisou();
  return 0;
}