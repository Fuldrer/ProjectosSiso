syscall_printString(char *str);
syscall_printString(char *str);
syscall_readSector(char *buffer, int sector);

int main()
{
    /*char str[80], buffer[512];
    syscall_printString("Enter a line: ");
    syscall_readString(str);
    syscall_printString("\r\n");
    syscall_printString(str);
    syscall_printString("\r\n");
    syscall_printString("Reading sector 30 from floppy\r\n");
    syscall_printString("\r\n");
    syscall_readSector(buffer, 30);
    syscall_printString(buffer);
    syscall_printString("Buenas Como estan Todos");*/
    char line[80];
    syscall_printString("Buenas Como estan Todos");
    syscall_printString("\r\n");
    syscall_readString(line);
    syscall_printString("\r\n");
    syscall_printString(line);
    while(1)
    {

    }
}