#include <stdio.h>

struct node 
{
	int iData;
	struct node *pNext;
	struct node *pPrev;
	
};

void Insert_First(struct node **,int);
void Insert_Last(struct node **, int);
void Insert_At_Position(struct node **, int, int);
int Delete_First(struct node **);
int Delete_Last(struct node **);
int Delete_At_Position(struct node **, int);
int Search_First_Occurence(struct node *, int);
int Search_Last_Occurence(struct node *, int);
int Search_All_Occurence(struct node *, int);
void Physical_Reverse(struct node **);
void Reverse_Display(struct node *);
void Concat_List(struct node **,struct node **);
void Concat_At_Position(struct node **, struct node **, int);
int Count_Nodes(struct node *);
void Delete_All(struct node **);
void Display(struct node *);



int main(void)
{
	struct node *pFirst = NULL;
    struct node *pSecond = NULL;
    int iChoice_1;
    int iChoice_2;
    int iData;
    int iPos;
    int iPos1;
    int iSearch;

    while(1)
    {
        printf("\n|Operations On Linked List|\n 1.Insert First\n 2.Insert Last\n 3.Insert At Position\n 4.Delete First\n 5.Delete Last\n 6.Delete At Postion\n 7.Search First Occurence\n 8.Search Last Occurence\n 9.Search All Accurence\n10.Physical Reverce\n11.Reverse Display\n12.Concat List\n13.Concat At Position\n14.Count Nodes\n15.Exit\n");
    
        printf("\nEnter Your Choice:");
        scanf("%d",&iChoice_1);
    
    switch(iChoice_1)
    {
        case 1:

        case 2:
            
        case 3:
            if(iChoice_1 == 3)
            {
                printf("Enter a Position =");
                scanf("%d",&iPos);
                
                if(iPos <= 0 || iPos > Count_Nodes(pFirst)+1)
                {
                    printf("Position is Not Valid\n");
                    printf("Linked List is = ");
                    Display(pFirst);
                    break;
                }
            }

            printf("Enter a Data = ");
            scanf("%d",&iData);
            
            if(iChoice_1 == 1)
                Insert_First(&pFirst,iData);
            else if(iChoice_1 == 2)
                Insert_Last(&pFirst,iData);
            else
                Insert_At_Position(&pFirst,iData,iPos);
            
            printf("Linked List is = ");
            Display(pFirst);
            break;

        case 4:
           
        case 5:
            
        case 6:
            if(0 == Count_Nodes(pFirst))
            {
                printf("Linked List is Empty!\n");
                break;
            }
            if(iChoice_1 == 6)
            {                
                printf("Which Position Data you want to delete:");
                scanf("%d",&iPos);
                
                if(iPos <= 0 || iPos > Count_Nodes(pFirst))
                {
                    printf("Position is Not Valid");
                    printf("\nLinked List is =");
                    Display(pFirst);
                    break;
                }
            }
            
            if(iChoice_1 == 4)
                printf("Deleted Data is %d",Delete_First(&pFirst));
            else if(iChoice_1 == 5)
                printf("Deleted Data is %d",Delete_Last(&pFirst));
            else
                printf("Deleted Data is %d.",Delete_At_Position(&pFirst,iPos));

            printf("\nLinked List is =");
            Display(pFirst);
            
            break;
            
        case 7:
           
        case 8:
        
                if(pFirst == NULL)
                {
                    printf("Linked List  is Empty.");
                    break;
                }
        
                printf("Which Data you want search :");
                scanf("%d",&iData);
                
                if(iChoice_1 == 7)
                {
                     iSearch = Search_First_Occurence(pFirst, iData);   
                }
                else
                {
                    iSearch = Search_Last_Occurence(pFirst, iData);
                }
                
                if(iSearch == 0)
                {
                    printf("Data not Found.");
                }
                else
                {
                    printf("Data Position is %d",iSearch);
                }
                break;
        case 9:
             if(pFirst == NULL)
            {
                printf("Linked List  is Empty.");
                break;
            }
            printf("Which Data you want search :");
            scanf("%d",&iData);

            printf("Data All Occurence is %d\n",Search_All_Occurence(pFirst,iData));            
            break;

        case 10:
        
        case 11:
            if(pFirst == NULL)
            {
                printf("Linked List  is Empty.");
                break;
            }
            if(iChoice_1 == 10)
            {
                Physical_Reverse(&pFirst);
                printf("Linked List is = ");
                Display(pFirst);
            }
            else
            {
                printf("Reverse Display =  ");
                Reverse_Display(pFirst);
            }
            break;

        case 12:
            
        case 13:
            if(iChoice_1 == 13)
                {
                    printf("Enter a Position = ");
                    scanf("%d",&iPos);
                    
                    if(iPos <= 0 || iPos > Count_Nodes(pFirst)+1)
                    {
                        printf("\n Position is Not Valid\n");
                        break;
                    }
                }
            while(1)
            {
                printf("\n--------------------------");
                printf("\n1.Insert First\n2.Insert Last\n3.Insert at Position \n4.Back\n");
                printf("\nEnter a Choice : ");
                scanf("%d",&iChoice_2);

                

                switch(iChoice_2)
                {
                    case 1:
                        
                    case 2:
                       
                    case 3:
                        if(iChoice_2 == 3)
                        {
                            printf("Enter a Position = ");
                            scanf("%d",&iPos1);
                                
                            if(iPos1 <= 0 || iPos1 > Count_Nodes(pSecond)+1)
                            {
                                printf("Position is Not Valid! \n");
                                break;
                            }
                        }

                        printf("Enter a Data = ");
                        scanf("%d",&iData);

                        if(iChoice_2 == 1)
                        {
                            Insert_First(&pSecond, iData);
                        }
                        else if(iChoice_2 == 2)
                        {
                            Insert_Last(&pSecond, iData);
                        }
                        else
                        {
                            Insert_At_Position(&pSecond, iData, iPos1);
                        }

                    case 4:
                        break;
                    
                    default :
                        printf("Enter Valid Choice.\n");
                        //break;
                }
                if(iChoice_2 == 4)
                    break;
                
                printf("pSecond Linked List is:"); 
                Display(pSecond);
            }
            
            if(iChoice_1 == 12)
            {
                Concat_List(&pFirst,&pSecond);    
            }
            else
            {   
                Concat_At_Position(&pFirst,&pSecond,iPos);
            }
            printf("pFirst Linked List is:");
            Display(pFirst);
            printf("\npSecond Linked List is: "); 
            Display(pSecond);
            break;
        
        case 14:
            printf("Total Nodes Count is = %d",Count_Nodes(pFirst));
            break;   
            
        case 15:
            Delete_All(&pFirst);
            printf("pFirst Linked List is:");
            Display(pFirst);
            
            printf("\nThank You To Visit!\n\n");
            exit(0);
            
        default:
            printf("Operation  is Invalid");   
    }
    printf("\n-----------------------------------------------------");
    printf("\n");
    }

	return 0;
}

