#include<stdio.h>
#define MAX_BOOK_NAME 100
int main(){






}


void menu()
{
    int choice = 0;
    do
    {
        printf("MAIN MENU");
        printf("\n\n\n\t\t\t1.Store_information");
        printf("\n\t\t\t2.Read_book");
        printf("\n\t\t\t3.View Books");
        printf("\n\t\t\t4.Delete Book");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
           Store_information();
            break;
        case 2:
            Read_book();
            break;
        case 3:
            viewBooks();
            break;
        case 4:
            deleteBooks();
            break;

        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tWrong Input!!! Try again...");
        }                                            //Switch Ended
    }
    while(choice!=0);                                        //Loop Ended
}


// view store informatiom
void store_info()
{
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_Store_Info addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    unsigned int countBook = 1;
    headMessage("VIEW STORE BOOKS DETAILS");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
        exit(1);
    }
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        printf("\n\t\t\tBook Count = %d\n\n",countBook);
        printf("\t\t\tBook id = %u",addBookInfoInDataBase.books_id);
        printf("\n\t\t\tBook name = %s",addBookInfoInDataBase.bookName);
        printf("\t\t\tBook authorName = %s",addBookInfoInDataBase.authorName);
        printf("\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)",addBookInfoInDataBase.bookIssueDate.dd,
               addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
        found = 1;
        ++countBook;
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
void Read_book(){


 FILE *fp;

 fp = freopen("momin.txt","r");

 if(!fp){
    printf("Error open this file");
    exit(1);
 }

 char ch = getc(fp);
 int count =1;

  while ((ch != '\n') && (ch != EOF)) {


        printf("%d. %s",count,ch++);


        ch = getc(file);
    }










}
