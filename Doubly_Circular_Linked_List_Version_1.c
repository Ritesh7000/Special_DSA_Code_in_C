#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
    struct node *pPrev;
};

void Insert_First(struct node **, struct node **, int);
void Insert_Last(struct node **, struct node **, int);
void Insert_At_Position(struct node **, struct node **, int, int);
int Delete_First(struct node **, struct node **);
int Delete_Last(struct node **, struct node **);
int Delete_At_Position(struct node **, struct node **, int);
int Search_First_Occurence(struct node *, struct node *, int);
int Search_Last_Occurence(struct node *, struct node *, int);
int Search_All_Occurence(struct node *, struct node *, int);
void Concat_List(struct node **, struct node **, struct node **, struct node **);
void Concat_At_Position(struct node **, struct node **, struct node **, struct node **, int);
void Physical_Reverse(struct node **, struct node **);
void Reverse_Display(struct node *, struct node *);
int Count_Nodes(struct node *, struct node *);
void Delete_All_Nodes(struct node **, struct node **);
void Display(struct node *, struct node *);

int main(void)
{
    struct node * pFirst = NULL;
    struct node * pLast1 = NULL;

    struct node * pSecond = NULL;
    struct node * pLast2 = NULL;

    Display(pFirst,pLast1);

    Insert_First(&pFirst,&pLast1,30);
    Insert_First(&pFirst,&pLast1,20);
    Insert_First(&pFirst,&pLast1,10);
    printf("\nInsert  First = \n");
    Display(pFirst,pLast1);

    Insert_Last(&pFirst,&pLast1,40);
    Insert_Last(&pFirst,&pLast1,30);
    Insert_Last(&pFirst,&pLast1,60);
    printf("\nInsert Last = \n");
    Display(pFirst,pLast1);


    printf("\nInsert At Positon = \n");
    Insert_At_Position(&pFirst,&pLast1,70,4);
    Display(pFirst,pLast1);

    printf("\nDelete First = %d\n",Delete_First(&pFirst,&pLast1));
    Display(pFirst,pLast1);

    printf("\nDelete Last = %d\n",Delete_Last(&pFirst,&pLast1));
    Display(pFirst,pLast1);

    printf("\nDelete At Position = %d\n",Delete_At_Position(&pFirst,&pLast1,3));
    Display(pFirst,pLast1);


    printf("\n\nSearch First Occurence = %d\n",Search_First_Occurence(pFirst,pLast1,30));
    printf("Search Last occurence = %d\n",Search_Last_Occurence(pFirst,pLast1,30));
    printf("Search Last Occurence  = %d\n",Search_All_Occurence(pFirst,pLast1,30));

    printf("\nCount Nodes = %d \n",Count_Nodes(pFirst,pLast1));

    printf("\npFirst = \n");
    Display(pFirst,pLast1);

    printf("\nReverse Display = \n");
    Reverse_Display(pFirst,pLast1);
    printf("\npFirst = \n");
    Display(pFirst,pLast1);

    printf("\n\nPhysical Reverse = \n");
    Physical_Reverse(&pFirst,&pLast1);
    printf("\npFirst = \n");
    Display(pFirst,pLast1);

    printf("\n\nPhysical Reverse = \n");
    Physical_Reverse(&pFirst,&pLast1);
    printf("\npFirst = \n");
    Display(pFirst,pLast1);

    Insert_Last(&pSecond,&pLast2,100);
    Insert_Last(&pSecond,&pLast2,200);
    Insert_Last(&pSecond,&pLast2,300);

    printf("\npSecond = \n");
    Display(pSecond,pLast2);

    printf("\nConacat List = \n");
    Concat_List(&pFirst,&pLast1,&pSecond,&pLast2);

    printf("\npFirst = \n");
    Display(pFirst,pLast1);

    printf("\npSecond = \n");
    Display(pSecond,pLast2);

    Insert_Last(&pSecond,&pLast2,400);
    Insert_Last(&pSecond,&pLast2,500);
    Insert_Last(&pSecond,&pLast2,600);
    
    printf("\npSecond = \n");
    Display(pSecond,pLast2);

    printf("\nConacat At List 3 = \n");
    Concat_At_Position(&pFirst,&pLast1,&pSecond,&pLast2,3);

    printf("\npFirst = \n");
    Display(pFirst,pLast1);

    printf("\npSecond = \n");
    Display(pSecond,pLast2);

    printf("\nDelete pFirst = \n");
    Delete_All_Nodes(&pFirst,&pLast1);
    Display(pFirst,pLast1);

    printf("\nDelete pSecond = \n");
    Delete_All_Nodes(&pSecond,&pLast2);
    Display(pSecond,pLast2);
    printf("\nabcdefghijklmnopqrstuvwxyz\n"); 

    return 0;
}

