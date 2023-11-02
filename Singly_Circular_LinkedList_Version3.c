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

	 int iChoice_1;
    int iChoice_2;
    int iChoice_3;
    int iData;
    int iPos;
    int iPos2;
    int iNodes;

    while (1)
    {
        printf("\n|Operations On Linked List|\n1.Insert Data \n2.Delete Data\n3.Search Data\n4.Reverse\n5.Concat Linked List\n6.Count Nodes\n7.Exit");

        printf("\nEnter Your Choice = ");
        scanf("%d", &iChoice_1);

        switch (iChoice_1)
        {
        case 1:
            while (1)
            {
                printf("\n-------------------------");
                printf("\n1.Insert First\n2.Insert Last\n3.Insert at Position\n4.Back");

                printf("\nYour Choice = ");
                scanf("%d", &iChoice_2);

                switch (iChoice_2)
                {
                case 1:
                case 2:
                case 3:
                    if (iChoice_2 == 3)
                    {
                        printf("Enter a position = ");
                        scanf("%d", &iPos);

                        if (iPos <= 0 || iPos > Count_Nodes(pFirst,pLast1) + 1)
                        {
                            printf("Please Enter a Valid Position. \n");
                            break;
                        }

                    }
                    printf("Enter a data = ");
                    scanf("%d", &iData);

                    if (iChoice_2 == 1)
                    {
                        Insert_First(&pFirst, &pLast1,iData);
                    }
                    else if (iChoice_2 == 2)
                    {
                        Insert_Last(&pFirst, &pLast1,iData);
                    }
                    else
                    {
                        Insert_At_Position(&pFirst, &pLast1,iData, iPos);
                    }
                    break;
                case 4:
                    break;
                default:
                    printf("Enter a Valid Choice.\n");
                }
                printf("\nLinked List is =  ");
                Display(pFirst,pLast1);

                if (iChoice_2 == 4)
                    break;
            }
            break;

        case 2:
            while (1)
            {
                iNodes = Count_Nodes(pFirst,pLast1);
                if (iNodes == 0)
                {
                    printf("\nLinked List is Empty\n");
                    break;
                }
                printf("\n-------------------------");
                printf("\n1.Delete First\n2.Delete Last\n3.Delete At Position\n4.Back");
                iNodes = Count_Nodes(pFirst,pLast1);

                printf("\nEnter Your Choice = ");
                scanf("%d", &iChoice_2);

                switch (iChoice_2)
                {
                case 1:
                case 2:
                case 3:
                    if (iNodes == 0)
                    {
                        printf("Linked List is Empty!");
                        break;
                    }
                    if (iChoice_2 == 3)
                    {
                        printf("Enter a Pos = ");
                        scanf("%d", &iPos);

                        if (iPos <= 0 || iPos > iNodes)
                        {
                            printf("Enter a valid Position\n");
                            break;
                        }
                    }
                    if (iChoice_2 == 1)
                    {
                        printf("Delete Data is %d", Delete_First(&pFirst,&pLast1));
                    }
                    else if (iChoice_2 == 2)
                    {
                        printf("Delete Data is %d", Delete_Last(&pFirst,&pLast1));
                    }
                    else
                    {
                        printf("Delete Data is %d", Delete_At_Position(&pFirst, &pLast1,iPos));
                    }
                    break;
                case 4:
                    break;
                default:
                    printf("Enter a Valid Choice..\n");
                }
                printf("\n\nLinked List is = ");
                Display(pFirst,pLast1);

                if (iChoice_2 == 4)
                    break;
            }
            break;

        case 3:
            while (1)
            {
                iNodes = Count_Nodes(pFirst,pLast1);
                if (iNodes == 0)
                {
                    printf("\nLinked List is Empty\n");
                    break;
                }

                printf("\n-------------------------");
                printf("\n1.Search First Occurence\n2.Search Last Occurence\n3.Search All Occurence\n4.Back\n");

                printf("Enter Your Choice = ");
                scanf("%d", &iChoice_2);



                switch (iChoice_2)
                {
                case 1:
                case 2:
                case 3:
                    printf("Which Data you want to search = ");
                    scanf("%d", &iData);

                    if (iChoice_2 == 1 || iChoice_2 == 2)
                    {
                        if (iChoice_2 == 1)
                        {
                            iNodes = Search_First_Occurence(pFirst, pLast1,iData);
                        }
                        if (iChoice_2 == 2)
                        {
                            iNodes = Search_Last_Occurence(pFirst, pLast1,iData);
                        }
                        if (iNodes == 0)
                        {
                            printf("Data Not Found.\n");
                            break;
                        }
                        else
                        {
                            printf("Data Position is %d", iNodes);
                        }
                    }
                    else
                    {
                        printf("\nSearch all Occurence is %d \n", Search_All_Occurence(pFirst,pLast1,iData));
                    }

                    /*
                                                    if(iChoice_2 == 1)
                                                    {
                                                        printf("\nSerch First Occurence  is %d \n",Search_First_Occurence(pFirst, iData));
                                                    }
                                                    else if(iChoice_2 == 2)
                                                    {
                                                        printf("\nSearch Last Occurence is %d \n",Search_Last_Occurence(pFirst, iData));
                                                    }
                                                    else
                                                    {
                                                        printf("\nSearch all Occurence is %d \n", Search_All_Occurence(pFirst, iData));
                                                    }
                    */
                case 4:
                    break;
                default:
                    printf("Enter a Valid Choice.");
                }
                printf("\nLinked List = ");
                Display(pFirst,pLast1);

                if (iChoice_2 == 4)
                    break;
            }
            break;

        case 4:
            while (1)
            {
                if (pFirst == NULL)
                {
                    printf("Linked List is Empty.");
                    break;
                }
                printf("\n-------------------------");
                printf("\n1.Physical Reverse\n2.Reverse Display\n3.Back\n");

                printf("Enter Your Choice = ");
                scanf("%d", &iChoice_2);

                switch (iChoice_2)
                {
                case 1:
                    Physical_Reverse(&pFirst,&pLast1);
                    printf("\nLinked List = ");
                    Display(pFirst,pLast1);
                    break;
                case 2:
                    printf("\nRevrese Display : ");
                    Reverse_Display(pFirst,pLast1);
                    break;
                case 3:
                    break;
                default:
                    printf("\nEnter a valid choice.\n");
                }
                if (iChoice_2 == 3)
                    break;
            }
            break;

        case 5:
            while (1)
            {
                gVar:
                printf("\n--------------------------------");
                printf("\n1.Concat List\n2.Concat At Position\n3.Back\n");

                printf("\nEnter Your Choice = ");
                scanf("%d", &iChoice_2);

                if (iChoice_2 == 2)
                {
                    printf("\nEnter a Position = ");
                    scanf("%d", &iPos);

                    if (iPos <= 0 || iPos > Count_Nodes(pFirst,pLast1) + 1)
                    {
                        printf("\nEnter a Valid Position.\n");
                        goto gVar;
                    }
                }


                switch (iChoice_2)
                {
                case 1:
                case 2:
                    while (1)
                    {
                        printf("\n-----------------------");
                        printf("\n1.Insert First\n2.Insert Last\n3.Insert at Position\n4.Exit\n");
                        printf("Enter Your Choice = ");
                        scanf("%d", &iChoice_3);

                        switch (iChoice_3)
                        {
                        case 1:
                        case 2:
                        case 3:
                            if (iChoice_3 == 3)
                            {
                                printf("Enter a position = ");
                                scanf("%d", &iPos2);

                                if (iPos2 <= 0 || iPos2 > Count_Nodes(pSecond,pLast2) + 1)
                                {
                                    printf("Please Enter a Valid Position. \n");
                                    break;
                                }

                            }
                            printf("Enter a data = ");
                            scanf("%d", &iData);

                            if (iChoice_3 == 1)
                            {
                                Insert_First(&pSecond, &pLast2,iData);
                            }
                            else if (iChoice_3 == 2)
                            {
                                Insert_Last(&pSecond, &pLast2,iData);
                            }
                            if (iChoice_3 == 3)
                            {
                                Insert_At_Position(&pSecond, &pLast2,iData, iPos2);
                            }
                            break;
                        case 4:
                            break;
                        default:
                            printf("Enter a Valid Choice.\n");
                        }
                        if (iChoice_3 == 4)
                            break;

                        printf("\nLinked List is(pSecond) = ");
                        Display(pSecond,pLast2);

                    }

                    if (iChoice_2 == 1)
                    {
                        Concat_List(&pFirst, &pLast1,&pSecond,&pLast2);
                    }
                    else
                    {
                        Concat_List_At_Position(&pFirst,&pLast1,&pSecond,&pLast2,iPos);
                    }
                    break;
                case 3:
                    break;

                default:
                    printf("\nEnter a Valid Choice\n");
                    break;
                }
                if (iChoice_2 == 3)
                    break;
                
                    printf("\nLinked List pFisrt is  = ");
   	                Display(pFirst,pLast1);

   	            if(iChoice_2 == 1 || iChoice_2 == 2)
                {    
                	printf("\nLinked List pSecond is = ");
   	                Display(pSecond,pLast2);
                }
            }
            break;
        case 6:
            printf("Total Nodes is %d", Count_Nodes(pFirst,pLast1));
            break;

        case 7:
            Delete_All(&pFirst,&pLast1);
            return 0;//exit(0);

        default:
            printf("Please Enter a Valid Choice!");
        }
        printf("\n--------------------------------------------------\n");
    }
 

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