#include <stdio.h>
#include <ctype.h>

struct State
{
	int c;  /* a-Z, . , * */
	struct State *next;
};

void toNFA(char *pattern, struct State *state) {	
	
	if (pattern == '\0')
		return;

	struct State *next = malloc(sizeof(struct State));

	if (isalpha(pattern) || pattern == '.') {
		state->c = pattern;
		state->next = next;
	}

	if (pattern == '*')
	{
		state->c = '.';
		state->next = next;
	}

}




int main(void) {
	system("pause");

	return 0;
}