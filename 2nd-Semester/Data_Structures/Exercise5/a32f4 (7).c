#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NumberOfNodes 10   /*���� �������� ��� ������������ ������,
                            ���������� ������ ��� �� 50*/
#define NilValue -1          // ������ �������� ���� ������� �� ����� ��� ����.������

#define MaxLine 50
#define BufferLength 40

typedef struct{
    char name[20];
    int high_School;
} ListElementType; /*����� ��������� ��� �� �������� ��� ������������ ������,
                                ���������� ���������� � ����� int */
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr, ListElementType *item);
void TraverseLinked(ListPointer List, NodeType Node[]);

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);


int main(){

    NodeType FirstPhase[NumberOfNodes], SecondPhase[NumberOfNodes];

    ListPointer FreePtrA, FreePtrB, PredPtrA=-1, PredPtrB, listA, listB, CurrPtrA, CurrPtrB, lastPTR;

    FILE *students;

    students = fopen("students.dat", "r");
    if(students==NULL){
        printf("Can't open %s\n", "students.dat");
    }
    else{
    printf("Question a:\n");

    InitializeStoragePool(FirstPhase, &FreePtrA);
    CreateList(&listA);


    InitializeStoragePool(SecondPhase, &FreePtrB);
    CreateList(&listB);

    char ch;

    ListElementType AnItem, item;

    int i, m;

    char buffer[BufferLength];

    while(fgets(buffer, BufferLength, students) != NULL)
    {
        buffer[strlen(buffer)-1] = '\0';
        strcpy(AnItem.name, buffer);
        AnItem.high_School = atoi(fgets(buffer, BufferLength, students));
        Insert(&listA, FirstPhase, &FreePtrA, PredPtrA, AnItem);
    }

    /*for(i=0;i<10;i++){
        m = fscanf(students, "%40[^\n]%d%c", FirstPhase[i].Data.name, &FirstPhase[i].Data.high_School, &ch);
        Insert(&listA, FirstPhase, &FreePtrA, PredPtrA, FirstPhase[i].Data);
    }
    */

    printAll(listA, FreePtrA, FirstPhase);
    printf("Lista A\n");
    TraverseLinked(listA, FirstPhase);

    int posit;
    PredPtrB = NilValue;
    for(i=0;i<4;i++){
        do{
            printf("Dwse thn thesi toy ma8hth poy klhrw8hke: ");
            scanf("%d", &posit);
        }while(posit>9 || posit<0);
        PredPtrA = NilValue;
        CurrPtrA = listA;
        while(CurrPtrA != posit){
            PredPtrA = CurrPtrA;
            CurrPtrA = FirstPhase[CurrPtrA].Next;
        }
        Delete(&listA, FirstPhase, &FreePtrA, PredPtrA, &item);
        Insert(&listB, SecondPhase, &FreePtrB, PredPtrB, item);
        PredPtrB = listB;
        while(SecondPhase[PredPtrB].Next!=NilValue){
            PredPtrB = SecondPhase[PredPtrB].Next;
        }
    }
    printf("Question b:\n");
    printAll(listA, FreePtrA, FirstPhase);
    printf("Lista A\n"); //EDW DEN EMFANIZEI TOUS KOMBOUS TIS LISTAS POU PREPEI, EMFANIZEI TOUS KENOUS
    TraverseLinked(listA, FirstPhase);

    printAll(listB, FreePtrB, SecondPhase);
    printf("Lista B\n");
    TraverseLinked(listB, SecondPhase);

    printf("Question c:\n");


    PredPtrB = NilValue;
    CurrPtrB = listB;
    while(CurrPtrB!=1){
        PredPtrB = CurrPtrB;
        CurrPtrB = SecondPhase[CurrPtrB].Next;
    }
    Delete(&listB, SecondPhase, &FreePtrB, PredPtrB, &item);
    Insert(&listA, FirstPhase, &FreePtrA, PredPtrA, item);

    printAll(listA, FreePtrA, FirstPhase);
    printf("Lista A\n");
    TraverseLinked(listA, FirstPhase);

    printAll(listB, FreePtrB, SecondPhase);
    printf("Lista B\n");
    TraverseLinked(listB, SecondPhase);
    }
    fclose(students);

    return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* �������:   ��� ������ Node ��� ��� ������ FreePtr ��� ������� ����
                ����� ��������� �����.
  ����������: ����������� ��� ������ Node �� ����������� ����� ���������� ������
                ���� ���������� �������� ��� ������,
                ��� ����������� ��� ������ FreePtr .
  ����������: ��� ������������� ������ Node ��� ���
                ������ FreePtr ��� ������ ���������� ������
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.high_School=-1;
        Node[i].Data.name[0]= '\0';    /* ��� ����� �������� � ������� ������� ����� ��� ����� ��� ���������, ������� ���� �������� */
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.high_School=-1;
    Node[NumberOfNodes-1].Data.name[0]= '\0';
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/* ����������: ���������� ��� ���� ����������� �����.
   ����������: ���� (��������) ������ ��� ������� �� ���� �����
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* �������:    ���� ������ List ��� ������� �� ��� ����������� �����.
   ����������: ������� �� � ����������� ����� ����� ����.
   ����������: True �� � ����������� ����� ����� ���� ��� false �����������
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* �������:    ��� ����������� �����.
   ����������: ������� �� � ����������� ����� ����� ������.
   ����������: True �� � ���������������� ����� ������, false �����������
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* �������:   ��� ������ Node ��� ��� ������ FreePtr.
  ����������: ������ ���� "��������" ����� ��� ��� ������� � ������� P.
  ����������: ��� ������ P ��� ��� �������������  ������ FreePtr
                ��� ����������� ��� ����� ��������� �����
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* �������:    ��� ������ Node, ��� ���������� �� �������� ��� ���������� ������,
                ���� ������ TempPtr ��� ��� ������ FreePtr.
   ����������: ���������� ��� �������� ��� ����� ���� ����� ������� � TempPtr.
   ����������: ��� ������������� ������ Node ��� ��� ������ FreePtr
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data.high_School = -1;
  Node[P].Data.name[0] = '\0';
    /* ��� �������� ������, ��������� ��� �� ��������� ����
                        �������� �� ������������ ������ */
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* �������:    ��� ����������� �����, ��� ������ Node, ��� ������ PredPtr ���
                ��� �������� Item.
  ����������: ������� ��� ����������� �����, �� ��� ����� ������, �� ��������
                Item ���� ��� ��� ����� ���� ����� ������� � ������� PredPtr.
  ����������: ��� ������������� ����������� �����, ��� ������������� ������ Node
                ��� ��� ������ FreePtr.
  ������:     ������ ������� ������, �� � ����������� ����� ����� ������
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        strcpy(Node[TempPtr].Data.name, Item.name);
        Node[TempPtr].Data.high_School =Item.high_School; //?
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

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr, ListElementType *item)
/* �������:   ��� ����������� ����� ��� ��� ������ PredPtr ��� �������
                ���� ����������� ����� ��� ����� ��� �� ���������.
  ����������: ��������� ��� �� ����������� �����, �� ��� ����� ����,
                ��� ����������� ����� ��� ����� ���� ����� ������� � PredPtr.
  ����������: ��� ������������� ����� ��� �� ������ FreePtr.
  ������:     ������ ����� ������, �� � ����������� ����� ����� ����
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
      item->high_School = Node[TempPtr].Data.high_School;
      strcpy(item->name, Node[TempPtr].Data.name);
      ReleaseNode(Node,TempPtr,FreePtr);

  }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* �������:    ��� ����������� �����.
   ����������: ����� �������� ��� ������������ ������, �� ��� ����� ����.
   ������:     ��������� ��� ��� �����������
*/
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d:<%s,%d> ->%d) ",CurrPtr,Node[CurrPtr].Data.name, Node[CurrPtr].Data.high_School, Node[CurrPtr].Next);
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
        printf("(%d:<%s,%d> ->%d) ",i,Node[i].Data.name, Node[i].Data.high_School, Node[i].Next);
    printf("\n");
}




