#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node**, int);
void InsertLast(struct node**, int);
void InsertAtPosititon(struct node**, int, int);
int DeleteFirst(struct node**);
int DeleteLast(struct node**);
int DeleteAtPosititon(struct node**, int);
int SearchFirstOccurence(struct node*, int);
int SearchLastOccurence(struct node*, int);
int SearchAllOccurence(struct node*, int);
void PhysicalReverse(struct node**);
void ReverseDisplay(struct node*);
void ConcatList(struct node**, struct node**);
void ConcatAtPosition(struct node**, struct node**, int);
int CountNodes(struct node*);
void DeleteAll(struct node**);
void Display(struct node*);

int main(void)
{
    struct node* pFirst = NULL;
    struct node* pSecond = NULL;
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

                        if (iPos <= 0 || iPos > CountNodes(pFirst) + 1)
                        {
                            printf("Please Enter a Valid Position. \n");
                            break;
                        }

                    }
                    printf("Enter a data = ");
                    scanf("%d", &iData);

                    if (iChoice_2 == 1)
                    {
                        InsertFirst(&pFirst, iData);
                    }
                    else if (iChoice_2 == 2)
                    {
                        InsertLast(&pFirst, iData);
                    }
                    else
                    {
                        InsertAtPosititon(&pFirst, iData, iPos);
                    }
                    break;
                case 4:
                    break;
                default:
                    printf("Enter a Valid Choice.\n");
                }
                printf("\nLinked List is =  ");
                Display(pFirst);

                if (iChoice_2 == 4)
                    break;
            }
            break;

        case 2:
            while (1)
            {
                iNodes = CountNodes(pFirst);
                if (iNodes == 0)
                {
                    printf("\nLinked List is Empty\n");
                    break;
                }
                printf("\n-------------------------");
                printf("\n1.Delete First\n2.Delete Last\n3.Delete At Position\n4.Back");
                iNodes = CountNodes(pFirst);

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
                        printf("Delete Data is %d", DeleteFirst(&pFirst));
                    }
                    else if (iChoice_2 == 2)
                    {
                        printf("Delete Data is %d", DeleteLast(&pFirst));
                    }
                    else
                    {
                        printf("Delete Data is %d", DeleteAtPosititon(&pFirst, iPos));
                    }
                    break;
                case 4:
                    break;
                default:
                    printf("Enter a Valid Choice..\n");
                }
                printf("\n\nLinked List is = ");
                Display(pFirst);

                if (iChoice_2 == 4)
                    break;
            }
            break;

        case 3:
            while (1)
            {
                iNodes = CountNodes(pFirst);
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
                            iNodes = SearchFirstOccurence(pFirst, iData);
                        }
                        if (iChoice_2 == 2)
                        {
                            iNodes = SearchLastOccurence(pFirst, iData);
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
                        printf("\nSearch all Occurence is %d \n", SearchAllOccurence(pFirst, iData));
                    }

                    /*
                                                    if(iChoice_2 == 1)
                                                    {
                                                        printf("\nSerch First Occurence  is %d \n",SearchFirstOccurence(pFirst, iData));
                                                    }
                                                    else if(iChoice_2 == 2)
                                                    {
                                                        printf("\nSearch Last Occurence is %d \n",SearchLastOccurence(pFirst, iData));
                                                    }
                                                    else
                                                    {
                                                        printf("\nSearch all Occurence is %d \n", SearchAllOccurence(pFirst, iData));
                                                    }
                    */
                case 4:
                    break;
                default:
                    printf("Enter a Valid Choice.");
                }
                printf("\nLinked List = ");
                Display(pFirst);

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
                    PhysicalReverse(&pFirst);
                    printf("\nLinked List = ");
                    Display(pFirst);
                    break;
                case 2:
                    printf("\nRevrese Display : ");
                    ReverseDisplay(pFirst);
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

                    if (iPos <= 0 || iPos > CountNodes(pFirst) + 1)
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

                                if (iPos2 <= 0 || iPos2 > CountNodes(pSecond) + 1)
                                {
                                    printf("Please Enter a Valid Position. \n");
                                    break;
                                }

                            }
                            printf("Enter a data = ");
                            scanf("%d", &iData);

                            if (iChoice_3 == 1)
                            {
                                InsertFirst(&pSecond, iData);
                            }
                            else if (iChoice_3 == 2)
                            {
                                InsertLast(&pSecond, iData);
                            }
                            if (iChoice_3 == 3)
                            {
                                InsertAtPosititon(&pSecond, iData, iPos2);
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
                        Display(pSecond);

                    }

                    if (iChoice_2 == 1)
                    {
                        ConcatList(&pFirst, &pSecond);
                    }
                    else
                    {
                        ConcatAtPosition(&pFirst, &pSecond, iPos);
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
                Display(pFirst);
                printf("\nLinked List pSecond is = ");
                Display(pSecond);
            }
            break;
        case 6:
            printf("Total Nodes is %d", CountNodes(pFirst));
            break;

        case 7:
            DeleteAll(&pFirst);
            return 0;//exit(0);

        default:
            printf("Please Enter a Valid Choice!");
        }
        printf("\n--------------------------------------------------\n");
    }
    return 0;
}

