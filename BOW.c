#include <stdio.h>
#include <dirent.h>
#include <string.h>

struct nodeCat {
	char catName[10];
    struct nodeCat *next;
};

struct node {
    char term[100];
    int ctr;
	struct node *next;
	struct nodeCat *categories;
  };
typedef struct node nodeMLL;

// read file word by word
char *getWord(FILE *fp){
	char c;
	char *word[100];
	int i=0;

	while((c = fgetc(fp)) != EOF)
	{
		if(c == ' ' || c == '\n')
		{
			return NULL;
		}
		else
		{
			word[i++] = c;
		}
		word[i]='\0';
		return word;
	}
}


//count stop words

findStopWords(nodeMLL *header){
	nodeMLL *p, *q;
	p=header;
	q=p;
	int first, second, third, fourth, fifth=0;

	while (p != NULL) {
		if(p->ctr>first){
			fifth = fourth;
			fourth = third;
			third = second;
			second = first;
			first = p->ctr;
		}
		else if (p->ctr> second) {
			fifth = fourth;
			fourth = third;
			third = second;
			second = p->ctr;
		}
		else if (p->ctr> third) {
			fifth = fourth;
			fourth = third;
			third = p->ctr;
		}
		else if (p->ctr> fourth) {
			fifth = fourth;
			fourth = p->ctr;
		}
		else if (p->ctr> fifth) {
			fifth = p->ctr;
		}

    	q=p;
		p=p->next;
  	}
  	printf("\n\nSTOP WORDS");
  	printf("\nTerm-1: %d", first);
  	printf("\nTerm-2: %d", second);
  	printf("\nTerm-3: %d", third);
  	printf("\nTerm-4: %d", fourth);
  	printf("\nTerm-5: %d", fifth);
}



//find discriminating words

findDiscWords(nodeMLL *header, char *category){
	nodeMLL *p, *q;
	p=header;
	q=p;
	int first, second, third, fourth, fifth=0;

	while (p != NULL && p->categories->catName==category) {
		if(p->ctr>first){
			fifth = fourth;
			fourth = third;
			third = second;
			second = first;
			first = p->ctr;
		}
		else if (p->ctr> second) {
			fifth = fourth;
			fourth = third;
			third = second;
			second = p->ctr;
		}
		else if (p->ctr> third) {
			fifth = fourth;
			fourth = third;
			third = p->ctr;
		}
		else if (p->ctr> fourth) {
			fifth = fourth;
			fourth = p->ctr;
		}
		else if (p->ctr> fifth) {
			fifth = p->ctr;
		}

    	q=p;
		p=p->next;
  	}
  	printf("\n\nDISCRIMINATING WORDS");
  	printf("\n %s", category);
  	printf("\nTerm-1: %d", first);
  	printf("\nTerm-2: %d", second);
  	printf("\nTerm-3: %d", third);
  	printf("\nTerm-4: %d", fourth);
  	printf("\nTerm-5: %d", fifth);
}

// insertion function
int insert(nodeMLL **header, char *word, char *category){
	nodeMLL *p,*q,*r;

   // create node to insert and assign values to its fields
   p=malloc(sizeof(nodeMLL));
   int n = strlen(word);
   strncpy(p->term, word, n);
   p->ctr=1;
   p->next=NULL;
   int nc = strlen(category);
   strncpy(p->categories->catName, category, nc);
   p->categories->next=NULL;


   // if LL empty
   if (*header == NULL) *header=p;

   // if LL not empty
   else {
     q=*header;
     while (q != NULL && strcmp(q->term, p->term)<0) {
       r=q;
	   q=q->next;
	 }

	 //if it already exists
	 if (q!=NULL && strcmp(q->term, p->term)==0) {
	 	if(strcmp(q->categories->catName, category)==0){
	 		q->ctr++;
	 		return 0;
		 }
		 else{
		 	int nc = strlen(category);
   		 	strncpy(q->categories->next->catName, category, nc);
	 	 	q->categories->next->next=NULL;
	 	 	q->ctr++;
		 }
	 }

	 // insert node in a sorted fashion
	 if (q!=NULL) p->next=q;

	 // if value to insert is the least in LL then have header point to node
     if (q==*header) *header=p;

	 // otherwise insert node in correct position
	 else r->next=p;
   }
   return 1;
}

void main_of_bag()
{
	nodeMLL *MLL;
    struct dirent *de, *dh, *dm;  // Pointer for directory entry

  	///////////////////////////////////////////////
    // opendir() FOR ECON DIRECTORY //////////////
    //////////////////////////////////////////////
    DIR *dirEcon = opendir("dataset/econ");

    if (dirEcon == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }

    //read directory
    while ((de = readdir(dirEcon)) != NULL) {

    		// open file ...
			FILE *econf;
			econf=fopen(de->d_name,"r");

			// read in matrix ...
		  	while (!feof(econf)) {
		  		char *tempWord=getWord(econf);
		  		insert(&MLL,tempWord,"econ");
		  	}
			fclose(econf);
    }
    closedir(dirEcon);

    //opendir() FOR HEALTH	 DIRECTORY
    DIR *dirHealth = opendir("dataset/health");

    if (dirHealth == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }

    //read directory
    while ((dh = readdir(dirHealth)) != NULL) {

    		// open file ...
			FILE *healthf;
			healthf=fopen(dh->d_name,"r");

			// read in matrix ...
		  	while (!feof(healthf)) {
		  		char *tempWord=getWord(healthf);
		  		insert(&MLL,tempWord,"health");
		  	}
			fclose(healthf);
    }
    closedir(dirHealth);

    // opendir() FOR MAGAZIN DIRECTORY
    DIR *dirMag = opendir("dataset/magazin");

    if (dirMag == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }

    //read directory
    while ((dm = readdir(dirMag)) != NULL) {

    		// open file ...
			FILE *magf;
			magf=fopen(dm->d_name,"r");

			// read in matrix ...
		  	while (!feof(magf)) {
		  		char *tempWord=getWord(magf);
		  		insert(&MLL,tempWord,"econ");
		  	}
			fclose(magf);
    }
    closedir(dirEcon);



    // count stop words //////////////

    findStopWords(MLL);


    // Finding discriminating words //

    findDiscWords(MLL,"econ");
    findDiscWords(MLL,"health");
    findDiscWords(MLL,"magazin");


    return 0;
}
