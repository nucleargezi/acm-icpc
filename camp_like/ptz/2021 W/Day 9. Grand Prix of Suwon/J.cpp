#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  sort(a, greater());
  ll s = -1;
  max_heap<pair<ll, ll>> q;
  vc<ll> ss(N, -1), sss(ss);
  for (int i = N - 1; i >= 1; --i) {
    ll B = a[i];
    while (si(q)) {
      Z [sm, DC] = q.top();
      if (B >= DC) q.pop();
      else break; 
    }
    if (si(q)) {
      Z [sm, DC] = q.top();
      ll D = (sm + DC) / 2, C = sm - D;
      ss[i] = C, sss[i] = D;
    }
    if (i + 4 < N) {
      ll C = a[i], D = a[i + 1] + a[i + 2] + a[i + 3] + a[i + 4];
      q.eb(C + D, (D - C));
    }
  }
  set<ll> se;
  FOR(i, N) {
    if (ss[i] != -1) {
      ll B = a[i], C = ss[i], D = sss[i];
      Z it = se.lower_bound(B + C);
      if (it != bg(se)) {
        --it;
        ll A = *it;
        if (A < B + C) chmax(s, A + B + C + D);
      }
    }
    se.eb(a[i]);
  }
  print(s);
}

int main() { Yorisou(); }