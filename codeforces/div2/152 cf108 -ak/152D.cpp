#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/ds/basic/retsu.hpp"

struct rec {
  int x, y, xx, yy;
  rec to() const { return {x + 1, y + 1, xx - 1, yy - 1}; }
  int C() const { return (xx - x + yy - y) << 1; }
};

int ins(const rec &a, const rec &b) {
  int x = min(a.xx, b.xx) - max(a.x, b.x) + 1;
  int y = min(a.yy, b.yy) - max(a.y, b.y) + 1;
  return max(x, 0) * max(y, 0);
}

int fra(const rec &a, const rec &b) { return ins(a, b) - ins(a.to(), b); }

int fra_ins (const rec &a, const rec &b)  {
  rec aa = a.to(), bb = b.to();
  return ins(a, b) - ins(aa, b) - ins(a, bb) + ins(aa, bb);
};

void Yorisou() {
  INT(N, M);
  VEC(string, mp, N);
  retsu<int> pr(N + 1, M + 1);
  int tt = 0, sx = -1, sy;
  FOR(i, N) FOR(k, M) {
    int x = mp[i][k] == '#';
    if (x and sx == -1) sx = i, sy = k;
    tt += x;
    pr[i + 1][k + 1] = x;
  }
  pr.pres();

  Z prod = [&](const rec &a) -> int {
    return pr.prod(a.x, a.xx + 1, a.y, a.yy + 1);
  };
  Z ck = [&](const rec &a) -> bool {
    if (a.xx - a.x < 2 or a.yy - a.y < 2) return 0;
    return prod(a) - prod(a.to()) == a.C();
  };
  if (tt < 8 or tt > 4 * N + 4 * M - 8) return NO();
  rec rs, rss;
  bool ok = 0;
  FOR(x, sx + 2, N) FOR(y, sy + 2, M) if (not ok) {
    rec A(sx, sy, x, y);
    if (not ck(A)) continue;
    int re = tt - A.C();
    if (re == 0) {
      rs = rss = A;
      ok = 1;
      break;
    }
    Z kn = [&](int x) {
      rec s(0, 0, x, M - 1);
      return prod(s) - fra(A, s);
    };
    Z km = [&](int y) {
      rec s(0, 0, N - 1, y);
      return prod(s) - fra(A, s);
    };
    int buf[4];
    buf[0] = bina([&](int x) { return kn(x) >= 1; }, N - 1, -1);
    buf[1] = bina([&](int x) { return kn(x) >= re; }, N - 1, -1);
    buf[2] = bina([&](int x) { return km(x) >= 1; }, M - 1, -1);
    buf[3] = bina([&](int x) { return km(x) >= re; }, M - 1, -1);
    for (int x : {buf[0], A.x, A.xx}) {
      for (int xx : {buf[1], A.x, A.xx}) {
        for (int y : {buf[2], A.y, A.yy}) {
          for (int yy : {buf[3], A.y, A.yy}) {
            rec B(x, y, xx, yy);
            if (not ck(B)) continue;
            if (A.C() + B.C() - fra_ins(A, B) == tt) rs = A, rss = B, ok = 1;
          }
        }
      }
    }
  }
  
  if (not ok) return NO();
  YES();
  for (var [x, y, xx, yy] : {rs, rss}) {
    print(x + 1, y + 1, xx + 1, yy + 1);
  }
}

int main() {
  Yorisou();
  return 0;
}