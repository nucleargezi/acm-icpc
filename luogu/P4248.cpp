#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/bass_occ.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  STR(s);
  ll N = si(s);
  bass g(s);
  ll x = bass_occ<Add<ll>>(g, 1, {PII{0, N}})[0];
  print(N * (N + 1) / 2 * N - x);
}

int main() { Yorisou(); }