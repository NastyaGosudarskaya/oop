#include "argz.h"

int main()
{
	char *const string = "SHELL=/bin/bash:usr=monty:PWD=/bin/monty:LANG=en_US.UTF-8";
	char *argz;
	size_t argz_len;
	argz_create_sep(string, 58, &argz, &argz_len);
	argz_count(argz, argz_len);
	argz_add(&argz, &argz_len, "bpvmfl");
	argz_delete(&argz, &argz_len, "sr=monty");
	argz_insert(&argz, &argz_len, "PWD=/bin/monty", "PWD=/bin/montykas");
	char *entry = NULL;
    while (entry = argz_next(argz, argz_len, entry)) {
		printf("%s\n", entry);
	}
	argz_replace(&argz, &argz_len, "LANG=en_US.UTF-8", "ppp");
	argz_print(argz, argz_len);
	system("pause");
	return 0;
}