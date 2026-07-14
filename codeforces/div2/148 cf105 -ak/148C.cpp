#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, a, b);
  int aa = a, bb = b;
  vc<ll> rs(N, 2);
  ll s = 2, m = 2;
  if (a and not b) {
    FOR(i, 2, N) rs[i] = rs[i - 1] + (a-- > 0);
  } else {
    FOR(i, 1, N) {
      if (b) m = s + 1, --b, rs[i] = m, s += m;
      else if (a) ++m, --a, rs[i] = m, s += m;
    }
  }
  s = m = rs[0];
  FOR(i, 1, N) {
    if (rs[i] > s) --bb;
    else if (rs[i] > m) --aa;
    chmax(m, rs[i]);
    s += rs[i];
  }
  if (aa or bb) return print(-1);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}