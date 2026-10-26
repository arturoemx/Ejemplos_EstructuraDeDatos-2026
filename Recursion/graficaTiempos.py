#! /usr/bin/python3
#encoding: utf-8

import sys
import csv
import numpy as np
from matplotlib import pyplot as plt

argc = len(sys.argv)

if argc>1:
	nombreArchivo = sys.argv[1]

	columnNames = []
	data = []
	with open(nombreArchivo) as archivo_csv:
		lector_csv = csv.reader(archivo_csv, delimiter=',')
		line_count = -1
		for row in lector_csv:
			if line_count == -1:
				columnNames = [ x for x in row]
				line_count = 0
			else:
				data.append([np.float64(x) for x in row])
				line_count += 1

	rows = len(data)
	cols = len(data[0])
	D = np.zeros((rows, cols), dtype = np.float64)
	
	i = 0
	for d in data:
		D[i,:]=data[i][:]
		i+=1
	

	fig, ax = plt.subplots()
	ax.set_title('Numero de Operaciones vs Tiempo de Ejecución')
	ax.set_ylabel('Tiempo [ns]', color='0.1')
	ax.set_xlabel('número de operaciones', color='0.1')
	iterativo = ax.plot(D[:,0], D[:,1],label=f"{columnNames[1]}")
	recursivo = ax.plot(D[:,0], D[:,2],label=f"{columnNames[2]}")
	formula = ax.plot(D[:,0], D[:,3],label=f"{columnNames[3]}")
	ax.legend()
	plt.show()