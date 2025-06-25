#include"file_io.h"
#include<stdio.h>

Account find_account_file(unsigned int number)
{
    Account temp;
    FILE *fp;
    char line[256];

    fp = fopen(ACCOUNT_FILE,"r+");
    if(!fp){
        perror("Error: Cannot find Accounts file.\n");
    }

    while(fgets(line,sizeof(line),fp))
    {
        if (sscanf(line, "%u,%49[^,],%49[^,], %c, %c,%d,%14[^,], %f,%29[^\n]",
                    &temp.id, temp.name, temp.fname, &temp.gender,
                    &temp.acc_type, &temp.is_active, temp.phone,
                    &temp.bal, temp.created_at) == 9){
                    if(temp.id == number){        
                        #ifdef DEBUG
                        printf("Found account,Account Balance: %f\n",temp.bal);
                        #endif
                        return temp;
                        }
                    else{
                        temp.id = 0;    //If account not found retuens 0.
                        return temp;
                    }
                }
        else{
                    printf("Failed to Load Account details from file....\n");
        }
        
    }
}

void update_data(Account acc)
{

}