from fractions import Fraction
from collections import Counter
import sys

def Meion_is_UMP45():
    n = int(input())
    points = [tuple(map(int, input().split())) for _ in range(n)]
    qx = [x for x, y in points]
    cnt = Counter(qx)
    qx = sorted(set(qx))
    sz = len(qx)
    mx = cnt[max(cnt, key = cnt.get)]

    def quis(x):
        print(f"? {x.numerator} {x.denominator}")
        sys.stdout.flush()
        a, b = map(int, input().split())
        return Fraction(a, b)
    def answer(f):
        print(f"! {f.numerator} {f.denominator}")
        sys.stdout.flush()
    if mx == 1:
        get = []
        for i, x in enumerate(qx):
            if (i == 0 and cnt[x] == 1) or (i + 1 == sz and cnt[x] == 1):
                get.append(Fraction(0))
            else:
                get.append(quis(Fraction(x)))
        ans = Fraction(0)
        for i in range(sz - 1):
            ans += (get[i] + get[i + 1]) * (qx[i + 1] - qx[i])
        if ans.numerator % 2 == 1:
            ans = Fraction(ans.numerator, ans.denominator * 2)
        else:
            ans = Fraction(ans.numerator // 2, ans.denominator)
        answer(ans)
    else:
        ans = Fraction(0)
        for i in range(sz - 1):
            h = quis(Fraction(qx[i] + qx[i + 1]) / 2)
            ans += h * (qx[i + 1] - qx[i])
        answer(ans)

T = int(input())
for t in range(T):
    Meion_is_UMP45()