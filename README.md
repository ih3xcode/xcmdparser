# xcmdparser
_Originally derived from [XUJINKAI/cmdparser](https://github.com/XUJINKAI/cmdparser)_

Command parser library (C/C++), with highly customizable.

## Feature

-  Friendly API, configuration in ONE struct
-  Follow GNU/POSIX option conversion, short/long option supported
-  Nested sub-commands support, and they can share same logic
-  Global option supported
-  Parse strict: repeat option detect
-  Highly customizable: Hide/Disable options or sub-commands, Language (error message), help option, doc generator, output stream, etc.

## Demo
Short option: `-a -b -n XJK` can be shorten to `-abn XJK` (`-nab XJK` as well)

Long option: `--name=XJK` can be write as `--name XJK`

End of option: `-all -- -abc`, -abc will be treat as argument

Global option can behind sub-command: `git status --git-dir=.git` :)

Repeat option detect: `-a -b -a` will cause error

## Examples

[simple](demo/simple/main.c) is an basic demo about parse options.

[git](demo/git) follows git commands demos how to handle complex sub-commands/options.

[tests](tests) Unit Tests covers most features.

## Documentation

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
    return cmdp_run(argc - 1, argv + 1, &cmdp, NULL);
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

See [test/chinese_error_msg_test.c](test/chinese_error_msg_test.c)

You can custom your own error message.

## Credits

-  [cmdparser](https://github.com/XUJINKAI/cmdparser)
-  [utest.h](https://github.com/sheredom/utest.h)
