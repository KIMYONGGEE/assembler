#include "myas.h"

int is_valid(char *op, char *args)
{
	char PUPPIT[256];

	strcpy(PUPPIT, args);
	
	char* LeftSearch=NULL;
	char* RightSearch=NULL;
	char c1,c2;
	char* Left=NULL;
	char* Rigt=NULL;
	
	if(strcmp(op,'mov') == 0)
		return 1;
	
	Left = strtok(PUPPIT,",");
	Right = strtok(NULL,"\n");

	if(Left==NULL||Right==NULL)
		return 0;

	c1=Left[0];
	c2=Left[1]
	switch(c1)
	{
		case '%':
			LeftSearch =="reg";
			break;
		case '$'
			LeftSearch =="immed";
			break;
		case '0'
			if(c2=='x')
				LeftSearch = "mem";
		case '-'
			if(c2=='0')
				if(Left[3]=='x')
					LeftSearch = "mem";
		case '('
			if(c2=='%')
				LeftSearch ="mem";
		default
			LeftSearch = "X";

	}
	c1=Right[0];
	c2=Right[1];
	switch(c1)
	{
		case '%':
			ReftSearch =="reg";
			break;
		case '$'
			ReftSearch =="immed";
			break;
		case '0'
			if(c2=='x')
				ReftSearch = "mem";
		case '-'
			if(c2=='0')
				if(Right[3]=='x')
					ReftSearch = "mem";
		case '('
			if(c2=='%')
				RightSearch ="mem";
		default
			ReftSearch = "X";

	}


	return 1;
}
