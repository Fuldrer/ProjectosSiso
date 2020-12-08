
 extern void putInMemory (int segment, int address, char character);

int main()
{
    putInMemory(0xB000, 0x8140, 'A');
    putInMemory(0xB000, 0x8141, 0x7);
    return 0;
}
