#include <stdio.h>

//@see https://swtch.com/~rsc/regexp/fig13.png

struct State
{
    int c;
    State *out;
    State *out1;
    int lastlist;
};

struct Frag
{
    State *start;
    Ptrlist *out;
};

Ptrlist *list1(State **outp);
Ptrlist *append(Ptrlist *l1, Ptrlist *l2);
void patch(Ptrlist *l, State *s);

State *
post2nfa(char *postfix)
{
    char *p;
    Frag stack[1000], *stackp, e1, e2, e;
    State *s;

#define push(s) *stackp++ = s
#define pop() *--stackp

    stackp = stack;
    for (p = postfix; *p; p++)
    {
        switch (*p)
        {
            /* compilation cases, described below */
        }
    }

    e = pop();
    patch(e.out, matchstate);
    return e.start;
}

int main(int argc, char *argv[])
{
}