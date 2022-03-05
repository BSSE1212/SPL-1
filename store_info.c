#include<stdio.h>
#include<string.h>
#include<stdlib.h>




struct book_list
{
          char name[100];
          char author_name[100];
          char category[100];
          int page;

};
struct book_list b[50];

void output(struct book_list v[],int MAX_BOOK);
void Store_information();

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

    printf("\n\n\n\t\t\t Press any key to continue.....\n\n");
    getch();
}



void book_List()
{
          //struct book_list b[MAX_BOOK];

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
                   scanf("%s",b[i].author_name);

                   printf("Enter the category of Book:\n");
                   scanf("%s",b[i].category);

          }

          output(b,num);

}



// view store informatiom
/*void store_info()
{
    int found = 0;
    char bookName[MAX_BOOK] = {0};
    //s_Store_Info addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    unsigned int countBook = 1;
    headMessage("VIEW STORE BOOKS DETAILS");
    fp = fopen(FILE_NAME,"r");
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
}*/





 void search_books(){

    FILE *fp;

    if((fp=fopen("C:\\Users\\Hp\\Desktop\\SPL-1\\book.txt","r"))==NULL){
        printf("Error opening file");
        exit(1);
    }


    char name[100],name_2[100],author[100],catagory[100];
    printf("input book name: ");
    getchar();
    gets(name);
    int x = strlen(name);
    name[x++] = '\n';
    name[x] = '\0';

    int trace =0;

    while(1){

            if(fgets(name_2,100,fp)==NULL){
                break;
            }
            fgets(author,100,fp);
            fgets(catagory,100,fp);


            if(strcmp(name,name_2)==0){
                    trace = 1;
                printf("Book found\n");
                printf("Book name: %s",name);
                printf("Author name: %s",author);
                printf("catagory name: %s",catagory);

                break;
            }
            else if(strlen(name_2)== 0){
                break;
            }
    }

    if(trace ==0 ){
        printf("Book not found\n");
    }
 }



void Read_book(){
    search_books();
char bookname[50];
printf("input book name: ");

    gets(bookname);
    strcat(bookname,".txt");
    printf("the %s is opening soon %d \n",bookname,strcmp(bookname,"Gora.txt"));

 FILE *fp;

 fp = fopen(bookname,"r+");        //read corresponding text

 if(!fp){
    printf("Error open this file");
    exit(1);
 }
 char ch[1000];
 printf("the %s is opening\n",bookname);

 while(1){

            if(fgets(ch,100,fp)==NULL){
                break;
            }

        printf("%s\n",ch);


    }

}

void add_books(){





                                                //it will update the book_list()




}
void Store_information()
{
    int counter=0,number_of_book;
    char temp[100];

    FILE *fp;

    if((fp= fopen("test.txt","r"))==NULL){
        printf("Error openning file");
        exit(0);
    }

    fscanf(fp, "%d\n",&number_of_book);
    printf("Total number of book: %d \n",number_of_book);

    for(int i=0;i<number_of_book;i++){
            fgets(b[i].name, 100, fp);
            fgets(b[i].author_name, 100, fp);
            fgets(b[i].category, 100, fp);


    }

}




void output(struct book_list v[],int MAX_BOOK)

{

          int i,t=1;

          for(i=0;i<MAX_BOOK;i++,t++)

          {

                    printf("\n");

                   printf("Book No.%d\n",t);

                   printf("\t\tBook %d Name is=%s \n",t,v[i].name);

                   printf("\t\tBook %d Author is=%s \n",t,v[i].author_name);

                   printf("\t\tBook %d category is=%s \n",t,v[i].page);

                   printf("\n");

          }

}


void deleteBooks()
{

}


void Information_retrieval()
{

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
        printf("\n\t\t\t6.Search Book");
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
            book_List();
            break;
        case 4:
            deleteBooks();
            break;
        case 5:
           Information_retrieval();
            break;
        case 6:
           search_books();
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





int main(){
     WELCOME_PAGE();
    MAIN_MENU();

}

