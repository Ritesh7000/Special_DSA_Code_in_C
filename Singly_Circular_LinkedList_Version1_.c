#include<stdio.h>
#include<malloc.h>

struct node
{
	int iData;
	struct node * pNext;
};

void Insert_First(struct node **,struct node **, int);
void Insert_Last(struct node **,struct node **, int);
void Insert_At_Position(struct node **,struct node **, int, int);
int Delete_First(struct node **,struct node **);
int Delete_Last(struct node **,struct node **);
int Delete_At_Position(struct node **,struct node **, int);
int Search_First_Occurence(struct node *,struct node *, int);
int Search_Last_Occurence(struct node *,struct node *, int);
int Search_All_Occurence(struct node *,struct node *, int);
void Concat_List(struct node **, struct node **, struct node **, struct node ** );
void Concat_List_At_Position(struct node **, struct node **, struct node **, struct node **, int);
void Physical_Reverse(struct node **, struct node **);
void Reverse_Display(struct node*, struct node *);
int Count_Nodes(struct node *, struct node *);
void Delete_All(struct node **, struct node **);
void Display(struct node *, struct node *);


int main(void)
{
	struct node * pFirst = NULL;
	struct node * pLast1 = NULL;

    struct node *pSecond = NULL;
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


    printf("\nInsert At Positon 4 = \n");
    Insert_At_Position(&pFirst,&pLast1,70,4);
    Display(pFirst,pLast1);
    
    printf("\nDelete First = %d\n",Delete_First(&pFirst, &pLast1));

    Display(pFirst, pLast1);

    printf("\nDelete Last = %d\n",Delete_Last(&pFirst,&pLast1));
    Display(pFirst,pLast1);

    printf("\nDelete At Position = %d\n",Delete_At_Position(&pFirst,&pLast1,3));
    Display(pFirst, pLast1);

    
    printf("\n\nSearch First Occurence = %d\n",Search_First_Occurence(pFirst,pLast1,30));
    printf("Search Last Occurence = %d\n",Search_Last_Occurence(pFirst,pLast1,30));
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
    Concat_List_At_Position(&pFirst, &pLast1,&pSecond,&pLast2,3);

    printf("\npFirst = \n");
    Display(pFirst,pLast1);

    printf("\npSecond = \n");
    Display(pSecond,pLast2);

    printf("\nDelete pFirst = \n");
    Delete_All(&pFirst,&pLast1);
    Display(pFirst,pLast1);

    printf("\nDelete pSecond = \n");
    Delete_All(&pSecond,&pLast2);
    Display(pSecond,pLast2);

	return 0;
}
void Insert_First(struct node **ppHead, struct node ** ppTail, int iNo)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *)malloc(sizeof(struct node));

	if(pNewNode == NULL)
	{
		printf("Memory Allocationn is Failed !\n");
		return;
	}

	pNewNode ->iData = iNo;

	if(*ppHead == NULL)
	{
		(*ppHead) = pNewNode;
		(*ppTail) = pNewNode;
		(*ppTail) ->pNext = *ppHead;
		return;
	}
	pNewNode -> pNext = (*ppHead);
	*ppHead = pNewNode;
	(*ppTail)->pNext = pNewNode;
}
void Insert_Last(struct node **ppHead,struct node ** ppTail, int iNo)
{
	struct node * pNewNode = NULL;

	pNewNode = (struct node*)malloc(sizeof(struct node));

	if(pNewNode == NULL) 
	{
		printf("Memory Allocationn is Failed!\n");
		return;
	}

	pNewNode ->iData = iNo;

	if(*ppHead == NULL)
	{
		*ppHead = pNewNode;
		*ppTail = pNewNode;
		(*ppTail)-> pNext = *ppHead;
		return;
	}

	(*ppTail)->pNext = pNewNode;
	(*ppTail) = pNewNode;
	(*ppTail) ->pNext = *ppHead;
}

void Insert_At_Position(struct node **ppHead, struct node **ppTail, int iNo, int iPos)
{
	struct node * pNewNode = NULL;
	struct node * pTemp = NULL;
	int iCount = 0;

	iCount = Count_Nodes(*ppHead, *ppTail);

	if(iPos <= 0 || iPos > iCount+1)
	{
		printf("Position is not Valid!");
		return;
	}

	if(iPos == 1)
	{
		Insert_First(ppHead, ppTail,iNo);
	}
	else if(iPos == iCount +1)
	{
		Insert_Last(ppHead, ppTail,iNo);
	}
	else
	{
		pNewNode = (struct node *)malloc(sizeof(struct node));

		if(pNewNode == NULL)
		{
			printf("memory Allocation is Failed!\n");
			return;
		}

		pNewNode ->iData = iNo;
		pTemp = (*ppHead);
		iCount = 1;

		while(iPos-1 > iCount)
		{
			iCount++;
			pTemp = pTemp ->pNext;
		}

		pNewNode ->pNext = pTemp ->pNext;
		pTemp -> pNext = pNewNode;
		pTemp = NULL;
	}
}

int Delete_First(struct node **ppHead, struct node ** ppTail)
{
	int iDelData;

	if((*ppHead) == NULL)
	{
		printf("LinkedList is Empty!\n");

		return -1;
	}

	iDelData = (*ppHead)->iData;

	if(*ppHead == *ppTail)
	{
		(*ppHead)->pNext = NULL;
		free(*ppHead);
		(*ppHead)=(*ppTail)= NULL;
	}
	else
	{
		(*ppTail)->pNext = (*ppHead)->pNext;
		(*ppHead)->pNext = NULL;
		free(*ppHead);
		*ppHead = (*ppTail)->pNext;
	}
	return iDelData;
}

int Delete_Last(struct node **ppHead, struct node ** ppTail)
{
	struct node *pTemp = NULL;
	int iDelData;

	if((*ppHead) == NULL)
	{
		printf("LinkedList is Empty!\n");

		return -1;
	}

	iDelData = (*ppTail)->iData;

	if((*ppHead) == (*ppTail))
	{
		(*ppHead)->pNext = NULL;
		free(*ppHead);
		(*ppHead)=(*ppTail) = NULL;
	}
	else
	{
		pTemp = (*ppHead);

		while(pTemp->pNext != (*ppTail))
		{
			pTemp = pTemp ->pNext;
		}

		pTemp ->pNext = (*ppTail)->pNext;
		(*ppTail)->pNext = NULL;
		free(*ppTail);
		(*ppTail) = pTemp;
		 pTemp = NULL;
	}

	return iDelData;
}

int Delete_At_Position(struct node ** ppHead, struct node ** ppTail,int iPos)
{
	struct  node * pTemp1 = NULL;
	struct  node * pTemp2 = NULL;
	// int iDelData;
	int iCount;

	iCount = Count_Nodes(*ppHead, *ppTail);

	if(iPos <= 0 || iCount < iPos)
	{
		printf("Position is not Valid!\n");
		return -1;
	}

	if(iPos == 1)
	{
		return Delete_First(ppHead, ppTail);
	}
	else if(iPos == iCount)
	{
		return Delete_Last(ppHead, ppTail);
	}
	else
	{
		pTemp1 = (*ppHead);
		iCount =1;

		while(iPos-1 != iCount)
		{
			iCount++;
			pTemp1 = pTemp1 ->pNext;
		}

		pTemp2 = pTemp1 -> pNext; 
		iCount = pTemp2 -> iData;		//reuse of Variable's
		pTemp1 ->pNext = pTemp2 ->pNext;
		pTemp2->pNext = NULL;
		free(pTemp2);
		pTemp1 = pTemp2 = NULL;
		
		return iCount;
	}
}

int Search_First_Occurence(struct node *pHead, struct node *pTail,int iKey)
{
	int iCount = 0;

	do
	{
		iCount++;

		if((pHead)->iData == iKey)
			return iCount;
		(pHead) = (pHead)->pNext;
	}while(pHead != pTail->pNext);

	return 0;
}
int Search_Last_Occurence(struct node *pHead, struct node *pTail,int iKey)
{
	 int iCount = 0;
	 int iPos = 0;

	 do
	 {
	 	iCount++;

	 	if((pHead)->iData == iKey)
	 		iPos = iCount;

	 	(pHead) = (pHead) ->pNext;
	 }while((pHead) != (pTail)->pNext);

	 return iPos;
}

