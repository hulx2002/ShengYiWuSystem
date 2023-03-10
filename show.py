import matplotlib.pyplot as plt

file = open("out/fixace_out.txt", "r")
data = []
for line in file:
    data.append(int(line.strip()))
file.close()

x_value = []
y_value = []
for i in range(0, max(data) + 1):
    x_value.append(i)
    y_value.append(0)
for i in range(0, len(data)):
    y_value[data[i]] += 100.0 / len(data)
for i in range(1, max(data) + 1):
    y_value[i] += y_value[i - 1]

fig, ax = plt.subplots()
ax.plot(x_value, y_value)
ax.legend()

plt.show()