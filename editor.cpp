//Eu sunt Andrei
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#define N 60000

using namespace std;

stack<int> exp_p, exp_r; // r - paranteza rotunda , p - paranteza patrata
int v[N], contor;
char buffer[N];

int is_correct_expresion (int position)
{
	int i;
	for (i = position - 1; i >= 0; i--)
	{
		contor = 0;
		if ( buffer[i+1] != '*') {
			if ( buffer[i] == ')') {
				exp_r.push(i);
			} else if ( buffer[i] == ']' ) {
				exp_p.push(i);
			} else if ( buffer[i] == '[' ) {
				if (exp_p.empty() || buffer[i+1] == ')'){
				//	printf(":(\n");
					return 0;
				}
				exp_p.pop();
			} else if ( buffer[i] == '(' ) {
				if (exp_r.empty() || buffer[i+1] == ']') {
				//	printf(":(\n");
					return 0;
				}
				exp_r.pop();
			}
		} else {
			while( i > 0  && buffer[i] == '*') { 
				i--;
				contor++;
			}
			i -= contor;
		}
	}
	if ( exp_p.empty() && exp_r.empty())
		return 1;

	return 0;
}
int main ()
{
	freopen ("editor.in", "r", stdin);
	freopen ("editor.out", "w", stdout);
	char c;
	int i, l;
	int nr_Expressions;
	int check;

	scanf("%d", &nr_Expressions);
	scanf("%c", &c);
	for (;nr_Expressions > 0; nr_Expressions --)
	{
		fgets (buffer, N, stdin);
		l = strlen (buffer);
		if(buffer[l-1]=='\n')
			buffer[l-1]='\0';
		l--;
		check = 0; // no incorrect expression
		for (i = 0; i < l; i++) 
		{
			if ( buffer[i] == 'E' ) {
				if (!is_correct_expresion(i)) {
					check = 1;
					break;					
				} 
			}
		}
		if (check) {
			printf(":(\n");
		} else {
			printf(":)\n");
		}
		while ( !exp_r.empty())
			exp_r.pop();
		while ( !exp_p.empty())
			exp_p.pop();
  }	
	return 0;
}

