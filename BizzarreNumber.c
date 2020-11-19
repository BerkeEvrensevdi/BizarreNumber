#include <stdio.h>
#include "BizzarreNumber.h"
#include <math.h>


void push(StackNodePtr *topPtr, BizarreNumber_t info)
{

    StackNodePtr newPtr = malloc(sizeof(StackNode));

    if(newPtr != NULL)
    {
        newPtr->data = info;
        newPtr->nextPtr = *topPtr;
        *topPtr =  newPtr;
    }

    else
    {

        printf("%X not inserted. No memory available.\n", info);
    }

}

BizarreNumber_t pop(StackNodePtr *topPtr)
{

    StackNodePtr tempPtr = *topPtr;
    BizarreNumber_t popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;


}
int isEmpty(StackNodePtr topPtr)
{

    return topPtr == NULL;

}

void printStack(StackNodePtr currentPtr)
{

    if(currentPtr == NULL)
    {
        puts("The stack is empty.\n");
    }
    else
    {
         printf("TOP --> ");
        while(currentPtr != NULL)
        {
            if(currentPtr->data.num == -1)
                printf("NULL --> ");
            else
                printf("%d --> ", currentPtr->data.num);
            currentPtr = currentPtr->nextPtr;
        }
     printf("BOTTOM\n");

    }
}



void printStackDetailed(StackNodePtr currentPtr)
{
    printf("%9s\n","**TOP**");
    while(currentPtr != NULL)
    {
        printf("%3d, %d, %s\n", currentPtr->data.num,currentPtr->data.nrOfOpr,currentPtr->data.type);
        currentPtr = currentPtr->nextPtr;
    }

    printf("%10s","**BOTTOM**");
}


StackNodePtr reverseStack(StackNodePtr currentPtr)
{
    StackNodePtr newStack = NULL;
    /*
StackNodePtr *prev = NULL;
StackNodePtr *next = currentPtr;

while(*next != NULL)
{
*next = currentPtr->nextPtr;
currentPtr->nextPtr = *prev;
*prev = currentPtr;
currentPtr = currentPtr->nextPtr;
}
currentPtr = *prev;
*/

while(!isEmpty(currentPtr))
push(&newStack,pop(&currentPtr));


return newStack;



}

// maths related
int isAbundantNumber(int num)  //returns abundance (if 0 perfect, if > 0 abundant, if < 0 deficient)
{
    int total = 0;

    for(int i = 1; i <= num/2; i++)
    {

        if(num%i == 0)
            total = total + i;

    }

    return (total - num);

}

int isPrime(int num)  // also deficient numbers
{


    if(isAbundantNumber(num) == (-1)*(num-1))// HOME OVERPOPULATED
    {
        return 1;
    }
    return 0;

}


int isPerfectSquare(int num)
{

    double x = sqrt(num);

    if(x*x == num)
        return 1;


    return 0;


}


//recovery related
StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack)
{
    StackNodePtr recover = NULL;
    BizarreNumber_t temp;

    while(mainStack != NULL || helperStack != NULL){
         if(strcmp(mainStack->data.type,"AB") == 0 ){
                //if(isAbundantNumber((mainStack->data.num > 0)))
                    temp.num = mainStack->data.num + helperStack->data.num;
                    temp.nrOfOpr = mainStack->data.nrOfOpr;
                    strcpy(temp.type,mainStack->data.type);

                 }
         else if(strcmp(helperStack->data.type,"DF") == 0){
                    temp.num = helperStack->data.num;
                    temp.nrOfOpr = helperStack->data.nrOfOpr;
                    strcpy(temp.type,helperStack->data.type);

                 }


         else if(strcmp(mainStack->data.type,"PF") == 0){
                    temp.num = mainStack->data.num;
                    temp.nrOfOpr = mainStack->data.nrOfOpr;
                    strcpy(temp.type,mainStack->data.type);


                 }


         else if(strcmp(mainStack->data.type,"SQ") == 0 ){
                int k = mainStack->data.num;
                    for(int i = 0; i < mainStack->data.nrOfOpr; i++){
                        k = k*k;

                    }
                    temp.num = k;
                    temp.nrOfOpr = mainStack->data.nrOfOpr;
                    strcpy(temp.type,mainStack->data.type);

                 }

         else if(strcmp(mainStack->data.type,"PR") == 0 ){
                    temp.num = (int)sqrt(mainStack->data.num);
                    temp.nrOfOpr = mainStack->data.nrOfOpr;
                    strcpy(temp.type,mainStack->data.type);

                 }



            push(&recover, temp);
            mainStack = mainStack->nextPtr;
            helperStack = helperStack->nextPtr;


    }

    return recover;

}