void Insert_First(struct node ** ppHead, struct node ** ppTail, int iNo)
{
    struct node * pNewNode = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!");
        return;
    }

    pNewNode -> iData = iNo;

    if(NULL == (*ppHead))
    {
        (*ppHead) = (*ppTail) = pNewNode;
        (*ppHead) -> pPrev = (*ppTail);
        (*ppTail) -> pNext = (*ppHead); 

        return;
    }

    pNewNode ->pNext = (*ppHead);
    pNewNode ->pPrev = (*ppTail);

    (*ppHead) ->pPrev = pNewNode;
    (*ppTail) -> pNext = pNewNode;
    (*ppHead) = pNewNode;

    pNewNode = NULL;
}

void Insert_Last(struct node ** ppHead, struct node ** ppTail, int iNo)
{
    struct node * pNewNode = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("Mmeory Allocation is Failed!\n");
        return;
    }

    pNewNode ->iData = iNo;

    if(NULL == (*ppHead))
    {
        (*ppHead) = (*ppTail) = pNewNode;
        (*ppHead) -> pPrev = (*ppTail);
        (*ppTail) -> pNext = (*ppHead);
        return;
    }

    pNewNode -> pNext = (*ppTail) ->pNext;
    pNewNode -> pPrev = (*ppTail);
    (*ppTail) -> pNext = pNewNode;
    (*ppHead) -> pPrev = pNewNode;
    (*ppTail) = pNewNode;
    pNewNode = NULL;
}

void Insert_At_Position(struct node ** ppHead, struct node ** ppTail, int iNo, int iPos)
{
    struct node * pTemp = NULL;
    struct node * pNewNode = NULL;
    int iCount = 0;

    iCount = Count_Nodes(*ppHead, *ppTail);

    if(iPos <= 0 || iPos > iCount+1)
    {
        printf("Position is Invalid!\n");
        return;
    }

    if(iPos == 1)
    {
        Insert_First(ppHead, ppTail,iNo);
    }
    else if(iPos == iCount + 1)
    {
        Insert_Last(ppHead, ppTail, iNo);
    }
    else
    {
        pNewNode = (struct node*)malloc (sizeof(struct node));

        if(pNewNode == NULL)
        {
            printf("Memory allocation is Failed\n");
            return;
        }

        pTemp = (*ppHead);
        iCount = 1;

        while( iPos-1 != iCount)
        {
            pTemp = pTemp -> pNext;
            iCount++;
        }

        pNewNode -> iData = iNo;

        pNewNode -> pNext = pTemp ->pNext;
        pNewNode -> pPrev = pTemp;
        pTemp ->pNext ->pPrev = pNewNode;
        pTemp -> pNext = pNewNode;

        pNewNode = pTemp = NULL; 
    }
}

int Delete_First(struct node ** ppHead, struct node ** ppTail)
{
    int iDelData;

    iDelData = (*ppHead) -> iData;
    if((*ppHead) == (*ppTail))
    {
        (*ppHead) -> pNext = (*ppHead) -> pPrev = NULL;
        free(*ppHead);
        (*ppHead) = (*ppTail) = NULL;
    }
    else
    {
        (*ppTail) -> pNext = (*ppHead) -> pNext;
        (*ppHead) -> pNext -> pPrev = (*ppTail);
        (*ppHead) -> pNext = (*ppHead) -> pPrev = NULL;
        free(*ppHead);
        (*ppHead) = (*ppTail) -> pNext;
    }

    return iDelData;
}

int Delete_Last(struct node ** ppHead, struct node ** ppTail)
{
    int iDelData; 

    iDelData = (*ppTail) -> iData;

    if((*ppHead) == (*ppTail))
    {
        (*ppTail) -> pNext = (*ppTail) -> pPrev = NULL;
        free(*ppTail);
        (*ppHead) = (*ppTail) = NULL;
    }
    else
    {
        (*ppHead) -> pPrev = (*ppTail) -> pPrev;
        (*ppTail) -> pPrev -> pNext = (*ppHead);
        (*ppTail) -> pNext = (*ppTail) -> pPrev = NULL;
        free(*ppTail);
        (*ppTail) = (*ppHead) -> pPrev;
    }

    return iDelData;
}

int Delete_At_Position(struct node ** ppHead, struct node ** ppTail, int iPos)
{
    int iCount = 0;
    int iDelData;
    struct node * pTemp = NULL;

    iCount = Count_Nodes(*ppHead, *ppTail);

    if(iPos <= 0 || iPos > iCount)
    {
        printf("Position is Invalid!!\n");
        return -1;
    }

    if(iPos == 1)
    {
        iDelData = Delete_First(ppHead, ppTail);
    }
    else if(iPos == iCount)
    {
        iDelData = Delete_Last(ppHead, ppTail);
    }
    else
    {
        pTemp = (*ppHead);
        iCount = 1;

        while(iPos != iCount)
        {
            pTemp = pTemp ->pNext;
            iCount++;
        }

        iDelData = pTemp -> iData;
        pTemp -> pPrev -> pNext = pTemp -> pNext;
        pTemp -> pNext -> pPrev = pTemp -> pPrev;
        pTemp -> pNext  = pTemp -> pPrev = NULL;    //Mohmayetun Mukt
        free(pTemp);
        pTemp = NULL;
    }

    return iDelData;
}
int Search_First_Occurence(struct node * pHead, struct node * pTail, int iKey)
{
    int iPos = 0;

    do
    {
        iPos++;
        if((pHead)->iData == iKey)
            return iPos;
        pHead = pHead -> pNext;

    }while((pHead) != (pTail) -> pNext);

    return 0;
}

