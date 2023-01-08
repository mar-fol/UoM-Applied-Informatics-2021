#include <stdio.h>
#include <stdlib.h>

#define NumberOfNodes 10   /*üñéï ìåãÝèïõò ôçò óõíäåäåìÝíçò ëßóôáò,
                            åíäåéêôéêÜ ôÝèçêå ßóï ìå 50*/
#define NilValue -1          // åéäéêÞ ìåäåíéêç ôéìç äåß÷íåé ôï ôÝëïò ôçò Óõíä.ëßóôáò

#define StackLimit 10   // ôï üñéï ìåãÝèïõò ôçò óôïßâáò, åíäåéêôéêÜ ßóï ìå 50


typedef int StackElementType;  // ï ôýðïò ôùí óôïé÷åßùí  ôçò óôïßâáò
                                //åíäåéêôéêÜ ôýðïò int
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


typedef struct{
    int am;
    float grade;
} ListElementType; /*ôýðïò äåäïìÝíùí ãéá ôá óôïé÷åßá ôçò óõíäåäåìÝíçò ëßóôáò,
                                åíäåéêôéêÜ åðéëÝ÷èçêå ï ôýðïò int */
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);


void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

float findMaxs(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);

int main(){

    NodeType StudentsData[NumberOfNodes];
    ListPointer ptrList;
    ListElementType item1;
    StackType stack;
    StackElementType item2;
    int i;
    char ch;
    ListPointer PredPtr,FreePtr;



    InitializeStoragePool(StudentsData, &FreePtr);
    CreateList(&ptrList);
    printAll(ptrList, FreePtr, StudentsData);

    printf("Question 4\nLinked list\n");
    TraverseLinked(ptrList, StudentsData);
    float max;

    printf("Question 5\n");
    for(i=0;i<5;i++){
        printf("DWSE AM GIA EISAGWGH STH LISTA: ");
        scanf("%d", &item1.am);
        printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
        scanf("%f", &item1.grade);
        PredPtr = NilValue;
        Insert(&ptrList, StudentsData, &FreePtr, PredPtr, item1);
    }
    printf("Question 6");
    printf("\nStorage pool\n");
    printAll(ptrList, FreePtr, StudentsData);
    printf("Question 7\nLinked list\n");
    TraverseLinked(ptrList, StudentsData);


    printf("Question 8\n");
    if(EmptyList(ptrList)){
        printf("Empty List\n");
    }
    else{
        printf("Not an Empty List\n");
    }
    printf("Question 9\n");
    if(FullList(FreePtr)){
        printf("Full List\n");
    }
    else{
        printf("Not a Full List\n");
    }
    printf("Question 10\n");
    max = findMaxs(ptrList, StudentsData, &stack);
    printf("max vathmos=%.1f\n", max);

    printf("AM me megisto vathmo: ");
    while(!EmptyStack(stack)){
        Pop(&stack, &item2);
        printf("%d ", item2);
    }

    printf("\nQuestion 11\n");
    TraverseStack(stack);

    printf("Question 12\n");
    printAll(ptrList, FreePtr, StudentsData);
    printf("Question 13\n");
    printf("Linked list\n");
    TraverseLinked(ptrList, StudentsData);


    return 0;
}

float findMaxs(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack){

    ListPointer CurrPtr;

    float max=-1;
    if(!EmptyList(List)){
        CreateStack(Stack);
        CurrPtr = List;
        while(!FullList(CurrPtr)){
            if(Node[CurrPtr].Data.grade>=max){
                if(Node[CurrPtr].Data.grade>max){
                    CreateStack(Stack);
                    max = Node[CurrPtr].Data.grade;
                }
                Push(Stack, Node[CurrPtr].Data.am);
            }
            CurrPtr = Node[CurrPtr].Next;
        }
    }
    return max;

}


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* ÄÝ÷åôáé:   Ôïí ðßíáêá Node êáé ôïí äåßêôç FreePtr ðïõ äåß÷íåé óôïí
                ðñþôï äéáèÝóéìï êüìâï.
  Ëåéôïõñãßá: Áñ÷éêïðïéåß ôïí ðßíáêá Node ùò óõíäåäåìÝíç ëßóôá óõíäÝïíôáò ìåôáîý
                ôïõò äéáäï÷éêÝò åããñáöÝò ôïõ ðßíáêá,
                êáé áñ÷éêïðïéåß ôïí äåßêôç FreePtr .
  ÅðéóôñÝöåé: Ôïí ôñïðïðïéçìÝíï ðßíáêá Node êáé ôïí
                äåßêôç FreePtr ôïõ ðñþôïõ äéáèÝóéìïõ êüìâïõ
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.am=-1;
        Node[i].Data.grade=-1.0;     /* äåí åßíáé áíáãêáßï ç áðüäïóç áñ÷éêÞò ôéìÞò óôï ðåäßï ôùí äåäïìÝíùí, âïçèÜåé óôçí åêôýðùóç */
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.am=-1;

    Node[NumberOfNodes-1].Data.grade=-1.0;
    *FreePtr=0;
}

