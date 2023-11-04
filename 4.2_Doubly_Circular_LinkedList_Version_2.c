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
                
                if(iPos <= 0 || iPos > Count_Nodes(pFirst,pLast1)+1)
                {
                    printf("Position is Not Valid\n");
                    printf("Linked List is = ");
                    Display(pFirst,pLast1);
                    break;
                }
            }

            printf("Enter a Data = ");
            scanf("%d",&iData);
            
            if(iChoice_1 == 1)
                Insert_First(&pFirst,&pLast1,iData);
            else if(iChoice_1 == 2)
                Insert_Last(&pFirst,&pLast1,iData);
            else
                Insert_At_Position(&pFirst,&pLast1,iData,iPos);
            
            printf("Linked List is = ");
            Display(pFirst,pLast1);
            break;

        case 4:
           
        case 5:
            
        case 6:
            if(0 == Count_Nodes(pFirst,pLast1))
            {
                printf("Linked List is Empty!\n");
                break;
            }
            if(iChoice_1 == 6)
            {                
                printf("Which Position Data you want to delete:");
                scanf("%d",&iPos);
                
                if(iPos <= 0 || iPos > Count_Nodes(pFirst,pLast1))
                {
                    printf("Position is Not Valid");
                    printf("\nLinked List is =");
                    Display(pFirst,pLast1);
                    break;
                }
            }
            
            if(iChoice_1 == 4)
                printf("Deleted Data is %d",Delete_First(&pFirst,&pLast1));
            else if(iChoice_1 == 5)
                printf("Deleted Data is %d",Delete_Last(&pFirst, &pLast1));
            else
                printf("Deleted Data is %d.",Delete_At_Position(&pFirst,&pLast1,iPos));

            printf("\nLinked List is =");
            Display(pFirst,pLast1);
            
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
                     iSearch = Search_First_Occurence(pFirst, pLast1,iData);   
                }
                else
                {
                    iSearch = Search_Last_Occurence(pFirst, pLast1,iData);
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

            printf("Data All Occurence is %d\n",Search_All_Occurence(pFirst,pLast1,iData));            
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
                Physical_Reverse(&pFirst,&pLast1);
                printf("Linked List is = ");
                Display(pFirst,pLast1);
            }
            else
            {
                printf("Reverse Display =  ");
                Reverse_Display(pFirst,pLast1);
            }
            break;

        case 12:
            
        case 13:
            if(iChoice_1 == 13)
                {
                    printf("Enter a Position = ");
                    scanf("%d",&iPos);
                //    printf("\nif chya var\n");
                    
                    if(iPos <= 0 || iPos > Count_Nodes(pFirst,pLast1)+1)
                    {
                        printf("\n Position is Not Valid\n");
                        break;
                    }
                //    printf("\nif chya khali\n");

                }
                //    printf("\n while chya var\n");

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
                                
                            if(iPos1 <= 0 || iPos1 > Count_Nodes(pSecond,pLast2)+1)
                            {
                                printf("Position is Not Valid! \n");
                                break;
                            }
                        }

                        printf("Enter a Data = ");
                        scanf("%d",&iData);

                        if(iChoice_2 == 1)
                        {
                            Insert_First(&pSecond, &pLast2,iData);
                        }
                        else if(iChoice_2 == 2)
                        {
                            Insert_Last(&pSecond, &pLast2,iData);
                        }
                        else
                        {
                            Insert_At_Position(&pSecond, &pLast2,iData, iPos1);
                        }

                    case 4:
                        break;
                    
                    default :
                        printf("Enter Valid Choice.\n");
                        //break;
                }

                if(iChoice_2 == 4)
                 {
                 	break;
                 }   
                
                printf("pSecond Linked List is:"); 
                Display(pSecond,pLast2);
            }
            
            if(iChoice_1 == 12)
            {
                Concat_List(&pFirst,&pLast1,&pSecond,&pLast2);    
            }
            else
            {   
                Concat_At_Position(&pFirst,&pLast1,&pSecond,&pLast2,iPos);               	
            }
            printf("pFirst Linked List is:");
            Display(pFirst,pLast1);
            printf("\npSecond Linked List is: "); 
            Display(pSecond,pLast2);
            break;
        
        case 14:
            printf("Total Nodes Count is = %d",Count_Nodes(pFirst,pLast1));
            break;   
            
        case 15:
            Delete_All_Nodes(&pFirst,&pLast1);
            printf("pFirst Linked List is:");
            Display(pFirst,pLast1);
            
            printf("\n\n\tGOOD BY\n\n");
            exit(0);
            
        default:
            printf("Operation  is Invalid");   
    }
    printf("\n-----------------------------------------------------");
    printf("\n");
    }

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
		(*ppTail1) = (*ppTail2);
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
	
	do{
		iCount++;
		pHead = pHead ->pNext;

	}while((pHead) != (pTail)->pNext);

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
