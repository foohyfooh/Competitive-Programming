'''
Read R, S
Read N
Read N values of F
Calculate the total value of T
'''

from sys import stdin, stdout

R, S = stdin.readline().split()
R, S = float(R), float(S)
N = int(stdin.readline())

T = 2 * N
for _ in range(N):
  F = float(stdin.readline())
  T += (R - F) / S
stdout.write(str(T))
