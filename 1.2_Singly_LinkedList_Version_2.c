#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node * pNext;
};

void InsertFirst(struct node **,int);
void InsertLast(struct node **,int);
void InsertAtPosition(struct node **,int,int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int DeleteAtPosition(struct node **,int);
int SearchFirstOccurence(struct node *,int);
int SearchLastOccurence(struct node *,int );
int SearchAllOccurence(struct node *,int);
void ConcatList(struct node **,struct node **);
void ConcatAtPosition(struct node **,struct node **,int);
void PhysicalReverse(struct node **);
void ReverseDisplay(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);
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
                
                if(iPos <= 0 || iPos > CountNodes(pFirst)+1)
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
                InsertFirst(&pFirst,iData);
            else if(iChoice_1 == 2)
                InsertLast(&pFirst,iData);
            else
                InsertAtPosition(&pFirst,iData,iPos);
            
            printf("Linked List is = ");
            Display(pFirst);
            break;

        case 4:
           
        case 5:
            
        case 6:
            if(0 == CountNodes(pFirst))
            {
                printf("Linked List is Empty!\n");
                break;
            }
            if(iChoice_1 == 6)
            {                
                printf("Which Position Data you want to delete:");
                scanf("%d",&iPos);
                
                if(iPos <= 0 || iPos > CountNodes(pFirst))
                {
                    printf("Position is Not Valid");
                    printf("\nLinked List is =");
                    Display(pFirst);
                    break;
                }
            }
            
            if(iChoice_1 == 4)
                printf("Deleted Data is %d",DeleteFirst(&pFirst));
            else if(iChoice_1 == 5)
                printf("Deleted Data is %d",DeleteLast(&pFirst));
            else
                printf("Deleted Data is %d.",DeleteAtPosition(&pFirst,iPos));

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
                     iSearch = SearchFirstOccurence(pFirst, iData);   
                }
                else
                {
                    iSearch = SearchLastOccurence(pFirst, iData);
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

            printf("Data All Occurence is %d\n",SearchAllOccurence(pFirst,iData));            
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
                PhysicalReverse(&pFirst);
                printf("Linked List is = ");
                Display(pFirst);
            }
            else
            {
                printf("Reverse Display =  ");
                ReverseDisplay(pFirst);
            }
            break;

        case 12:
            
        case 13:
            if(iChoice_1 == 13)
                {
                    printf("Enter a Position = ");
                    scanf("%d",&iPos);
                    
                    if(iPos <= 0 || iPos > CountNodes(pFirst)+1)
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
                                
                            if(iPos1 <= 0 || iPos1 > CountNodes(pSecond)+1)
                            {
                                printf("Position is Not Valid! \n");
                                break;
                            }
                        }

                        printf("Enter a Data = ");
                        scanf("%d",&iData);

                        if(iChoice_2 == 1)
                        {
                            InsertFirst(&pSecond, iData);
                        }
                        else if(iChoice_2 == 2)
                        {
                            InsertLast(&pSecond, iData);
                        }
                        else
                        {
                            InsertAtPosition(&pSecond, iData, iPos1);
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
                ConcatList(&pFirst,&pSecond);    
            }
            else
            {   
                ConcatAtPosition(&pFirst,&pSecond,iPos);
            }
            printf("pFirst Linked List is:");
            Display(pFirst);
            printf("\npSecond Linked List is: "); 
            Display(pSecond);
            break;
        
        case 14:
            printf("Total Nodes Count is = %d",CountNodes(pFirst));
            break;   
            
        case 15:
            DeleteAll(&pFirst);
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

void InsertFirst(struct node **ppHead,int iNo)
{
    //printf("\nInsert madhe ala ahe!!\n");
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

int SearchFirstOccurence(struct node *pHead,int iKey)
{
    int iPos=0;
    
    while(pHead != NULL)
    {
        iPos++;

        if(pHead->iData == iKey)
        {
            return iPos;
        }    
        pHead = pHead->pNext;
    }
    return 0;
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
        pHead = pHead->pNext;
    }
    return iPos;
}

int SearchAllOccurence(struct node *pHead,int iKey)
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

void ConcatList(struct node **ppHead1,struct node **ppHead2)
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

void ConcatAtPosition(struct node **ppHead1,struct node **ppHead2,int iPos)
{
    int iCount = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2  = NULL;

    iCount = CountNodes(*ppHead1);

    if(iPos <= 0 || iPos > iCount +1)
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
    printf("\n");
    return;
}
