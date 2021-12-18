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


int equal(char* s, char* t, int len){
  int k=0;
  for(int i=0;i<len;i++){
    if(s[i]==' '){
      k++;
    }else if(s[i+k]!=t[i]){
      return 0;
    }else{
      continue;
    }
  }return 1;
}

int countS(char* s, char* t){
  int k=0;
  int c=0;
  int i=0;
  while(i<strlen(t) && c<strlen(s)){
    if(t[i]==' '){
      k++;
    }else{
      c++;
    }i++;
  }return k;
}
// int eq(char* p1,char* p2){
//   int k=0;
//   for(int i=0;i<strlen(p1);i++){
//     if(p1[k]==' ')
//       k++;
//     if(p2[i]!=p1[k]){
//       return 0;
//     }
//      k++;
//   }return 1;
// }

void Atbash(char* word, char* text){
  printf("\nAtbash Sequences: ");
  char at[strlen(word)];
  int first=0;
  int cSP=0;
  for(int i=0;i<strlen(word);i++){
    at[i]=catbs(word[i]);
  }
  char op[strlen(word)];
  for(int i=0;i<strlen(word);i++){
    op[i]=catbs(word[strlen(word)-1-i]);
  }
  for(int i=0;i<strlen(text)-strlen(word);i++){
    if(equal(text+i,at,strlen(word)) || equal(text+i,op,strlen(word))){
      cSP=countS(at,text+i);
      if(first==0){
        printStr(text+i,text+i+strlen(word)+cSP);
        first++;
      }else{
        printf("~");
        printStr(text+i,text+i+strlen(word)+cSP);
      }

    }
  }
}

 //void Atbash2(char* word, char* text){
   // for(int j=0; j<strlen(text); j++){
   //      text1=strncpy(text1,text+j,strlen(text));
   //      for(int i=0; i<=strlen(text1); i++){
   //          //setting up substr to be our temp substring for the current run
   //          char* substr = malloc(256);
   //          strncpy(substr,text1,i);
//   printf("\nAtbash Sequences: ");
//   char at[strlen(word)];
//   int first=0;
//   for(int i=0;i<strlen(word);i++){
//     at[i]=catbs(word[i]);
//   }
//   char op[strlen(word)];
//   for(int i=0;i<strlen(word);i++){
//     op[i]=catbs(word[strlen(word)-1-i]);
//   }
//   int k=0;
//   int dis=0;
//   for(int i=0;i<strlen(text)-strlen(word);i++){
//     while(text[k]==' '){
//       k++;
//       dis++;
//     }
//     if(at[i]!=text[k]){
//       break;
//       // k++;
//       // continue;
//     }else{
//     if(equal(text+i,at,strlen(word)) || equal(text+i,op,strlen(word))){
//       if(first==0){
//         printStr(text+i,text+i+strlen(word));
//         first++;
//       }else{
//         printf("~");
//         printStr(text+i,text+i+strlen(word));
//       }
//
//     }
//   }
// }
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}
int comp (int* a,int* b){
  for(int i=0;i<127;i++){
    if(a[i]!=b[i])
    return 0;
  }return 1;
}

void Anagram (char* word, char* text){
  printf("\nAnagram Sequences: ");

  int count[127]={};
  int c2[127]={};
  int temp=0;
  int temp2=0;
  for(int i=0;i<strlen(word);i++){
    temp=(int)word[i];
    count[temp]++;
    //printf("%d",temp);
  }
  // printf("%d\n",count[98]);
  // printf("%d\n",count[88]);
  char text1[strlen(text)];
  strcpy(text1,text);
  //printf("%s",&text1[1]);
  //printf
  for(int j=0; j<strlen(text); j++){
       strncpy(text1,text+j,strlen(text));
       printf("%s\n",&text1[0]);
       for(int i=0; i<=strlen(text1); i++){
           //setting up substr to be our temp substring for the current run
           char substr[strlen(text)];
           strncpy(substr,text1,i);
           printf("%s\n",&substr[0]);
           for(int i=0;i<strlen(text);i++){
            if(substr[i]!=' '){
              temp2=(int)substr[i];
              printf("%d\n",temp2);
              c2[temp2]++;
              //printf("f");
             }
            //if(comp(count,c2))
            //   printf("%s",substr);
          }
        }
      }
    }
    //}
  // printf("\nAnagram Sequences: ");
  // qsort(word,sizeof(word)/sizeof(word[0]),sizeof(word[0]),cmpfunc);
  // printf("%s",word);
  // int countC=0;
  // int countS=0;
  // //char* p1=text;
  // char* p2=text;
  // //char sortedw[strlen(word)]={1,2,3};
  // qsort(word,strlen(word),sizeof(char),cmpfunc);
  // for(int i=0;i<strlen(text)-strlen(word);i++){
  //   if(text[i]==' '){
  //     countS++;
  //     p2++;
  //   }else{
  //     countC++;
  //     p2++;
  //   }if(countC==strlen(word)){
  //     qsort(text+i,strlen(word)+countS,sizeof(char),cmpfunc);
  //     printf("%s",word);
  //   }
  // }