void Insert_First(struct node **ppHead,int iNo)
{
	struct node * pNewNode = NULL;
	pNewNode = (struct node*) malloc(sizeof(struct node));

	if(NULL == pNewNode)
	{
		printf("Memory Allocation is Failed. \n");
		return;
	}

	pNewNode->iData = iNo;
	pNewNode->pPrev = NULL;

	if(NULL == *ppHead)
	{
		pNewNode->pNext = NULL;
		*ppHead = pNewNode;
		return;
	}

	(*ppHead)->pPrev = pNewNode;
	pNewNode->pNext = *ppHead;
	(*ppHead) = pNewNode;

}

void Insert_Last(struct node **ppHead, int iNo)
{
	struct node * pNewNode = NULL;
	struct node *pTemp = NULL;

	pNewNode = (struct node*)malloc(sizeof(struct node));

	if(NULL == pNewNode)
	{
		printf("Memory Allocation is falied \n");
		return;
	}

	pNewNode->iData = iNo;
	pNewNode->pNext = NULL;

	if(NULL == (*ppHead))
	{
		pNewNode->pPrev = NULL;
		(*ppHead) = pNewNode;
		return;
	}

	pTemp = (*ppHead);

	while(pTemp->pNext != NULL)
	{
		pTemp = pTemp ->pNext;
	}

	pTemp->pNext = pNewNode;
	pNewNode ->pPrev = pTemp;

	return;
}

