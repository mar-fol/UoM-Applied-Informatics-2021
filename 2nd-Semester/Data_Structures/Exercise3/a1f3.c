
#include <stdio.h>
#include <stdlib.h>


#define QueueLimit 21  //ôï üñéï ìåãÝèïõò ôçò ïõñÜò

typedef int QueueElementType;   /* ï ôýðïò äåäïìÝíùí ôùí óôïé÷åßùí ôçò ïõñÜò
                         ôýðïò struct (äïìÞ) */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);


void TraverseQ(QueueType Queue);

int QSizeA(QueueType Queue);
int QSizeB(QueueType *Q);

int main(){

    QueueType Q;
    QueueElementType QEle;
    CreateQ(&Q);
    int size, i;

    printf("Question a\n");


    for(i=0;i<20;i++){
        AddQ(&Q, i);
    }

    printf("Printing Queue\n");
    TraverseQ(Q);
    size = QSizeA(Q);
    printf("(QSizeA) size=%d\n", size);
    printf("Printing Queue\n");
    TraverseQ(Q);
    size = QSizeB(&Q);
    printf("(QSizeB) size=%d\n", size);
    printf("Printing Queue\n");
    TraverseQ(Q);

    printf("\nQuestion b\n");

    for(i=0;i<20;i++){
        AddQ(&Q, i);
    }

    for(i=0;i<10;i++){
        RemoveQ(&Q, &QEle);
    }
    printf("Printing Queue\n");
    TraverseQ(Q);
    size = QSizeA(Q);
    printf("(QSizeA) size=%d\n", size);

    printf("Printing Queue\n");
    TraverseQ(Q);
    size = QSizeB(&Q);
    printf("(QSizeB) size=%d\n", size);
    printf("Printing Queue\n");
    TraverseQ(Q);

    printf("\nQuestion c\n");
    size = QSizeA(Q);
    printf("(QSizeA) size=%d\n", size);
    printf("Printing Queue\n");
    TraverseQ(Q);
    size = QSizeB(&Q);
    printf("(QSizeB) size=%d\n", size);
    printf("Printing Queue\n");
    TraverseQ(Q);




    return 0;



}

int QSizeA(QueueType Queue){
    return ((QueueLimit - Queue.Front + Queue.Rear )%QueueLimit);
    //åäþ êÜíïõìå - front + rear êáé ìåôá ïëï áõôï mod äéüôé Ý÷ïõìå ôçí ðåñßðôùóç üðïõ óôïí ðßíáêá ôï rear åßíáé ðñéí áðü ôï front
}

int QSizeB(QueueType *Q){

    QueueElementType item;
    int count=0;

    while(!EmptyQ(*Q)){
        RemoveQ(Q, &item); //edw exoume &(*Q)
        count++;
    }


    return count;


}


void CreateQ(QueueType *Queue)
/*  Ëåéôïõñãßá:  Äçìéïõñãåß ìéá êåíÞ ïõñÜ.
    ÅðéóôñÝöåé:  ÊåíÞ ïõñÜ
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* ÄÝ÷åôáé:    Ìéá ïõñÜ.
   Ëåéôïõñãßá: ÅëÝã÷åé áí ç ïõñÜ åßíáé êåíÞ.
   ÅðéóôñÝöåé: True áí ç ïõñÜ åßíáé êåíÞ, False äéáöïñåôéêÜ
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* ÄÝ÷åôáé:    Ìéá ïõñÜ.
   Ëåéôïõñãßá: ÅëÝã÷åé áí ç ïõñÜ åßíáé ãåìÜôç.
   ÅðéóôñÝöåé: True áí ç ïõñÜ åßíáé ãåìÜôç, False äéáöïñåôéêÜ
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* ÄÝ÷åôáé:    Ìéá ïõñÜ.
   Ëåéôïõñãßá: Áöáéñåß ôï óôïé÷åßï Item áðü ôçí åìðñüò Üêñç ôçò ïõñÜò
                áí ç ïõñÜ äåí åßíáé êåíÞ.
   ÅðéóôñÝöåé: Ôï óôïé÷åßï Item êáé ôçí ôñïðïðïéçìÝíç ïõñÜ.
   ¸îïäïò:     ÌÞíõìá êåíÞò ïõñÜ áí ç ïõñÜ åßíáé êåíÞ
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* ÄÝ÷åôáé:    Ìéá ïõñÜ Queue êáé Ýíá óôïé÷åßï Item.
   Ëåéôïõñãßá: ÐñïóèÝôåé ôï óôïé÷åßï Item óôçí ïõñÜ Queue
                áí ç ïõñÜ äåí åßíáé ãåìÜôç.
   ÅðéóôñÝöåé: Ôçí ôñïðïðïéçìÝíç ïõñÜ.
   ¸îïäïò:     ÌÞíõìá ãåìÜôçò ïõñÜò áí ç ïõñÜ åßíáé ãåìÜôç
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}

void TraverseQ(QueueType Queue) {
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%d ", Queue.Element[current]);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}




