
#include <stdio.h>
#include <stdlib.h>

#define megisto_plithos 255          //μέγιστο πλήθος στοιχείων συνόλου

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);

boolean isValidInteger(char a[],typos_synolou DigitSet[255], typos_synolou CharacterSet[255]);
boolean isValidIdentifier(char a[], typos_synolou LetterSet[255], typos_synolou DigitSet[255]);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

int main(){
    typos_synolou CharacterSet[255],DigitSet[255],LetterSet[255];
    char s[80], choice;
    stoixeio_synolou i;

    Dimiourgia(CharacterSet);
    Dimiourgia(DigitSet);
    Dimiourgia(LetterSet);

    Eisagogi(43, CharacterSet);
    Eisagogi(45, CharacterSet);

    for(i=48;i<=57;i++){
        Eisagogi(i,DigitSet);
    }

    for(i=65;i<=90;i++){
        Eisagogi(i,LetterSet);
    }

    for(i=97;i<=122;i++){
        Eisagogi(i,LetterSet);
    }

    do{
        printf("Give an integer:");
        gets(s);
        if(isValidInteger(s,DigitSet,CharacterSet)){
            printf("Correct Integer\n");
        }
        else{
            printf("Wrong Integer\n");
        }
        do{
            printf("Continue with more integers (Y or N):");
            scanf("%c", &choice);
            getchar();
        }while (choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N');
    }while(choice=='y'||choice=='Y');

    do{
        printf("Give an identifier:");
        gets(s);
        if(isValidIdentifier(s,LetterSet,DigitSet)){
            printf("Correct Identifier\n");
        }
        else{
            printf("Wrong Identifier\n");
        }
        do{
            printf("Continue with more identifiers (Y or N):");
            scanf("%c", &choice);
            getchar();
        }while (choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N');
    }while(choice=='y'||choice=='Y');




}


void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}

void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}


boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}

boolean isValidIdentifier(char s[], typos_synolou LetterSet[255], typos_synolou DigitSet[255]){

    int i;
    boolean flag=TRUE;

    if(Melos(s[0],LetterSet)==FALSE){
        flag= FALSE;
    }
    else{
        i=1;
        while(s[i]!='\0' && flag==TRUE){
            if(Melos(s[i],LetterSet)==FALSE && Melos(s[i],DigitSet)==FALSE && s[i]!='_'){
                flag = FALSE;
            }
            else{
                i++;
            }
        }
    return flag;

    }
}

boolean isValidInteger(char s[],typos_synolou DigitSet[255], typos_synolou CharacterSet[255]){

    int i;
    boolean flag=TRUE;

    if(Melos(s[0],CharacterSet)==FALSE && Melos(s[0], DigitSet)==FALSE){
        flag = FALSE;
    }
    else if(Melos(s[0],CharacterSet)!=FALSE && Melos(s[1], DigitSet)==FALSE){
            flag = FALSE;
    }
    else{
        i=1;
        while(s[i]!='\0' && flag==TRUE){
            if(Melos(s[i],DigitSet)==FALSE){
                flag=FALSE;
            }
            else{
                i++;
            }
        }
    }
    return flag;

}






