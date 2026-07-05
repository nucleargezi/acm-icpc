#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  vc<int> L(N), R(N);
  FOR(i, 1, N) {
    if (s[i] == s[i - 1]) L[i] = L[i - 1];
    else L[i] = i;
  }
  R[N - 1] = N - 1; 
  FOR_R(i, N - 1) {
    if (s[i] == s[i + 1]) R[i] = R[i + 1];
    else R[i] = i;
  }
  string rs;
  for (int l = 0, r = N - 1; l <= r; ) {
    if (s[l] != s[r]) {
      if (s[l] < s[r]) rs += s[l++];
      else rs += s[r--];
      continue;
    }
    int lp = R[l], rp = L[r];
    if (lp >= rp) {
      rs += string(ceil(r - l + 2, 2), s[l]);
      break;
    }
    if (s[lp + 1] < s[l] and s[rp - 1] < s[r]) {
      int sz = min(lp - l + 1, r - rp + 1);
      rs += string(sz, s[l]);
      l += sz, r -= sz;
      continue;
    } else if (s[lp + 1] < s[l]) {
      rs += string(lp - l + 1, s[l]);
      l = lp + 1;
    } else if (s[rp - 1] < s[r]) {
      rs += string(r - rp + 1, s[r]);
      r = rp - 1;
    } else {
      rs += string(lp - l + 1 + r - rp + 1, s[l]);
      l = lp + 1;
      r = rp - 1;
    }
  }
  print(rs);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}