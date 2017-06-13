#include <stdio.h>

//Funcao show_message pega o numero
// 1 ou 2 do usuario , sao esses que serao
// multiplicados
int show_message(int number)
{
	//Valor recebdi do usario
	int value;

	//Se for o primeiro 
	if(number==1)
	{
		printf("Write the first number :\n");
	}
	//Se for o segundo
	else
	{
		printf("Write the second number :\n");
	}
	//Recebe o numero
	scanf("%d",&value);
	//Retorna o numero
	return value;
}

//Funcao que achara a maior base em funcao 10
// do numero , ex = 19 base e 19 // ex = 200 base e 100
// ex = 1234 e 1000
int base(int number)
{
	//Comecando com 10
	int n=10;

	//Enquanto nao for maior que o numero aumenta a base
	while(n<number)
	{
		//Base = base * 10
		n=n*10;
	}
	//Retorna a base , sobre 10 por que fez um loop a mais
	return n/10;		
}

//FUncao que calcula o maximo numero que multiplica a base e nao seja maior
// que o proprio numero
int maximum(int number,int b)
{
	//Comecando com 1
	int m=1;

	//Enquanto nao for maior, aumenta o numero M
	while(m*b<number)
	{
		//Incrementando
		m=m+1;
	}

	//Retorna o numero, -1 por que ele fez 1 loop a mais
	return m-1;

}
//Funcao rest retorna o valor que sobrou
// entre a subtracao do numero com a base vezes
// o maior numero que multiplique a base e nao passe o numero
int rest(int number,int b,int m)
{
	//Cacula o resto
	int rest = number - b*m;

	//Retorna o resto
	return rest;
}

int karatusa(int n1,int n2)
{
	if( n1 <10 || n2<10)
	{
		return n1*n2;
	}
	//Etapas do calculos
	int z0,z1,z2;
	//Auxliares
	int z2_1,z2_2;
	//Bases dos numeros
	int b1,b2;
	//Resultado final
	int result ;

	//Pega as bases dos numeros
	b1 = base(n1);
	b2 = base(n2);

	//Escolha a base comum
	if(b1>b2)
	{
		b1=b2;
	}
	else
	{
		b2=b1;
	}

	//Maximo do numero 1
	z2_1 = maximum(n1,b1);
	//Maximo do numero 2
	z2_2 = maximum(n2,b2);

	//Calcula Z2
	z2 = z2_1 * z2_2;

	//Calcula Z0
	z0 = rest(n1,b1,z2_1) * rest(n2,b2,z2_2);

	//Primeira parte do calculo de z1
	z1 = (z2_1+rest(n1,b1,z2_1))*(z2_2+rest(n2,b2,z2_2));

	//Segunda parte do calculo de z2
	z1 = z1 - z2 - z0;

	//Calcula resultado
	result = z2*b1*b1 + z1*b1 + z0;

	//Retona valor do resultado
	return result;
}


int main()
{
	//Variaveis para receber os dois numeros e o resultado
	int number1, number2,result;

	//Funcao SHOW_MESSAGE pega valores dos dois numeros do usuario
	number1 = show_message(1);
	number2 = show_message(2);

	//Result recebe valor final da multiplicacao
	result = karatusa(number1,number2);

	//Motra resultado na tela 	
	printf("\nResult of %d x %d is %d\n",number1,number2,result );	

	return 0;
}