#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  map<int, int> mp;
  Z f = [&](int x) {
    Z it = mp.find(x);
    return it == ed(mp) ? 0 : it->se;
  };
  ll s = 0;
  FOR(i, N) {
    s += f(i - a[i]);
    ++mp[i + a[i]];
  }
  print(s);
}

int main() { Yorisou(); }