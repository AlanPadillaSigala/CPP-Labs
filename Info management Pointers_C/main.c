#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMBRE 15
#define TIPO 18
#define MODELO 15
#define TAM_COMP 3
#define INICIO 0

typedef struct componentes{
    int id;
    char nombre[NOMBRE];
    float precio;
    char tipo[TIPO];
    char modelo[MODELO];
}comp;

enum opcionesMenuPrincipal{
    AGREGAR = 1,
    AGREGAR_DEFAULT,
    MOSTRAR_PRODUCTOS,
    ORDENAR,
    ELIMINAR
};
enum menuTipo{
   MOTHERBOARD = 1,
   PROCESADOR,
   DISCO_DURO,
   RAM,
   TARJETA_V
};
enum menuMostrar{
    MUESTRA_TODO = 1,
    MUESTRA_TIPO
};

enum quick{
    ID,
    PRECIO,
    NOMBRES
};

void menuprincipal(comp** producto);
void agregar(comp** producto, int tam, int idaux);
comp* iniciliza_producto(int ide, char* nombre, float precio, char* tipo, char* modelo);
void mostrar(comp** producto, int tam);
void imprimir(comp* productito);
void ordenar(comp** produto, int tam);
void quicksort(comp **arr, int inicio, int fin, int opcion, int (* compara) (comp*, comp*, int));
int compara(comp* pivote, comp* productito);
void eliminar(comp** producto, int tam);
comp** agrega_default(comp** info, int n, int indice);
comp* crea_default(const int ide, const char * nom, const float pre, const char * tip, const char * nom_mod);

//--------------------------------------------------------------------------------------
int main()
{
    comp** producto = (comp**) malloc (TAM_COMP * sizeof(comp*));
    menuprincipal(producto);
    return 0;
}
//--------------------------------------------------------------------------------------

void menuprincipal(comp** producto){
    int res, cont = 0, idaux = 0;

    do{
        printf("--------------*  Menu  *----------------\n");
        printf("1.Agregar \n");
        printf("2.Agrega default \n");
        printf("3.Mostrar \n");
        printf("4.Ordenar \n");
        printf("5.Eliminar \n");
        printf("Cualquier tecla para salir");
        printf("\nOpcion: ");
        scanf("%i", &res);
        printf("\n--------------------------------------\n");
        switch(res){
            case AGREGAR:{
                cont ++;
                idaux ++;
                if(cont > TAM_COMP){
                    producto = (comp**) realloc (producto, cont * sizeof(comp*));
                }
                agregar(producto, cont, idaux);
                break;
            }
            case AGREGAR_DEFAULT:{
                if((cont+TAM_COMP > TAM_COMP) && cont<TAM_COMP){
                    producto=(comp**)realloc(producto,(TAM_COMP-cont)*sizeof(comp*));
                }
                else{
                    producto=(comp**)realloc(producto,TAM_COMP * sizeof (comp*));
                }
                producto=agrega_default(producto,idaux,cont);
                cont+=TAM_COMP;
                idaux+=TAM_COMP;
                break;
            }
            case MOSTRAR_PRODUCTOS:{
                mostrar(producto, cont);
                break;
            }
            case ORDENAR:{
                ordenar(producto, cont);
                break;
            }
            case ELIMINAR:{
                eliminar(producto, cont);
                cont --;
                producto = (comp**) realloc (producto, cont * sizeof(comp*));
                break;
            }
            default:{
                break;
            }
        }
    }while(res > 0 && res < 6);
    //menuPrincipal(producto);
}

void agregar(comp** producto, int tam, int idaux){
    int ide, res = 0;
    float precio;
    char* nombre, *modelo, *tipo;
    nombre = (char *) malloc (NOMBRE * sizeof(char));
    modelo = (char *) malloc (MODELO * sizeof(char));
    tipo = (char *) malloc (TIPO * sizeof(char));
    ide = idaux;
    printf("\nNombre: ");
    fflush(stdin);
    scanf("%s",nombre);
    printf("\nPrecio: ");
    scanf("%f", &precio);
    fflush(stdin);
    printf("\nModelo: ");
    fflush(stdin);
    scanf("%s",modelo);
   do{
        printf("Tipo: \n");
        printf("1.Motherboard \n");
        printf("2.Procesador \n");
        printf("3.Disco Duro \n");
        printf("4.Memoria RAM \n");
        printf("5.Tarjeta de Video\n");
        printf("Respuesta: ");
        scanf("%i", &res);
        switch(res){
            case MOTHERBOARD:{
                strcpy(tipo, "Motherboard");
                break;
            }
            case PROCESADOR:{
                strcpy(tipo, "Procesador");
                break;
            }
            case DISCO_DURO:{
                strcpy(tipo, "Disco Duro");
                break;
            }
            case RAM:{
                strcpy(tipo, "Memoria RAM");
                break;
            }
            case TARJETA_V:{
                strcpy(tipo, "Tarjeta de Video");
                break;
            }
        }
    }while(res < 1 && res > 5);

    producto[tam-1] = iniciliza_producto(ide, nombre, precio, tipo, modelo);

    free(nombre);
    free(tipo);
    free(modelo);
}

comp* iniciliza_producto(int ide, char* nombre, float precio, char* tipo, char* modelo){
    comp* dato = (comp*) malloc (TAM_COMP * sizeof(comp));
    dato -> id = ide;
    strcpy(dato -> nombre, nombre);
    dato -> precio = precio;
    strcpy(dato -> tipo, tipo);
    strcpy(dato -> modelo, modelo);
    return dato;
    free(dato);
}

