import matplotlib.pyplot as plt
import numpy as np

path = "Ablacio.txt"
matrix = []
z = np.linspace(0, 2, 200)
t = np.linspace(0, (0.51 * (2 / 200) ** 2) * 200, 200)
T, Z = np.meshgrid(t, z)

with open(path, "r") as f:
    lines = [line.rstrip() for line in f]

for line in lines:
    matrix.append(line.split(","))

for i in range(len(matrix)):
    for j in range(int(len(matrix[0]))):
        matrix[i][j] = float(matrix[i][j])

ax = plt.pcolormesh(Z, T, matrix)
plt.colorbar()
plt.title("Temperatura")
plt.ylabel("t (s)")
plt.xlabel("z (cm)")
plt.axvline(0.75, color="red")
plt.axvline(1.25, color="red")
plt.show()
