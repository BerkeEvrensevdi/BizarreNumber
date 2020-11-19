#include <stdio.h>
#include <stdlib.h>
#include "BizzarreNumber.c"

int main()
{
    StackNodePtr mainStack = NULL;
    StackNodePtr helperStack = NULL;

    int number;
    int status;


    puts("Enter an integer number to push");
        status = scanf("%d", &number);

    while(status != EOF)
    {

         BizarreNumber_t helper;
         BizarreNumber_t main;


        if(isPrime(number))
        {


            strcpy(main.type,"PR");
            main.num = number*number;
            main.nrOfOpr = 0;

            strcpy(helper.type,"");
            helper.num = -1;
            helper.nrOfOpr = 0;

            push(&mainStack, main);
            push(&helperStack, helper);

        }
        else if(isPerfectSquare(number))
        {

            main.nrOfOpr = 0;
            while(isPerfectSquare(number))
            {
                number = sqrt(number);
                (main.nrOfOpr)++;
            }

            strcpy(main.type,"SQ");
            main.num = number;

            strcpy(helper.type,"");
            helper.num = -1;
            helper.nrOfOpr = 0;

            push(&mainStack,main);
            push(&helperStack,helper);



        }

        else if(isAbundantNumber(number)>0)
        {

            strcpy(helper.type,"AB");
            helper.num = isAbundantNumber(number);
            helper.nrOfOpr = 0;
            push(&helperStack, helper);


            strcpy(main.type,"AB");
            main.num = number-isAbundantNumber(number);
            main.nrOfOpr = 0;
            push(&mainStack, main);

        }
        else if( (isAbundantNumber(number) < 0))
        {

            strcpy(helper.type,"DF");
            helper.num = number;
            helper.nrOfOpr = 0;
            strcpy(main.type,"");
            main.num = -1;
            main.nrOfOpr = 0;
            push(&helperStack, helper);
            push(&mainStack, main);

        }
        else
        {


            strcpy(main.type,"PF");
            main.nrOfOpr = 0;
            main.num = number;
            strcpy(helper.type,"");
            helper.num = -1;
            helper.nrOfOpr = 0;
            push(&helperStack, helper);
            push(&mainStack,main);


        }





puts("Enter an integer number to push");
        status = scanf("%d", &number);


    }


   system("cls");
   StackNodePtr recover = NULL;
    puts("The main stack is:");
    printStack(mainStack);
    puts("");
    puts("The helper stack is:");
    printStack(helperStack);
    puts("");

    puts("Recovered stack is:");
    recover = recoverCipher(mainStack,helperStack);
    recover = reverseStack(recover);
    printStackDetailed(recover);
    puts("\n");





    return 0;
}
