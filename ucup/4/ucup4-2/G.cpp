#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
int N = 0;
constexpr int sz = 1'000'10;
string s[sz];
int pos[sz];
void make(int t) {
  int c = 0, p = -1;
  const int N = len(s[t]);
  FOR(i, N) {
    if (s[t][i] == ',') p = i, ++c;
  }
  if (c == 1) pos[t] = p;
}
string get(int t) {
  int p = pos[t];
  return s[t].substr(0, p);
}
bool ckfi(const string &s, const string &a) {
  return s == (a + ", " + a + " " + a + "ity " + a);
}
bool ckse(const string &s, const string &a) {
  return s == ("i said " + a + ", " + a + ' ' + a + "ity " + a);
}
void Yorisou() {
  memset(pos, -1, sizeof pos);
  while (std::getline(cin, s[N])) ++N;
  FOR(i, N) make(i);
  int ans = -1;
  FOR(i, 2) {
    for (int l = i, r; l + 1 < N; l = r + 2) {
      r = l;
      if (pos[l] == -1 or pos[l + 1] == -1) continue;
      string a = get(l);
      while (r + 1 < N) {
        if (pos[r] != -1 and pos[r + 1] != -1 and ckfi(s[r], a) and
            ckse(s[r + 1], a)) {
          r += 2;
        } else {
          break;
        }
      }
      int c = (r - l) / 2;
      int d = len(s[l]) + len(s[l + 1]) + 2;
      if (r != l) r -= 2, chmax(ans, c * d);
    }
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"