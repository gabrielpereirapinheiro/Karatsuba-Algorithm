#include <stdio.h>
int show_message(int number)
{
	int value;

	if(number==1)
	{
		printf("Write the first number\n");
		scanf("%d",&value);
	}
	else
	{
		printf("Write the second number\n");
		scanf("%d",&value);
	}

	return value;
}

int karatusa(int n1,int n2, int base)
{
	
}


int main()
{
	int number1, number2,base=10;

	number1 = show_message(1);
	number2 = show_message(2);

	karatusa(number1,number2,base);
	return 0;
}