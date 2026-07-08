#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M, K);
  int x = 0, y = 0;
  vc<int> st;
  FOR(N) {
    STR(s);
    vc<int> a, b;
    FOR(i, M) if (s[i] == 'G') a.ep(i);
    FOR(i, M) if (s[i] == 'R') b.ep(i);
    if (a.empty() and b.empty()) ;
    else if (b.empty()) x += M - si(a);
    else if (a.empty()) y += M - si(b);
    else st.ep(abs(a[0] - b[0]) - 1);
  }
  if (x and y) return print("Draw");
  if (x and not y) return print("First");
  if (not x and y) return print("Second");
  FOR(i, 20) {
    int x = 0;
    for (int e : st) x += e >> i & 1;
    if (x % (K + 1)) return print("First");
  }
  print("Second");
}

int main() {
  Yorisou();
  return 0;
}