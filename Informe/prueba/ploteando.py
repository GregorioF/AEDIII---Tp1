import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import random
import numpy as np
def a():
	df = pd.DataFrame()
	x = []
	y = []
	v = []
	for i in range(50):
	    for j in range(50):
	        x.append(j)
	        y.append(i)
	        v.append((i+j)**2)
	df['value'] = v
	df['x'] = x
	df['y'] = y

	plt.clf()
	for i in [0,9,29,39,49]:
	    df[df['y'] == i].plot(x='x',y='value')
	plt.show()


def b():
	nodos = pl.frange(0,50,0.1)
	clique = [x**5 for x in nodos]
	a = [random.normalvariate(x**2,0.5) for x in nodos]
	b = [random.normalvariate(x**2.5,0.5) for x in nodos]

	plt.clf()
	df = pd.DataFrame({'Algoritmo A': a[0:50], 'Algoritmo B': b[0:50], 'Clique máxima': clique[0:50]})
	df.plot(x='Clique máxima')

	plt.show()

b()