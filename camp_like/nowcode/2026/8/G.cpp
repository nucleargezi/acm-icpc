#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/nt/bigint/big.hpp"

constexpr int lm = 2'000'00;
void Yorisou() {
  INT(a, b, c);
  string x0, x1, y0, y1;
  x0 += '1';
  FOR(a - 1) x0 += '0';
  FOR(i, lm) x0 += '0';

  FOR(b) y0 += '9';
  FOR(i, lm) y0 += '0';

  x1 += '1';
  FOR(a - 1) x1 += '0';
  FOR(i, lm) x1 += '4';

  FOR(b) y1 += '9';
  FOR(i, lm) y1 += '4';

  using ll = bigint;
  for (int x : {1, 4, 5, 9}) {
    FOR(i, lm) x1[i + a] = x + '0';
    FOR(i, lm) y1[i + b] = x + '0';
    string ls = (ll(x0) * y0).to_string(), rs = (ll(x1) * y1).to_string();
    ls.resize(c), rs.resize(c);
    if (ls == rs) continue;
    print(x0, y0, x1, y1);
    return;
  }
}

int main() {
  Yorisou();
  return 0;
}