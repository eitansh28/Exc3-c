#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "StringFunc.h"


int cgem(char c){
  int val=0;
  if(c<123 && c>96){
    val=c-96;
  }
  if(c<91 && c>64){
    val=c-64;
  }
  return val;
}
int wgem(char* s){
  int wg=0;
  for(int i=0;i<strlen(s);i++){
    wg+=cgem(s[i]);
  }
  return wg;
}


void printStr(char* p1,char* p2){
  for(int i=0;i<p2-p1;i++){
    printf("%c",p1[i]);
  }
}

void Gematria(char* word, char* text){
  printf("Gematria Sequences: ");
  char* p1=text;
  char* p2=text;
  int b=0;
  int sum=0;
  int first=0;
  while(b<=strlen(text)){
    if(sum>wgem(word)){
      sum-=cgem(p1[0]);
      p1++;
      while(cgem(p1[0])==0)
        p1++;
    }
    if(sum==wgem(word)){
      while(cgem(p1[0])==0)
        p1++;
      sum-=cgem(p1[0]);
      if(first==0){
        printStr(p1,p2);
        first++;
      }else{
        printf("~");
        printStr(p1,p2);
      }

      p1++;
    }
    if(sum<wgem(word)){
      sum+=cgem(p2[0]);
      p2++;
      b++;
    }
  }
}

char catbs(char c){
  if(c<123 && c>96){
    c+=27-(2*cgem(c));
  }
  if(c<91 && c>64){
    c+=27-(2*cgem(c));
  }
  return c;
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
int ismin(char* word){
    if ((int)word[0]<65||(int)word[0]>122)
        {
            return 0;
        }
        if ((int)word[0]<96&&(int)word[0]>90)
        {
            return 0;
        }
        if ((int)word[strlen(word)-1]<65||(int)word[strlen(word)-1]>122)
        {
            return 0;
        }
        if ((int)word[strlen(word)-1]<96&&(int)word[strlen(word)-1]>90)
        {
            return 0;
        }
        return 1;
}

int wordvalue (char* word){
    int i;
    int answer =0;
    for (i = 0; i < strlen(word); i++) {
        //the 4 following if will chekc if the first or last latter is not a alphabetic latter if its not
        //an alphabetic latter we return -1
        if ((int)word[0]<65||(int)word[0]>122)
        {
            return -1;
        }
        if ((int)word[0]<96&&(int)word[0]>90)
        {
            return -1;
        }
        if ((int)word[strlen(word)-1]<65||(int)word[strlen(word)-1]>122)
        {
            return -1;
        }
        if ((int)word[strlen(word)-1]<96&&(int)word[strlen(word)-1]>90)
        {
            return -1;
        }

        //if it is an alphabetic latter we gonna return its value with the next 2 if
        if(isupper(word[i])){
            answer+=(int)word[i]-64;
        }
        if(islower(word[i])){
            answer+=(int)word[i]-96;
        }
        }
        return answer;
}

int ismatch(char* word,char* strsub){
    //if word is larger then strsub we already faile
    if(strlen(word)>strlen(strsub)){
        return 0;
    }
    int j=0;
    //we run on both strsub and word ignoreing all ' ' in strsub while checking every word in strsub as atbsh
    //if they not equal re fail
        for(int i =0; i<strlen(strsub); i++){
            if(strsub[i]==' '){
                continue;
            }
            if(word[j]!=catbs(strsub[i])){
                return 0;
            }
            j++;

        }
        //we run over the entire word and strsub they match we retrun true
    return 1;
    }




void Atbash(char* text,char* word){
    printf("\nAtbash Sequences: ");
    //building up our text1 that gonna help us run on every substring
    char* text1 =malloc(256);
    int first =1;
    //we use 2 fors to run on every possible substring of text by runnning over all text1 with each run
    //we reduce the last latter after we finish running over text1 we gonna reduce the first latter
    //in text1 and run all over it until we got every substring
    for(int j=0; j<strlen(text); j++){
        text1=strncpy(text1,text+j,strlen(text));
        for(int i=0; i<=strlen(text1); i++){
            char* substr = malloc(256);
            strncpy(substr,text1,i);
            //gonna check if its minimal rechef
            if (ismin(substr))
            {
                //if is match in asbash we will print it
            if (ismatch(word,substr)){
                if (first)
                {
                    printf("%s",substr);
                    first=0;
                }
                else{
                    printf("%c",'~');
                    printf("%s",substr);
                }
            }
            //we gonna reverse the substr and try to check if its match again
            strrev(substr);
            if (ismatch(word,substr)){
                strrev(substr);
                if (first)
                {
                    printf("%s",substr);
                    first=0;
                }
                else{
                    printf("%c",'~');
                    printf("%s",substr);
                }
            }
            }
            }
    }
  }

int cmp(const void *a, const void *b) { return *(char *)a - *(char *)b; }

void Anagram(char *text, char *word, int size){
    printf("\nAnagram Sequences: ");
    int a = 0, b = 0;
    int countChars=0;
    int first=0;
    qsort(word, strlen(word), 1, (cmp));
    if (b == 0 && *(text + b) != ' ' && *(text + b) != '\n' && *(text + b) != '\t') {
        countChars++;
    }
    while (b < size) {
        if (*(text + a) == ' ' || *(text + a) == '\n' || *(text + a) == '\t') {
            a++;
            continue;
        }
        if (countChars < strlen(word)) {
            b++;
            if (b < size && *(text + b) != ' ' && *(text + b) != '\n' && *(text + b) != '\t') {
                countChars++;
            }
            continue;
        }
        if (countChars > strlen(word)) {
            if (*(text + a) != ' ' && *(text + a) != '\n' && *(text + a) != '\t' ) {
                countChars--;
            }
            a++;
            continue;
        }
        if (countChars == strlen(word)) {
            int len = b - a + 1;
            char *dest = (char *) malloc(sizeof(char) * (len + 1));
            char* toFree = dest;
            if (dest != NULL){
                for (int i = a; i <= b && (*(text + i) != '\0'); i++) {
                    *dest = *(text + i);
                    dest++;
                }
                *dest = '\0';
                int spaces = len - countChars;
                char temp[len + 1];
                char substrNotSpace[len + 1 - spaces];
                strcpy(temp, dest - len);
                qsort(temp, strlen(temp), 1, cmp);
                strcpy(substrNotSpace, temp + spaces);

                if (strcmp(word, substrNotSpace) == 0) {
                    if (first == 1) {
                        printf("~%s", dest - len);
                    } else {
                        printf("%s", dest - len);
                        first = 1;
                    }
                }
                countChars--;
                a++;
            }
            free(toFree);
        }
    }
}
