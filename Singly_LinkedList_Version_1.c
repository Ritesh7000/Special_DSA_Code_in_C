#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct node{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,int);
void InsertLast(struct node **,int);
void InsertAtPosition(struct node **,int,int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int DeleteAtPosition(struct node **,int);
int SerachFirst(struct node *,int);
int SearchLast(struct node *,int);
int SearchAllOccurence(struct node * ,int);
void ConcatList(struct node **, struct node **);
void ConcatAtPosition(struct node **,struct node **,int);
void PhysicalReverse(struct node **);
void ReverseDisplay(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);
void Display(struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    struct node  *pSecond  = NULL;
    
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


    printf("\nInsert At Positon = \n");
    InsertAtPosition(&pFirst,70,4);
    Display(pFirst);

    printf("\nDelete First = %d\n",DeleteFirst(&pFirst));
    Display(pFirst);

    printf("\nDelete Last = %d\n",DeleteLast(&pFirst));
    Display(pFirst);

    printf("\nDelete At Position = %d\n",DeleteAtPosition(&pFirst,3));
    Display(pFirst);


    printf("\n\nSearch First Occurence = %d\n",SerachFirst(pFirst,30));
    printf("Search Last occurence = %d\n",SearchLast(pFirst,30));
    printf("Search Last Occurence  = %d\n",SearchAllOccurence(pFirst,30));

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
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed1");
        return;
    }

    pNewNode->iData=iNo;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;
        (*ppHead)->pNext= NULL;
        return;
    }

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;

    return;
}
void InsertLast(struct node **ppHead,int iNo)
{
    struct node *pNewNode = NULL;
    struct node  *pTemp = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));
    if(pNewNode==NULL)
    {
        printf("Memoory allocation is failed");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(*ppHead == NULL)
    {
        (*ppHead)= pNewNode;
        return;
    }

    pTemp = (*ppHead);
    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNewNode;

    return;
}
void InsertAtPosition(struct node **ppHead,int iNo,int iPos)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;
    int iCount = 0;

    iCount = CountNodes(*ppHead);

    if(iPos <= 0 || iPos > iCount+1)
    {
        printf("Position is invalid!");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(ppHead,iNo);
        return;
    }
    if(iPos == iCount+1)
    {
        InsertLast(ppHead,iNo);
        return;
    }

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!");
        return;
    }
    pTemp = *ppHead;
    iCount = 1;
    while(iPos-1 != iCount)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }
    pNewNode->iData = iNo;
    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode; 
    return;
}
int DeleteFirst(struct node **ppHead)
{
    struct node *pTemp = NULL;
    int iDelData;

    if(*ppHead == NULL)
    {
        printf("\nLinke List is Empty!\n");
        return -1;
    }
 
    pTemp = *ppHead;
    iDelData = pTemp->iData;
    *ppHead = pTemp->pNext;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;
    return iDelData;
}
int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        printf("\nLinked List is empty!\n");
        return -1;
    }
    
    pTemp = *ppHead;
    if(pTemp->pNext == NULL)
    {
        iDelData = pTemp->iData;
        free(pTemp);
        pTemp = (*ppHead)=NULL;
        return iDelData;
    }

    while((pTemp)->pNext->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }

    iDelData = pTemp->pNext->iData;
    free(pTemp->pNext);
    pTemp ->pNext = NULL;
    pTemp = NULL;

    return iDelData;
}
int DeleteAtPosition(struct node **ppHead,int iPos)
{
    int iDelData;
    int iCount = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNodes(*ppHead);

    if(iPos <= 0 || iPos > iCount)
    {
        printf("\nPosition is Invalid\n");
        return -1;
    }

    if(iPos == 1)
    {
        return DeleteFirst(ppHead);
    }
    if(iPos == iCount)
    {
        return DeleteLast(ppHead);
    }

    pTemp1 = *ppHead;
    iCount = 1;
    while(iPos-1 > iCount)
    {
        iCount++;
        pTemp1 = pTemp1->pNext;
    }
    pTemp2 = pTemp1->pNext;
    iDelData = pTemp2 ->iData;

    pTemp1->pNext = pTemp2 ->pNext;
    pTemp2 ->pNext = NULL;
    free(pTemp2);
    pTemp2 = NULL;

    return iDelData;
}
int SerachFirst(struct node *pHead,int ikey)
{
    int iPos=0;
    
    while(pHead != NULL)
    {
        iPos++;

        if(pHead->iData == ikey)
        {
            return iPos;
        }    
        pHead = pHead->pNext;
    }
    return 0;
}
int SearchLast(struct node *pHead,int iKey)
{
    int iPos = 0;
    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;

        if(pHead->iData == iKey) 
        iPos = iCount;
        pHead = pHead->pNext;
    }
    return iPos;
}
int SearchAllOccurence(struct node *pHead ,int iKey)
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
void ConcatList(struct node **ppHead1, struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if((*ppHead2) == NULL)
    return;

    if((*ppHead1) == NULL)
    {
        (*ppHead1) = *ppHead2;
        (*ppHead2) = NULL;
        return;
    }

    pTemp = *ppHead1;

    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;        
    }
    pTemp ->pNext = *ppHead2;

    (*ppHead2) =pTemp= NULL;

    return;
}
void ConcatAtPosition(struct node **pphead1,struct node **ppHead2,int iPos)
{
    int iCount = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2  = NULL;

    iCount = CountNodes(*pphead1);

    if(iPos <= 0 || iPos > iCount +1)
    {
        printf("\nPosition is Invalid!\n");
        return;
    }
    if(iPos == iCount+1)
    {
        ConcatList(pphead1,ppHead2);
        return;
    }
    if(iPos == 1)
    {
        ConcatList(ppHead2,pphead1);
        *pphead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    pTemp1 = *pphead1;
    iCount = 1;
    
    while(iPos-1 != iCount)
    {
        iCount++;
        pTemp1 = pTemp1->pNext;
    }
    
    pTemp2 = *ppHead2;
    while(pTemp2->pNext != NULL)
    {
        pTemp2 = pTemp2 ->pNext;
    }
    pTemp2 ->pNext = pTemp1->pNext;

    pTemp1->pNext = *ppHead2;

    *ppHead2 = pTemp1=pTemp2 = NULL;

    return;
}
void PhysicalReverse(struct node **ppHead)
{
    struct node *pPrev = NULL;
    struct node *pCurrent  = *ppHead;
    struct node  *pNext = NULL;

    while(pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent ->pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    
    *ppHead = pPrev;
    return;

}
void ReverseDisplay(struct node *pHead)
{
    PhysicalReverse(&pHead);
    Display(pHead);
    PhysicalReverse(&pHead);
   
    return;
}
int CountNodes(struct node *pHead)
{
    int iCount = 0;

    if(pHead == NULL)
    {
        printf("Linked List is empty!\n");
    }
    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }
    return iCount;
}
void DeleteAll(struct node **ppHead)
{
    struct node *pTemp = NULL;
    while((*ppHead) != NULL)
    {
        pTemp = (*ppHead);
        (*ppHead) = pTemp->pNext;
        pTemp->pNext = NULL;
        free(pTemp);
    }
    pTemp = NULL;

    return;
}
void Display(struct node *pHead)
{
    if(pHead == NULL)
    {
        printf("LinkedList is Empty!");
        return;
    }
    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead = pHead->pNext;
    }
    return;
}
