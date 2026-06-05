#include <stdio.h>
#include <limits.h>

void exercise1();
void exercise2(int);
int exercise3(char[]);
void exercise4(char[], char[]);
int exercise5(char[], char[]);
int exercise6(int, int, int, int);
int exercise7(int, int, int);
int exercise8(int, int);
int validHexChar(char);
int getIntValue(char);
int contains(char[], char);
void print_binary(unsigned int num);

int main() {
    //exercise1();

    //exercise2(10);

    //exercise 3
    //char string[8] = "deaf";
    // int result = exercise3(string);
    // printf("Result of the string %s: %d", string, result == -1 ? 0 : result);
    
    //exercise 4
    // char string1[8] = "dome";
    // char string2[8] = "faded";
    // exercise4(string1, string2);
    // printf("string1 after being super squeezed: %s", string1);

    //exercise 5
    // char string3[] = "test";
    // char string4[] = "slow";
    // printf("index where the first character from string4 occurs: %d\n", exercise5(string3, string4));

    //exercise 6
    // int result = exercise6(0xBF, 2, 3, 0xA5);
    // print_binary(result);

    //exercise 7
    // int result = exercise7(0b01011011, 2, 3);
    // print_binary(result);

    //exercise 8
    // int value = 0xF46D;
    // print_binary(value);
    // value = exercise8(0xF46D, 33);
    // print_binary(value);
    return 0;
}

void exercise1() {
    printf("Signed char Limits: %d = %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char limit: %d - %d\n", 0, UCHAR_MAX);
    printf("Signed int limits: %d - %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int limits: %d - %u\n",0, UINT_MAX);
    printf("Signed short limits: %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short limits: %d - %d\n", 0, USHRT_MAX);
    printf("Hello, World!\n");
}

void exercise2(int lim) {
    for(int i = 0; i < lim -1; i++) {
        int c = getchar();
        if (c == '\n') break;
        if(c == EOF) break;
        putchar(c);
    }
}

int exercise3(char string[]) {
    int index, value, firstCharZero;
    index = value = firstCharZero = 0;
    while(string[index] != '\0') {
        if(string[index] == '0' && index == 0)
            firstCharZero = 1;
        else if((string[index] == 'x' || string[index] == 'X') && firstCharZero);
        else if(validHexChar(string[index])) {
            printf("valid hex char: %c\n", string[index]);
            value = value * 16 + getIntValue(string[index]);
        } else {
            return -1;
        }
        index++;
    }
    return value;
}

void exercise4(char string1[], char string2[]) {
    int i, j;
    for(i = j = 0; string1[i] != '\0'; i++) {
        if(!contains(string2, string1[i]))
            string1[j++] = string1[i];
    }
    string1[j] = '\0';
}

int exercise5(char string1[], char string2[]) {
    for(int i = 0; string1[i] != '\0'; i++)
        if(contains(string2, string1[i]))
            return i;
    return -1;
}

int exercise6(int x, int p, int n , int y) {
    int mask = ~(~0U << n);
    y = (y & mask) << p;
    mask = ~(mask << p);
    return (x & mask) | y;
}

int exercise7(int x, int p, int n) {
    return x ^ (~(~0U << n) << p);
}

int exercise8(int x, int n) {
    int total_bits = sizeof(x) * CHAR_BIT;
    return (x >> n) | (x << (total_bits - n));
}

int contains(char string[], char check) {
    for(int i = 0; string[i] != '\0'; i++)
        if(string[i] == check)
            return 1;
    return 0;
}

int validHexChar(char testChar) {
    if(
        (testChar >= 'a' && testChar <= 'f') ||
        (testChar >= 'A' && testChar <= 'F') ||
        (testChar >= '0' && testChar <= '9')
    )
        return 1;
    else return 0;
}

int getIntValue(char val) {
    if(val >= '0' && val <= '9')
        return val - '0';
    else if(val >= 'a' && val <= 'f')
        return val - 'a' + 10;
    else if(val >= 'A' && val <= 'F')
        return val - 'A' + 10;
    return 0;
}

void print_binary(unsigned int num) {
    int total_bits = sizeof(num) * CHAR_BIT;
    unsigned int mask = 1 << (total_bits - 1);
    
    for (int i = 0; i < total_bits; i++) {
        putchar((num & mask) ? '1' : '0');
        mask >>= 1;
        if ((i + 1) % 8 == 0 && i != total_bits - 1) {
            putchar(' ');
        }
    }
    putchar('\n');
}