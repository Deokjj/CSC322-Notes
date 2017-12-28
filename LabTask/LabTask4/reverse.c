//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 256
//-----------------------------------------------------------------------------
void reverse(char s[]);
void swap(char s[], int begin, int end);
//-----------------------------------------------------------------------------
void input(char *s) {
	printf("Input a string to be reversed:\n");
	scanf("%s", &*s);
}
//-----------------------------------------------------------------------------
int main(void) {

	char s[STRING_LENGTH];
	input(s);
	reverse(s);

	printf("%s\n",s);
	return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
void reverse (char s[]){
	int length =0;
	while(s[length] != '\0' )
		length++;

	swap(s,0,length-1);
}
//-----------------------------------------------------------------------------
void swap(char s[], int begin, int end){
	char temp = s[begin];
	if(begin>=end)
		return;

	s[begin] = s[end];
	s[end] = temp;
	swap(s,++begin,--end);
}
//-----------------------------------------------------------------------------
