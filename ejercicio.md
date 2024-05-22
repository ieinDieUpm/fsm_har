# Ejercicio

**En este ejercicio se trata de comprobar el funcionamiento de un sistema de reconocimiento de actividad física basado en un acelerómetro analógico, FSM y un modelo kNN de clasificación.**

**Ponga puntos de parada en las siguientes ficheros/ funciones para poder ver los valores de las variables:**

* `interr.c`: **cuando salta la ISR del timer y lee y convierte 1 dato**
* `do_store_data()`: **para cuando se guarda un dato leído del acelerómetro**
* `do_compute_features()`: **para cuando se han guardado 5 segundos de datos y se calculan las features**
* `do_compute_activity()`: **para cuando se han calculado las 21 features y se calcula la actividad**

## Preguntas

**1. El programa no compila porque hay varias funciones que no están implementadas. Implemente las funciones que faltan.**

* Completar la función: `_compute_max()`
* Completar la función: `_compute_min()`
* Completar la función: `_compute_mean()`
* Completar la función: `_compute_variance()`
* Completar las llamadas a las funciones anteriores en la función: `do_compute_features()` y el cálculo de la desviación estándar y la amplitud.


**2. Compruebe que el código funciona correctamente y súbalo a Moodle.**

Ejecute el código y haga captura 1 captura de pantalla que muestre en la terminal SWO el valor de las features calculadas y la primera actividad inferida. También que se muestre el valor de las variables en el menú de VARIABLES durante la depuración.

Ponga la captura de pantalla en la carpeta /docs/assets/imgs del proyecto con el nombre `ejercicio.png`.

Compruebe que los valores son los correctos utilizando el fichero `har_comprueba_ejercicio.xlsx` que se encuentra en la carpeta /docs/assets/xlsx.

Suba el proyecto a Moodle en un archivo comprimido con el nombre `fsm_har_apellido1_nombre.zip`.
