// https://icpc.bjtu.edu.cn/problem/11416
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/cartesian.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  cartesian<int, 1> s(a);
  ll l = 0, r = 0;
  FOR(i, N) {
    ll x = i + 1;
    l ^= x * (s.ls[i] + 2);
    r ^= x * (s.rs[i] + 2);
  }
  print(l, r);
}

int main() {
  Yorisou();
  return 0;
}