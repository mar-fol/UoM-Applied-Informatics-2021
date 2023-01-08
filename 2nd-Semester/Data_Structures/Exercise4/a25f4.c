#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NumberOfNodes 10    /*üñéï ìåãÝèïõò ôçò óõíäåäåìÝíçò ëßóôáò,
                            åíäåéêôéêÜ ôÝèçêå ßóï ìå 50*/
#define NilValue -1          // åéäéêÞ ìåäåíéêç ôéìç äåß÷íåé ôï ôÝëïò ôçò Óõíä.ëßóôáò

typedef struct{
    char name[20];
    int weight;
    int cost;
} ListElementType; /*ôýðïò äåäïìÝíùí ãéá ôá óôïé÷åßá ôçò óõíäåäåìÝíçò ëßóôáò,
                                åíäåéêôéêÜ åðéëÝ÷èçêå ï ôýðïò int */
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);
void sort_list(ListPointer *List, NodeType Node[], boolean choice, int ByFeature);

void switch_positions(ListPointer prevptr, ListPointer CurrPtr, ListPointer NextPtr, NodeType Node[], ListPointer *List);

int main(){

    ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr, PredPtr;
    char ch;

    int n;
    ListElementType AnItem;

    InitializeStoragePool(Node, &FreePtr);
    CreateList(&AList);
    printAll(AList, FreePtr, Node);

    TraverseLinked(AList, Node);


    printf("Give objects number: ");
    do{
        scanf("%d%c", &n, &ch);
    }while(n>10 || n<0);
    int i;
    for(i=0;i<n;i++){
        printf("Give name: ");
        scanf("%s%c", AnItem.name, &ch);
        printf("Give weight: ");
        scanf("%d%c", &AnItem.weight, &ch);
        printf("Give cost: ");
        scanf("%d%c", &AnItem.cost, &ch);

        PredPtr=NilValue;
        Insert(&AList, Node, &FreePtr, PredPtr, AnItem);
    }

    printAll(AList, FreePtr, Node);
    TraverseLinked(AList, Node);

    printf("Name Ascending\n");
    sort_list(&AList, Node, TRUE, 1);
    TraverseLinked(AList, Node);
    printf("Weight Ascending\n");
    sort_list(&AList, Node, TRUE, 2);
    TraverseLinked(AList, Node);
    printf("Cost Ascending\n");
    sort_list(&AList, Node, TRUE, 3);
    TraverseLinked(AList, Node);

    printf("Name Descending\n");
    sort_list(&AList, Node, FALSE, 1);
    TraverseLinked(AList, Node);
    printf("Weight Descending\n");
    sort_list(&AList, Node, FALSE, 2);
    TraverseLinked(AList, Node);
    printf("Cost Descending\n");
    sort_list(&AList, Node, FALSE, 3);
    TraverseLinked(AList, Node);

    return 0;




}

void sort_list(ListPointer *List, NodeType Node[], boolean choice, int ByFeature){
    ListPointer NextPointer, CurrPtr, PrevPtr, OutPtr;
    boolean swap;

    if(!EmptyList(*List)){
        OutPtr = *List;
        while(OutPtr!=NilValue){
            CurrPtr = *List;
            PrevPtr = NilValue;
            NextPointer = Node[CurrPtr].Next;
            while(!FullList(NextPointer)){
                swap = FALSE;
                if(choice){ //ascending
                    switch(ByFeature){
                        case 1:
                            if(strcmp(Node[CurrPtr].Data.name,Node[NextPointer].Data.name)>0)
                                swap = TRUE;
                            break;
                        case 2:
                            if(Node[CurrPtr].Data.weight>Node[NextPointer].Data.weight)
                                swap = TRUE;
                            break;

                        case 3:
                            if(Node[CurrPtr].Data.cost>Node[NextPointer].Data.cost)
                                swap = TRUE;
                            break;
                    }
                }
                else if(choice==FALSE){
                    switch(ByFeature){
                        case 1:
                            if(strcmp(Node[CurrPtr].Data.name, Node[NextPointer].Data.name)<0)
                                swap = TRUE;
                            break;
                        case 2:
                            if(Node[CurrPtr].Data.weight<Node[NextPointer].Data.weight)
                                swap = TRUE;
                            break;

                        case 3:
                            if(Node[CurrPtr].Data.cost<Node[NextPointer].Data.cost)
                                swap = TRUE;
                            break;

                        }
                    }
                if(swap){
                    switch_positions(PrevPtr, CurrPtr, NextPointer, Node, List);
                    if(OutPtr==CurrPtr){
                        OutPtr = NextPointer;
                    }
                }
                PrevPtr = CurrPtr;
                CurrPtr = NextPointer;
                NextPointer = Node[CurrPtr].Next;
                }
                OutPtr = Node[OutPtr].Next;
            }
        }
        else{
            printf("empty list");
        }
}

void switch_positions(ListPointer prevptr, ListPointer CurrPtr, ListPointer NextPtr, NodeType Node[], ListPointer *List){

    if(CurrPtr == *List){
        *List = NextPtr;
    }
    Node[CurrPtr].Next = Node[NextPtr].Next;
    Node[NextPtr].Next = CurrPtr;
    if(Node[prevptr].Data.weight!=0 && Node[prevptr].Data.cost!=0 && Node[prevptr].Data.name[0]!='\0'){
        Node[prevptr].Next = NextPtr;
    }

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
    ListElementType t;
   int i;


    t.weight = 0;

    t.cost = 0;

    t.name[0]='\0';
    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=t;    /* äåí åßíáé áíáãêáßï ç áðüäïóç áñ÷éêÞò ôéìÞò óôï ðåäßï ôùí äåäïìÝíùí, âïçèÜåé óôçí åêôýðùóç */
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=t;
    *FreePtr=0;
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    //printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%s,%d,%d> ->%d) ",i,Node[i].Data.name, Node[i].Data.weight, Node[i].Data.cost, Node[i].Next );
    printf("\n");
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
    ListElementType t;
    t.name[0]='\0';
    t.weight = 0;

    t.cost = 0;
  Node[P].Next =*FreePtr;
  Node[P].Data = t; //Ï÷é áíáãêáßá åíôïëÞ, âïçèçôéêÞ ãéá íá öáßíïíôáé óôçí åêôýðùóç ïé äéáãñáììÝíïé êüìâïé
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

  if (!EmptyList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
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
          printf("(%s,%d,%d)\n",Node[CurrPtr].Data.name, Node[CurrPtr].Data.weight, Node[CurrPtr].Data.cost);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
