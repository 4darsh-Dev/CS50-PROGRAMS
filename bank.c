#include <stdio.h>
#include <stdbool.h>

// typedef struct person
// {
//     /* data */
    
// };

int credit(int *camount, int oamount);
int debit(int *damount, int oamount);


int main(void)
{   
    int oamount = 10000;
    bool myCond = true;
    printf("******Welcome to Hello bank!****** \n");
    do
    {
        printf("Choose Option :\n");
        
        printf("1. Balance\n");
        printf("2. Credit\n");
        printf("3. Debit\n");
        printf("0. Exit\n");

        int num ;
        scanf("%i", &num);
        
        if(num == 1)
        {
            printf("Balance : %i\n", oamount);
        }
        else if(num  == 2)
        {   
            int camount;
            printf("Enter Credit Amount : ");
            scanf("%i", &camount);
            oamount = credit(&camount, oamount);
            printf("Updated Balance : %i\n",oamount);
            
        }
        else if(num == 3)
        {
            int damount;
            printf("Enter Debit Amount : ");
            scanf("%i", &damount);
            oamount = debit(&damount, oamount);
            printf("Updated Balance : %i\n",oamount);


        }
        else if(num == 0)
        {
            myCond = false;
        }
        else
        {
            printf("Inavlid Input\n");
        }
    } while (myCond);
    


}
// handles the credit process
int credit(int *camount, int oamount)
{
    oamount += *camount;
    return oamount;

}

// handles the debit process and updates the balance
int debit(int *damount, int oamount)
{
    oamount -= *damount;
    return oamount;
    

}


