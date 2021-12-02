ANÁLISIS DE COMPLEJIDAD TEMPORAL PARA PUSH: Para esta función existe una recursividad la cual se encarga de agregar elementos a la lista. Utiliza un heapify por lo que hay una complejidad O(n)*Log(n). O sea O(n Log(n)). Debido a que se está utilizando Heapify() se puede llegar a una complejidad O(log(n)). 

ANÁLISIS DE COMPLEJIDAD TEMPORAL PARA POP: Para esta función existe una recursividad la cual se encarga de eliminar un elemento de la lista. Utiliza un swap por lo que hay una complejidad O(n)*log(n). O sea O(nlog (n)). Debido a que se puede utilizar Heapify() se puede llegar a una complejidad 0(log(n)).

ANÁLISIS DE COMPLEJIDAD TEMPORAL PARA TOP: Esta función solo regresa el primer valor de la lista por lo que tiene una complejidad O(1).

ANÁLISIS DE COMPLEJIDAD TEMPORAL PARA SIZE: De igual forma, esta función no tiene valores de entrada y no existe una recursividad, solamente regresa el tamaño del array por lo que es una complejidad O(1).

ANÁLISIS DE COMPLEJIDAD TEMPORAL PARA EMPTY: De igual forma, esta función no tiene valores de entrada y no existe una recursividad, solamente regresa un valor booleano por si está vacía el array o no, por lo que es una complejidad O(1).

:

