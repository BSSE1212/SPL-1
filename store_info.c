#include<stdio.h>
#include<string.h>
#define MAX_BOOK 50
int main(){
    void WELCOME_PAGE();
    void MAIN_MENU();




}
void WELCOME_PAGE()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  ########################################################\n");
    printf("\n\t\t\t        ............................................");
    printf("\n\t\t\t        .                 WELCOME                   .");
    printf("\n\t\t\t        .                   TO                      .");
    printf("\n\t\t\t        .                 LIBRARY                   .");
    printf("\n\t\t\t        .               MANAGEMENT                  .");
    printf("\n\t\t\t        .                 SYSTEM                    .");
    printf("\n\t\t\t        ............................................");
    printf("\n\t\t\t  ########################################################\n");
    printf("\n\n\n\t\t\t Press any key to continue.....");
    getch();
}

void MAIN_MENU()
{
    int choice = 0;
    do
    {
        printf("\t\t\t\tMAIN MENU");
        printf("\n\n\n\t\t\t1.Store_information");
        printf("\n\t\t\t2.Read_book");
        printf("\n\t\t\t3.View Books");
        printf("\n\t\t\t4.Delete Book");
        printf("\n\t\t\t5.Search Book");
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
            book_list();
            break;
        case 4:
            deleteBooks();
            break;
        case 5:
           Information_retrieval();
            break;

        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tWrong Input!!! Try again...");
        }
    }
    while(choice!=0);
}


// view store informatiom
void store_info()
{
    int found = 0;
    char bookName[MAX_BOOK] = {0};
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
    while (fread (&addBook, sizeof(addBook), 1, fp))
    {
        printf("\n\t\t\tBook Count = %d\n\n",countBook);
        printf("\t\t\tBook id = %u",addBook.books_id);
        printf("\n\t\t\tBook name = %s",addBook.bookName);
        printf("\t\t\tBook authorName = %s",addBook.authorName);
        printf("\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)",addBook.bookIssueDate.dd,
               addBook.bookIssueDate.mm, addBook.bookIssueDate.yyyy);
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
 //   #include<stdio.h>
//#include<string.h>
//#define SIZE 20

struct book_list
{
          char name[100];
          char author[100];
          char category[100];

};

void output(struct book_list v[],int MAX_BOOK);

void main()
{
          struct bookdetail b[SIZE];

          int num,i;
          printf("Enter the Numbers of Books:");
          scanf("%d",&num);
          printf("\n");
          for(i=0;i<num;i++)

          {

                   printf("\t=:Book %d Detail:=\n",i+1);

                   printf("\nEnter the Book Name:\n");
                   scanf("%s",b[i].name);

                   printf("Enter the Author of Book:\n");
                   scanf("%s",b[i].author);

                   printf("Enter the category of Book:\n");
                   scanf("%s",b[i].category);

          }

          output(b,num);

}

void output(struct book_list v[],int MAX_BOOK)

{

          int i,t=1;

          for(i=0;i<MAX_BOOK;i++,t++)

          {

                    printf("\n");

                   printf("Book No.%d\n",t);

                   printf("\t\tBook %d Name is=%s \n",t,v[i].name);

                   printf("\t\tBook %d Author is=%s \n",t,v[i].author);

                   printf("\t\tBook %d category is=%s \n",t,v[i].pages);

                   printf("\n");

          }

}



    void book_list(){

    int i;
    struct book_list{
        char name[100];
        char author_name[100];
        char category[100];

    for(i=0;i<MAX_BOOK;I++){

    }


                                    //get input info about books and
                                    //display them






    }

 void search_books(){


 struct search_book{
    char name[100];
    char authorname[100];
    char category[100];
    }


                                                            //match with book_list to be confirm that we have the book or not



 }



void Read_book(){
    search_books();

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

void add_books(){










}









    }






}