void mostrar(comp** producto, int tam){
    int res, i;
    char * tipo;
    tipo = (char *) malloc (TIPO * sizeof(char));
    printf("Mostrar: \n1) Todo \n2) Tipo\n");
    scanf("%i", &res);

    switch (res) {
        case MUESTRA_TODO:{
            for(i = 0; i < tam; i++){
                imprimir(producto[i]);
            }
            break;
        }
        case MUESTRA_TIPO:{
            printf("Tipo: \n");
            printf("1.Motherboard \n");
            printf("2.Procesador \n");
            printf("3.Disco Duro \n");
            printf("4.Memoria RAM \n");
            printf("5.Tarjeta de Video\n");
            printf("Respuesta: ");
            scanf("%i", &res);
            switch(res){
                case MOTHERBOARD:{
                    strcpy(tipo, "Motherboard");
                    break;
                }
                case PROCESADOR:{
                    strcpy(tipo, "Procesador");
                    break;
                }
                case DISCO_DURO:{
                    strcpy(tipo, "Disco Duro");
                    break;
                }
                case RAM:{
                    strcpy(tipo, "Memoria RAM");
                    break;
                }
                case TARJETA_V:{
                    strcpy(tipo, "Tarjeta de Video");
                    break;
                }
            }
            for(i = 0; i < tam; i++){
                if(strcmp(producto[i] -> tipo,tipo) == 0){
                    imprimir(producto[i]);
                }
            else{
                    printf("\nNo hay tipos en el producto %i :(\n",i+1);
                }
            }
            break;
        }
    }
    free(tipo);
}

void imprimir(comp* valor){
    printf("\n------------------------------------\n");
    printf("\nID: %i", valor->id);
    printf("\nNombre: %s", valor->nombre);
    printf("\nPrecio: %.2f", valor->precio);
    printf("\nTipo: %s", valor->tipo);
    printf("\nModelo: %s\n\n\n", valor->modelo);
    printf("\n------------------------------------\n");
}

void ordenar(comp** producto, int tam){
    int res = 0;
    printf("\nOrdenar Por: \n1.Id \n2.Precio \n3.Nombre producto\n");
    printf("Opcion: ");
    scanf("%i", &res);

    quicksort(producto, INICIO , tam-1, res, &compara);
}

int compara(comp* pivote, comp* productito){
    comp* p1 = (comp*) pivote;
    comp* p2 = (comp*) productito;
    // strcmp regresa:
    // < 0 cuando es menor
    // == 0 cuando son iguales
    // > 0 cuando es mayor
    return strcmp(p1->nombre, p2->nombre);
}

void eliminar(comp** producto, int tam){
    int ide, pos = -1, i;
    printf("Ingrese el id a eliminar: ");
    scanf("%d", &ide);

    for(i = 0; i < tam; i++){
        if(producto[i]->id == ide){
            pos = i;
            break;
        }
    }

    for(i = pos; i < tam; i++){
        producto[i] = producto[i+1];
    }
}

void quicksort(comp **arr, int inicio, int fin, int opcion, int (* compara) (comp*, comp*, int)){
    comp* pivote = (comp*) malloc (TAM_COMP * sizeof(comp));;
    int medio = (inicio+fin)/2;
    int i = inicio, j = fin;
    switch (opcion) {
        case ID:{
            pivote->id=arr[medio]->id;
            do{
                while(compara(arr[i], pivote, opcion) < 0  && i<=fin){
                    i++;
                }
                while(compara(arr[j], pivote, opcion) > 0 && inicio<j){
                    j--;
                }
                if(i<=j){
                    comp* aux = arr[i];
                    arr[i] = arr[j];
                    arr[j] = aux;
                    i++;
                    j--;
                }
            }while(i <= j);
            break;
        }
        case PRECIO:{
            pivote->precio=arr[medio]->precio;
            do{
                while(compara(arr[i], pivote, opcion) < 0  && i<=fin){
                    i++;
                }
                while(compara(arr[j], pivote, opcion) > 0 && inicio<j){
                    j--;
                }
                if(i<=j){
                    comp* aux = arr[i];
                    arr[i] = arr[j];
                    arr[j] = aux;
                    i++;
                    j--;
                }
            }while(i <= j);
            break;
        }
        case NOMBRES:{
            strcpy(pivote -> nombre,arr[medio] -> nombre);
            do{
                while(compara(arr[i], pivote, opcion) < 0 && i<=fin){
                    i++;
                }
                while(compara(arr[j], pivote, opcion) > 0 && inicio<j){
                    j--;
                }
                if(i<=j){
                    comp* aux = arr[i];
                    arr[i] = arr[j];
                    arr[j] = aux;
                    i++;
                    j--;
                }
            }while(i <= j);
            break;
        }
    }

    if(inicio < j){
        quicksort(arr, inicio, j, opcion, compara);
    }
    if(i < fin){
        quicksort(arr, i, fin, opcion, compara);
    }
}

comp** agrega_default(comp** info, int n, int indice){
    n++;
    //n += ide;
    info[indice] = crea_default(n, "Nvidia", 1500.25,"Tarjeta de Video", "RTX 3050");
    indice++;
    n ++;
    info[indice] = crea_default(n, "AMD", 700.20, "Procesador", "RYZEN 5");
    indice++;
    n ++;
    info[indice] = crea_default(n, "WD", 880.70,"Disco Duro", "SSD");
    return info;
}

// Función para inicializar un producto predefinido
comp* crea_default(const int ide, const char * nom, const float pre, const char * tip, const char * nom_mod){
    comp* dato = (comp*) malloc (TAM_COMP * sizeof(comp));
    dato -> id = ide;
    strcpy(dato -> nombre, nom);
    dato -> precio = pre;
    strcpy(dato -> tipo, tip);
    strcpy(dato -> modelo, nom_mod);
    return dato;
    free(dato);
}



