#!/usr/bin/env python
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from decimal import * 
import datetime

# Abrimos el archivo de la comunicacón
archivo = open("comunicacion.txt", "r")

# Leemos el archivo
entrada = archivo.read()

# Separamos por comas
separar = entrada.split(",")

#Convertimos a número
terminos = {}
i = 0
for t in separar:
	terminos[i] = float(t)
	i += 1

# Tipo de ecuación (n de términos - 1)
tipo = len(terminos) - 1

# Leemos el rango para graficar
print("Dame el rango para graficar [x1, x2]")
x1 = float(raw_input(" x1: "))
x2 = float(raw_input(" x2: "))

# Rango de la función
x = np.arange(x1, x2)

# Dependiendo del tipo de ecuación es la función
if tipo == 1:
	y = (x * terminos[0]) +  terminos[1]
	# u es unicode
	plt.title(u"{0}x + {1} = 0".format(terminos[0], terminos[1]))
elif tipo == 2:
	y = ((x**2) * terminos[0]) + (x * terminos[1])
	y += Decimal(terminos[2])

	plt.title(u"{0}x² + {1}x + {2} = 0".format(
		terminos[0], terminos[1], terminos[2]))
elif tipo == 3:
	y = (x**3 * terminos[0]) + ((x**2) * terminos[1])
	y += (x * terminos[2]) + terminos[3]
	plt.title(u"{0}x³ + {1}x² + {2}x + {3} = 0".format(
		terminos[0], terminos[1], terminos[2], terminos[3]))

# Graficamos, formateamos y guardamos con nombre de la fecha y hora
plt.plot(x, y)
plt.grid()
time = datetime.datetime.now().strftime("%Y-%m-%d %H·%M")
plt.savefig("graficas/{0}.png".format(time))