/* --------------------------------------------------------- *\
* Ejercicio 20 *
    (a) Calcula la longitud de una cadena;
    (b) Determina si una cadena dada es vacía.
    (c) Concatena dos cadenas.


* Ejercicio 21 *
    (a) Construya un programa de testeo para cada función del ejercicio anterior
\* --------------------------------------------------------- */
#include <assert.h>
#include <stdlib.h>

/* ------------------- Declaraciones de funciones ------------------- */

int cadenaLongitud(const char* cadena);
int cadenaEsVacia(const char* cadena);
char* cadenaConcatenar(const char* cadena1,const char* cadena2);
int cadenaAreEqual(const char* cadena1,const char* cadena2);
char caracterFinal = '\0';
char* cadenaVacia = "\0";


/* ------------------- main ------------------- */

int main(){
    const char* holamundo = "hola mundo\0";
    const char* chaumundo = "chau mundo\0";
    assert(cadenaLongitud(holamundo) == 10);
    assert(cadenaLongitud("") == 0);
    assert(cadenaEsVacia(holamundo) == 0);
    assert(cadenaEsVacia("vacia") == 0);
    assert(cadenaEsVacia(cadenaVacia) == 1);
    assert(cadenaEsVacia("") == 1);
    assert(cadenaLongitud(cadenaConcatenar(holamundo,chaumundo)) == 20);
    assert(cadenaEsVacia(cadenaConcatenar("","")) == 1);
    assert(cadenaAreEqual(cadenaConcatenar(holamundo,chaumundo),"hola mundochau mundo") == 1);
    assert(cadenaAreEqual(cadenaConcatenar("estas cadenas ","estan concatenadas"),"estas cadenas estan concatenadas") == 1);
    assert(cadenaLongitud(cadenaConcatenar(holamundo,chaumundo)) == 20);
}

/* ------------------- FUNCIONES ------------------- */
// length
int cadenaLongitud(const char* cadena){
    int longitud = 0;
    while(cadena[longitud] != caracterFinal)
        longitud++;
    return longitud;
}
/* --------------------------------------------------------- */
// isEmpty
int cadenaEsVacia(const char* cadena){    
    return cadena[0] == caracterFinal ? 1 : 0;
}
/* --------------------------------------------------------- */
// concatenate
char* cadenaConcatenar(const char* cadena1,const char* cadena2){
    int longitud_cadena = cadenaLongitud(cadena1)+cadenaLongitud(cadena2);
    if(longitud_cadena == 0)
        return cadenaVacia;
    char* cadenaNueva = malloc(longitud_cadena * sizeof *cadenaNueva);
    if(cadenaNueva){
        for(int i = 0 ; cadena1[i] != caracterFinal; i++)
            cadenaNueva[i] = cadena1[i];
        for(int i = 0, j = cadenaLongitud(cadena1); cadena2[i] != caracterFinal; i++, j++)
            cadenaNueva[j] = cadena2[i];
        cadenaNueva[cadenaLongitud(cadena1)+cadenaLongitud(cadena2)] = caracterFinal;
        // para no retornar la direccion de una variable local
        char* cadenaARetornar = cadenaNueva;
        free(cadenaNueva);
        return cadenaARetornar;
    }
    return cadenaVacia;
}
/* --------------------------------------------------------- */
// areEqual
int cadenaAreEqual(const char* cadena1,const char* cadena2){
    for(int i = 0 ; cadena1[i] != caracterFinal || cadena2[i] != caracterFinal; i++)
        if(cadena1[i] != cadena2[i])
            return 0;
    return 1;
}