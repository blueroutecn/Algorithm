a = [1,2,3,4]

import operator
min_index, min_value = min(enumerate(a), key=operator.itemgetter(1))
print(min_index,min_value)

a =(1,2)
print(operator.itemgetter(1))
a = {"1":0,"2":1,"3":2}
def f(x):
    return a[x]

min(a.keys(),key = f)


print(sorted(a))
