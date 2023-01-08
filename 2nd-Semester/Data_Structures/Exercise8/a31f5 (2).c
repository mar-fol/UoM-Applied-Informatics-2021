#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char AM[9];
    char Name[10];
    char Surname[10];
} BinTreeElementType;                   /*� ����� ��� ��������� ��� ��� �����
                                        ����� struct */
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr, int *nodes);
void InorderTraversal(BinTreePointer Root);
void BuildBST(BinTreePointer *Root);


int main(){

    BinTreePointer ARoot, LocPtr;

    int i;
    boolean found=FALSE;
    BinTreeElementType student;
    int num=0;

    BuildBST(&ARoot);
    for(i=0;i<3;i++){
        printf("Give am:");
        scanf("%s", student.AM);
        BSTSearch(ARoot, student, &found, &LocPtr, &num);
        //InorderTraversal(ARoot);
        if(found==TRUE){
            printf("komboi=%d AM=%s Onoma=%s Epwnymo=%s\n", num, LocPtr->Data.AM, LocPtr->Data.Name, LocPtr->Data.Surname);
        }
        else{
            printf("komboi=%d o foithths den brethike sto DDA\n", num);
        }
    }



    return 0;
}

void BuildBST(BinTreePointer *Root){

    BinTreeElementType student;
    FILE *fp;
    CreateBST(Root);

    fp = fopen("i31f5.txt", "r");

    if(fp==NULL){
        printf("Problem opening file\n");
    }
    else{
        while(!feof(fp)){
            fscanf(fp, "%s %s %s ", student.AM, student.Name, student.Surname);
            BSTInsert(Root, student);
        }
    }
    fclose(fp);

}



void CreateBST(BinTreePointer *Root)
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (strcmp(Item.AM, LocPtr ->Data.AM)<0)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item.AM, LocPtr ->Data.AM)>0)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("TO STOIXEIO EINAI HDH STO DDA\n");
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item.AM, Parent ->Data.AM)<0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr,int *nodes)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
*/
{
    boolean stop;
    *nodes = 0;

    *LocPtr = Root;
    stop = FALSE;
    while (!stop && (*LocPtr) != NULL)
    {
        (*nodes)++;
        if (strcmp(KeyValue.AM, (*LocPtr)->Data.AM)<0)
            *LocPtr = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue.AM ,(*LocPtr)->Data.AM)>0)
                *LocPtr = (*LocPtr)->RChild;
            else stop = TRUE;
    }
   *Found=stop;
}

void InorderTraversal(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s %s %s\n",Root->Data.AM, Root->Data.Name, Root->Data.Surname);
        InorderTraversal(Root->RChild);
    }
}

