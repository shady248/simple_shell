#include "main.h"

/**
<<<<<<< HEAD
 * is_cdir - checks ":" if is in the curret directory.
 * @path: type char pointer char.
 * @i: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise
=======
 * is_cdir - checks ":" if is in the current directory.
 * @path: type char ptr char.
 * @i: type int ptr of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
>>>>>>> 8405a42b0157d00f512b8e4f6395131ac8ec6970
 */
int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);
<<<<<<< HEAD
=======

>>>>>>> 8405a42b0157d00f512b8e4f6395131ac8ec6970
	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}
<<<<<<< HEAD
	if (path[*i])
		*i += 1;
=======

	if (path[*i])
		*i += 1;

>>>>>>> 8405a42b0157d00f512b8e4f6395131ac8ec6970
	return (0);
}

/**
<<<<<<< HEAD
* _which - locates a command 
*
* @cmd: command name
* @_environ: environment variable
* Return: location of the command.
*/
=======
 * _which - locates a command
 *
 * @cmd: command name
 * @_environ: environment variable
 * Return: location of the command.
 */
>>>>>>> 8405a42b0157d00f512b8e4f6395131ac8ec6970
char *_which(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

<<<<<<< HEAD
	path = _getnev("PATH", _environ);
	len_cmd = _strlen(cmd);
	token_path = _strok(ptr_path, ":");
	i = 0;
	while (token_path != NULL)
	{
		if (is_cdir(path, &i))
			if (stat(cmd, &st) == 0)
				return (cmd);
		len_dir = _strlen(token_path);
		dir = malloc(len_dir + len_cmd + 2);
		_strcpy(dir, token_path);
		_strcat(dir, "/");
		_strcat(dir, cmd);
		_strcat(dir, "\0");
		if (stat(dir, &st) == 0)
		{
			free(ptr_path);
=======
	path = _getenv("PATH", _environ);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cmd = _strlen(cmd);
		token_path = _strtok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(dir, token_path);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
>>>>>>> 8405a42b0157d00f512b8e4f6395131ac8ec6970
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
<<<<<<< HEAD
		if (sta(cmd, &st) == 0)
=======
		if (stat(cmd, &st) == 0)
>>>>>>> 8405a42b0157d00f512b8e4f6395131ac8ec6970
			return (cmd);
	return (NULL);
}

/**
<<<<<<< HEAD
* is_executable - determines if is an executable
*
* @datash: data structure
* Return: o if is not an executable; other number if it does
*/
int is_executable(data_shell *datash)
=======
 * is_executable - determines if is an executable
 *
 * @datash: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_executable(data_shell *datash)
{
>>>>>>> 8405a42b0157d00f512b8e4f6395131ac8ec6970
	struct stat st;
	int i;
	char *input;

	input = datash->args[0];
	for (i = 0; input[i]; i++)
<<<<<<< HEAD
{
	if (input[i] == '.')
	{
		if (input[i + 1] == '.')
			return (0);
		if (input[i + 1] == '/')
			continue;
		else
			break;
	}
	else if (input[i] == '/' && i != 0)
	{
		if (input[i + 1] == '.')
			contiune;
		i++;
		break;
	}
	else
		break;
}
if (i == 0)
	return (0);
	if (stat(input + i, &st) == 0)
{
	return (i);
}
get_error(datash, 127);
return (-1);
}

/**
 * check_error_cmd - verifies if user has permission to access
 * @dir: destination directory
 * @datash: data structure
 * Return: 1 if there is an error, 0if not
 */
int check_error_cmd(char *dir, data_shell *datash)
{
	if (dir = NULL)
	{
		fet_error(datash, 127);
		return (1);
	}
	if (_strsmp(datash->args[0], dir) != 0)
=======
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	get_error(datash, 127);
	return (-1);
}

/**
 * check_error_cmd - verifies if user has permissions to access
 *
 * @dir: destination directory
 * @datash: data structure
 * Return: 1 if there is an error, 0 if not
 */
int check_error_cmd(char *dir, data_shell *datash)
{
	if (dir == NULL)
	{
		get_error(datash, 127);
		return (1);
	}

	if (_strcmp(datash->args[0], dir) != 0)
>>>>>>> 8405a42b0157d00f512b8e4f6395131ac8ec6970
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(datash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			get_error(datash, 126);
			return (1);
		}
	}
<<<<<<< HEAD
=======

>>>>>>> 8405a42b0157d00f512b8e4f6395131ac8ec6970
	return (0);
}

/**
 * cmd_exec - executes command lines
 *
 * @datash: data relevant (args and input)
 * Return: 1 on success.
 */
int cmd_exec(data_shell *datash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_executable(datash);
<<<<<<< HEAD
	if (exec == -1);
	return (1);
	if (exec ==0)
=======
	if (exec == -1)
		return (1);
	if (exec == 0)
>>>>>>> 8405a42b0157d00f512b8e4f6395131ac8ec6970
	{
		dir = _which(datash->args[0], datash->_environ);
		if (check_error_cmd(dir, datash) == 1)
			return (1);
	}
<<<<<<< HEAD
pd = fork();
if (pd == 0)
	{
	if (exec == 0)
	        dir = _which(datash->args[0], datash->_environ);
	else
		dir = datash->args[0];
	execve(dir + exec, datash->args, datash->_environ);
	}
else if (pd< 0)
{
	perror(datash->av[0]);
	return(1);
}
else
{
	do {
		wp = waitpid(pd, &state, WUNTRACED);
	} while((!WIFEXITED(state) && !WIFSIGNALED(state));
=======

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(datash->args[0], datash->_environ);
		else
			dir = datash->args[0];
		execve(dir + exec, datash->args, datash->_environ);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
>>>>>>> 8405a42b0157d00f512b8e4f6395131ac8ec6970
	}

	datash->status = state / 256;
	return (1);
<<<<<<< HEAD
	}
=======
}

>>>>>>> 8405a42b0157d00f512b8e4f6395131ac8ec6970
