#include <stdio.h>  
#include <string.h>
#include <iostream>


using namespace std;  //聲明一個命名的空間

//參考：https://www.cnblogs.com/c-cloud/p/3224788.html

// KMP中的get_next, 回傳子字串s的next陣列，這個next是指子字串與主字串比對到子字串中第q個數然後發現不匹配時，i要回溯到哪個位置繼續比對
void get_next(const char P[], int next[])
{
      int m = strlen(P);   //要找的子字串的長度
      int q,k;  //q:子字串遍歷的下標，k:在子字串中尋找跟開頭相同字元串的下標（會在q之前）  
      next[0] = 0;    //next陣列的第一個都是0，第一個字的最大前後綴長度給0
   
      for(k=0, q=1;q < m;q++){  //從子字串第二個字元開始，依序遍歷子字串，找子字串中有沒有相同前後綴字串
         while(k>0 && P[k]!=P[q]) {
            printf("%d\n", k); 
            k = next[k-1]; 
            printf("here is k:"); 
            printf("%d\n", k);       //子字串之後有找到與開頭相同的值，但後續匹配又不相同
            printf("here is q:"); 
            printf("%d\n", q);      
         }
         if(P[k]==P[q]){   //當q遍歷到與開頭字母（k的位置）一樣的字時，k就會移去下一個字母
            k++;
         } 
         next[q] = k;  //
      }
}


// KMP主程式，從一個主字串中，找到子字串並回傳子字串開始的位置
int  kmp(const char T[],const char P[], int next[]){
   int n,m;
   int i,q;
   n = strlen(T);
   m = strlen(P);
   for (i=0, q=0; i<n; i++)
   {
      while(q>0 && P[q] != T[i]){
         q = next[q-1];
      }
      if (T[i] == P[q]){
         q++;
      }
      if (q == m){
             printf("Pattern occurs with shift: %d\n", (i-m+1));
      }
   }
}

int main(){
   int i;
   int next[20] = {0};
   char T[] = "aaaaapabcdexaababaaababbaaaaaaaab";
   char P[] = "abcdex";
   printf("%s\n", T);
   printf("%s\n", P );
   get_next(P, next);
   for (i = 0; i < strlen(P); ++i)
    {
      printf("%d ",next[i]);
    }
   kmp(T, P, next);
   printf("\n");

   return 0;
}