#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#define N 60000

using namespace std;

stack <int> st; // here we drop parenthesis
char expression[N];

int is_correct_expresion (int where_to_start)
{
	int cur_pos;
	int stars_counter;
	for (cur_pos = where_to_start; cur_pos >= 0; cur_pos--)
	{
		stars_counter = 0;
		if (expression[cur_pos] == '*') {
			while (cur_pos >= 0  && expression[cur_pos] == '*') { 
				cur_pos--;
				stars_counter++;
			}
			// delete those items from expression:
			cur_pos = cur_pos - stars_counter + 1;
		}
		else {
			if (expression[cur_pos] == ')' || expression[cur_pos] == ']') 
				st.push(expression[cur_pos]);
			else if (expression[cur_pos] == '(') 
				if (!st.empty() && st.top() == ')')
					st.pop();
				else return 0;
			else if (expression[cur_pos] == '[')
				if (!st.empty() && st.top() == ']')
					st.pop();
				else return 0;
		}
	}
	if (!st.empty())
		return 0;
	return 1;
}

int main ()
{
	freopen ("editor.in", "r", stdin);
	freopen ("editor.out", "w", stdout);	
	int nr_expressions;
	scanf("%d", &nr_expressions);
	char c;
	scanf("%c", &c); // read the newline left behind
	for (;nr_expressions > 0; nr_expressions--)
	{
		fgets(expression, N, stdin);
		int len = strlen (expression);
		int i;
		for (i = 0; i < len; i++) 
		{
			if (expression[i] == 'E') 
				if (is_correct_expresion(i - 1))
					printf(":)\n");
				else printf(":(\n");
		}
		while (!st.empty()) st.pop();
	}	
	return 0;
}
