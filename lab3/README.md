# Enunciado posible

## Enunciado tomado de un libro...

Una manera interesante de calcular $\pi$ es utilizar una técnica conocida como Monte Carlo, la cual involucra aleatorización. Esta técnica funciona de la siguiente manera: Suponga que tiene un círculo inscrito dentro de un cuadrado, como se muestra en la siguiente figura (Asuma que el radio de este círculo es 1).

<p align="center">
  <img src="montecarlo.png" alt="Texto alternativo" width="500">
  <br>
  <em>Tecnica de Montecarlo para el calculo de PI</em>
</p>


Primero, genere una serie de puntos aleatorios como coordenadas simples $(x, y)$. Estos puntos deben caer dentro de las coordenadas Cartesianas que delimitan el cuadrado. Del número total de puntos aleatorios que se generan, algunos ocurrirán dentro del círculo.A continuación, estime $\pi$ realizando el siguiente cálculo:

$$\pi \approx 4 \times (\text{número de puntos en el círculo}) / (\text{número total de puntos})$$

Escriba una versión multihilo de este algoritmo que cree un hilo separado para generar una cantidad de puntos aleatorios. El hilo contará el número de puntos que ocurran dentro del círculo y almacenará ese resultado en una variable global. Cuando este hilo haya finalizado, el hilo padre calculará y mostrará el valor estimado de $\pi$. Vale la pena experimentar con el número de puntos aleatorios generados. Como regla general, cuanto mayor sea el número de puntos, más cercana será la aproximación a $\pi$. 



## Referencias

1. http://misovirtual.virtual.uniandes.edu.co:8080/codelabs/maia-rl-montecarlo/index.html#0
2. https://colab.research.google.com/github/aizardar/blogs/blob/master/_notebooks/2020-11-18-Pi_Monte_Carlo.ipynb
3. https://www.101computing.net/estimating-pi-using-the-monte-carlo-method/
4. https://www3.nd.edu/~pbui/teaching/cdt.30010.fa16/notebook03.html
5. https://github.com/MylesJohnson/Monte-Carlo-Pi