void Insert_At_Position(struct node ** ppHead,int iNo,int iPos)
{
    struct node  *pNewNode = NULL;
    struct node  *pTemp = NULL;
    int iCount = 0;
    
    iCount = Count_Nodes(*ppHead);

    if(iPos <= 0 || iPos > iCount+1)
    {
        printf("\nPsition is Invalid\n");
        return;
    }
    if(iPos == 1)
    {
        Insert_First(ppHead,iNo);
        return;
    }
    if(iPos == iCount+1)
    {
        Insert_Last(ppHead,iNo);
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

int Delete_First(struct node **ppHead)
{
	struct node *pTemp;
	int iDelData;

	if(NULL == (*ppHead))
	{
		printf("LinkedList is Empty!\n");
		return -1;
	}

	iDelData = (*ppHead)->iData;
	if(NULL == (*ppHead)->pNext)
	{
		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{
		pTemp = *ppHead;
		*ppHead = pTemp ->pNext;	
		pTemp ->pNext = NULL;
		free(pTemp);
		pTemp = NULL;
	}

	return iDelData;
}

int Delete_Last(struct node ** ppHead)
{
	struct node *pTemp = NULL;
	int iDelData;

	if(*ppHead == NULL)
	{
		printf("Linked List is Empty\n");
		return -1;
	}

	if((*ppHead)->pNext == NULL)
	{
		iDelData = (*ppHead)->iData;
		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{ 
		pTemp = *ppHead;

		while(pTemp->pNext != NULL)
		{
			pTemp = pTemp -> pNext;
		}
	
		iDelData = pTemp ->iData;
		pTemp ->pPrev ->pNext = NULL;
		pTemp ->pPrev = NULL;
		free(pTemp);
	
		pTemp = NULL;
	}

	return iDelData;
}
int Delete_At_Position(struct node **ppHead, int iPos)
{
	int iDelData;
	int iCount = 0;
	struct node *pTemp = NULL;

	iCount = Count_Nodes(*ppHead);
	if(iPos <= 0 || iPos > iCount)
	{
		printf("positon is Invalid\n");
		return -1;
	}
	if(iPos == 1)
	{
		iDelData = Delete_First(ppHead);
	}
	else if(iPos == iCount)
	{
		iDelData = Delete_Last(ppHead);
	}
	else
	{
		pTemp = *ppHead;
		iCount = 1;

		while(iPos != iCount)
		{
			iCount++;
			pTemp = pTemp ->pNext;
		}

		iDelData = pTemp ->iData;

		pTemp ->pPrev ->pNext = pTemp ->pNext;
		pTemp ->pNext ->pPrev = pTemp ->pPrev;

		pTemp ->pNext = pTemp ->pPrev = NULL;

		free(pTemp);
		pTemp = NULL;
	}

	return iDelData;
}
int Search_First_Occurence(struct node *pHead, int iKey)
{
	int iPos = 0;

	while(pHead != NULL)
	{
		iPos++;
	
		if(iKey == pHead->iData)
			return iPos;
		pHead = pHead ->pNext;
	}

	return 0;
}

int Search_Last_Occurence(struct node *pHead, int iKey)
{
	int iPos = 0;
	int iCount = 0;

	while(pHead != NULL)
	{
		iCount++;

		if(iKey == pHead->iData)
			iPos = iCount;

		pHead = pHead ->pNext;
	}

	return iPos;
}

int Search_All_Occurence(struct node *pHead, int iKey)
{
	int iCount = 0;

	while(NULL !=  pHead)
	{
		if(pHead ->iData == iKey)
			iCount++;
		pHead = pHead ->pNext;
	}

	return iCount;
}

void Physical_Reverse(struct node **ppHead)
{
	struct node *pPrev = NULL;
	struct node *pCurrent = (*ppHead);
	struct node *pNext = NULL;

	while(pCurrent != NULL)
	{
		pNext = pCurrent ->pNext;
		pCurrent ->pNext = pPrev;
		pCurrent->pPrev = pNext;
		pPrev = pCurrent;
		pCurrent = pNext;
	}

	*ppHead = pPrev;
	pPrev = NULL;
}
void Reverse_Display(struct node *pHead)
{
	Physical_Reverse(&pHead);
	Display(pHead);
	Physical_Reverse(&pHead);
}
void Concat_List(struct node **ppHead1,struct node **ppHead2)
{
	struct node * pTemp = NULL;

	if(*ppHead2 == NULL)
	;
	//{
	//	return;
	//}
	else if(*ppHead1 == NULL)
	{
		*ppHead1 = *ppHead2;
		*ppHead2 = NULL;
	}
	else
	{
		pTemp = *ppHead1;

		while(pTemp->pNext != NULL)
		{
			pTemp = pTemp ->pNext;
		}

		pTemp ->pNext = (*ppHead2);
		(*ppHead2)->pPrev = pTemp;

		(*ppHead2) = pTemp = NULL;
	}
}
void Concat_At_Position(struct node **ppHead1, struct node **ppHead2, int iPos)
{
	struct node * pTemp = NULL;
	struct node * pTemp2 =NULL;
	int iCount = 0;

	iCount = Count_Nodes(*ppHead1);
	if(iPos <= 0 || iPos > iCount+1)
	{
		printf("Position is not Vaalid!!\n");
		return;
	}

	if(iPos == iCount+1)
	{
		Concat_List(ppHead1, ppHead2);
	}
	else if(iPos == 1)
	{
		Concat_List(ppHead2,ppHead1);
		ppHead1 = ppHead2;
		ppHead2 = NULL;
	}
	else
	{
		pTemp = *ppHead1;
		pTemp2 = *ppHead2;
		iCount = 1;

		while(iCount != iPos-1)
		{
			iCount++;
			pTemp = pTemp ->pNext;
		}

		while((pTemp2) ->pNext != NULL)
		{
			pTemp2 = pTemp2 ->pNext;
		}

		pTemp ->pNext ->pPrev = pTemp2;
		(pTemp2) ->pNext = pTemp ->pNext;
		pTemp ->pNext = *ppHead2;
		(*ppHead2) ->pPrev = pTemp;

		(*ppHead2) = pTemp = pTemp2 = NULL;
	}

}
int Count_Nodes(struct node *pHead)
{
	int iCount = 0;


	while(pHead != NULL)
	{	
		pHead = pHead->pNext;
		iCount++;
	}

	return iCount;
}
void Delete_All(struct node **ppHead)
{
	struct node *pTemp = NULL;

	while(ppHead != NULL)
	{
		pTemp = *ppHead;

		(*ppHead) = pTemp ->pNext;
		pTemp->pNext=pTemp ->pPrev = NULL;
		free(pTemp);
	}

	pTemp = NULL;

}
void Display(struct node *pHead)
{

	if((pHead) == NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	do
	{
		printf("|%d|->",pHead->iData);
		pHead = pHead->pNext;

	}
	while(pHead != NULL);

}