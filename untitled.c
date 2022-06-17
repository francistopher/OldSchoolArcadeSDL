#include <stdio.h>

int getStrLen(char * stri, int len) {
	if (*stri++ != '\0') {
		return getStrLen(stri, len + 1);
	} else {
		return len;
	}
}

char * printC(char * stri, int span) {
	int striLen = 0;
	printf("%d", getStrLen(stri, 0));
	return stri;
}


int main(int argc, const char** argv) {
	printC("Hello World!", 20);

	return 0;
}
