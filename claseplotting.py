import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("C:/Users/minih/Documents/GitHub/M-todos-Num-ricos-II/cmake-build-debug/population.csv")

time, preys, predators = df["Time"].to_numpy(), df["Preys"].to_numpy(), df["Predators"].to_numpy()
plt.plot(time, preys, label="Preys")
plt.plot(time, predators, label="Predators")
plt.legend()
plt.xlabel("$t$")
plt.ylabel("$N$")

plt.show()

plt.plot(preys, predators)
plt.show()
