syscall_readSector(char *buffer, int sector);
syscall_printString(char *str);
syscall_readString(char *str);
syscall_readFile(char *str, char*buffer);
syscall_clearScreen();


typedef struct 
{
    char *syntax;
    int size;
}comms;

void call(char*input);

int main()
{
    while(1)
    {
    char str[80], argument[512];
    syscall_printString("QUORR:>");
    syscall_readString(str);
    syscall_printString("\r\n");
    call(str);
    }
}

int check(char *str, char *syntax, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(str[i] != syntax[i])
        {
            return 0;
        }
    }
    return 1;
}

void call(char *input)
{
    char buffer[13312];
    comms commands[3];
    char *filename;
    commands[0].syntax = "type";
    commands[1].syntax = "load";
    commands[2].syntax = "clear";
    commands[2].size = 5;
    commands[1].size = 4;
    commands[0].size = 4;
    if(check(input,commands[2].syntax, commands[2].size))
    {
            syscall_clearScreen();
    }
    else if(check(input,commands[1].syntax, commands[1].size))
    {
            syscall_printString("Command not implemented \0");
            syscall_printString("\r\n");
    }
    else if(check(input,commands[0].syntax, commands[0].size))
    {
            filename = (input + commands[0].size) + 1;
            syscall_readFile(filename,buffer);
            //syscall_printString(buffer);
            syscall_printString("\r\n");
    }
    else
    {
        syscall_printString("Command doesnt exist or a syntax error is present");
        syscall_printString("\r\n");
    }
    
}