int Search_Last_Occurence(struct node * pHead, struct node * pTail, int iKey)
{
    int iPos = 0;
    int iCount = 0;

     do
     {
        iCount++;
        if((pHead)->iData == iKey)
            iPos = iCount;
        pHead = pHead -> pNext;
     }while((pHead) != (pTail) -> pNext);

    return iPos;
}
int Search_All_Occurence(struct node * pHead, struct node * pTail, int iKey)
{
    int iCount = 0;

    do
    {
        if((pHead)->iData == iKey)
            iCount++;
        pHead = pHead -> pNext;
    }while((pHead) != (pTail)->pNext);

    return iCount;
}
void Concat_List(struct node ** ppHead1,struct node ** ppTail1, struct node ** ppHead2, struct node ** ppTail2)
{
    if((*ppHead1) == NULL)
    {
        (*ppHead1) = (*ppHead2);
        (*ppTail1) = (*ppTail2);
        (*ppHead2) = (*ppTail2) = NULL; 
    }
    else if((*ppHead2 == NULL))
    {
        return;
    }
    else
    {
        (*ppTail1) -> pNext = (*ppHead2);
        (*ppHead2) -> pPrev = (*ppTail1);
        (*ppTail2) -> pNext = (*ppHead1);
        (*ppHead1) -> pPrev = (*ppTail2);
        (*ppTail1) = (*ppTail2);
        (*ppHead2) = (*ppTail2) = NULL;
    }
}

void Concat_At_Position(struct node ** ppHead1, struct node ** ppTail1, struct node ** ppHead2, struct node ** ppTail2, int iPos)
{
    int iCount = 0;
    struct node * pTemp = NULL;


    iCount = Count_Nodes(*ppHead1, *ppTail1);

    if(iPos <= 0 || iPos > iCount + 1)
    {
        printf("Position is Invald!\n");
        return;
    }

    if(iPos == iCount + 1)
    {
        Concat_List(ppHead1,ppTail1,ppHead2,ppTail2);
    }
    else if(iPos == 1)
    {
        Concat_List(ppHead2, ppTail2,ppHead1,ppTail1);
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;
        *ppHead2 = *ppTail2 = NULL;
    }
    else
    {
        pTemp = (*ppHead1);
        iCount = 1;

        while(iPos-1 != iCount)
        {
            pTemp = pTemp -> pNext;
            iCount++;
        }
        (*ppHead2) -> pPrev = pTemp;
        (*ppTail2) -> pNext = pTemp -> pNext;
        pTemp -> pNext -> pPrev = (*ppTail2);
        pTemp -> pNext = (*ppHead2);
        (*ppHead2) = (*ppTail2) = pTemp = NULL;
    }
}

void Physical_Reverse(struct node ** ppHead, struct node ** ppTail)
{
    struct node * pPrev= *ppTail;
    struct node * pCurrent = *ppHead;
    struct node * pNext = NULL;

    do
    {
        pNext = pCurrent -> pNext;
        pCurrent -> pNext = pPrev;
        pCurrent -> pPrev = pNext;
        pPrev = pCurrent;
        pCurrent = pNext;
    }while(pCurrent != *ppHead);


    (*ppTail) = (*ppHead);
    (*ppHead) = pPrev;
}
void Reverse_Display(struct node * pHead, struct node * pTail)
{
    Physical_Reverse(&pHead, &pTail);
    Display(pHead, pTail);
    Physical_Reverse(&pHead, &pTail);
}
int Count_Nodes(struct node * pHead, struct node * pTail)
{
    int iCount = 0;
    if(pHead == NULL)
    {
        return 0;
    }

    do
    {
        iCount++;
        pHead = pHead -> pNext;
    }while(pHead != pTail -> pNext);

    return iCount;
}
void Delete_All_Nodes(struct node ** ppHead, struct node ** ppTail)
{
    if((*ppHead) == NULL)
    {
        return;
    }
    do
    {
        (*ppTail) -> pNext = (*ppHead) ->pNext;
        (*ppHead) -> pNext -> pPrev = (*ppTail); 
        (*ppHead)-> pNext = (*ppHead) -> pPrev = NULL;
        free(*ppHead);
        (*ppHead) = (*ppTail) ->pNext;
    }while((*ppHead) != (*ppTail));


    (*ppHead) = (*ppTail) = NULL;
}
void Display(struct node * pHead, struct node * pTail)
{

    if((pHead) == NULL)
    {
        printf("Linked List is Empty");
        return;
    }

    do
    {
        printf("|%d|%d|%d|->",pHead->pPrev,pHead->iData,pHead->pNext);
        pHead = pHead ->pNext;
    }while((pHead) != (pTail)->pNext);

}

