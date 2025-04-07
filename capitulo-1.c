/* --------------------------------------------------------- *\
* Ejercicio 20 *
    (a) Calcula la longitud de una cadena;
    (b) Determina si una cadena dada es vacía.
    (c) Concatena dos cadenas.


* Ejercicio 21 *
    (a) Construya un programa de testeo para cada función del ejercicio anterior
\* --------------------------------------------------------- */
#include <assert.h>

/* ------------------- Declaraciones de funciones ------------------- */

int cadenaLongitud(const char* cadena);
int cadenaEsVacia(const char* cadena);
char* cadenaConcatenar(const char* cadena1,const char* cadena2);
int cadenaAreEqual(const char* cadena1,const char* cadena2);

/* ------------------- main ------------------- */

int main(){
    const char* holamundo = "hola mundo";
    const char* chaumundo = "chau mundo";
    assert(cadenaLongitud(holamundo) == 10);
    assert(cadenaLongitud("") == 0);
    assert(cadenaEsVacia(holamundo) == 0);
    assert(cadenaEsVacia("vacia") == 0);
    assert(cadenaEsVacia("") == 1);
    assert(cadenaLongitud(cadenaConcatenar(holamundo,chaumundo)) == 20);
    assert(cadenaEsVacia(cadenaConcatenar("","")) == 1);
    assert(cadenaAreEqual(cadenaConcatenar(holamundo,chaumundo),"hola mundochau mundo") == 1);
    assert(cadenaAreEqual(cadenaConcatenar("estas cadenas ","estan concatenadas"),"estas cadenas estan concatenadas") == 1);
    // assert(cadenaLongitud(cadenaConcatenar(holamundo,chaumundo)) == 20);
    // cadenaConcatenar de linea 34 devuelve "hola mundochau mundoconcatenadas" --> "estas cadenas estan" == 20 chars
}

/* ------------------- FUNCIONES ------------------- */
// length
int cadenaLongitud(const char* cadena){
    int longitud = 0;
    for(int i = 0; cadena[i] != '\0'; i++)
        longitud++;
    return longitud;
}
/* --------------------------------------------------------- */
// isEmpty
int cadenaEsVacia(const char* cadena){
    return cadena[0] == '\0' ? 1 : 0;
}
/* --------------------------------------------------------- */
// concatenate
char* cadenaConcatenar(const char* cadena1,const char* cadena2){
    char cadenaNueva[cadenaLongitud(cadena1)+cadenaLongitud(cadena2)];
    for(int i = 0 ; cadena1[i] != '\0'; i++)
        cadenaNueva[i] = cadena1[i];
    for(int i = 0, j = cadenaLongitud(cadena1); cadena2[i] != '\0'; i++, j++)
        cadenaNueva[j] = cadena2[i];
    // para no retornar la direccion de una variable local
    char* cadenaARetornar = cadenaNueva;
    return cadenaARetornar;
}
/* --------------------------------------------------------- */
// areEqual
int cadenaAreEqual(const char* cadena1,const char* cadena2){
    for(int i = 0 ; cadena1[i] != '\0' || cadena2[i] != '\0'; i++)
        if(cadena1[i] != cadena2[i])
            return 0;
    return 1;
}