void InsertFirst(struct node** ppHead, int iNo)
{
    struct node* pNewNode = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if (pNewNode == NULL)
    {
        printf("Memory Allocation is Falied!\n");
        return;
    }

    pNewNode->iData = iNo;

    if ((*ppHead) == NULL)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;

        return;
    }

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;

    return;
}
void InsertLast(struct node** ppHead, int iNo)
{
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if (pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!\n");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    pTemp = (*ppHead);

    if (pTemp == NULL)
    {
        *ppHead = pNewNode;
        return;
    }

    while (pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }

    pTemp->pNext = pNewNode;
    pTemp = NULL;

    return;
}

void InsertAtPosititon(struct node** ppHead, int iNo, int iPos)
{
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL;
    int iCount;

    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("\nPosition is Invalid!\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(ppHead, iNo);
        return;
    }
    if (iPos == iCount + 1)
    {
        InsertLast(ppHead, iNo);
        return;
    }

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if (pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!\n");
        return;
    }

    pTemp = *ppHead;
    iCount = 1;

    while (iPos - 1 != iCount)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
    pTemp = NULL;

    return;
}
int DeleteFirst(struct node** ppHead)
{
    struct node* pTemp = NULL;
    int iDelData;

    if ((*ppHead) == NULL)
    {
        printf("Linked List is Empty\n");
        return -1;
    }

    pTemp = (*ppHead);
    (*ppHead) = pTemp->pNext;

    iDelData = pTemp->iData;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDelData;
}
int DeleteLast(struct node** ppHead)
{
    struct node* pTemp = NULL;
    int iDelData;

    pTemp = (*ppHead);

    if (pTemp->pNext == NULL)
    {
        iDelData = pTemp->iData;
        free(pTemp);
        (*ppHead) = pTemp = NULL;

        return iDelData;
    }

    while (pTemp->pNext->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }

    iDelData = pTemp->pNext->iData;
    free(pTemp->pNext);
    pTemp->pNext = NULL;
    pTemp = NULL;

    return iDelData;
}
int DeleteAtPosititon(struct node** ppHead, int iPos)
{
    struct node* pTemp1 = NULL;
    struct node* pTemp2 = NULL;
    int iDelData;
    int iCount;

    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount)
    {
        printf("Linked List is Empty!");
        return -1;
    }

    if (iPos == 1)
    {
        return DeleteFirst(ppHead);
    }

    if (iPos == iCount)
    {
        return DeleteLast(ppHead);
    }

    pTemp1 = (*ppHead);
    iCount = 1;

    while (iPos - 1 != iCount)
    {
        iCount++;
        pTemp1 = pTemp1->pNext;
    }
    pTemp2 = pTemp1->pNext->pNext;

    iDelData = pTemp1->pNext->iData;
    pTemp1->pNext->pNext = NULL;
    free(pTemp1->pNext);
    pTemp1->pNext = pTemp2;

    pTemp1 = pTemp2 = NULL;

    return iDelData;
}
int SearchFirstOccurence(struct node* pHead, int iKey)
{
    int iPos = 0;

    while (pHead != NULL)
    {
        iPos++;

        if (pHead->iData == iKey)
            return iPos;

        pHead = pHead->pNext;
    }

    return 0;
}
int SearchLastOccurence(struct node* pHead, int iKey)
{
    int iPos = 0;
    int iCount = 0;

    while (pHead != NULL)
    {
        iCount++;

        if (pHead->iData == iKey)
            iPos = iCount;

        pHead = pHead->pNext;
    }

    return iPos;
}
int SearchAllOccurence(struct node* pHead, int iKey)
{
    int iCount = 0;

    while (pHead != NULL)
    {
        if (pHead->iData == iKey)
            iCount++;

        pHead = pHead->pNext;
    }

    return iCount;
}
void PhysicalReverse(struct node** ppHead)
{
    struct node* pPrev = NULL;
    struct node* pCurrent = *ppHead;
    struct node* pNext = NULL;

    while (pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }

    (*ppHead) = pPrev;
    return;
}
void ReverseDisplay(struct node* pHead)
{
    PhysicalReverse(&pHead);
    Display(pHead);
    PhysicalReverse(&pHead);

    return;
}
void ConcatList(struct node** ppHead1, struct node** ppHead2)
{
    struct node* pTemp = NULL;

    if ((*ppHead2) == NULL)
        return;

    if ((*ppHead1) == NULL)
    {
        *ppHead1 = *ppHead2;
        (*ppHead2) = NULL;
        return;
    }

    pTemp = (*ppHead1);

    while (pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }

    pTemp->pNext = (*ppHead2);
    (*ppHead2) = NULL;

    return;
}
void ConcatAtPosition(struct node** ppHead1, struct node** ppHead2, int iPos)
{
    struct node* pTemp1 = NULL;
    struct node* pTemp2 = NULL;
    int iCount;

    iCount = CountNodes(*ppHead1);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("Invalid Posititon! \n");
        return;
    }

    if ((*ppHead2) == NULL)
        return;

    if (iPos == 1)
    {
        ConcatList(ppHead2, ppHead1);
        (*ppHead1) = *ppHead2;
        (*ppHead2) = NULL;
        return;
    }

    if (iPos == iCount + 1)
    {
        ConcatList(ppHead1, ppHead2);
        return;
    }


    pTemp1 = (*ppHead1);
    iCount = 1;

    while (iPos - 1 != iCount)
    {
        iCount++;
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = (*ppHead2);

    while (pTemp2->pNext != NULL)
    {
        pTemp2 = pTemp2->pNext;
    }

    pTemp2->pNext = pTemp1->pNext;
    pTemp1->pNext = (*ppHead2);

    (*ppHead2) = pTemp1 = pTemp2 = NULL;

    return;
}

int CountNodes(struct node* pHead)
{
    int iCount = 0;

    while (pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }

    return iCount;
}

void DeleteAll(struct node** ppHead)
{
    struct node* pTemp = NULL;

    while (*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;

        pTemp->pNext = NULL;
        free(pTemp);
    }

    pTemp = NULL;
    return;
}

void Display(struct node* pHead)
{
    //struct node *pTemp;
    if (NULL == pHead)
    {
        printf("Linked List is Empty!");
        return;
    }
    while (pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }

    return;
}
