#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node  *pNext;
};

void InsertFirst(struct node **,int);
void InsertLast(struct node **,int);
void InsertAtPosition(struct node **,int ,int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int DeleteAtPosition(struct node **, int);
int SearchFirstOccurence(struct node *,int);
int SearchLastOccurence(struct node *,int );
int SearchAllOcuurence(struct node *,int);
void PhysicalReverse(struct node **);
void ReverseDisplay(struct node *);
void ConcatList(struct node**,struct node** );
void ConcatAtPosition(struct node **,struct node **,int);
int CountNodes(struct node *);
void DeleteAll(struct node **);
void Display(struct node *);


int main(void)
{
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    Display(pFirst);

    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,10);
    printf("\nInsert  First = \n");
    Display(pFirst);

    InsertLast(&pFirst,40);
    InsertLast(&pFirst,30);
    InsertLast(&pFirst,60);
    printf("\nInsert Last = \n");
    Display(pFirst);


    printf("\nInsert At Positon 4 = \n");
    InsertAtPosition(&pFirst,70,4);
    Display(pFirst);
    
    printf("\nDelete First = %d\n",DeleteFirst(&pFirst));
    Display(pFirst);

    printf("\nDelete Last = %d\n",DeleteLast(&pFirst));
    Display(pFirst);

    printf("\nDelete At Position = %d\n",DeleteAtPosition(&pFirst,3));
    Display(pFirst);

    
    printf("\n\nSearch First Occurence = %d\n",SearchFirstOccurence(pFirst,30));
    printf("Search Last Occurence = %d\n",SearchLastOccurence(pFirst,30));
    printf("Search Last Occurence  = %d\n",SearchAllOcuurence(pFirst,30));

    printf("\nCount Nodes = %d \n",CountNodes(pFirst));

    printf("\npFirst = \n");
    Display(pFirst);

    printf("\nReverse Display = \n");
    ReverseDisplay(pFirst);
    printf("\npFirst = \n");
    Display(pFirst);

    printf("\n\nPhysical Reverse = \n");
    PhysicalReverse(&pFirst);
    printf("\npFirst = \n");
    Display(pFirst);

    printf("\n\nPhysical Reverse = \n");
    PhysicalReverse(&pFirst);
    printf("\npFirst = \n");
    Display(pFirst);

    InsertLast(&pSecond,100);
    InsertLast(&pSecond,200);
    InsertLast(&pSecond,300);

    printf("\npSecond = \n");
    Display(pSecond);

    printf("\nConacat List = \n");
    ConcatList(&pFirst,&pSecond);

    printf("\npFirst = \n");
    Display(pFirst);

    printf("\npSecond = \n");
    Display(pSecond);

    InsertLast(&pSecond,400);
    InsertLast(&pSecond,500);
    InsertLast(&pSecond,600);
    
    printf("\npSecond = \n");
    Display(pSecond);

    printf("\nConacat At List 3 = \n");
    ConcatAtPosition(&pFirst,&pSecond,3);

    printf("\npFirst = \n");
    Display(pFirst);

    printf("\npSecond = \n");
    Display(pSecond);

    printf("\nDelete pFirst = \n");
    DeleteAll(&pFirst);
    Display(pFirst);

    printf("\nDelete pSecond = \n");
    DeleteAll(&pSecond);
    Display(pSecond);

    return 0;
}

void InsertFirst(struct node **ppHead,int iNo)
{
    struct node *pNewNode  = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
    {
        printf("\nMemory Allocation is Failed!\n");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pPrev = NULL;

    if((*ppHead) == NULL)
    {
        pNewNode->pNext = NULL;
        (*ppHead) = pNewNode;
        return;
    }

    pNewNode->pNext = (*ppHead);
    (*ppHead)->pPrev = pNewNode;
    *ppHead = pNewNode;

    return;
}

void InsertLast(struct node **ppHead,int iNo)
{
    struct node  *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!\n");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(*ppHead == NULL)
    {
        pNewNode->pPrev = NULL;
        (*ppHead) = pNewNode;
        return;
    }

    pTemp = (*ppHead);
    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }

    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;

    return;
}

void InsertAtPosition(struct node ** ppHead,int iNo,int iPos)
{
    struct node  *pNewNode = NULL;
    struct node  *pTemp = NULL;
    int iCount = 0;
    iCount = CountNodes(*ppHead);

    if(iPos <= 0 || iPos > iCount+1)
    {
        printf("\nPsition is Invalid\n");
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(ppHead,iPos);
        return;
    }
    if(iPos == iCount+1)
    {
        InsertLast(ppHead,iPos);
        return;
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));
    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!\n");
        return;
    }

    pNewNode->iData= iNo;
    pTemp = *ppHead;
    iCount = 1;

    while(iPos-1 != iCount)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    pNewNode->pNext = pTemp->pNext;
    pNewNode->pPrev = pTemp;
    pTemp->pNext->pPrev = pNewNode;
    pTemp->pNext = pNewNode;
    pTemp = NULL;

    return;
}

