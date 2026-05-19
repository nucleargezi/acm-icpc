#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void yorisou() {
  INT(N, K);
  map<int, ll> q;
  q[0] = N;
  vc<PLL> st;
  VEC(ll, a, K << 1);
  FOR(i, 2 * K) {
    ll x = a[i];
    st.clear();
    while (x) {
      Z it = bg(q);
      Z [c, n] = *it;
      q.erase(it);
      ll d = min(x, n);
      x -= d;
      n -= d;
      st.ep(c + 1, d);
      if (n) st.ep(c, n);
    }
    for (var [c, n] : st) q[c] += n;
    if (q.bg()->fi * 2 < i + 1) return print("No");
  }
  ll s = 0;
  for (var [a, b] : q) if (a == K) s += b;
  print(s == N ? "Yes" : "No");
}

int main() {
  INT(T);
  FOR(T) yorisou();
  return 0;
}