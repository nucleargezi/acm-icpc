#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
using RE = long double;
struct P {
  RE x, y, z;
};
P add(P a, P b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}
P sub(P a, P b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}
P div(P a, RE w) {
  a.x /= w;
  a.y /= w;
  a.z /= w;
  return a;
}
P mul(P a, RE w) {
  a.x *= w;
  a.y *= w;
  a.z *= w;
  return a;
}
RE dist(P a, P b) {
  RE x = a.x - b.x, y = a.y - b.y, z = a.z - b.z;
  return sqrtl(x * x + y * y + z * z);
}
constexpr RE eps = 1e-8;
bool eq(RE x, RE y) {
  return std::abs(x - y) < eps;
}
void Yorisou() {
  INT(N);
  vector<P> a(N + 1);
  FOR(i, N + 1) IN(a[i].x, a[i].y, a[i].z);
  REA(v, vv);
  P st;
  IN(st.x, st.y, st.z);
  RE s = 0;
  FOR(i, N) s += dist(a[i + 1], a[i]);
  setp(10);
  if (s * v < dist(a[N], st) * vv)
    return NO();
  else if (eq(s * v, dist(a[N], st) * vv)) {
    return YES(),
           print(s / vv),
           print(a[N].x, a[N].y, a[N].z);
  }
  P ans;
  YES();
  print(binary_search_real<RE>([&](RE m) -> bool {
    RE al = vv * m;
    int idx = -1;
    FOR(i, N) {
      if (al >= dist(a[i + 1], a[i])) {
        al -= dist(a[i + 1], a[i]);
      } else {
        idx = i;
        break;
      }
    }
    if (idx == -1) idx = N;
    P p = a[idx];
    if (al > 1e-6 and idx != N) {
      P t = mul(div(sub(a[idx + 1], a[idx]), dist(a[idx + 1], a[idx])), al);
      p = add(p, t);
    }
    return dist(st, p) <= m * v ? ans = p, true : false;
  }, s / vv, 0));
  print(ans.x, ans.y, ans.z);
}
#include "YRS/Z_H/main.hpp"