#!/usr/bin/env python
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import time
from scipy.interpolate import spline

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
x1 = float(input(" x1: "))
x2 = float(input(" x2: "))

# Rango de la función
x = np.arange(x1, x2)

# Damos el formato para poder graficar 
fig = plt.figure()

# Dependiendo del tipo de ecuación es la función
if tipo == 1:
	y = (x * terminos[0]) +  terminos[1]
	# u es unicode
	# {:g} trunca los ceros sobrantes y los puntos inecesarios en los números
	# fontsize y fontweight dan formato al título
	fig.suptitle(u"{:g}x + {:g} = 0".format(terminos[0], terminos[1]),
		fontsize=14, fontweight='bold')
elif tipo == 2:
	y = ((x**2) * terminos[0]) + (x * terminos[1]) + terminos[2]
	fig.suptitle(u"{:g}x² + {:g}x + {:g} = 0".format(
		terminos[0], terminos[1], terminos[2]), fontsize=14, fontweight='bold')
elif tipo == 3:
	y = (x**3 * terminos[0]) + ((x**2) * terminos[1])
	y += (x * terminos[2]) + terminos[3]
	fig.suptitle(u"{:g}x³ + {:g}x² + {:g}x + {:g} = 0".format(
		terminos[0], terminos[1], terminos[2], terminos[3]),
		fontsize=14, fontweight='bold')

# sx y sy es la función ya suavizada (para mejor apariencia)
sx = np.linspace(x.min(), x.max(), 300)
sy = spline(x, y, sx)
# Creamos la gráfica
plt.plot(sx, sy)
# Agregamos ejes y cuadrícula
plt.grid()
plt.axhline(0, color='black')
plt.axvline(0, color='black')

# Ruta donde se va a guardar el archivo con fecha y hora
nombre = "graficas/{0}-{1}-{2} {3}:{4}:{5}.png".format(
	time.strftime('%Y'),
	time.strftime('%m'),
	time.strftime('%d'),
	time.strftime('%H'),
	time.strftime('%M'),
	time.strftime('%S'))

# Guardamos y avisamos de ello
plt.savefig(nombre, bbox_inches="tight")
print("Tú gráfica se ha guardado en \"{0}\"".format(nombre))
