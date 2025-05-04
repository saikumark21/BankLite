#include"account.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

unsigned int generate_id(void)
{
    FILE *fp = fopen(ACCOUNT_FILE,"r");
    if(!fp)
        return FIRST_ACC_NUMBER;
    #ifdef DEBUG
    else
        printf("File Opened successfully, in generate_id... \n");
    #endif
    
    unsigned int id,last_id = 0;
    char line[LINE_LENGTH];

    #ifdef DEBUG
    printf("Generated last_id, in generate_id... \n");
    #endif

    while(fgets(line,LINE_LENGTH,fp)){
        if(sscanf(line,"%u,",&id) == 1)
            last_id = id;
    }
   
    fclose(fp);
    #ifdef DEBUG
    printf("File closed successfully, in generate_id... \n");
    #endif

    if(last_id == 0){
        return FIRST_ACC_NUMBER+1;
    }
    else
        return last_id + 1;
}

void create_account(void)
{
    printf("Creating New Account \n");

    Account acc;
    FILE *fp = fopen(ACCOUNT_FILE,"a");
    if(!fp){
        printf("Error opening the file....\n");
        return;
    }
    #ifdef DEBUG
    else
        printf("File Opened successfully, in create_account... \n");
    #endif
    
    acc.id = generate_id();

    fflush(stdin);      //To clear stdin Buffer

    //Taking user inputs
    printf("Full Name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = 0;

    printf("Father's name: ");
    fgets(acc.fname, sizeof(acc.fname), stdin);
    acc.fname[strcspn(acc.fname, "\n")] = 0;

GENDER_INPUT:
    printf("Gender(M/F/O): ");
    scanf(" %c",&acc.gender);
    fflush(stdin);      //To clear stdin Buffer
    if(acc.gender == 'm' || acc.gender == 'f' || acc.gender == 'o' || acc.gender == 'M' || acc.gender == 'F' || acc.gender == 'O');
    else
        goto GENDER_INPUT;

ACC_INPUT:
    printf("Account Type(S/C): ");
    scanf(" %c",&acc.acc_type);
    fflush(stdin);      //To clear stdin Buffer
    if(acc.acc_type == 's' || acc.acc_type == 'c' || acc.acc_type == 'S' || acc.acc_type == 'C');
    else
        goto ACC_INPUT;

    acc.is_active = 1; //By Default, Account is active

    printf("Contact Number: ");
    fgets(acc.phone, sizeof(acc.phone), stdin);
    acc.phone[strcspn(acc.phone, "\n")] = 0;

AMOUNT_DEP:
    printf("Initial Deposit: ");
    scanf("%f",&acc.bal);
    if(acc.bal < 0){
        printf("Warning: Initial Deposit cannot be negative... \n");
        goto AMOUNT_DEP; 
    }

    //update_log(acc.id,acc.);

    //Saving account details to file
    fprintf(fp,"%u,%s,%s,%c,%c,%d,%s,%.2f\n",acc.id,acc.name,acc.fname,acc.gender,acc.acc_type,acc.is_active,acc.phone,acc.bal);

    printf("Account creation successful. \n");
    
    fclose(fp);
    #ifdef DEBUG
    printf("File closed successfully, in create_account... \n");
    #endif

    return;
}