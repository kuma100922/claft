#ランダムに生成した10個の整数の順位を出力するプログラム
import random as rd

a,b,c=[],[],[]
for i in range(10):
    a.append(rd.randint(0,100))
    b=sorted(a,reverse=True)
for i in range(10):
    for j in range(10):
        if a[i]==b[j]:
            c.append(j+1)
print(a)
print(b)
print(c)