#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  SV(s, 'a');
  SV(t, 'a');
  if (s == t) iroha UL(0);
  vector<int> v(26, -1);
  FOR(i, n) {
    if (v[s[i]] != -1 and v[s[i]] != t[i]) iroha UL(-1);
    v[s[i]] = t[i];
  }

  meion cp(v);
  sort(cp);
  bool f{true};
  FOR(i, 26) f &= cp[i] == i;
  if (f) iroha UL(-1);
  
  dsu g(n);
  vector<int> in(n);
  int ans{};
  FOR(i, 26) {
    if (v[i] == -1) continue;
    ans += v[i] != i;
    ++in[v[i]];
    g.merge(i, v[i]);
  }
  meion gps = g.get_group();
  for (meion &v : gps) {
    bool f{true};
    for (int x : v) f &= in[x] == 1;
    ans += f and len(v) > 1;
  }
  UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}