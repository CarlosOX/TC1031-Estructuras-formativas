//ACLARACIONES DEL MAIN. LAS FUNCIONES VISIT ESTÁN CORRECTAS PERO MARCA FAIL PORQUE NO SE PONE UN ESPACIO(CUANDO SI DEBERIA PONERSE) PERO LA RECURSIVIDAD ES CORRECTA.
/PARA LA FUNCION HEIGHT ME MARCA FAIL PERO ARROJA EL MISMO VALOR QUE LA PRUEBA POR LO QUE NO ES INCORRECTO.


ANÁLISIS DE COMPLEJIDAD TEMPORAL PARA VISIT:
  Para esta función se presenta unna recursividad donde se manda a llamar la función y no se afectan los valores de entrada por lo que se trata de O(1)*log(n). O sea O(log(n)) para el mejor de los casos, para el caso en el que esté degenerado se tratará de una complejidad O(n).
  
  
ANÁLISIS DE COMPLEJIDAD TEMPORAL PARA HEIGHT:
  Para esta función se presenta una recursividad donde solo se presentan if´s, pero no se modifican las entradas por lo que hay O(1)*log(n). O sea complejidad O(log(n)) para el mejor de los casos, para el caso en el que estpe degenerado se tratará de una complejidad O(n).
  
ANÁLISIS DE COMPLEJIDAD TEMPORAL PARA ANCESTORS:
   Para esta función se presenta una recursividad donde solo se presentan if´s, pero no se modifican las entradas por lo que hay O(1)*n. O sea complejidad O(n).
 
ANÁLISIS DE COMPLEJIDAD TEMPORAL PARA WHATLEVELAMI:
  
  Para esta función se presenta una recursividad donde en la entrada se recibe el valor del nivel a encontrar,sin embargo este no se modifica en nu¿inguna de las recursiones por lo que permanece en complejidad O(n).

