syscall_printString(char *str);
syscall_readString(char *str);
syscall_readSector(char *buffer, int sector);
syscall_clearScreen();

void clear();
void type(char *str);
void load(char *str);

struct command
{
    char *syntax;
};

int main()
{
    while(1)
    {
    char str[80], buffer[512];
    syscall_printString("QUORR:>");
    syscall_readString(str);
    syscall_printString("\r\n");
    }
}