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

  Gematria (word, text);
  Atbash (text,word);
  Anagram (text,word,strlen(text));
  return 0;
}