void CreateStack(StackType *Stack)
/* Ëåéôïõñãßá: Äçìéïõñãåß ìéá êåíÞ óôïßâá.
   ÅðéóôñÝöåé: ÊåíÞ Óôïßâá.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* ÄÝ÷åôáé: Ìéá óôïßâá Stack.
   Ëåéôïõñãßá: ÅëÝã÷åé áí ç óôïßâá Stack åßíáé êåíÞ.
   ÅðéóôñÝöåé: True áí ç Stack åßíáé êåíÞ, False äéáöïñåôéêÜ
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* ÄÝ÷åôáé: Ìéá óôïßâá Stack.
   Ëåéôïõñãßá: ÅëÝã÷åé áí ç óôïßâá Stack åßíáé ãåìÜôç.
   ÅðéóôñÝöåé: True áí ç Stack åßíáé ãåìÜôç, False äéáöïñåôéêÜ
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* ÄÝ÷åôáé: Ìéá óôïßâá Stack êáé Ýíá óôïé÷åßï Item.
   Ëåéôïõñãßá: ÅéóÜãåé ôï óôïé÷åßï Item óôçí óôïßâá Stack áí ç Stack äåí åßíáé ãåìÜôç.
   ÅðéóôñÝöåé: Ôçí ôñïðïðïéçìÝíç Stack.
   ¸îïäïò: ÌÞíõìá ãåìÜôçò óôïßâáò, áí ç óôïßâá Stack åßíáé ãåìÜôç
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* ÄÝ÷åôáé: Ìéá óôïßâá Stack.
   Ëåéôïõñãßá: ÄéáãñÜöåé ôï óôïé÷åßï Item áðü ôçí êïñõöÞ ôçò Óôïßâáò áí ç Óôïßâá äåí åßíáé êåíÞ.
   ÅðéóôñÝöåé: Ôï óôïé÷åßï Item êáé ôçí ôñïðïðïéçìÝíç Stack.
   ¸îïäïò:  ÌÞíõìá êåíÞò óôïßâáò áí ç Stack åßíáé êåíÞ
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


void CreateList(ListPointer *List)
/* Ëåéôïõñãßá: Äçìéïõñãåß ìéá êåíÞ óõíäåäåìÝíç ëßóôá.
   ÅðéóôñÝöåé: ¸íáí (ìçäåíéêü) äåßêôç ðïõ äåß÷íåé óå êåíÞ ëßóôá
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* ÄÝ÷åôáé:    ¸íáí äåßêôç List ðïõ äåß÷íåé óå ìéá óõíäåäåìÝíç ëßóôá.
   Ëåéôïõñãßá: ÅëÝã÷åé áí ç óõíäåäåìÝíç ëßóôá åßíáé êåíÞ.
   ÅðéóôñÝöåé: True áí ç óõíäåäåìÝíç ëßóôá åßíáé êåíÞ êáé false äéáöïñåôéêÜ
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* ÄÝ÷åôáé:    Ìéá óõíäåäåìÝíç ëßóôá.
   Ëåéôïõñãßá: ÅëÝã÷åé áí ç óõíäåäåìÝíç ëßóôá åßíáé ãåìÜôç.
   ÅðéóôñÝöåé: True áí ç óõíäåäåìÝíçëßóôá åßíáé ãåìÜôç, false äéáöïñåôéêÜ
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* ÄÝ÷åôáé:   Ôïí ðßíáêá Node êáé ôïí äåßêôç FreePtr.
  Ëåéôïõñãßá: ÁðïêôÜ Ýíáí "åëåýèåñï" êüìâï ðïõ ôïí äåß÷íåé ï äåßêôçò P.
  ÅðéóôñÝöåé: Ôïí äåßêôç P êáé ôïí ôñïðïðïéçìÝíï  äåßêôç FreePtr
                ðïõ äåéêôïäïôåß óôï ðñþôï äéáèÝóéìï êüìâï
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* ÄÝ÷åôáé:    Ôïí ðßíáêá Node, ðïõ áíáðáñéóôÜ ôç äåîáìåíÞ ôùí äéáèÝóéìùí êüìâùí,
                Ýíáí äåßêôç TempPtr êáé ôïí äåßêôç FreePtr.
   Ëåéôïõñãßá: ÅðéóôñÝöåé óôç äåîáìåíÞ ôïí êüìâï óôïí ïðïßï äåß÷íåé ï TempPtr.
   ÅðéóôñÝöåé: Ôïí ôñïðïðïéçìÝíï ðßíáêá Node êáé ôïí äåßêôç FreePtr
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data.am = -1; /* Ï÷é áíáãêáßá åíôïëÞ, âïçèçôéêÞ ãéá íá öáßíïíôáé óôçí åêôýðùóç ïé äéáãñáììÝíïé êüìâïé */
    Node[P].Data.grade = -1;
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* ÄÝ÷åôáé:    Ìéá óõíäåäåìÝíç ëßóôá, ôïí ðßíáêá Node, ôïí äåßêôç PredPtr êáé
                Ýíá óôïé÷åßï Item.
  Ëåéôïõñãßá: ÅéóÜãåé óôç óõíäåäåìÝíç ëßóôá, áí äåí åßíáé ãåìÜôç, ôï óôïé÷åßï
                Item ìåôÜ áðü ôïí êüìâï óôïí ïðïßï äåß÷íåé ï äåßêôçò PredPtr.
  ÅðéóôñÝöåé: Ôçí ôñïðïðïéçìÝíç óõíäåäåìÝíç ëßóôá, ôïí ôñïðïðïéçìÝíï ðßíáêá Node
                êáé ôïí äåßêôç FreePtr.
  Åîïäïò:     ÌÞíõìá ãåìÜôçò ëßóôáò, áí ç óõíäåäåìÝíç ëßóôá åßíáé ãåìÜôç
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* ÄÝ÷åôáé:   Ìéá óõíäåäåìÝíç ëßóôá êáé ôïí äåßêôç PredPtr ðïõ äåß÷íåé
                óôïí ðñïçãïýìåíï êüìâï áðü áõôüí ðïõ èá äéáãñáöåß.
  Ëåéôïõñãßá: ÄéáãñÜöåé áðü ôç óõíäåäåìÝíç ëßóôá, áí äåí åßíáé êåíÞ,
                ôïí ðñïçãïýìåíï êüìâï áðü áõôüí óôïí ïðïßï äåß÷íåé ï PredPtr.
  ÅðéóôñÝöåé: Ôçí ôñïðïðïéçìÝíç ëßóôá êáé ôï äåßêôç FreePtr.
  ¸îïäïò:     ÌÞíõìá êåíÞò ëßóôáò, áí ç óõíäåäåìÝíç ëßóôá åßíáé êåíÞ
*/
{
  ListPointer TempPtr ;

  if (!EmptyList(*List)) {
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
      }
      ReleaseNode(Node,TempPtr,FreePtr);
  }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* ÄÝ÷åôáé:    Ìéá óõíäåäåìÝíç ëßóôá.
   Ëåéôïõñãßá: ÊÜíåé äéÜó÷éóç ôçò óõíäåäåìÝíçò ëßóôáò, áí äåí åßíáé êåíÞ.
   ¸îïäïò:     ÅîáñôÜôáé áðü ôçí åðåîåñãáóßá
*/
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d:<%d,%.1f> ->%d) ",CurrPtr,Node[CurrPtr].Data.am, Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%.1f> ->%d) ",i,Node[i].Data.am, Node[i].Data.grade, Node[i].Next);
    printf("\n");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
