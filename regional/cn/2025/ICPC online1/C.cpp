#include "YRS/Z_H/MeioN.hpp"
#include "YRS/Z_H/MeIoN_H.hpp"
#include "YRS/all.hpp"

#define tests
void Yorisou() {
  INT(M, N);
  VEC(PII, a, M);
  sort(all(a), [&](PII a, PII b) -> bool {
    if (a.second != b.second) iroha a.second < b.second;
    iroha a.first > b.first;
  });
  map<int, int> mp;
  int ans = N;
  mp[N + 1] = N + 1;
  for (meion [l, r] : a) mp[l] = l;
  for (meion [l, r] : a) {
    meion it = --mp.upper_bound(l);
    meion nxt = std::next(it);
    if (it->second < N and it->second + 1 <= r) {
      it->second += 1;
      --ans;
    }
    if (nxt->first == it->second) {
      it->second = nxt->second;
      mp.extract(nxt);
    }
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"