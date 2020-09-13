#include "revert_string.h"
#include <string.h>

void RevertString(char *str)
{
    /* char temp[128];
    strcpy(temp,str);
    int i=0, j=strlen(temp)-1;
    while(i<=i+j)
    str[i++]=temp[j--];*/
    /* #include<algorithm>
    std::reverse(str.begin(), str.end());*/
    int length = strlen(str);
    int last_pos = length-1;
    int half = length/2;
    for(int i = 0; i < half; i++)
    {
        char tmp = str[i];
        str[i] = str[last_pos - i];
        str[last_pos - i] = tmp;
    }
}

