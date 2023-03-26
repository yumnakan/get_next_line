# include<stdio.h>

void test(void)
{
	static int i = 9;
	// printf("%i\n", i);
	i ++;
	printf("%i\n", i);
}

int main(void)
{
	int	i = 9;
	test();
	test();
}