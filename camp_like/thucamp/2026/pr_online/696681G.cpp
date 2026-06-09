#include "YRS/all.hpp"

int q(int l, int r) {
  print("?", l + 1, r + 1);
  string s;
  IN(s);
  return s[0] == 'Y';
}

bool ok(string s) {
  int c = 0;
  for (char f : s) {
    if (f == '(') ++c;
    else --c;
    if (c < 0) return 0;
  }
  return c == 0;
}

void Yorisou() {
  int N, Q;
  IN(N, Q);
  string rs(N, ' ');
  rs[0] = '(', rs.back() = ')';
  if (N == 2) return print("!", rs);
  vc<int> st{0};
  FOR(i, 1, N - 2) {
    if (st.empty()) st.ep(i), rs[i] = '(';
    else if (q(st.back(), i)) rs[i] = ')', pop(st);
    else rs[i] = '(', st.ep(i);
  }
  rs[N - 2] = '(';
  if (not ok(rs)) rs[N - 2] = ')';
  print("!", rs);
}

int main() {
  Yorisou();
  return 0;
}