#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	char* LeftSearch = NULL;
	char* RightSearch = NULL;
	char c1,c2;
	char* Left = NULL;
	char* Right = NULL;

	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}

	if(strcmp(op,"mov") == 0)
		return 0;
	strcpy(args, args);
	Left = strtok(args, ",");
	Right = strtok(NULL, "\n");
	

	c1=Left[0];
	c2=Left[1];
	switch(c1)
	{
		case '%':
			LeftSearch =="reg";
			break;
		case '$':
			LeftSearch =="immed";
			break;
		case '0':
			if(c2=='x')
				LeftSearch = "mem";
			break;
		case '-':
			if(c2=='0')
				if(Left[3]=='x')
					LeftSearch = "memex";
			break;
		case '(':
			if(c2=='%')
				LeftSearch ="mem";
			break;
		default:
			LeftSearch = "X";
			break;

	}
	c1=Right[0];
	c2=Right[1];
	switch(c1)
	{
		case '%':
			RightSearch =="reg";
			break;
		case '$':
			RightSearch =="immed";
			break;
		case '0':
			if(c2=='x')
				RightSearch = "mem";
			break;
		case '-':
			if(c2=='0')
				if(Right[3]=='x')
					RightSearch = "memex";
			break;
		case '(':
			if(c2=='%')
				RightSearch ="mem";
			break;
		default:
			RightSearch = "X";
			break;

	}
	if(!strcmp(LeftSearch,"reg"))
		if(!strcmp(RightSearch,"reg"))
			strcpy(mcode,"89");
	else if((!strcmp(LeftSearch,"mem"))&&(!strcmp(RightSearch,"%eax")))
		strcpy(mcode,"a1");
	else if((!strcmp(LeftSearch,"mem"))&&(!strcmp(RightSearch,"reg")))
		strcpy(mcode,"8b");
	else if((!strcmp(LeftSearch,"memex"))&&(!strcmp(LeftSearch,"mem"))&&(!strcmp(RightSearch,"reg")))
		strcpy(mcode,"8b");
	else if((!strcmp(LeftSearch,"%eax"))&&(!strcmp(RightSearch,"mem")))
		strcmp(mcode,"a3");
	else if((!strcmp(LeftSearch, "immed"))&&(!strcmp(RightSearch,"reg")))
	{
		if(!strcmp(Right,"%eax"))
			strcpy(mcode,"b8");
		else if(!strcmp(Right,"ecx"))
			strcmp(mcode,"b9");
		else if(!strcmp(Right,"edx"))
			strcmp(mcode,"ba");
		else if(!strcmp(Right,"ebx"))
			strcmp(mcode,"bb");
		else if(!strcmp(Right,"esp"))
			strcmp(mcode,"bc");
		else if(!strcmp(Right,"ebp"))
			strcmp(mcode,"bd");
		else if(!strcmp(Right,"esi"))
			strcmp(mcode,"be");
		else if(!strcmp(Right,"edi"))
			strcmp(mcode,"bf");
			
	}

	
	return 1;	
}
