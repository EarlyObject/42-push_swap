#include <string.h>
#include <stdlib.h>

#ifndef MAX
# define MAX 100
#endif

void
*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;

	dest = b;
	if (!b)
		return (NULL);
	while (len > 0)
	{
		*dest = (unsigned char)c;
		dest++;
		len--;
	}
	return (b);
}
void
	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void
	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count == 0)
		count = 1;
	if (size == 0)
		size = 1;
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

static	unsigned int
	count_len(long long n)
{
	unsigned int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char
	*ft_itoa(long long n)
{
	char			*p;
	char			sign;
	unsigned int	len;

	if (n < 0)
		sign = '-';
	else
		sign = '\0';
	len = count_len(n);
	p = (char *)ft_calloc(sizeof(char ), len + 1);
	p[len] = '\0';
	while (len)
	{
		if (n < 0)
			p[--len] = -(n % 10) + '0';
		else
			p[--len] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign)
		p[len] = sign;
	return (p);
}

void
	swap(int arr[], int a, int b)
{
	int	temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void printArr(int arr[], int n)
{
	char	*args = "ARG=\"";
	char	a[1000];
	char	b[1000];
	char	c[1000];

	strcat(b, args);
	for(int i = 0; i < n; i++)
	{
		strcat(a, " ");
		strcat(a, ft_itoa((long) arr[i]));
		strcat(a, " ");
	}
	strncpy(c, a, 1000);
	strcat(b, a);
	strcat(b, "\"; ./push_swap $ARG | ./checker $ARG");
	system(b);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	return ;
}

// Generating permutation using Heap Algorithm
void heapPermutation(int a[], int size, int n)
{
	// if size becomes 1 then prints the obtained
	// permutation
	if (size == 1) {
		printArr(a, n);
		return;
	}

	for (int i = 0; i < size; i++) {
		heapPermutation(a, size - 1, n);

		// if size is odd, swap 0th i.e (first) and
		// (size-1)th i.e (last) element
		if (size % 2 == 1)
			swap(a, 0, size - 1);

			// If size is even, swap ith and
			// (size-1)th i.e (last) element
		else
			swap(a, i, size - 1);
	}
}

// Driver code
int
	main(void)
{
	int a[] = { 45 };
	int n = sizeof a / sizeof a[0];

	heapPermutation(a, n, n);
	exit(0);
}