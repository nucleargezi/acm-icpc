#include "YRS/all.hpp"

void yorisou() {
  INT(N);
  VEC(string, s, N);

  map<char, int> mp;
  FOR(i, N) {
    int c = s[i][0];
    if (mp.contains(c)) {
      if (len(s[mp[c]]) > len(s[i])) mp[c] = i;
    } else {
      mp[c] = i;
    }
  }

  for (Z &ss : s) {
    bool ok = true;
    for (char c : ss) {
      if (not mp.contains(c)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      string ans;
      for (char c : ss) {
        ans += s[mp[c]];
        ans += ' ';
      }
      pop(ans);
      print(len(ans));
      print(ans);
      return;
    }
  }
  print(-1);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  yorisou();
  return 0;
}