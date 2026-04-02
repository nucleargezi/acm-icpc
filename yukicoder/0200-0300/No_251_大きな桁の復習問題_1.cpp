#include "YRS/all.hpp"
#include "YRS/mod/mint_t.hpp"

constexpr int mod = 129402307;
using mint = mint_t<mod>;
void Yorisou() {
  STR(a, b);
  mint N;
  ll M{};
  for (char c : a) {
    c -= '0';
    N = N * 10 + c;
  }
  for (char c : b) {
    c -= '0';
    M = M * 10 + c;
    if (M > mod) M = M % (mod - 1) + mod - 1;
  }
  print(N.pow(M).val());
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"