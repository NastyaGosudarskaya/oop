#include "argz.h"

error_t argz_create_sep(const char *string, int sep, char **argz, size_t *argz_len)
{
	*argz_len = strlen(string);
	int i = 0;
	*argz = (char*)malloc(sizeof(char)*((*argz_len) + 1));
	while (i<*argz_len)
	{
		if (string[i] == sep)
		{
			(*argz)[i] = '\0';
		}
		else
		{
			(*argz)[i] = string[i];
		}
		i++;
	}
	(*argz)[i] = '\0';
	*argz_len = *argz_len + 1;
	return OK;
}

size_t argz_count(const char *argz, size_t arg_len)
{
	int counter = 0;
	size_t i = 0;
	while (i<arg_len)
	{
		if (argz[i] == '\0')
			counter++;
		i++;
	}
	return counter;
}

error_t argz_add(char **argz, size_t *argz_len, const char *str)
{
	*argz = (char*)realloc(*argz, (*argz_len + strlen(str)+1) * sizeof(char));
	int i = *argz_len;
	while (i<(*argz_len + strlen(str)))
	{
		(*argz)[i] = str[i - *argz_len];
		i++;
	}
	(*argz)[i] = '\0';
	*argz_len = i + 1;
	return OK;
}

void argz_delete(char **argz, size_t *argz_len, char *entry)
{
	int len_entry = strlen(entry);
	int counter = 0, i, j = 0, k;
	for (i = 0; i<(*argz_len); i++)
	{
		//пошук entry в argz
		counter = 0;
		k = i;
		for (j = 0; j<len_entry; j++)
		{
			if ((*argz)[k] == entry[j])
			{
				counter++;
			}
			else
			{
				break;
			}
			k++;
		}
		if (counter == len_entry)
		{
			break;
		}
	}
	//кінець пошуку
	if (counter != len_entry)
	{
		return;
	}
	for (j = 0; j<counter; j++)
	{
		for (i = k - counter; i<*argz_len - 1 - j; i++)
		{
			(*argz)[i] = (*argz)[i + 1];
		}
	}
	*argz_len = *argz_len - counter;
	*argz = (char*)realloc(*argz, *argz_len * sizeof(char));
}

error_t argz_insert(char **argz, size_t *argz_len, char *before, const char *entry)
{
	int len_before = strlen(before);
	int counter = 0, i = 0, j = 0, k;
	for (i = 0; i<*argz_len; i++)
	{
		//пошук before в argz
		counter = 0;
		k = i;
		for (j = 0; j<len_before; j++)
		{
			if ((*argz)[k] == before[j])
			{
				counter++;
			}
			else
			{
				break;
			}
			k++;
		}
		if (counter == len_before)
		{
			break;
		}
	}
	//кінець пошуку
	if (counter != len_before)
	{
		return ERROR;
	}
	*argz = (char*)realloc(*argz, (*argz_len + strlen(entry)) * sizeof(char));
	for (j = 0; j<strlen(entry); j++)
	{
		for (i = *argz_len + j; i>k - counter; i--)
		{
			(*argz)[i] = (*argz)[i - 1];
		}
	}
	for (j = 0; j<strlen(entry); j++)
	{
		(*argz)[k - counter + j] = entry[j];
	}
	*argz_len = *argz_len + strlen(entry);
	return OK;
}

char * argz_next(char *argz, size_t argz_len, const char *entry)
{
	int entry_len;
	if (entry == NULL)
		return argz;
	entry_len = strlen(entry);
	int index, j, k, i;
	index = 0;
	i = 0;
	j = 0;
	k = 0;
	while (i <= argz_len) {
		k = i;
		while ((argz[k] == entry[j]) && (entry[j] != '\0')) {
			k++;
			j++;
		}
		if (entry[j] != '\0') {
			j = 0;
			k = 0;
			i++;
		}
		else {
			index = k - j;
			if (index + entry_len + 1 >= argz_len)
			{
				return 0;
			}
			else
			{
				return &(*(argz + index + entry_len + 1));
			}
		}
	}
}

error_t argz_replace(char **argz, size_t *argz_len, const char *str, const char *with)
{
	int len_str = strlen(str);
	int counter = 0, i, j = 0, k;
	for (i = 0; i<(*argz_len); i++)
	{
		//пошук str в argz
		counter = 0;
		k = i;
		for (j = 0; j<len_str; j++)
		{
			if ((*argz)[k] == str[j])
			{
				counter++;
			}
			else
			{
				break;
			}
			k++;
		}
		if (counter == len_str)
		{
			break;
		}
	}
	//кінець пошуку
	if (counter != len_str)
	{
		return ERROR;
	}
	if (strlen(str)<strlen(with))
	{
		for (i = 0; i<strlen(str); i++)
		{
			(*argz)[k - counter + i] = with[i];
		}
		*argz = (char*)realloc(*argz, (*argz_len + strlen(with) - strlen(str)) * sizeof(char));
		for (j = 0; j<strlen(with) - strlen(str); j++)
		{
			for (i = *argz_len + j; i>k - counter + strlen(str); i--)
			{
				(*argz)[i] = (*argz)[i - 1];
			}
		}
		for (i = strlen(str); i<strlen(with); i++)
		{
			(*argz)[k - counter + i] = with[i];
		}
	}
	else
	{
		for (i = 0; i<strlen(with); i++)
		{
			(*argz)[k - counter + i] = with[i];
		}
		for (j = 0; j<strlen(str) - strlen(with); j++)
		{
			for (i = k - counter + strlen(with); i<*argz_len - 1; i++)
			{
				(*argz)[i] = (*argz)[i + 1];
			}
		}
	}
	*argz_len = *argz_len + strlen(with) - strlen(str);
	return OK;
}

void argz_print(const char *argz, size_t argz_len)
{
	int i = 0;
	while (i<argz_len)
	{
		printf("%c",argz[i]);
		i++;
	}
}