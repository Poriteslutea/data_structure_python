#include <stdio.h>  
#include <string.h>
#include <iostream>


using namespace std;  //聲明一個命名的空間

//參考：https://www.cnblogs.com/c-cloud/p/3224788.html

// KMP中的get_next, 回傳子字串s的next陣列，這個next是指子字串每一位置的最大相同前後綴的長度
void get_next(const char P[], int next[])
{
      int m = strlen(P);   //要找的子字串的長度
      int q,k;  //q:子字串的下標，k:最大前後綴的長度  
      next[0] = 0;    //next陣列的第一個都是0，第一個字的最大前後綴長度給0
   
      for(k=0, q=1;q < m;++q){  //從子字串第二個字元開始，依次計算每一個字符可以對應的next值
         while(k>0 && P[k]!=P[q]) {
            k = next[k-1];         //前一步有找到相同的值，並且有前後綴長度相同的字串
         }
         if(P[k]==P[q]){   //如果兩者相等，最大相同前後綴長度加一
            k++;
         } 
         next[q] = k;
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
   char T[] = "aaaaaaaaaaaabbbaaaaaaaab";
   char P[] = "aaabbbaaa";
   printf("%s\n", T);
   printf("%s\n", P );
   kmp(T, P, next);
   printf("\n");

   return 0;
}