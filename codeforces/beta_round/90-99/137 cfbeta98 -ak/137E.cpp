#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/st/range_max.hpp"

void Yorisou() {
  STR(s);
  for (char &c : s) c = tolower(c);
  int N = si(s);
  vc<int> a(N);
  FOR(i, N) a[i] = string("aeiou").find(s[i]) != string::npos ? -1 : 2;
  a = pre_sum(a);
  range_max<int> st(a);
  int mx = -1, c = 0;
  FOR(i, N) {
    int r = bina([&](int r) -> bool {
      if (r == N + 1) return 1;
      return st.prod(r, N + 1) < a[i];
    }, N + 1, i) - 1;
    if (chmax(mx, r - i)) c = 1;
    else if (mx == r - i) ++c;
  }
  if (mx == 0) print("No solution");
  else print(mx, c);
}

int main() {
  Yorisou();
  return 0;
}