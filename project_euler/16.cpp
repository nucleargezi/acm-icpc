#include "YRS/all.hpp"
#include "YRS/nt/bigint/big.hpp"

void Yorisou() {
  using ll = bigint;
  ll s = 1;
  FOR(i, 1000) s *= 2;
  string f = s.to_string();
  print(f);
  ll r = 0;
  for (char c : f) r += c - '0';
  print(r);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"