int Search_All_Occurence(struct node *pHead, struct node *pTail,int iKey)
{
	int iCount = 0;

	do{
		if((pHead)->iData == iKey)
			iCount++;

		(pHead) = (pHead)->pNext;
	}while((pHead) != (pTail)->pNext);

	return iCount;
}
void Concat_List(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node ** ppTail2)
{

	if((*ppHead2) == NULL)
		;
	else if(*ppHead1 == NULL)
	{
		(*ppHead1)  = (*ppHead2);
		(*ppTail1) = (*ppTail2);

		(*ppHead1) = (*ppTail1) = NULL;
	}
	else
	{
		(*ppTail1)->pNext = (*ppHead2);
		(*ppTail1) = (*ppTail2);
		(*ppTail1)->pNext = (*ppHead1);

		(*ppHead2) = (*ppTail2) = NULL;
	}
	return;

}
void Concat_List_At_Position(struct node **ppHead1, struct node **ppTail1,
							 struct node **ppHead2, struct node **ppTail2,
							 int iPos)
{
	struct node *pTemp = NULL;
	int iCount;

	iCount = Count_Nodes(*ppHead1, *ppTail1);

	if(iPos <= 0 || iPos > iCount + 1)
	{
		printf("Position is not valid!\n");
		return;
	}

	if(iPos == 1)
	{
		Concat_List(ppHead2, ppTail2, ppHead1, ppTail1);

		(*ppHead1) = (*ppHead2);
		(*ppTail1) = (*ppTail2);

		(*ppHead2) = (*ppTail2) = NULL;
	}
	else if(iPos == iCount + 1)
	{
		Concat_List(ppHead1, ppTail1, ppHead2, ppTail2);
	}
	else
	{
		iCount = 1;
		pTemp = (*ppHead1);

		while(iPos-1 != iCount)
		{
			iCount++;
			pTemp = pTemp ->pNext;
		}

		(*ppTail2) -> pNext = pTemp ->pNext;
		pTemp -> pNext = (*ppHead2);

		(*ppHead2) = (*ppTail2) = pTemp  = NULL;
	}

	return;
}

void Physical_Reverse(struct node **ppHead, struct node ** ppTail)
{
	struct node *pPrev = *ppTail;
	struct node *pCurrent = (*ppHead);
	struct node *pNext = NULL;

	do
	{
		pNext = pCurrent ->pNext;
		pCurrent ->pNext = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;
	}while(pCurrent != *ppHead);

	*ppTail = *ppHead;
	*ppHead = pPrev;
}

void Reverse_Display(struct node *pHead, struct node *pTail)
{
	Physical_Reverse(&pHead, &pTail);
	Display(pHead,pTail);
	Physical_Reverse(&pHead, &pTail);
}

int Count_Nodes(struct node *pHead, struct node * pTail)
{
	int iCount = 0;
	
	if(pHead == NULL)
	{
		return 0;
	}
	
	do{
		iCount++;
		pHead = pHead ->pNext;
	}while((pHead) != (pTail)->pNext);

	return iCount;
}

void Delete_All(struct node **ppHead, struct node ** ppTail)
{
	struct node * pTemp = NULL;

    if(NULL == *ppHead)
    {
        printf("Linked List is Empty!!\n");
        return;
    }
    
    while(*ppHead != *ppTail)
    {   pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        pTemp->pNext = NULL;
        free(pTemp);
        pTemp = pTemp ->pNext;
    }
    free(*ppTail);
    *ppHead = *ppTail = NULL;
}

void Display(struct node *pHead, struct node *pTail)
{
	if(pHead == NULL)
	{
		printf("\tLinked List is Empty");
		return;
	}

	do{
		printf("|%d|%d|->",pHead->iData);
		pHead = pHead ->pNext;

	}while(pHead != (pTail)->pNext);

	return;
}