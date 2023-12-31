#include "xcmdparser.h"
#include <string.h>

static cmdp_action_t callback_function(cmdp_process_param_st *params);

static struct
{
    bool b;
    int i;
    double d;
    char *s;
} arg = {0};


static cmdp_command_st g_command = {
    .doc = "An simple demo about how to use cmdparser library.\n"
           "Url: https://github.com/XUJINKAI/cmdparser \n"
           "\n",
    .options =
        (cmdp_option_st[]){
            {'b', "Bool", "Input Bool Option", CMDP_TYPE_BOOL, &arg.b},
            {'i', "Int", "Input Int Option", CMDP_TYPE_INT4, &arg.i},
            {'d', "Double", "Input Double Option", CMDP_TYPE_DOUBLE, &arg.d},
            {'s', "String", "Input String Option", CMDP_TYPE_STRING_PTR, &arg.s, .type_name = "<ANY>"},
            {0},
        },
    .fn_process = callback_function,
};


int main(int argc, char **argv)
{
    return cmdp_run(argc - 1, argv + 1, &g_command, NULL);
}


static cmdp_action_t callback_function(cmdp_process_param_st *params)
{
    if (params->opts == 0)
    {
        return CMDP_ACT_SHOW_HELP;
    }
    printf("bool: %s\n"
           "int: %d\n"
           "double: %f\n"
           "string: %s\n",
           arg.b ? "true" : "false", arg.i, arg.d, arg.s);
    for (int i = 0; i < params->argc; i++)
    {
        printf("argv[%d]: %s\n", i, params->argv[i]);
    }
    return CMDP_ACT_OK;
}