int DeleteFirst(struct node **ppHead)
{
    int iDelData;
    
    if((*ppHead) == NULL)
    {
        printf("\nLinked List is Empty!\n");
        return 1;
    }
    
    iDelData = (*ppHead)->iData;
    if((*ppHead)->pNext == NULL)
    {
        free(*ppHead);
        *ppHead = NULL;
        return iDelData;
    }

    *ppHead = (*ppHead)->pNext;
    (*ppHead)->pPrev->pNext = NULL;
    free((*ppHead)->pPrev);
    (*ppHead)->pPrev = NULL;

    return iDelData;  
}

int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp =NULL;

    if(*ppHead == NULL)
    {
        printf("\nLinked List is Empty\n");
        return 1;
    }

    pTemp = *ppHead;
    if(pTemp->pNext == NULL)
    {
        iDelData = pTemp->iData;
        free(pTemp);
        *ppHead = NULL;
        return iDelData;
    }

    while(pTemp ->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    iDelData = pTemp->iData;
    pTemp->pPrev->pNext = NULL;
    pTemp->pPrev = NULL;
    free(pTemp);

    pTemp = NULL;
    return iDelData;
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
    int iDelData;
    struct node *pTemp = NULL;
    int iCount = 0;

    iCount = CountNodes(*ppHead);
    if(iPos <= 0 || iPos>iCount)
    {
        printf("\nPosition is Invalid\n");
        return 1;
    }
    if(iPos == 1)
    {
       return DeleteFirst(ppHead);
    }
    if(iPos == iCount)
    {
        return DeleteLast(ppHead);
    }

    pTemp = *ppHead;
    iCount = 1;

    while(iPos != iCount)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    iDelData = pTemp->iData;
    pTemp->pNext->pPrev = pTemp->pPrev;
    pTemp->pPrev->pNext = pTemp->pNext;
    pTemp->pNext=pTemp->pPrev = NULL;
    free(pTemp);

    pTemp = NULL;
    return iDelData;
}

int SearchFirstOccurence(struct node *pHead,int iKey)
{
    int iPos = 0;

    while(pHead != NULL)
    {
        iPos++;
        if(pHead->iData == iKey)
        break;
        pHead = pHead->pNext;
    }

    return iPos;
}

int SearchLastOccurence(struct node *pHead,int iKey)
{
    int iPos = 0;
    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;
        if(pHead->iData == iKey)
        iPos = iCount;

        pHead= pHead->pNext;
    }
    return iPos;
}

int SearchAllOcuurence(struct node *pHead,int iKey)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        if(pHead->iData == iKey)
        iCount++;

        pHead = pHead->pNext;
    }
    return iCount;
}

void PhysicalReverse(struct node **ppHead)
{
    struct node *pPrev = NULL;
    struct node *pCurrent = (*ppHead);
    struct node *pNext = NULL;

    while(pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pCurrent->pPrev= pNext;
        pPrev =  pCurrent;
        pCurrent = pNext;
    }

    *ppHead = pPrev;
    pPrev = NULL;

    return;
}

void ReverseDisplay(struct node *pHead)
{
    PhysicalReverse(&pHead);
    Display(pHead);
    PhysicalReverse(&pHead);

    return;
}

void ConcatList(struct node**ppHead1,struct node**ppHead2)
{
    struct node *pTemp = NULL;

    if(*ppHead2 == NULL)
    return;

    if(*ppHead1 == NULL)
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    pTemp = *ppHead1;
    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }

    pTemp->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp;

    (*ppHead2)=pTemp = NULL;
    
    return;
}

void ConcatAtPosition(struct node **ppHead1,struct node **ppHead2,int iPos)
{
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;
    int iCount = 0;

    iCount = CountNodes(*ppHead1);

    if(iPos <= 0 || iPos > iCount+1)
    {
        printf("\nPosition is Invalid!\n");
        return;
    }

    if(iPos == iCount+1)
    {
        ConcatList(ppHead1,ppHead2);
        return;
    }

    if(iPos == 1)
    {
        ConcatList(ppHead2,ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    pTemp1 = *ppHead1;
    pTemp2 = *ppHead2;
    iCount = 1;

    while(iPos-1 != iCount)
    {
        iCount++;
        pTemp1 = pTemp1->pNext;
    }

    while(pTemp2->pNext != NULL)
    {
        pTemp2 =pTemp2->pNext;
    }

    (*ppHead2)->pPrev = pTemp1;
    pTemp2->pNext = pTemp1->pNext;
    pTemp1->pNext->pPrev= pTemp2;
    pTemp1->pNext = *ppHead2;

    *ppHead2=pTemp1=pTemp2 = NULL;
    return;
}

int CountNodes(struct node *pHead)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead ->pNext;
    }
    return iCount;
}

void DeleteAll(struct node **ppHead)
{
    struct node *pTemp = NULL;

    while(*ppHead != NULL)
    {
        pTemp = *ppHead;
        (*ppHead) = pTemp->pNext;

        pTemp->pNext,pTemp->pPrev==NULL;
        free(pTemp);
    }
    pTemp = NULL;
    return;
}

void Display(struct node *pHead)
{
    if(pHead == NULL)
    {
        printf("\nLinked List Empty!\n");
        return;
    }

    while(pHead != NULL)
    {   
        printf("|%d|->",pHead->iData);
        //printf("|%d|%d|%d|->",pHead->pPrev,pHead->iData,pHead->pNext);
        pHead=pHead->pNext;
    }
    return;
}
