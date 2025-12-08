#ifndef UTILS_H
# define UTILS_H

typedef struct s_node t_node;

void	ft_skip_spaces(char **s);
char	*add_path_to_file(char *s);
size_t	ft_arraylen(char **array);
t_node	*create_node(char *s);

#endif