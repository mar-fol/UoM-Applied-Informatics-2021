
#include <stdio.h>
#include <stdlib.h>

#define megisto_plithos 90        //������� ������ ��������� �������

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Dimiourgia(typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

void createVowelSet(typos_synolou VowelTable[megisto_plithos]);
void createAlphabetSet(typos_synolou AlphabetTable[megisto_plithos]);
boolean isVowel(char c, typos_synolou VowelTable[megisto_plithos]);
int vowelCount(char s[], typos_synolou AlphabetTable[megisto_plithos], typos_synolou VowelTable[megisto_plithos]);
void displayset(typos_synolou set);


int main(){

    typos_synolou alphabet[megisto_plithos],vowels[megisto_plithos];
    char word[80];


    createAlphabetSet(alphabet);
    createVowelSet(vowels);

    displayset(alphabet);
    displayset(vowels);

    for(int i=0;i<3;i++){
        printf("Give a string with uppercase characters: ");
        gets(word);
        int num = vowelCount(word, alphabet, vowels);
        printf("Number of vowels: %d\n", num);
    }


}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* �������:    ��� ������ ��� ��� ��������.
   ����������: ������� �� �������� ��� ������.
   ����������: �� ������������� ������
*/
{
    synolo[stoixeio] = TRUE;
}

void Dimiourgia(typos_synolou synolo)
/* ����������: ���������� ��� ������ ����� ��������, ������ �� ���� ������.
   ����������: �� ���� ������
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* �������:    ��� ������ ��� ��� ��������.
   ����������: ������� �� �� �������� ����� ����� ��� �������.
   ����������: ���������� TRUE �� �� �������� ����� ����� ��� ��� FALSE �����������
*/
{
    return synolo[stoixeio];
}

void createVowelSet(typos_synolou VowelTable[megisto_plithos]){
    Dimiourgia(VowelTable);

    Eisagogi(65, VowelTable);
    Eisagogi(69, VowelTable);
    Eisagogi(73, VowelTable);
    Eisagogi(79, VowelTable);
    Eisagogi(85, VowelTable);
    Eisagogi(89, VowelTable);
}

void createAlphabetSet(typos_synolou AlphabetTable[megisto_plithos]){

    Dimiourgia(AlphabetTable);

    for(int i=65;i<=90;i++){
        Eisagogi(i,AlphabetTable);
    }
}

boolean isVowel(char c, typos_synolou VowelTable[megisto_plithos]){
    return Melos(c,VowelTable);
}

int vowelCount(char s[], typos_synolou AlphabetTable[megisto_plithos], typos_synolou VowelTable[megisto_plithos]){
    int VowelNo=0;
    int i;

    for(i=0;s[i]!='\0';i++){
        if(isVowel(s[i], VowelTable)){
            VowelNo++;
        }
        else if(Melos(s[i],AlphabetTable)==FALSE){
            printf("Invalid character detected: %c-%d\n", s[i], s[i]);
        }
    }
    return VowelNo;
}

void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf("%c ",i);
	}
	printf("\n");
}


