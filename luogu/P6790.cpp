#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/gg/gsp.hpp"

using mint = M99;

struct DP {
  using X = array<mint, 2>;
  using cp = const X &;
  mint ans = 1;
  static X com(int, cp a, cp b) {
    return {a[0] * b[0], a[0] * b[1] + a[1] * b[0]};
  }
  static X twist(cp a, cp b) {
    return {a[0] * b[1] + a[1] * b[0], a[1] * b[1]};
  }
  void rak(int, int, cp a) { ans *= a[0]; }
};

void Yorisou() {
  INT(N, M);
  gsp<DP> v(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    if (a != b) v.add(a, b, {1, 1});
  }
  v.build(), print(v.ans);
}

int main() { Yorisou(); }