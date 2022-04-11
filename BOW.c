#include <stdio.h>
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



//insertion function

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





