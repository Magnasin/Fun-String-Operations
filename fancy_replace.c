#include "fancy_replace.h"

/*
* Creating a pattern at random
*/
// 
void wildCard(char *str, char *a, int *occur, int *size) {

size_t n = strlen(str), m = strlen(a);

for (int i = 0; i < n; ++i) { // finds a string that matches 

int found = 1;

for (int j = 0; j < m; ++j) {

if (a[j] == '?') // ? random operator 
continue;

else if ((i + j >= n) || (a[j] != str[i + j])) {
found = 0;
break;

}
}
        
if (found)// return the count size
occur[(*size)++] = i;

}
}

void replace(char *str, const char *b, int start) {

for (int i = 0; b[i]; ++i) // strings are swapped
str[start + i] = b[i];

}

    /*
     * accept null terminated string
     * function to locate ocurence of string a in str
     * replace found instances with string b
     * return new string
     * a: word to search in str
     * b: replace if match found
     */
char *fancy_replace(char *str, char *a, char *b){

int ocurences[256];
int size = 0;
char* result; // result after replacement
int i, counter = 0;
size_t b_len = strlen(b); // size of string a
size_t a_len = strlen(a); // size of pattern
size_t str_len = strlen(str); // size of search string

for (i = 0; str[i] != '\0'; i++) { // null terminate
        
if (strstr(&str[i], a) == &str[i]) {
counter++;
i += b_len - 1;
}
}

result = (char*)malloc(i + counter * (a_len - b_len) + 1); // dynamic memory allocation
wildCard(str, a, ocurences, &size); // pattern matrching
int k = 0, data = 0; // size of result string
    
for (i = 0; i < str_len; ) {

if (k < size && ocurences[k] == i) {

replace(result, b, data);

i += a_len; // strcpy(&result[i], b);
data += b_len;
k++;
}

else {
       
result[data++] = str[i++]; // copies the data to result variable

}
}

return  result;// returns result

}
