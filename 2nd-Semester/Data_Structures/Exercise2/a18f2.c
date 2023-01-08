#include <stdio.h>
#include <stdlib.h>

#define StackLimit 6


typedef int StackElementType;   // ď ôýđďň ôůí óôďé÷ĺßůí  ôçň óôďßâáň
                                //ĺíäĺéęôéęÜ ôýđďň int
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);



void TraverseStack(StackType Stack);

int main(){
    StackType Stack, minStack;
    StackElementType temp, min;
    int i;
    char ch;

    CreateStack(&Stack);
    CreateStack(&minStack);

    printf("Dwse to epomeno stoixeio: ");

    scanf("%d%c", &temp, &ch);
    Push(&Stack, temp);
    min = temp;
    Push(&minStack, min);
    TraverseStack(Stack);
    printf("Min=%d", min);
    for(i=0;i<5;i++){
        printf("\nDwse to epomeno stoixeio: ");
        scanf("%d%c", &temp, &ch);
        Push(&Stack, temp);
        if(temp<=min){
            min = temp;
            Push(&minStack, min);
        }
        TraverseStack(Stack);
        printf("Min=%d", min);
    }

    printf("\n\nEmptying stack\n");

    while(!EmptyStack(Stack)){
        Pop(&Stack, &temp);
        if(temp == min){
            Pop(&minStack, &min);
            if(!EmptyStack(minStack)){
                Pop(&minStack, &min);
                Push(&minStack, min);
                printf("Min=%d\n", min);
            }
        }
        TraverseStack(Stack);

    }











    return 0;
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

void CreateStack(StackType *Stack)
/* Ëĺéôďőńăßá: Äçěéďőńăĺß ěéá ęĺíŢ óôďßâá.
   ĹđéóôńÝöĺé: ĘĺíŢ Óôďßâá.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* ÄÝ÷ĺôáé: Ěéá óôďßâá Stack.
   Ëĺéôďőńăßá: ĹëÝă÷ĺé áí ç óôďßâá Stack ĺßíáé ęĺíŢ.
   ĹđéóôńÝöĺé: True áí ç Stack ĺßíáé ęĺíŢ, False äéáöďńĺôéęÜ
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* ÄÝ÷ĺôáé: Ěéá óôďßâá Stack.
   Ëĺéôďőńăßá: ĹëÝă÷ĺé áí ç óôďßâá Stack ĺßíáé ăĺěÜôç.
   ĹđéóôńÝöĺé: True áí ç Stack ĺßíáé ăĺěÜôç, False äéáöďńĺôéęÜ
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* ÄÝ÷ĺôáé: Ěéá óôďßâá Stack ęáé Ýíá óôďé÷ĺßď Item.
   Ëĺéôďőńăßá: ĹéóÜăĺé ôď óôďé÷ĺßď Item óôçí óôďßâá Stack áí ç Stack äĺí ĺßíáé ăĺěÜôç.
   ĹđéóôńÝöĺé: Ôçí ôńďđďđďéçěÝíç Stack.
   ¸îďäďň: ĚŢíőěá ăĺěÜôçň óôďßâáň, áí ç óôďßâá Stack ĺßíáé ăĺěÜôç
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* ÄÝ÷ĺôáé: Ěéá óôďßâá Stack.
   Ëĺéôďőńăßá: ÄéáăńÜöĺé ôď óôďé÷ĺßď Item áđü ôçí ęďńőöŢ ôçň Óôďßâáň áí ç Óôďßâá äĺí ĺßíáé ęĺíŢ.
   ĹđéóôńÝöĺé: Ôď óôďé÷ĺßď Item ęáé ôçí ôńďđďđďéçěÝíç Stack.
   ¸îďäďň:  ĚŢíőěá ęĺíŢň óôďßâáň áí ç Stack ĺßíáé ęĺíŢ
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}




