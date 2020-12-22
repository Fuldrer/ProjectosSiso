syscall_printString(char *str);
syscall_readString(char *str);
syscall_readSector(char *buffer, int sector);
syscall_readFile(char*name, char*buffer);

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
    syscall_printString("\r\n");
    syscall_readSector(buffer, 31);
    syscall_printString(buffer);
    syscall_printString("\r\n");*/
    syscall_printString("Buenas Como estan Todos");
    /*char buffer[13312];
    syscall_readFile("message", buffer);
    syscall_printString(buffer);*/
    while(1);
}