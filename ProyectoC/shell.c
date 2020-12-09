syscall_printString(char *str);
syscall_readString(char *str);
syscall_readSector(char *buffer, int sector);
syscall_clearScreen();

typedef struct 
{
    char *syntax;
    int size;
}comms;

void call(char*input, char *args);

int main()
{
    while(1)
    {
    char str[80], buffer[512];
    syscall_printString("QUORR:>");
    syscall_readString(str);
    syscall_printString("\r\n");
    call(str,buffer);
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

void call(char *input, char* arg)
{
    comms commands[3];
    commands[0].syntax = "type";
    commands[1].syntax = "load";
    commands[2].syntax = "clear";
    commands[2].size = 5;
    if(check(input,commands[2].syntax, commands[2].size))
    {
            syscall_clearScreen();
    }
    else
    {
        syscall_printString("Command doesnt exist or a syntax error is present");
        syscall_printString("\r\n");
    }
    
}