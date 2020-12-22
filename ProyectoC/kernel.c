#define Back 0x08
#define Enter 0x0d
#define Clear 0x20
#define TRUE 1
#define FALSE 0

int comparename(char filename[6], char *start);
void readFile(char *filename, char *buffer);
void printChar(char ch);
char readChar();
void printString(char *ch2);
void readString(char line[80]);
void readSector(char *buff, int sec);
void makeInterrupt21();
void int21(int AX, char* BX, int CX, int DX );
void handleInterrupt21(int AX, int BX, int CX, int DX);
void interrupt(int number, int AX, int BX, int CX, int DX);
void printerror();
void executeProgram(char *name, int segment);
void terminate();
void clearScreen();


int main()
{
    char buffer[13312];
    readFile("messag",buffer);
    printString(buffer);
  	makeInterrupt21();
	//executeProgram("shell", 0x2000);
    loadProgram();
}

int comparename(char *filename, char *start)
{
    int i;
    for(i = 0; i<6;i++)
    {
        if(filename[i] == start[i])
        {
            return 1;
        }
    }
    return 0;
}


void readFile(char *fileName, char *buffer)
{
    //char *check = "Hola \0";
    //printString(check);
    int bufferdir = 0;
    int comp;
    int i,j,a,b, sectorfile;
    char buffer2[512];
    char *check = "File not found \0";
    char* check2 = "File found \0";
    char* diskfilename;
    a = 0;

    readSector(buffer2, 2);
    for(i = 0; i < 512; i+= 32)
    {
        for(a = 0; a < 6 ; a++)
        {
            if(i < 32)
            {
                diskfilename[a] = buffer2[a];
            }
            diskfilename[a] = buffer2[a+i];
        }
        comp = comparename(fileName, diskfilename);
        if(comp == 1)
        {
            for(a = 0; a < 26;a++)
            {
                if(i < 32)
                {
                    sectorfile = buffer2[a+6];
                }
                sectorfile = buffer2[a+i+6];
                readSector(buffer, sectorfile);
                buffer += 512;
            }
            printString(check2);
            printString("\r\n");
            return;
        }
    }
    printString(check);
    printString("\r\n");
    return;
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
	case 3:
		readFile(BX,CX);
		break;
	case 4:
		loadProgram(BX,CX);
	case 5:
		terminate();
		break;
	case 6:
		clearScreen();
		break;
	default:
		printerror();
		break;
	}
}

void terminate()
{
	while(1);
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

