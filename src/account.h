#ifndef ACCOUNT_H
#define ACCOUNT_H

//#define DEBUG         //Enable if needed to debug code
//#define IMPROVE

#define NAME_SIZE 40
#define ACCOUNT_FILE "../data/accounts.txt"
#define FIRST_ACC_NUMBER 1000   //Accounts serial Number
#define LINE_LENGTH 256         //Length of the characters in file in each line

typedef struct {
    unsigned int id;                 //unique account id(Auto-generated)
    float bal;                       //Account balance of the holder
    char name[NAME_SIZE];            //Full Name of the Account Holder
    char fname[NAME_SIZE];           //Father's Name of the Account Holder
    char gender;                     //Gender of the account holder
    char acc_type;                   //Account Type
    short int is_active;             //If the account is active
    char phone[15];                  //contact number of the holder
    char created_at[30];             //Account created time stamp
    //char mail_id[30];              //Mail ID of the Holder
    //char addr[100];                //Residential address of the Holder
}Account;

void create_account(void);
unsigned int generate_id(void);
void view_account(void);

#endif