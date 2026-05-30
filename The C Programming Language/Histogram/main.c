#include <stdio.h>
#define MAX_CHARACTER 26
#define STAR '*'
#define SPACE ' '


int main(){
     int current, highest = 0;
     int wordsize = 0;
     int letterCounts[MAX_CHARACTER];
     for(int i = 0; i < MAX_CHARACTER; i++){
          letterCounts[i] = 0;
     }
     do {
          current = getchar();
          if(!(current == ' ' || current == '\t' || current == '\n' || current == EOF)) {
               int index = current - 'a';
               if(index >= 0 && index <= MAX_CHARACTER) {
                    letterCounts[index]++;
               }
          }
     } while(current != '\n' && current != EOF);

     for(int i = 0; i < MAX_CHARACTER; i++){
          printf("%4c", 'a' + i);
          if(highest < letterCounts[i])
               highest = letterCounts[i];
     }
     printf("\n");
     for(int i = highest; i > 0; i--){
          for(int j = 0; j < MAX_CHARACTER; j++) {
               if(letterCounts[j] == i) {
                    printf("%4c", STAR);
                    letterCounts[j]--;
               }
               else
                    printf("%4c", SPACE);
          }
          printf("\n");
     }
     return 0;
}