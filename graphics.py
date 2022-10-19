import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# noinspection SpellCheckingInspection
df = pd.read_csv("C:/Users/minih/Documents/GitHub/M-todos-Num-ricos-II/cmake-build-debug/derivatives.csv")
print(df)
columns = df.keys()

x = np.array([i/1000 for i in range(int(10E5))])
f = df[columns[0]].to_numpy()
fp = df[columns[1]].to_numpy()
fpp = df[columns[2]].to_numpy()

plt.plot(x, f, label="$f(x)$")
plt.plot(x, fp, label="$f'(x)$")
plt.plot(x, fpp, label="$f''(x)$")

plt.legend()

plt.show()
