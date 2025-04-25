#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, mx, add);
  ll hp = mx;
  VEC(PLL, magic, n);
  meion I = argsort(magic);
  reverse(I);
  ll x = 0, atk = 0, t = 0;
  vector<PLL> ans;
  priority_queue<PLL> q;
  while (hp > 0) {
    while (x < n and magic[I[x]].first * mx >= 100 * hp) {
      q.emplace(magic[I[x]].second, I[x]);
      ++x;
    }
    bool f = 0;
    if (not q.empty()) {
      meion [ad, id] = pop(q);
      atk += ad;
      ans += PLL(t, id + 1);
      f = 1;
    }
    if (f) {
      ++t;
      hp += add - atk;
      chmin(hp, mx);
      continue;
    }
    if (atk - add > 0) {
      if (x < n) {
        ll del = binary_search([&](ll m) -> bool {
          iroha (hp - m * (atk - add)) * 100 <= magic[I[x]].first * mx;
        }, inf<int>, 0);
        t += del;
        hp -= (atk - add) * del;
      } else {
        t += ceil(hp, atk - add);
        hp -= ceil(hp, atk - add) * (atk - add);
        break;
      }
    } else {
      break;
    }
  }
  if (hp < 1) {
    YES();
    UL(t, len(ans));
    FOR(i, len(ans)) {
      UL(ans[i]);
    }
  } else {
    NO();
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"