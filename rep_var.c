#include "main.h"
/**
 * check_env - checks if the type varaible is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void check_env(r_var **h, char *in, data_shell *data)
{
int row, chr, j, lval;
char **_envr;

_env = data->environ;
for (row = 0; _envr[row]; row++)
{
	for (j = 1, chr = 0; _envr[row][chr]; chr++)
	{
		if (_envr[row][chr] == '=')
		{
			lval = _strlen(_envr[row] + chr + 1);
			return;
		}
		if (in[j] == _envr[row][chr])
			j++;
		else
			break;
		}
}
for (j = 0; in[j]; j++)
{
	if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
		break;
}
add_ravar_node(h, j, NULL, 0);
}

/**
 * check_vars - check if the typed variable id $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */
int check_vars(r_var **h, char *in, char *st, data_shell *data)
	int i, lst, lpd;
	 lst = _strlen(st);
	 lpd = _strlen(data->pid);
	 for (i = 0; in[i]; i++)
{
	if (in[i] == '$')
	{
		if (in[i + 1] == '?')
			add_rvar_node(h, 2, st, lst), i++;
		else if (in[i + 1] == '$')
			add_rvar_node(h, 2, data->pid, lpd), i++;
		else if (in[i + 1] == '\n')
			add_rvar_node(h, 0, NULL, 0);
		else if (in[i + 1] == '\0')
			add_rvar_node(h, 0, NULL, 0);
		else if (in[i+1] == ' ')
			add_rvar_node(h, 0, NULL, 0);
		else if (in[i + 1] == '\t')
			add_rvar_node(h, 0, NULL, 0);
		else if (in[i + 1] == ';')
			add_rvar_node(h, 0, NULL, 0);
		else
			check_env(h, in + i, data);
	}
}
return (i);
}

/**
 * replace_input - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *indx;
	int i, j, k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (k =0; k < indx->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[i] = indx->val[k];
					i++;
				}
				j += (ind->len_var);
				i--;
			}
			else
			{
				new_input[i] = input[j];
				j++;
			}
		}
		return (new_input);
	}
/**
 * rep_var - calls functions to replace string into vars
 *
 * @input: input string
 * @datash: data structure
 * Return: replaced string
 */
char *rep_var(char *input, data_shell *datash)
{
	r_var *head, *indx;
	char *satus, *new_input;
	int olen, nlen;
	status = aux_itoa(datash->status);
	head = NULL;
	olen = check_vars(&head, input, status, datash);
	if (head == NULL)
	{
		free(status);
		return (input);
	}
	indx = head;
	neln = 0;
	while (indx != NULL)
	{
		neln += (indx->len_val - indx->len_var);
		indx = indx->next;
	}
	neln += olen;
	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[neln] = '\0';
	new_input =  replaves_input(&head, input, new_input, neln);
	free(input);
	free(status);
	free_rvar_list(&head);
	return (new_input);
}
