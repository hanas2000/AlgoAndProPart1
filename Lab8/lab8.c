#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct employee {
  char name[40];
  char surname[40];
  char father[40]; 
  char post [40];
  int year ;
  int salary;
};
void delete(FILE *f,char *surname)
{
    FILE *F1;
    F1=fopen("g.txt","w+b");
    if (F1==NULL) {
        printf("Error while reading!\n");
        exit(2);
    }
    struct employee arr;
    while(1)
    {
        fread(&arr, sizeof(struct employee), 1, f);
        if (feof(f)) 
           break;
        if (!strcmp(surname,arr.surname)) {
        }
        else
        {
            fwrite(&arr, sizeof(struct employee), 1, F1);
        }
        
    }
    fclose(f);
    f = fopen("f.txt", "w+b");
    rewind(F1);
  while (1) {
    fread(&arr, sizeof(struct employee), 1, F1);
    if (feof(F1)) break;
    fwrite(&arr, sizeof(struct employee), 1, f);
    }
    fclose(F1);
    rewind(f);
  }
  
  
 
 void form(FILE *f) {
  struct employee arr;
  for (int i=0; i<2; i++) {
    printf("name=");
    scanf("%s", arr.name);
    printf("surname=");
    scanf("%s", arr.surname);
    printf("father=");
    scanf("%s", arr.father);
    printf("Position=");
    scanf("%s", arr.post);
    printf("Year=");
    scanf("%d",&arr.year);
    printf("Salary=");
    scanf("%d",&arr.salary);
    fwrite(&arr, sizeof(struct employee), 1, f);
    if (ferror(f)) {
      printf("Error while writing!\n");
      exit(1);
    }
  }
  rewind(f);
};

void show(FILE *f) {
  
  struct employee arr;
  while (1) {
    fread(&arr, sizeof(struct employee), 1, f);
    if (feof(f)) break;
    printf("Name %s Surname %s Father %s\n",arr.name,arr.surname,arr.father);
    printf("Position %s Year %d Salary %d\n",arr.post,arr.year,arr.salary);
  };
  rewind(f);
}
void add(FILE *f,int number)
{
    struct employee arr;
    int i=1,y=0;
    FILE *F1;
    F1=fopen("g.txt","w+b");
    while(1)
    {
        if(i==number)
        {
            printf("name: ");scanf("%s",arr.name);
            printf("surname: ");scanf("%s",arr.surname);
            printf("father: ");scanf("%s",arr.father);
            printf("post: ");scanf("%s",arr.post);
            printf("year: ");scanf("%d",&arr.year);
            printf("salary: ");scanf("%d",&arr.salary);
            fwrite(&arr,sizeof(struct employee),1,F1);
            if (feof(f)) break;
            y=1;
        }
        fread(&arr, sizeof(struct employee), 1, f);
        if (feof(f)&&y==1) {
        break;
        }else if(feof(f)&&y==0)
        {
        }else
        {
        fwrite(&arr, sizeof(struct employee), 1, F1);
        }
        i++;
    }
    rewind(F1);
    fclose(f);
    f = fopen("f.txt", "w+b");
    while (1) {
        fread(&arr, sizeof(struct employee), 1, F1);
        if (feof(F1)) break;
        fwrite(&arr, sizeof(struct employee), 1, f);
    }
    fclose(F1);
    rewind(f);
}

int main()
{
  FILE *f;  
  f=fopen("f.txt", "w+b");
  if (f==NULL) {
    printf("Error while reading!\n");
    exit(2);
  }
  form(f);
  
  show(f);
  printf("Delete: ");
  char surname[255];
  scanf("%s",surname);
  delete(f,surname);
  show(f);
  int number;
  printf("Put number to add employee: ");
  scanf("%d",&number);
  add(f,number);
  show(f);
  fclose(f);
return 0;
}

