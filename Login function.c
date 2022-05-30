#include<conio.h>
#include<stdio.h>
#include<string.h>
static int i=0;
struct web
{
char name[30],pass[30];
}w[99];
int n;
void login(void);

int main()
{
    printf("\n\n\n\n\n\t\t\t\tWELCOME TO LIBRARY SYSTEM\n\n");
    login();
}

void reg()
{
    FILE *fp;

    char c,checker[30];
    int z=0, flag;
    char userName[40], password[30];

    fp=fopen("Web_reg.txt","a+");

    printf("\n\n\t\t\t\tWELCOME TO REGISTER ZONE");

    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^");


    while(1) {
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",checker);
        flag = 1;

        while(!feof(fp))
        {
            fscanf(fp, "%s%s",&userName, &password);

            if(strcmp(checker,userName)==0)
            {
                printf("\n\n\t\t\t This user name already exist\n");
                printf("Enter the user name again.....\n");
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            strcpy(userName,checker);
            break;  // Because new user name found
        }
    }

    printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
    scanf("%s",password);

    fprintf(fp, "%s %s\n", userName, password);
    fclose(fp);
    printf("Your registration is successfully done!!!!");
  }


void login()
{
    FILE *fp;
    char userName[40], password[40], user[40], pass[40];
    int flag;

    fp=fopen("Web_reg.txt","a+");

    printf("\n\n\t\t\t\tWELCOME TO LOG IN ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");

    printf("\n\n\t\t\t\t  ENTER USERNAME: ");
    scanf("%s",userName);
    printf("\n\t\t\t\t  ENTER PASSWORD: ");
    scanf("%s",password);


    flag = 0;
    while(!feof(fp))
    {
        fscanf(fp, "%s %s", &user, &pass);
        // call decryption function using user and pass
        if(strcmp(user,userName) == 0 && strcmp(pass, password) == 0){
            printf("Login successfully done!!!");
            fclose(fp);
            flag = 1;
            break;
        }
    }
    if(flag != 1) {
        printf("There is no user in this name...");
        printf("\nPlease registration ");
        reg();
    }
}
