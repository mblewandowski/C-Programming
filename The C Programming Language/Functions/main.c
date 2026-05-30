#include <stdio.h>
#define TABSTOP 6 // you can chance this value to set the distance of tab stops could be a setting or something
#define MAXLINE 1000 // just an arbitrary value for the maximum line length, you can change it as needed

void leftShift(char string[], int index, int distance);
void rightShift(char string[], int index, int distance);
void detab(char string[]);
void fold(char string[], int maxLength);
void decomment(char string[]);

int main() {
    char string[MAXLINE];
    int c, index = 0;
    while ((c = getchar()) !='`') {
        string[index++] = c;
    }
    string[index] = '\0';
    printf("Original string: %s\n", string);
    decomment(string); // Example: decomment
    printf("%s\n", string);
    return 0;
}

void fold(char string[], int maxLength) {
    int index, lastSpaceIndex, currentLineLength;
    index = lastSpaceIndex = currentLineLength = 0;
    while(string[index] != '\0') {
        currentLineLength++;
        if(currentLineLength == maxLength){
            if (lastSpaceIndex != 0) {
                int spaceCount = lastSpaceIndex;
                for(; string[spaceCount] == ' '; spaceCount++);

                int spaceCountDistance = lastSpaceIndex - spaceCount;
                if (spaceCountDistance > 0) {
                    leftShift(string, spaceCount + 1, spaceCountDistance);
                }
                string[lastSpaceIndex] = '\n';
            } else {
                rightShift(string, index, 2);
                string[index] = '-';
                string[index + 1] = '\n';
            }
            currentLineLength = 0;
            lastSpaceIndex = 0;
        }
        if(string[index] == ' ') { 
            lastSpaceIndex = index;
        }
        if(string[index] == '\n') {
            currentLineLength = 0;
        }
        index++;
    }
}

void decomment(char string[]) {
     int currentCharacter, previousCharacter, index;
     int startIndex = -1; // Use -1 to indicate we are not in a comment
     currentCharacter = previousCharacter = index = 0;
     
     while(string[index] != '\0') {
        currentCharacter = string[index];
        if(currentCharacter == '/' && previousCharacter == '/') {
            startIndex = index - 1;
        }
        if(currentCharacter == '\n' && startIndex != -1) {
            leftShift(string, startIndex, index - startIndex);
            index = startIndex;
            startIndex = -1;
        } 
        previousCharacter = currentCharacter;
        index++;
     }
     if(string[index] == '\0' && startIndex != -1) {
        leftShift(string, startIndex, index - startIndex);
        string[index] = '\0';
     }
}

void detab(char string[]){
    int count, tabStopDistance;
    count = tabStopDistance = 0;
    while(string[count] != '\0') {
        if (count == MAXLINE) break;
        if(string[count] == '\t') {
            tabStopDistance = TABSTOP - (count % TABSTOP);
            rightShift(string, count + 1, tabStopDistance - 1);
            
            int finalIndex = count + tabStopDistance;
            for(count; count < finalIndex; count++){
                string[count] = ' ';
            }
        } else {
            count++;
        }
        
    }
}

void rightShift(char string[], int index, int distance) {
    for(int i = MAXLINE - 1; i > index; i--){
        if (i - distance >= 0) {
            string[i] = string[i-distance];
        } else {
            string[i] = '0';
        }
    }
}

void leftShift(char string[], int index, int distance) {
    for(int i = index; string[index] != '\0' && i < MAXLINE; i++){
        if (i + distance < MAXLINE) {
            string[i] = string[i + distance];
        } else {
            string[i] = '\0';
        }
    }
}