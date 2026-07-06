#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  if (N <= 5) {
    vc<int> s(N);
    iota(all(s), 1);
    return print(s);
  }
  int m = bina([&](int m) -> bool {
    if (m == 0) return 1;
    return (N - m) >= 2 * m;
  }, 0, N);
  vc<int> ls, rs, ms;
  FOR(i, m) ls.ep(i + 1);
  FOR(i, m) rs.ep(N - i);
  FOR(i, m, N - m) ms.ep(i + 1);
  vc<int> s;
  FOR(m) s.ep(pop(ms)), s.ep(pop(ls)), s.ep(pop(rs));
  s.insert(ed(s), all(ms));
  print(s);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}