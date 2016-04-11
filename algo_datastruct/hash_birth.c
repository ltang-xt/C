#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 365 /*Maximum days in a year*/

FILE * fin;   /* Birthday File */
int  namecount;    /* Number of names read */
int  dupecount;    /* Number of dupes founc */

int hash_birthday(char *); /* Our Hash function */

#ifdef __STDC__
char * strdup(const char *);
#endif

int main(int argc , char * argv[])
{
    char buffer[128]; /* where the records will be read */
    int hashvalue;   /* the hash value we will compute */
    char * name;
    char * table[TABLE_SIZE];
    int i;

    if(argc<2)
    {
        fprintf(stderr,"Error!Expecting birthday file\n");
        exit(EXIT_FAILURE);
    }

    if((fin = fopen(argv[1],"rt")) == NULL){
        fprintf(stderr,"Can't Open %s\n",argv[1]);
	exit(EXIT_FAILURE);
    }

    for(i=0;i<TABLE_SIZE;i++)table[i]=NULL;

    while(!feof(fin)){
        if(fgets(buffer,128,fin) == NULL)break;
        buffer[strlen(buffer)-1]='\0';
        
	namecount += 1;
	hashvalue = hash_birthday(buffer);
        name = strdup(buffer+4);
        
        printf("the number:%d name is %s,hashvalue is %d \r\n",namecount,name,hashvalue);
 
	if(table[hashvalue] == NULL){
	    table[hashvalue] = name;
	    continue;
	}
	else{
	    dupecount += 1;
	    printf("%s and %s have the same birthday.\n",name,table[hashvalue]);
	    continue;
	}
    }
    
    if(dupecount == 0){
        printf("No duplicate matches found among %d people.\n",namecount);
	if(namecount > 50){
	    printf("How rare!\n");
	}
    }
    else
	printf("Among %d people , %d matches were found\n",namecount,dupecount);
    exit(EXIT_SUCCESS);
}

int hash_birthday(char * data)
{
    const int days_elapsed[12]=
	{0,31,60,91,121,152,182,213,244,274,305,335};
    int mm,dd;
    char record[128];

    strcpy(record , data);

    record[4] = '\0';
    dd = atoi(record + 2);
    record[2] = '\0';
    mm = atoi(record);

    if(mm<1 || mm > 12){
        fprintf(stderr,"Wrong month!\n");
	exit(EXIT_FAILURE);
    }
     printf("dd is %d,mm is %d \r\n",dd,mm);
     return(days_elapsed[mm-1] + dd);
}
