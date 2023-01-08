#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int packageNumber;
    float totalWeight;
    char expirationDate[10];
}StackElementType;

typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

int IndexOfMin(StackPointer Stack1, StackPointer Stack2, StackPointer Stack3);
int StackSize(StackPointer Stack);
void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);

int main()
{
   StackPointer Warehouse1, Warehouse2, Warehouse3;
   StackElementType AnItem;
   int n,i,min;

   CreateStack(&Warehouse1);
   CreateStack(&Warehouse2);
   CreateStack(&Warehouse3);

   printf("Plithos fortiwn: ");
   scanf("%d", &n);
   for(i=0;i<n;i++)
   {
       printf("Arithmos kivwtiwn gia to %do fortio: ", i+1);
       scanf("%d", &AnItem.packageNumber);
       printf("Synoliko baros gia to %do fortio: ", i+1);
       scanf("%f", &AnItem.totalWeight);
       printf("Imeromhnia liksis gia to %do fortio: ", i+1);
       scanf("%s", AnItem.expirationDate);
       min = IndexOfMin(Warehouse1,Warehouse2,Warehouse3);
       if(min == 1)
           Push(&Warehouse1, AnItem);
       else if(min == 2)
           Push(&Warehouse2, AnItem);
       else
           Push(&Warehouse3, AnItem);
   }
   printf("WAREHOUSE 1\n");
   TraverseStack(Warehouse1);
   printf("WAREHOUSE 2\n");
   TraverseStack(Warehouse2);
   printf("WAREHOUSE 3\n");
   TraverseStack(Warehouse3);

   return 0;
}

int IndexOfMin(StackPointer Stack1, StackPointer Stack2, StackPointer Stack3)
{
    if((StackSize(Stack3)<=StackSize(Stack2)) && (StackSize(Stack3)<=StackSize(Stack1)))
        return 3;
    else if((StackSize(Stack2)<=StackSize(Stack1)) && (StackSize(Stack2)<=StackSize(Stack3)))
        return 2;
    else
        return 1;
}

int StackSize(StackPointer Stack)
{
    int count=0;
    StackPointer CurrPtr=Stack;

    while(CurrPtr!=NULL)
    {
        count = count + CurrPtr->Data.packageNumber;
        CurrPtr = CurrPtr->Next;
    }
    return count;
}

void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα.
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον
                δείκτη Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack.
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας,
                αν η στοίβα δεν είναι κενή, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item.
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d %.2f %s\n", CurrPtr->Data.packageNumber, CurrPtr->Data.totalWeight, CurrPtr->Data.expirationDate);
             CurrPtr = CurrPtr->Next;
        }
   }
//    printf("\n");
}
