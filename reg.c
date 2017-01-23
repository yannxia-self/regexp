#include <stdio.h>

//@see https://swtch.com/~rsc/regexp/fig13.png

int match(char *regexp, char *text)
{
    if (regexp[0] == '^')
        return matchhere(regexp + 1, text);
    do
    { /* must look even if string is empty */
        if (matchhere(regexp, text))
            return 1;
    } while (*text++ != '\0');
    return 0;
}

int matchhere(char *regexp, char *text)
{
    if (regexp[0] == '\0' && text[1] == '\0')
        return 1;
    if (regexp[1] == '*')
        return matchstar(regexp[0], regexp + 2, text);
    if (regexp[0] == '$' && regexp[1] == '\0')
        return *text == '\0';
    if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
        return matchhere(regexp + 1, text + 1);
    return 0;
}

int matchstar(int c, char *regexp, char *text)
{
    do
    { /* a * matches zero or more instances */
        if (matchhere(regexp, text))
            return 1;
    } while (*text != '\0' && (*text++ == c || c == '.'));
    return 0;
}


int main(int argc, char *argv[])
{
    //printf("isMatch('aa','aa') �� true, %d \n", match("aa", "aa"));
    //printf("isMatch('ab', '.*') �� true, %d \n", match(".*", "aa"));
   // printf("isMatch('aa', 'a*') �� true, %d \n", match("a*", "aa"));
	printf("isMatch('aa', 'a') �� false, %d \n", match("aa", "a"));
    //printf("isMatch('aa', 'a') �� false, %d \n", match("a", "aa"));
	printf('\n');
}
