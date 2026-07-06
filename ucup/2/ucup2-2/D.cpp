#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  vc<PII> rs;
  set<int> a, b;
  Z ins = [&](int x, int y) {
    if (min(x, y) < 1 or x > N or y > M) return;
    if (a.contains(x + y) or b.contains(x - y)) return;
    a.eb(x + y), b.eb(x - y);
    rs.ep(x, y);
  };
  if (N < M) {
    FOR(x, 1, N + 1) ins(x, 1);
    FOR(x, 1, N + 1) ins(x, M);
    FOR(y, 1, M + 1) {
      int x = ceil(N, 2);
      ins(x, y);
      ins(x - 1, y);
      ins(x + 1, y);
    }
  } else {
    FOR(y, 1, M + 1) ins(1, y);
    FOR(y, 1, M + 1) ins(N, y);
    FOR(x, 1, N + 1) {
      int y = ceil(M, 2);
      ins(x, y);
      ins(x, y - 1);
      ins(x, y + 1);
    }
  }
  print(si(rs));
  for (var [a, b] : rs) print(a, b);
}

int main() {
  Yorisou();
  return 0;
}