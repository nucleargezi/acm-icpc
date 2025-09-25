#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
using P = pair<char, char>;
P fmt(char a, char b) {
  if (a == 'J' and b == '1') return {0, 0};
  if (a == 'J' and b == '2') return {1, 1};
  return {a, b};
}
P read() {
  STR(s);
  return fmt(s[0], s[1]);
}
string to_s(P p) {
  if (p.fi == 0) return "J1";
  if (p.fi == 1) return "J2";
  string res;
  res += p.fi, res += p.se;
  return res;
}
void Yorisou() {
  INT(N, M);
  string n = "23456789TJQKA";
  string c = "CDHS";
  set<P> se;
  for (char a : n) for (char b : c) se.eb(a, b);
  P a[17][17]{};
  FOR(i, N) FOR(k, M) {
    a[i][k] = read();
    if (se.contains(a[i][k])) se.extract(a[i][k]);
  }
  vector<PII> ps;
  FOR(i, N) FOR(k, M) if (a[i][k].fi == 1 or a[i][k].fi == 0) ps.ep(i, k);

  Z f = [&](int x, int y) -> bool {
    set<char> se;
    FOR(i, 3) FOR(k, 3) se.eb(a[x + i][y + k].se);
    if (len(se) == 1) return true;
    se.clear();
    FOR(i, 3) FOR(k, 3) se.eb(a[x + i][y + k].fi);
    return len(se) == 9;
  };
  Z check = [&]() -> tuple<bool, PII, PII> {
    FOR(i, N - 2) FOR(k, M - 2) {
      if (f(i, k)) {
        FOR(x, N - 2) FOR(y, M - 2) {
          if (std::abs(x - i) > 2 or std::abs(y - k) > 2) {
            if (f(x, y)) return {true, {i, k}, {x, y}};
          }
        }
      }
    }
    return {false, {}, {}};
  };

  if (len(ps) == 0) {
    Z [ok, a, b] = check();
    if (ok) {
      print("Solution exists.");
      print("There are no jokers.");
      print(std::format("Put the first square to ({}, {}).", a.fi + 1, a.se + 1));
      print(std::format("Put the second square to ({}, {}).", b.fi + 1, b.se + 1));
      return;
    }
  } else if (len(ps) == 1) {
    Z [x, y] = ps[0];
    P king = a[x][y];
    for (Z p : se) {
      a[x][y] = p;
      Z [ok, a, b] = check();
      if (ok) {
        print("Solution exists.");
        print(std::format("Replace {} with {}.", to_s(king), to_s(p)));
        print(std::format("Put the first square to ({}, {}).", a.fi + 1, a.se + 1));
        print(std::format("Put the second square to ({}, {}).", b.fi + 1, b.se + 1));
        return;
      }
    }
  } else {
    if (a[ps[0].fi][ps[0].se] == P{1, 1}) swap(ps[0], ps[1]);
    Z [x, y] = ps[0];
    Z [xx, yy] = ps[1];
    P king = a[x][y], king1 = a[xx][yy];
    for (Z p : se) {
      for (Z pp : se) {
        if (p == pp) continue;
        a[x][y] = p;
        a[xx][yy] = pp;
        Z [ok, a, b] = check();
        if (ok) {
          print("Solution exists.");
          print(std::format("Replace {} with {} and {} with {}.", to_s(king), to_s(p), to_s(king1), to_s(pp)));
          print(std::format("Put the first square to ({}, {}).", a.fi + 1, a.se + 1));
          print(std::format("Put the second square to ({}, {}).", b.fi + 1, b.se + 1));
          return;
        }
      }
    }
  }
  print("No solution.");
}
#include "YRS/Z_H/main.hpp"