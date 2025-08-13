#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"
#include "YRS/math/PR/factors.hpp"

#define tests
void Yorisou() {
  LL(n);
  vector<ll> ans;
  for (meion [e, p] : factor(n)) {
    while (p--) ans.emplace_back(e);
  }
  UL(len(ans), ans);
}
#include "YRS/Z_H/main.hpp"