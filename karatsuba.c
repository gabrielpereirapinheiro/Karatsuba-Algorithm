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

int base(int number)
{
	int n=10;

	while(n<number)
	{
		n=n*10;
	}
	return n/10;		
}

int maximum(int number,int b)
{
	int m=1;

	while(m*b<number)
	{
		m=m+1;
	}

	return m-1;

}

int rest(int number,int b,int m)
{
	int rest = number - b*m;
}

int karatusa(int n1,int n2)
{
	if( n1 <10 || n2<10)
	{
		return n1*n2;
	}

	int z0,z1,z2;
	int z2_1,z2_2;
	int b1,b2;
	int result ;
	b1 = base(n1);
	b2 = base(n2);

	if(b1>b2)
	{
		b1=b2;
	}
	else
	{
		b2=b1;
	}

	z2_1 = maximum(n1,b1);
	
	z2_2 = maximum(n2,b2);

	z2 = z2_1 * z2_2;

	z0 = rest(n1,b1,z2_1) * rest(n2,b2,z2_2);

	z1 = (z2_1+rest(n1,b1,z2_1))*(z2_2+rest(n2,b2,z2_2));

	z1 = z1 - z2 - z0;

	result = z2*b1*b1 + z1*b1 + z0;

	return result;
}


int main()
{
	int number1, number2;

	number1 = show_message(1);
	number2 = show_message(2);

	int a = karatusa(number1,number2);
		
	printf("%d\n",  a );
	return 0;
}