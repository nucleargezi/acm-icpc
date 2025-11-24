#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
using RE = long double;
struct P {
  RE x, y, z;
  void in() { IN(x, y, z); }
};
P ad(P a, P b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
P sb(P a, P b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
ll sq(ll x) { return x * x; }
P det(P a, P b) {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
RE dot(P a, P b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
void Yorisou() {
  P a, d;
  a.in(), d.in();
  LL(R);
  RE ans = inf<ll> - 1;
  Z f = [&](P o, ll r) -> void {
    o = sb(o, a);
    ll A = dot(d, d);
    ll B = -2 * dot(d, o);
    ll C = dot(o, o) - sq(r + R);
    ll dis = B * B - 4 * A * C;
    if (dis < 0 or B >= 0) return;
    RE d = sqrtl(dis);
    chmin(ans, (-B - d) / (A + A));
  };
  Z g = [&](P s, P t) -> void {
    f(ad(s, t), 0);
    P x = det(sb(a, s), t), y = det(d, t);
    ll A = dot(y, y);
    ll B = dot(x, y) * 2;
    ll C = dot(x, x) - R * R * dot(t, t);
    if (A == 0) return;
    ll dis = B * B - 4 * A * C;
    if (dis < 0 or B >= 0) return;
    RE rr = sqrtl(dis);
    RE tl = (-B - rr) / (A + A), tr = (-B + rr) / (A + A);
    A = dot(sb(a, s), t);
    B = dot(d, t);
    C = dot(t, t);
    if (0 <= tl and 0 <= A + tl * B and A + tl * B <= C) chmin(ans, tl);
    if (0 <= tr and 0 <= A + tr * B and A + tr * B <= C) chmin(ans, tr);
  };
  INT(N);
  FOR(N) {
    P o;
    o.in();
    LL(r);
    f(o, r);
    INT(sz);
    FOR(sz) {
      P t;
      t.in();
      g(o, t);
    }
  }
  setp(10);
  if (ans >= inf<ll> - 2) print(-1);
  else print(ans);
}
#include "YRS/Z_H/main.hpp"