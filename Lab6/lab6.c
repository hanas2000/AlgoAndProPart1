#include <stdio.h>
#include <string.h>
int main() {
  char str[255], prob[2]=" ";
  char *word,*max_word,*min_word;
  printf("Put string: ");
  fgets(str,256,stdin);
  int lengthtext;
  if (str[strlen(str)-1]=='\n')
  {
  	str[strlen(str)-1]='\0';
  }
  lengthtext = strlen(str);
  word = strtok(str,prob);
  int max=strlen(word),min=strlen(word);
  max_word=word;
  min_word=word;
  while (word != NULL) {
 	 if(strlen(word)>max)
 	 {
  		max=strlen(word);
        		max_word=word;
    	  }                           
    	  if(strlen(word)<min)
    	 {
        	 	 min=strlen(word);
                 	 min_word=word; 
                 }
   	 word = strtok(NULL,prob);
  };  
  printf("Max word: %s\n",max_word);
  printf("Min word: %s\n",min_word);
  return 0;
}

