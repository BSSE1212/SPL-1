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
    void login(){
    char name[20];
    char password[10];
    printf("Enter username: ");
    scanf("%s",name);
    printf("Enter password: ");
    scanf("%s",password);
    if (strcmp(name, "Admin") == 0 && strcmp(password, "pass") == 0)
    printf("Access granted\n");
    else printf("Access denied\n");


    getch();
    }


int  load_book(char str[][3][30])
{

     FILE *fp;
    if((fp=fopen("book.txt","r"))==NULL){
        printf("Error opening file");
        exit(1);
    }

    //load book details in ram


    int i=0,total_book=0;
    while(1)
    {

            if(fgets(str[i][0],30,fp)==NULL){
                break;
            }
            fgets(str[i][1],30,fp);
            fgets(str[i][2],30,fp);
        i++;

    }

    return i;
}


void book_List()
{
    char str[100][3][30];
         int total_book = load_book(str);

    printf("Books are:\n\n\n");
    for(int p=0;p<total_book;p++){
        printf("%s\t%s \t%s\n",str[p][0],str[p][1],str[p][2]);
    }
}





// view store informatiom
/*void store_info()
{

    char str[100][3][30];
         int total_book = load_book(str);

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
        printf("\n\t\t\tBook Count = %d\n\n",total_book);
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
*/




void quickSort(char items[][3][30], int left, int right)
{
  int i, j;
  char *x;
  char temp[30];

  i = left;
  j = right;
  x = items[(left+right)/2];

  do {
    while((strcmp(items[i][0],x) < 0) && (i < right)) {
       i++;
    }
    while((strcmp(items[j][0],x) > 0) && (j > left)) {
        j--;
    }
    if(i <= j) {
        for(int p=0;p<3;p++){
            strcpy(temp, items[i][p]);
            strcpy(items[i][p], items[j][p]);
            strcpy(items[j][p], temp);
        }

      i++;
      j--;
   }
   //printf("%d %d\n",i,j);
  } while(i <= j);

  if(left < j) {
     quickSort(items, left, j);
  }
  if(i < right) {
     quickSort(items, i, right);
  }
}


void quickSortMain(char items[][3][30], int count)
{
  quickSort(items, 0, count-1);
  //printf("momin");
}




 void search_books(){


    char str[100][3][30],total_book;



    total_book = load_book(str);
    quickSortMain(str,total_book);




    char name[100],name_2[100],author[100],catagory[100];
    printf("input book name: ");
    getchar();
    gets(name);
    int x = strlen(name);
    name[x++] = '\n';
    name[x] = '\0';

    int trace =0,l=0,r=total_book,m;

    while(l<=r){
            m = (l+r)/2;
    //printf("%s %s %d %d %d %d %d\n",name,str[m][0],m,l,r,strlen(name),strlen(str[m][0]));
            if(strcmp(name,str[m][0])==0){
                trace = 1;
                printf("Book found\n");
                printf("Book name: %s",name);
                printf("Author name: %s",str[m][1]);
                printf("catagory name: %s",str[m][2]);

                break;
            }
            else if(strcmp(str[m][0],name) > 0){
                r = m-1;
            }
            else{
                l = m+1;
            }
    }

    if(trace ==0 ){
        printf("Book not found\n");
    }
 }



void Read_book(){
    //search_books();
char bookname[50];
printf("input book name: ");

    gets(bookname);
    strcat(bookname,".txt");
    printf("the %s is opening soon \n",bookname);

 FILE *fp;

 fp = fopen(bookname,"r+");        //read corresponding text

 if(!fp){
    printf("Book not found in library");
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
        char str[100][3][30];
        int total_book = load_book(str);

        FILE *fp;

        fp = fopen("book.txt","a+");
        if(fp == NULL){
            printf("Error opening filr");
        }

        printf("Input book name: ");
        scanf("%s",&str[total_book][0]);
        printf("Input book author name: ");
        scanf("%s",&str[total_book][1]);
        printf("Input book catagory name: ");
        scanf("%s",&str[total_book][2]);


        fprintf(fp,"%s\n%s\n%s",str[total_book][0],str[total_book][1],str[total_book][2]);


        printf("Book added successfuly\n\n\n");



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


//void Information_retrieval()


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
        printf("\n\t\t\t5.Add Book");
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
           add_books();
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

