#include <stdio.h>

/* Converts from decimal to any base system from 2 to 16 */

char reval(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

void convert(int N, int b)
{
    if (N == 0)
       return;
    int x = N % b;
    N /= b;
    if (x < 0)
       N += 1; 
    convert(N, b);
    printf("%c", x < 0 ? reval(x + (b * -1)) : reval(x));
    
}

int main()
{
    int num, base;

    printf("Number to convert: ");
    scanf("%d", &num);

    printf("Base of system to convert number to: ");
    scanf("%d", &base);

    convert(num, base);

    return 0;
}