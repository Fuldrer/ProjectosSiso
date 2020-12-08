#define Back 0x08
#define Enter 0x0d
#define Clear 0x20

void printChar(char ch);
char readChar();
void printString(char *ch2);
void readString(char line[80]);
void readSector(char *buff, int sec);
void makeInterrupt21();
void int21(int AX, char* BX, int CX, int DX );
void infinite(void);
void handleInterrupt21(int AX, int BX, int CX, int DX);
void interrupt(int number, int AX, int BX, int CX, int DX);
void printerror();
syscall_printString(char *str);
syscall_readString(char *str);

int main()
{
	//Step1 & Step2 & Step3
    /*char line[80];
    char line2[512];
    char *space = "\r\n\0";
    char *txt = "Enter a line: \0";
	char *txt2 = "Buenas \0";
	char txt3 = 'Q';
    /*printString(txt);
    readString(line);
    printString(space);
    printString(line);
    printString(space);

    readSector(line2, 30);
    printString(line2);
    
	//Step4
    makeInterrupt21();
	int21(0,txt, 0, 0);
	int21(1,line,30,0);
	int21(0,space,0,0);
	int21(0,line,0,0);
	int21(0,space,0,0);
	int21(2,line2,30,0);
	int21(0,line2,0,0);
	int21(0,space,0,0);
	int21(3,0,0,0);*/

	//Step5

  	makeInterrupt21();
    loadProgram();
    infinite();
}

void handleInterrupt21(int AX, int BX, int CX, int DX)
{
	switch (AX)
	{
	case 0:
		printString(BX);
		break;
	case 1:
		readString(BX);
		break;
	case 2:
		readSector(BX,CX);
		break;
	default:
		printerror();
		break;
	}
}

void printerror()
{
	char *error = "Esta no es una opcion valida para el interrupt 21 \0";
	printString(error);
}

void int21(int AX, char* BX, int CX, int DX)
{
	interrupt(0x21, AX, BX, CX, DX);
}

void infinite(){
    while(1);
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

