#include<stdio.h>
#include"account.h"

void display_menu(void)
{
    printf("\n\t Bank Lite \t\n");
    printf("==================\n");
    printf("1. Create Account \n");
    printf("2. View Account \n");
    printf("3. Deposit \n");
    printf("4. Withdrawl \n");
    printf("5. Delete Account \n");
    printf("6. List All Accounts \n");
    printf("7. View Transactions \n");
    printf("0. Exit \n");
    
    printf("\nEnter choice: ");
}
int main()
{
    unsigned int choice = 0;

    while(1)
    {
        display_menu();
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                 create_account();
                break;
            case 2:
                // view_account();
                break;
            case 3:
                // deposit();
                break;
            case 4:
                // withdraw();
                break;
            case 5:
                // delete_account();
                break;
            case 6:
                // list_all_accounts();
                break;
            case 7:
                // view_transactions();
                break;
            case 0:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

}