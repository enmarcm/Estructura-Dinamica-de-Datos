//ASIGNACION PILAS - ENMANUEL COLINA 29.955.728

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// DEFINIMOS LA ESTRUCTURA CON LA QUE TRABAJAREMOS LA INFORMACION, TELEFONO
typedef struct telefono{
    char marca[50];
    char modelo[50];
    char numSerie[50];
    char lugarFabricacion[50];
    char color[50];
    int almacenamientoGB;
    int ramGB;
    int dualSim; //1 SI, 0 NO 
}Telefono;

// DEFINIMOS ESTRUCTURA NODO
typedef struct nodo{
    Telefono *dato;
    struct nodo *Siguiente;
}Nodo;

// DEFINIMOS ESTRUCTURA PILA
typedef struct pila{
    // FORMADO DE UN NODO Y DE UN ENTERO QUE SE VA AUTOINCREMENTANDO
    Nodo *tope;
    int total; 
}Pila;  

// PROTOTIPOS DE LOS METODOS
Telefono *CrearTelefono(char marca[50],char modelo[50],char numSerie[50],char lugarFabricacion[50],char color[50],int almacenamientoGB,int ramGB,int dualSim);
Nodo *CrearNodo(Telefono *telefono);
Pila *CrearPila();
int EstaVacia(Pila *pila);
void Insertar(Pila *pila, Nodo *nodo);
void Imprimir(Pila *pila);
void EliminarElemento(Pila *pila);

int main(){
    //CREAMOS UNA PILA, LUEGO UN ELEMENTO ESTRUCTURA TELEFONO, LUEGO EL NODO DONDE SE ALMACENARA ESTA ESTRUCTURA Y POR ULTIMO, INSERTAMOS ESTE NODO A LA PILA 
    Pila *pila = CrearPila();
    Telefono *tel1 = CrearTelefono("Apple", "Iphone 11", "112JU90LS", "Vietnam", "Space Gray", 128, 4, 0);
    Nodo *nodo1 = CrearNodo(tel1);
    Insertar(pila,nodo1);

    Telefono *tel2 = CrearTelefono("Apple", "Iphone 12", "862JU9KZA", "Vietnam", "White", 256, 4, 0);
    Nodo *nodo2 = CrearNodo(tel2);
    Insertar(pila,nodo2);

    Telefono *tel3 = CrearTelefono("Apple", "Iphone 13", "9UASDB431", "Vietnam", "Black", 512, 6, 1);
    Nodo *nodo3 = CrearNodo(tel3);
    Insertar(pila,nodo3);

    Telefono *tel4 = CrearTelefono("OnePlus", "OnePlus 8", "000213KLS", "USA", "Militar Green", 256, 12, 1);
    Nodo *nodo4 = CrearNodo(tel4);
    Insertar(pila,nodo4);

    Telefono *tel5 = CrearTelefono("Samsung", "Z Fold 4", "JUA123AAKC", "China", "Black", 512, 18, 0);
    Nodo *nodo5 = CrearNodo(tel5);
    Insertar(pila,nodo5);

    // TAMBIEN SE PUEDEN AGREGAR LOS DIRECTAMENTE CON LA FUNCION INSERTAR Y LLAMAR AQUI LAS OTRAS FUNCIONES
    Insertar(pila, CrearNodo( CrearTelefono("Samsung", "A31", "MUP67ACC", "China", "White", 64, 6, 1) ) );

    Insertar(pila, CrearNodo( CrearTelefono("Xiaomi", "Redmi 9S", "IYASD872", "China", "Nefast Blue", 64, 4, 1) ) );

    Insertar(pila, CrearNodo( CrearTelefono("Xiaomi", "Mi 4", "ILO23UT2", "China", "Pacman Black", 256, 8, 0) ) );

    Imprimir(pila);

    // PODEMOS ELIMINAR LOS 3 ULTIMOS ELEMENTOS
    EliminarElemento(pila);
    EliminarElemento(pila);
    EliminarElemento(pila);

    printf("\n========================================\n");
    printf("\nAhora luego de haber eliminado 3 elementos\n");
    printf("\n========================================\n\n");
    Imprimir(pila);


    return 0;
}

Telefono *CrearTelefono(char marca[50],char modelo[50],char numSerie[50],char lugarFabricacion[50],char color[50],int almacenamientoGB,int ramGB,int dualSim){
    Telefono *aux = (Telefono*)malloc(sizeof(Telefono));
    strcpy(aux->marca, marca);
    strcpy(aux->modelo, modelo);
    strcpy(aux->numSerie, numSerie);
    strcpy(aux->lugarFabricacion, lugarFabricacion);
    strcpy(aux->color, color);
    aux->almacenamientoGB = almacenamientoGB;
    aux->ramGB = ramGB;
    aux->dualSim = dualSim;
    return aux;
}

Nodo *CrearNodo(Telefono *telefono){
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = telefono;
    aux->Siguiente = NULL;

}

Pila *CrearPila(){
    Pila *aux = (Pila*)malloc(sizeof(Pila));
    aux->tope = NULL;
    aux->total = 0;
    return aux;
}

int EstaVacia(Pila *pila){
// DEVUELVE UN 1 SI ESTA VACIA, 0 SI NO ESTA VACIA
    if(pila->total == 0){
        return 1;
    }else{
        return 0;
    }
}

void Insertar(Pila *pila, Nodo *aux){
    if(EstaVacia(pila)){
        pila->tope = aux;
    }else{
        aux->Siguiente = pila->tope;
        pila->tope = aux;
    }

    pila->total++;
}

void Imprimir(Pila *pila){
    Nodo *aux = pila->tope;
    Telefono *t;
    while(aux != NULL){
        t = aux->dato;

        printf("La marca es: %s\n", t->marca);
        printf("El modelo es: %s\n", t->modelo);
        printf("El numero de serie es: %s\n", t->numSerie);
        printf("El lugar de fabricacion es en: %s\n", t->lugarFabricacion);
        printf("El color del equipo es: %s\n", t->color);
        printf("El espacio de almacenamiento es de: %d GB\n", t->almacenamientoGB);
        printf("La cantidad de memoria RAM es de: %d GB\n", t->ramGB);

        if(t->dualSim){
            printf("El telefono SI posee dual SIM\n");
        }else{
            printf("El telefono NO posee dual SIM\n");
        }
 
        printf("\n\n");

        aux = aux->Siguiente;
    }
}

void EliminarElemento(Pila *pila){
    if(pila->tope == NULL){
        printf("No se pudo eliminar, la pila se encuentra vacia\n");
    }else{
        Nodo *aux = pila->tope;
        pila->tope = pila->tope->Siguiente;
        free(aux->dato);
        free(aux);
        pila->total--;
    }
}

