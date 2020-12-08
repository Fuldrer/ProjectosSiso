#define Back 0x08
#define Enter 0x0d
#define Clear 0x20

extern void printChar(char ch);
extern char readChar();
void printString(char *ch2);
void readString(char line[80]);
void readSector(char *buff, int sec);
void makeInterrupt21(void);
void infinite(void);


int main()
{
    char line[80];
    char line2[512];
    char *space = "\r\n\0";
    char *txt = "Enter a line: \0";
    printString(txt);
    readString(line);
    printString(space);
    printString(line);
    printString(space);

    readSector(line2, 30);
    printString(line2);
    
    //makeInterrupt21();
    return 0;
}

void printString(char *ch2) {
	int i = 0;
	while(ch2[i] != '\0') {
		printChar(ch2[i]);
		i++;
	}
}

void readString(char line[80]) {
	char chr;
	int i;
	char checker = 0;
	for( i = 0; i < 80 - 1 ;)
	{
		chr = readChar();
		switch(chr){
			case Back:
				printChar(Back);
				printChar(Clear);
				i--;
				i = may(0,i);
				break;
			case Enter:
				checker = 1;
				break;
			default:
				line[i] = chr;
				i++;
		}
		printChar(chr);
		line[i] = '\0';
		if(checker)
			break;
	}
}

int minim(int x , int y) {
	return x < y ? x : y;
}

int may(int x , int y) {
	return x > y ? x : y;
}

