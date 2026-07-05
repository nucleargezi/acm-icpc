#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  vc<int> I, E;
  FOR(i, N) (s[i] == '?' ? I : E).ep(i);
  
  set<string> se;
  Z slv = [&]() {
    deque<int> a, b;
    FOR(i, N) (s[i] == '1' ? a : b).ep(i);
    FOR(i, N - 2) {
      if (i & 1) {
        if (si(b)) b.pop_front();
        else a.pop_back();
      } else {
        if (si(a)) a.pop_front();
        else b.pop_back();
      }
    }
    vc<int> ls;
    for (int i : a) ls.ep(i);
    for (int i : b) ls.ep(i);
    sort(ls);
    string rs;
    for (int i : ls) rs += s[i];
    se.eb(rs);
  };

  for (int i : I) s[i] = '1';
  slv();
  for (int i : I) s[i] = '0';
  slv();
  
  if (si(I)) {
    int a = 0, b = 0;
    for (int i : E) (s[i] == '1' ? a : b) += 1;
    int d = abs(a - b);
    if (si(I) >= d) {
      Z make = [&](vc<int> I) {
        reverse(I);
        FOR(d) s[pop(I)] = a > b ? '0' : '1';
        int sz = si(I);
        FOR(i, sz - 2) s[pop(I)] = i & 1 ? '0' : '1';
        sz = si(I);
        if (sz == 1) {
          int a = I[0];
          s[a] = '0';
          slv();
          s[a] = '1';
          slv();
        } else {
          int a = I[0], b = I[1];
          s[a] = s[b] = '1';
          slv();
          s[a] = s[b] = '0';
          slv();
          s[a] = '1' ,s[b] = '0';
          slv();
          s[a] = '0', s[b] = '1';
          slv();
        }
      };
      make(I);
      reverse(I);
      make(I);
    }
  }
  for (var s : se) print(s);
}

int main() {
  Yorisou();
  return 0;
}