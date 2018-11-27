#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void write(FILE *F,int number){
    char words[257];
    printf("Put %d strings to fill the first file:\n",number);    
    for(int i = 0; i < number;i++){
        fgets(words,255,stdin);
        if (words[strlen(words)-1]!='\n') {
            words[strlen(words)]='\n';
            words[strlen(words)+1]='\0';
        }
        fputs(words,F);
    }
    rewind(F);
}
void print(FILE *F){
    char words[257];
    int count = 1;
    fgets(words,256,F);
    do{
        printf("%d. %s",count++,words);
        fgets(words,256,F);        
    }while(!feof(F));
    rewind(F);
}
void copy(FILE *f1,FILE *f2){
    char words[257];   
    fgets(words,256,f1);
    do{
        if(words[0] == 'A'){
            fputs(words,f2);
        }
        fgets(words,256,f1);        
    }while(!feof(f1));
    rewind(f2);
    rewind(f1);
}
int count(FILE *F){
    char words[257]; 
    int count = 0;
    fgets(words,256,F);
    do{
        count ++;
        fgets(words,256,F);
    }while(!feof(F));
    rewind(F);
    return count;
}
int main(){
    FILE *f1,*f2;
    if ((f1=fopen("F1.txt", "w+b"))==NULL || (f2=fopen("F2.txt", "w+b"))==NULL){
        printf("Error reading file!");
        exit(2);
    }
    write(f1,5);
    printf("The first file:\n");
    print(f1);
    copy(f1,f2);
    printf("The second file:\n");
    print(f2);
    printf("Count words in the second file: %d\n",count(f2));
    fclose(f1);
    fclose(f2);
    return 0;
}

