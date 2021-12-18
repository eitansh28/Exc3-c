#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StringFunc.h"

int main(){
  char word[30];
  char text[1024];
  char c=0;
  int i=0;
  while(i<30){
    scanf("%c",&c);
    if(c=='\n' || c=='\t' || c==' '){
      word[i]='\0';
      break;
    }word[i]=c;
    i++;
  }

  i=0;
  while(i<1024){
    scanf("%c",&c);
    if(c=='~'){
      text[i]='\0';
      break;
    }text[i]=c;
    i++;
  }
  //scanf("%s",word);
  //scanf("%s",text);

  Gematria (word, text);
  //Atbash (word, text);
  //Anagram (word, text,strlen(text));
  func2(text,word);
  anagram1 (text,word,strlen(text));
  // printf("%s\n",word);
  // printf("%s\n",text);
  // printf("%ld\n",strlen(word));
  // printf("%ld\n",strlen(text));
  // printf("%c\n",text[0]);
  //printf("%d\n",cgem('z'));
  //printf("%d\n",wgem(word));
  //printf("%c",word[7]);
  //printf("%c\n",catbs('d'));
  //printf("\n");
  return 0;
}
