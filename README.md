# cmdparser

![](https://github.com/XUJINKAI/cmdparser/actions/workflows/test.yml/badge.svg)

Command parser library (C/C++), with highly customizable.

命令行参数解析库，支持子命令嵌套，支持自定义错误语言，以及更多可定制化内容。

## Feature

- Friendly API, configuration in ONE struct

- Nested sub-commands support

- Short option (`-a`) and long options (`--all`)

- Short option `-a -b -n XJK` can be shorten to `-abn XJK` (`-nab XJK` as well)

- Long option `--name=XJK` can be write as `--name XJK`

- End of options `--` supported

- Global options. e.g. `git status --git-dir=.git` will work as expect. (if use this library)

- Hide/Disable options or sub-commands, repeat option detect

- Highly customizable: Language (error message), help option, doc generator, output stream, etc.

## Examples

[demo_simple](demo_simple/main.c) is an basic demo about parse options.

[demo_git](demo_git) follows git commands demos how to handle complex sub-commands/options.

[test](test) Unit Tests covers most features.

[xx-crypto-cli](https://github.com/XUJINKAI/xx-crypto-cli) A real example with plenty of commands.

## Document

### Get Started

Define an global struct and call `cmdp_run`.

```c
static cmdp_command_st cmdp = {
    .options = {
        {'i', "Int", "Input Int Option", CMDP_TYPE_INT4, &arg.i},
        {0},                        // ends with {0}
    },
    .fn_process = callback,         // called after options parsed
};

int main(int argc, char **argv)
{
    return cmdp_run(argc - 1, argv + 1, &cmdp);
}
```

### Nested Sub-commands

Set `sub_commands` field, nested can be infinite.

```c
static cmdp_command_st cmdp = {
    .options = {...},
    .sub_commands = (cmdp_command_st*[]){
        &(cmdp_command_st){
            .name = "sub",
            .options = {...},
            .fn_process = sub_callback,
        },
        NULL,                        // ends with NULL
    },
};
```

### Custom Error Message

See [test/cmdp_configure_chinese.c](test/cmdp_configure_chinese.c)

You can custom your own error message.

## Credits

[utest.h](https://github.com/sheredom/utest.h)

## License

MIT © XUJINKAI
