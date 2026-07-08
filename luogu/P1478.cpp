#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, s, a, b);
  vc<int> st;
  FOR(N) {
    INT(x, y);
    if (a + b >= x) st.ep(y);
  }
  sort(st);
  int rs = 0;
  for (int x : st) {
    if (s >= x) s -= x, ++rs;
    else break;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}