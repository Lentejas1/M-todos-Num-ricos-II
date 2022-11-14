import matplotlib.pyplot as plt

path = "C:/Users/minih/Documents/GitHub/M-todos-Num-ricos-II/cmake-build-debug/Ablacio.csv"

with open(path, "r") as f:
    matrix = f.readlines()

print(matrix)