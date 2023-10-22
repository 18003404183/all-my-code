import matplotlib
from matplotlib import pyplot as plt

x = [1,2,3,4]
y = [1,2,3,4]

f_1 = plt.figure(figsize=(5,10))
plt.plot(x,y)
plt.xlabel('x')
plt.ylabel('y')
plt.show()