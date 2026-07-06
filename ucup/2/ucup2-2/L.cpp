#include "YRS/all.hpp"

constexpr int N = 50;
string gen() {
  STR(s);
  set<char> se;
  string rs(N, '1');
  FOR(i, N) {
    if (se.eb(s[i]).se) rs[i] -= 1;
  }
  return rs;
}

string ge(int a) {
  print(a + 1);
  STR(rs);
  return rs;
}

void run() {
  string vis;
  IN(vis);

  FOR(i, N) vis[i] -= '0';
  vc<int> ls, rs;
  FOR(i, N) (vis[i] ? rs : ls).ep(i);

  string col;
  map<char, int> mp;
  FOR(i, 12) {
    int a = ls[i << 1], b = ls[i << 1 | 1];
    col = ge(a);
    mp[col[0]] = a;
    col = ge(b);
    mp[col[0]] = b;
  }
  int cha = pop(ls);
  for (char i = 'A'; i <= 'Y'; ++i) {
    if (not mp.contains(i)) mp[i] = cha;
  }
  for (int a : rs) {
    col = ge(a);
    char c = col[0];
    int p = mp[c];
    col = ge(p);
  }
}

void Yorisou(var s) {
  if (s == "play") run();
  else print(gen());
}

int main() {
  string s;
  int T;
  IN(s, T);
  FOR(T) Yorisou(s);
  return 0;
}