int cmp(const void *a, const void *b) { return *(char *)a - *(char *)b; }

int anagram1(char *text, char *word, int size){
    printf("\nAnagram Sequences: ");
    int a = 0, b = 0,count=0,flag=0;
    int length = strlen(word);
    for (int i =0;i<length;i++){
        if (*(word + i)!=32)
            count++;
    }
    int spaces = length - count;
    char temp[length+1];
    char wordNotSpace[length+1-spaces];
    strcpy (temp, word);
    qsort(temp, strlen(temp), 1, (cmp));
    strcpy (wordNotSpace,temp+spaces);
    int count2 = 0;
    if (b==0 && *(text + b)!=32) {
        count2++;
    }
    while(b<size){
        if (*(text + a)==32){
                a++;
            continue;
        }
        if(count2 < count){
            b++;
            if (b<size && *(text + b)!=32){
                count2++;
            }
            continue;
            }
        if(count2 > count){
            if (*(word + a)!=32){
                count2--;
            }
            a++;
            continue;
        }
        if (count == count2){
            int len = b - a + 1;
            char *dest = (char*)malloc(sizeof(char) * (len+1));
            for (int i = a; i <= b && (*(text + i) != '\0'); i++){
                *dest = *(text + i);
                dest++;
            }
            *dest = '\0';
            int spaces2 = len-count2;
            char temp2[len+1];
            char wordNotSpace2[len+1-spaces2];
            strcpy (temp2, dest-len);
            qsort(temp2, strlen(temp2), 1, (cmp));
            strcpy (wordNotSpace2,temp2+spaces2);

            if (strcmp(wordNotSpace, wordNotSpace2) == 0){
                if (flag == 1){
                    printf("~%s",dest-len);
                }
                else{
                    printf("%s",dest-len);
                    flag = 1;
                }
            }
            count2--;
            a++;
        }
    }return 0;
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
// int cgem(char c){
//     //your function
//     int val =0;
//     if((int)c<123&&(int)c>96){
//         val =c-96;
//     }
//     if((int)c<91&&(int)c>64){
//         val =c-64;
//     }
//     return val;
// }
// char catbs(char c){
//     //your function
//     if((int)c<123&&(int)c>96){
//         c+=27-(2*cgem(c));
//     }
//     if((int)c<91&&c>64){
//         c+=27-(2*cgem(c));
//     }
//
//     return c;
// }
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
   /*
int ismatch1(char* word,char* strsub){
    int k =0;
    if(strlen(word)>strlen(strsub)){
        return 0;
    }
        for(int i =0; i<strlen(strsub); i++){
            if(strsub[i]==' '){
                continue;
            }
            if(word[k]!=catbs(strsub[i])){
                return 0;
            }
            k++;
        }
        return 1;
    }
    */

int func1(char* text,char* word){
    //we set up num to be our string value goal text1 gonna contain copy of text for us to change to go over
    //every possible string
    int num =wordvalue(word);
    char* text1 =malloc(256);
    int first =1;
    //we use 2 fors to run on every possible substring of text
    for(int j=0; j<strlen(text); j++){
        text1=strncpy(text1,text+j,strlen(text));
        for(int i=0; i<=strlen(text1); i++){
            //setting up substr to be our temp substring for the current run
            char* substr = malloc(256);
            strncpy(substr,text1,i);
            //if wordvalue of substring equal to num we found a string that answer all the requirment and we can print him
            if(num==wordvalue(substr)){
                if (first){
                    first=0;
                    printf("%s",substr);
                }
                else{
                    printf("%s","~");
                    printf("%s",substr);
                }
            }
    }
    }
    return 0;
}
int func2(char* text,char* word){
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
    }return 0;
  }
