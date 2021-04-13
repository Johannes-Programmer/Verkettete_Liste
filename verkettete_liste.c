#include <stdlib.h>
#include <stdio.h>

//STRUKTUREN<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
struct Knoten{
    struct Knoten *Prev;    //Zeiger auf Struktur Knoten; Soll auf vorheriges Listenelement zeigen
    struct Knoten *Next;    //Zeiger auf Struktur Knoten; Soll auf nächstes Listenelement zeigen
    struct Element *Elem;   //Zeiger auf Struktur Element; Soll auf value zeigen
};

struct Element{
    int value;             
};
 

//FUNKTIONSDEKLARATIONEN<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void addElement(struct Knoten **pointerPointerRoot, int addValue);
void printList(struct Knoten *pointerRoot);
void removeElement(struct Knoten **pointerPointerRoot, struct Knoten **pointerPointerKnot, int pos);
void getValue(struct Knoten *pointerRoot, int pos, int *value);
void getElement(struct Knoten *pointerRoot, int pos, struct Element **pointerPointerValue);
void printValue(struct Knoten *root, int pos);


//FUNKTIONEN<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void addElement(struct Knoten **pointerPointerRoot, int addValue){  //Zeiger auf Zeiger root, der beinhaltet die Adresse auf die root zeigt
    //Neues Element erstellen
    struct Element *newElement = malloc(sizeof(struct Element));    
    //Malloc liefert eine Adresse auf einen dynamischen Speicherbereich Knoten mit der Größe der Struktur Element
    (*newElement).value=addValue;                                   
    /*Weiße der oben reservierten Adresse in das Feld value addValue zu. 
    Da in den Inhalt auf den der Zeiger zeigt geschrieben wird, 
    wird hier ein * vor Element verwendet. Eine andere Schreibweiße wäre: 
    newElement->value=addValue*/
    
    //Neuen Knoten erstellen
    struct Knoten *newKnoten = malloc(sizeof(struct Knoten));       //Reserviere Speicher von der Größe der Struktur Knoten 
    /*Wenn der Prev Zeiger auf die Adresse NULL zeigt gibt es kein Element davor.
    Das gleiche gilt für den Next Zeiger, der auf die nächste Adresse zeigt.*/
    newKnoten->Prev = NULL; //Es wird in den Inhalt von dem Zeiger geschrieben
    newKnoten->Next = NULL;
    newKnoten->Elem = newElement; 
    /*Gibt es bereits eine wurzel-root, also einen Listenanfang? 
    Inhalt ist NULL wenn es noch keine Liste gibt
    Hier ein *, da die Adresse, die in dem pointer root steht angeschaut wird*/                                 
    if(*pointerPointerRoot==NULL){ 
        *pointerPointerRoot=newKnoten; //Adresse von newKnoten wird in pointer root gespeichert -> aus NULL wird Adresse
    }else{
        //An den Anfang der Liste zurückkehren
        struct Knoten *lastKnoten =  *pointerPointerRoot; //Ein Zeiger vom Typ Knoten wird deklariert, die Adresse steht, auf die root zeigt
        while((*lastKnoten).Next!=NULL){ //Es wird geprüft ob der Next Zeiger auf eine Adresse zeigt. Wenn NULL gibt es kein nächstes Element
            lastKnoten=(*lastKnoten).Next; //Adresse von dem nächsten Listenelement wird in lastKnoten gespeichert
        }
        (*lastKnoten).Next=newKnoten;  //Das nächste Listenelement ist newKnoten. Hier steht value etc drin
        (*newKnoten).Prev=lastKnoten;  //In dem neu erstellten Listenelement muss ein Pointer auf den vorherigen Knoten stehen
    }
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void printList(struct Knoten *pointerRoot){     //In pointerRoot steht die Adresse von der Struktur der root
    if(pointerRoot==NULL){
        printf("\n Die Liste ist leer!\n");
    }else{
        struct Knoten *lastKnoten=pointerRoot;      //Muss am Anfang auf die Adresse der Wurzel zeigen
        for(int counter=1; lastKnoten!=0; counter++){
            printf("\nElement %i: %i",counter, (*(*lastKnoten).Elem).value); //Auf den Inhalt von pointerRoot, also das Element Elem soll zugegriffen werden, daher der *
            lastKnoten=(*lastKnoten).Next;
        }
    }
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void removeElement(struct Knoten **pointerPointerRoot, struct Knoten **pointerPointerKnot, int pos){
    struct Knoten *lastKnoten=*pointerPointerRoot;  //Adresse von der Wurzel da rein schreiben
    int aktuellePos = 1;
    while(lastKnoten!=NULL){
        if(aktuellePos==pos-1){
            *pointerPointerKnot=(*lastKnoten).Next;
            (*lastKnoten).Next=(*(*lastKnoten).Next).Next;
            break;
        }
        lastKnoten=(*lastKnoten).Next;
        aktuellePos++;
    }
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void getValue(struct Knoten *pointerRoot, int pos, int *value){
    struct Knoten *lastKnoten=pointerRoot;
    for(int posCounter=1; pos+1; posCounter++){
        if(lastKnoten==NULL){
            *value=0;
            break;
        }
        else if(posCounter==pos){
            *value=(*(*lastKnoten).Elem).value;
            break;
        }
        lastKnoten=(*lastKnoten).Next;
    }
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void getElement(struct Knoten *pointerRoot, int pos, struct Element **pointerPointerValue){
    struct Knoten *lastKnoten=pointerRoot;
    for(int posCounter=1; pos+1; posCounter++){
        if(lastKnoten==NULL){
            printf("\nEs befinden sich nicht genug Knoten in der Liste, um den gewuenschten Wert auszugeben!");
            break;
        }
        else if(posCounter==pos){
            *pointerPointerValue=(*lastKnoten).Elem;
            break;
        }
        lastKnoten=(*lastKnoten).Next;
    }
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void printValue(struct Knoten *root, int pos){
    int value=0;
    getValue(root, 1, &value);
    printf("\nDie Funktion printValue liefert an der Stelle 1: %i",value);
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//HAUPTPROGRAMM(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
void main(void){
    struct Knoten *root=NULL;           
    /*Zeiger, der auf Struktur Knoten zeigt (beinhaltet 3 Speicherplätze) wird deklariert. 
    Die Adresse ist jedoch NULL. D.h. Es gibt sie noch nicht und muss im weiteren Verlauf angepasst werden.
    Der Zeiger ist also aktuell noch leer und heißt root */

    /*Element soll der Liste hinzugefügt werden bzw. Ein erstes Listenelement, also die root-wurzelDerListe hinzugefügt werden.
    Da der Zeiger root aktuell auf keine Adresse zeigt muss die Adresse dieses Zeigers verändert werden können.
    Dazu könnte dieser Zeiger global deklariert werden, was jedoch nicht Speicherplatz-optimal ist.
    Stattdessen wird ein Zeiger auf einen Zeiger eingesetzt. Durch die Übergabe der Adresse des Zeigers root in eine Funktion
    kann dort der Zeiger auf einen Zeiger mit 2 Sternen deklariert werden. Der Zeiger hat eine andere Adresse, beinhaltet jedoch die Adresse,
    auf die der Zeiger root zeigt. Da dieser aktuell noch auf NULL zeigt muss diese ja verändert werden.
    Das ist möglich durch *pointer=...
    Dass die Adresse, auf die der Zeiger root zeigt verändert werden kann muss in die Funktion die Adresse von diesem übergeben werden.
    */

    //5 Elemente der Liste hinzufügen, mit den Werten 10,20,30,40,50  
    addElement(&root,10); 
    addElement(&root,20);
    addElement(&root,30);
    addElement(&root,40);
    addElement(&root,50);

    /*Um die Liste auszugeben ist es nicht erforderlich die Adresse der Listenelemente zu modifizieren, somit 
    muss kein Pointer auf Pointer erstellt werden. D.h. Die Funktion bekommt die Adresse, auf die root zeigt,
    aber NICHT die Adresse von root.*/
    printList(root);
    struct Knoten *knot=NULL;
    removeElement(&root, &knot, 2);
    printf("\nAuf Wunsch wurde ein ausgewaehlter Knoten geloescht. Dessen Inhalt war: %i", (*(*knot).Elem).value);
    printf("\nIn der Liste steht nun nur noch:");
    printList(root);

    int value=0;
    getValue(root, 1, &value);
    printf("\nAn Position 1 betraegt der Value = %i",value);

    struct Element *valueBack=NULL;
    getElement(root, 3, &valueBack);
    printf("\nAn Position 3 betraegt der Value = %i",(*valueBack).value);

    printValue(root, 1);             
}
//HAUPTPROGRAMM)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))