#ifndef BIZZARRENUMBER_H_INCLUDED
#define BIZZARRENUMBER_H_INCLUDED



#endif // BIZZARRENUMBER_H_INCLUDED


typedef struct
{
    char type[3];
    int nrOfOpr;
    int num;
} BizarreNumber_t;



struct stackNode
{
    BizarreNumber_t data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

// stack related
extern void push(StackNodePtr *topPtr, BizarreNumber_t info);
extern BizarreNumber_t pop(StackNodePtr *topPtr);
extern int isEmpty(StackNodePtr topPtr);
extern void printStack(StackNodePtr currentPtr);
extern void printStackDetailed(StackNodePtr currentPtr);
extern StackNodePtr reverseStack(StackNodePtr currentPtr);

// maths related
extern int isAbundantNumber(int num); //returns abundance (if 0 perfect, if > 0 abundant, if < 0 deficient)
extern int isPrime(int num);
extern int isPerfectSquare(int num);


//recovery related
extern StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack);
