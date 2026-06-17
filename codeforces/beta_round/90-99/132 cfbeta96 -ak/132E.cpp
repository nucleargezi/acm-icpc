#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/min_cost_bflow.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  min_cost_bflow<int, int> g(3 * N + 1);
  g.add(3 * N, 0, 0, K, 0);
  FOR(i, N) g.add(3 * i, 3 * i + 3, 0, K, 0);
  FOR(i, N) g.add(3 * i + 1, 3 * i + 2, 1, 1, 0);
  FOR(i, N) g.add(3 * i + 2, 3 * i + 3, 0, 1, 0);
  map<int, int> mp;
  FOR(i, N) {
    int x = a[i];
    g.add(3 * i, 3 * i + 1, 0, 1, pc(x));
    if (mp.contains(x)) g.add(3 * mp[x] + 2, 3 * i + 1, 0, 1, 0);
    mp[x] = i;
  }
  int co = *g.flow();

  vc<char> c(N), p(N);
  for (Z [f, t, l, r, fl, w] : g.get_es()) {
    if (f % 3 == 0 and t == f + 1 and fl) c[f / 3] = 1;
    if (f % 3 == 2 and t != f + 1 and fl) p[f / 3] = 1;
  }
  
  vc<string> st;
  vc<int> buf(K);
  FOR(i, N) {
    int x = a[i];
    if (c[i]) {
      FOR(k, K) if (buf[k] == 0) {
        buf[k] = x;
        st.ep(char('a' + k) + ("=" + to_string(x)));
        break;
      }
    }
    int t = -1;
    FOR(k, K) if (buf[k] == x) {
      st.ep((string)"print(" + char('a' + k) + ")");
      t = k;
      break;
    }
    if (not p[i]) buf[t] = 0;
  }
  print(si(st), co);
  for (var s : st) print(s);
}

int main() {
  Yorisou();
  return 0;
}