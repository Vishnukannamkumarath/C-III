#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *f1,*f2,*f3,*f4;
	char label[10],opcode[10],operand[10],length[10],tlength[10],locctr[10],op_name[10],op_code[10],sym_name[10],sym_code[10];
	int sa,operand_a,len,i;
	
	f1=fopen("intermediate.txt","r");
	f2=fopen("optab.txt","r");
	f3=fopen("symtab.txt","r");
	f4=fopen("len.txt","r");
	
	fscanf(f1,"%s%s%d",label,opcode,&operand_a);
	fscanf(f4,"%s%s",length,tlength);
	if(strcmp(opcode,"START")==0)
	{
		sa=operand_a;
		printf("H^  %s^__%d^%s\n",label,sa,length);
	}
	
	printf("T^__%d^%s^",sa,tlength);
	
	fscanf(f1,"%s%s%s%s",locctr,label,opcode,operand);
	while(strcmp(opcode,"END")!=0)
	{
		fseek(f2,0,SEEK_SET);
		fscanf(f2,"%s%s",op_name,op_code);
		while(!feof(f2))
		{	fseek(f3,0,SEEK_SET);
			if(strcmp(opcode,op_name)==0)
			{
				fscanf(f3,"%s%s",sym_code,sym_name);
				while(!feof(f3))
				{
					if(strcmp(operand,sym_name)==0)
					{
						printf("%s%s^",op_code,sym_code);
						break;
					}
					fscanf(f3,"%s%s",sym_code,sym_name);
				}
				break;
			}
			fscanf(f2,"%s%s",op_name,op_code);
		}
		if((strcmp(opcode,"BYTE")==0)||(strcmp(opcode,"WORD")==0))
		{
			if(strcmp(opcode,"BYTE")==0)
			{
				len=strlen(operand);
				for(i=2;i<len;i++)
				{
					printf("%c",operand[i]);
				}
			}
			else
			{
				printf("00000%s",operand);
			}
			printf("^");
			
		}
		fscanf(f1,"%s%s%s%s",locctr,label,opcode,operand);
	}
	if(strcmp(opcode,"END")==0)
	{
		printf("\nE^00%d",sa);
	}
}

