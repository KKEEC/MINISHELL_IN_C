#include "../includes/minishell.h"
#include "../includes/tokenizer.h"

static char *handle_input(void)
{
    t_token *tokens;
    char *input = readline("minishell$ ");
    if (!input)
    {
        printf("exit\n");
        exit(0);
    }
    if (*input)
        add_history(input);
    tokens = tokenize(input);
    if (!tokens)
    {
        printf("minishell: syntax error: unclosed quote\n");
    }
    t_token *curr = tokens;
    while (curr)
    {
        printf("Token: type=%d, value='%s'\n", curr->type, curr->value);
        curr = curr->next;
    }
    return (input);
}
void    minishell_loop(void)
{
    char *line;

    while(1)
    {
        line = handle_input();
        free(line);
    }
}
