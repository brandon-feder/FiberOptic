import numpy as np
from matplotlib import pyplot as plt

file = open("./points.out", "r")
raw = file.read().split("\n")
file.close()

X = []
Y = []

for pair in raw[0:-1]:
    cords = pair.split(" ")
    print(cords)
    X.append(float(cords[0])) 
    X.append(float(cords[2]))
    Y.append(float(cords[1])) 
    Y.append(float(cords[3]))

plt.plot(X, Y, 'o-')
plt.axis('equal')
plt.show()
