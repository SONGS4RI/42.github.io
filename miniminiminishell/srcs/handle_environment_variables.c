#include "../includes/miniminiminishell.h"

int	cmp_env_key(char *string, char *envp_string)
{
	int i;

	i = -1;
	while (string[++i])
	{
		if (string[i] != envp_string[i])
			return (0);
	}
	if (envp_string[i] != '=')
		return (0);
	return (1);
}

char *my_getenv(char *name, t_envp_node *node)
{
	while (node)
	{
		if (cmp_env_key(name, node->string))
			return(node->string + ft_strlen(name) + 1);
		node = node->next;
	}
	return (NULL);
}

char	*free_and_getenv(char *name)
{
	char	*env_var;

	env_var = getenv(name);
	free(name);
	if (env_var)
		return (ft_strdup(env_var));
	else
		return (ft_strdup(""));
}

