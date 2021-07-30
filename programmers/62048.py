# 파이썬은 최대 공약수 구하는 내장함수 존재!
from math import gcd
def solution(w,h):
    answer = 1
    total = w * h
    sub = w+h - gcd(w,h)
    answer = total-sub
    return answer