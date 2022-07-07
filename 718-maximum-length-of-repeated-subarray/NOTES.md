class Solution(object):
def findLength(self, A, B):
B,A = sorted([A,B],key=len)
m = len(A)
n = len(B)
maxLen = 0
for a in xrange(-n+1,m+n-1):
cnt = 0
for ptrB in xrange(n):
ptrA = a+ptrB
if ptrA < 0 : continue
if ptrA >= m : break
if A[ptrA]==B[ptrB]:
cnt += 1
if cnt > maxLen: maxLen = cnt
else:
cnt = 0
return maxLen