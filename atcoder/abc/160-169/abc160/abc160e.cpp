#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M, n, m, q);
  VEC(int, a, n);
  VEC(int, b, m);
  VEC(int, c, q);
  min_heap<int> ls, rs;
  ll s = 0;
  for (int x : a) {
    s += x;
    ls.eb(x);
    if (si(ls) > N) s -= pop(ls);
  }
  for (int x : b) {
    s += x;
    rs.eb(x);
    if (si(rs) > M) s -= pop(rs);
  }
  for (int x : c) {
    if (si(ls) < N) s += x, ls.eb(x);
    else if (si(rs) < M) s += x, rs.eb(x);
    else {
      if (ls.top() < rs.top()) {
        if (x > ls.top()) s += x - pop(ls), ls.eb(x);
      } else {
        if (x > rs.top()) s += x - pop(rs), rs.eb(x);
      }
    }
  }
  print(s);
}

int main() { Yorisou(); }