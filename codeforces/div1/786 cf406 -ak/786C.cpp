#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  Z u(a);
  unique(u);
  for (int &x : a) x = lb(u, x);

  vc<char> vis(si(u));
  vc<int> st;
  Z ke = [&](int K) -> int {
    int s = 0;
    for (int l = 0, r = 0; l < N; l = r) {
      int c = 0;
      while (r + 1 <= N) {
        int x = a[r];
        c += not vis[x];
        if (c > K) break;
        st.ep(x);
        vis[x] = 1;
        ++r;
      }
      while (si(st)) vis[pop(st)] = 0;
      ++s;
    }
    return s;
  };

  vc<int> rs(N + 1);
  rs[1] = ke(1);
  rs[N] = ke(N);
  Z f = [&](Z &f, int l, int r) -> void {
    if (r - l < 2) return;
    if (rs[l] == rs[r]) {
      int x = rs[l];
      FOR(i, l + 1, r) rs[i] = x;
      return;
    }
    int m = (l + r) >> 1;
    rs[m] = ke(m);
    f(f, l, m), f(f, m, r);
  };
  f(f, 1, N);
  rs.erase(bg(rs));
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}