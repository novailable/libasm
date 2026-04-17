#include "libasm.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
		printf("\"%s\" count %zu\n", argv[1], ft_strlen(argv[1]));
	printf("%zu\n", ft_strlen(""));
}