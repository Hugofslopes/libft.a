#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <stdlib.h>

//function to try iteri
void touperit(unsigned int c, char *putstr1)
{
	if (putstr1[c] >= 'a' && putstr1[c] <= 'z')
	putstr1[c] -= 32;
}

//function to try mapi
char touppermapi(unsigned int index, char c) 
{
	(void)index;
    if (c >= 'a' && c <= 'z') 
        return c - 32; 
    return c;
}

//function for lstiteri
void print_content(void *content) 
{
    printf("%s\n", (char *)content);
}

//function for lstclear
void del(void *content)
{
	free(content);
}

//function for lstmap
void *print_content2(void *content) 
{
	char *new_content = strdup((char *)content);
	if (!new_content) 
        return NULL; 
	return new_content;
}


int main()
{
//STRLEN
	printf("\033[107mStrlen\033[0m\n");
//1
	printf("\033[94mTest 1-FT-\033[0m %ld\t\t\t", ft_strlen("ola"));

	printf("\033[95mTest 1-O-\033[0m %ld\n", strlen("ola"));

//2
	printf("\033[94mTest 2-FT-\033[0m %ld\t\t\t", ft_strlen(""));

	printf("\033[95mTest 2-O-\033[0m %ld\n", strlen(""));

//3
	printf("\033[94mTest 3-FT-\033[0m %ld\t\t\t", ft_strlen(" "));

	printf("\033[95mTest 3-O-\033[0m %ld\n\n", strlen(" "));


//MEMSET
	printf("\033[107mMemset\033[0m\n");
//1
	char string_memset[20] = {};
	printf("\033[94mTest 1-FT-\033[0m %s", (char *)(ft_memset(string_memset,'b', 20)));

	printf("\033[95mTest 1-O-\033[0m %s\n", (char *)(memset(string_memset,'b', 20)));

//2
	printf("\033[94mTest 2-FT-\033[0m %s\t\t\t", (char *) (ft_memset(string_memset, 0, 20)));

	printf("\033[95mTest 2-O-\033[0m %s\n", (char *) (memset(string_memset, 0, 20)));

//3
	printf("\033[94mTest 3-FT-\033[0m %s\t\t", (char *) (ft_memset(string_memset, 'c', 10)));

	printf("\033[95mTest 3-O-\033[0m %s\n\n", (char *) (memset(string_memset, 'c', 10)));


//BZERO
//1
	printf("\033[107mBzero\033[0m\n");
	char string_b_zero[] = "Hello";
	printf("%s\t", string_b_zero);
	ft_bzero(string_b_zero, 5);
	printf("\033[94mTest 1-FT-\033[0m %s\t\t", string_b_zero);

	char string_b_zero_2[] = "Hello";
	printf("%s\t", string_b_zero_2);
	bzero(string_b_zero_2, 5);
	printf("\033[95mTest 1-O-\033[0m %s\n\n", string_b_zero_2);
	

//MEMCPY
	printf("\033[107mMemcpy\033[0m\n");
//1
	char src_memcpy[] = "Hello, World!";
	char dest_memcpy[20];
	ft_memcpy(dest_memcpy, src_memcpy, strlen(src_memcpy) + 1);
	printf("\033[94mTest 1-FT-\033[0m %s\t", dest_memcpy);

	char src_memcpy1[] = "Hello, World!";
	char dest_memcpy1[20];
	memcpy(dest_memcpy1, src_memcpy1, strlen(src_memcpy1) + 1);
	printf("\033[95mTest 1-O-\033[0m %s\n", dest_memcpy1);

//2
	char src_memcpy2[] = "Goodbye!";
	char dest_memcpy2[20];
	ft_memcpy(dest_memcpy2, src_memcpy2, strlen(src_memcpy2) + 1);
	printf("\033[94mTest 2-FT-\033[0m %s\t\t", dest_memcpy2);

	char src_memcpy3[] = "Goodbye!";
	char dest_memcpy3[20];
	memcpy(dest_memcpy3, src_memcpy3, strlen(src_memcpy3) + 1);
	printf("\033[95mTest 2-O-\033[0m %s\n", dest_memcpy3);

//3
	char src_memcpy4[] = "Hello!";
	char dest_memcpy4[] = "1234";
	ft_memcpy(dest_memcpy4, src_memcpy4, 0);
	printf("\033[94mTest 3-FT-\033[0m %s\t\t\t", dest_memcpy4);

	char src_memcpy5[] = "Hello!";
	char dest_memcpy5[] = "1234";
	memcpy(dest_memcpy5, src_memcpy5, 0);
	printf("\033[95mTest 3-O-\033[0m %s\n", dest_memcpy5);

//4
	//Test the overlap on the same string (string needs to have enough size)
	char src_memcpy6[] = "Overlap Test  ";
	ft_memcpy(src_memcpy6 + 8, src_memcpy6, 7);
	printf("\033[94mTest 4-FT-\033[0m %s\t", src_memcpy6);

	char src_memcpy7[] = "Overlap Test  ";;
	memcpy(src_memcpy7 + 8, src_memcpy7, 7);
	printf("\033[95mTest 4-O-\033[0m %s\n", src_memcpy7);

//5
	char src_memcpy8[] = "Hello, World!";
	ft_memcpy(src_memcpy8 + 7, src_memcpy8, 5);
	printf("\033[94mTest 5-FT-\033[0m %s\t", src_memcpy8);

	char src_memcpy9[] = "Hello, World!";
	memcpy(src_memcpy9 + 7, src_memcpy9, 5);
	printf("\033[95mTest 5-O-\033[0m %s\n\n", src_memcpy9);

	/* Overlapping Memory Regions:
    The C standard specifies that memcpy is intended for copying data from one 
	location to another without any consideration for overlapping regions. When 
	he source and destination overlap, the behavior is not defined. This means 
	that the compiler is free to assume that the source and destination do not 
	overlap and can optimize the operation accordingly. Because memcpy does not 
	check for overlaps, it may read from the string while simultaneously writing to 
	it, leading to unpredictable results */


//MEMMOVE
	printf("\033[107mMemmove\033[0m\n");
//1
	char src_memmove[] = "Hello, World!";
	char dest_memmove[20];
	ft_memmove(dest_memmove, src_memmove, strlen(src_memmove) + 1);
	printf("\033[94mTest 1-FT-\033[0m %s\t", dest_memmove);

	char src_memmove1[] = "Hello, World!";
	char dest_memmove1[20];
	memmove(dest_memmove1, src_memmove1, strlen(src_memmove1) + 1);
	printf("\033[95mTest 1-O-\033[0m %s\n", dest_memmove1);

//2
	char src_memmove2[] = "Goodbye!";
	char dest_memmove2[20];
	ft_memmove(dest_memmove2, src_memmove2, strlen(src_memmove2) + 1);
	printf("\033[94mTest 2-FT-\033[0m %s\t\t", dest_memmove2);

	char src_memmove3[] = "Goodbye!";
	char dest_memmove3[20];
	memmove(dest_memmove3, src_memmove3, strlen(src_memmove3) + 1);
	printf("\033[95mTest 2-O-\033[0m %s\n", dest_memmove3);

//3
	char src_memmove4[] = "Hello!";
	char dest_memmove4[] = "1234";
	ft_memmove(dest_memmove4, src_memmove4, 0);
	printf("\033[94mTest 3-FT-\033[0m %s\t\t\t", dest_memmove4);

	char src_memmove5[] = "Hello!";
	char dest_memmove5[] = "1234";
	memmove(dest_memmove5, src_memmove5, 0);
	printf("\033[95mTest 3-O-\033[0m %s\n", dest_memmove5);

//4
	//Test the overlap on the same string (string needs to have enough size)
	char src_memmove6[] = "Overlap Test  ";
	ft_memmove(src_memmove6 + 8, src_memmove6, 7);
	printf("\033[94mTest 4-FT-\033[0m %s\t", src_memmove6);

	char src_memmove7[] = "Overlap Test  ";;
	memmove(src_memmove7 + 8, src_memmove7, 7);
	printf("\033[95mTest 4-O-\033[0m %s\n", src_memmove7);

//5
	char src_memmove8[] = "Hello, World!";
	ft_memmove(src_memmove8 + 7, src_memmove8, 5);
	printf("\033[94mTest 5-FT-\033[0m %s\t", src_memmove8);

	char src_memmove9[] = "Hello, World!";
	memmove(src_memmove9 + 7, src_memmove9, 5);
	printf("\033[95mTest 5-O-\033[0m %s\n\n", src_memmove9);


//STRLCPY
	printf("\033[107mStrlcpy\033[0m\n");
//1
	char dest_strlcpy[20];
	char *src_strlcpy = "Hello, World";
	printf("\033[94mTest 1-FT-\033[0m %ld ", ft_strlcpy(dest_strlcpy, src_strlcpy, sizeof(dest_strlcpy)));
	printf("%s\t", dest_strlcpy);

	char dest_strlcpy1[20];
	char *src_strlcpy1 = "Hello, World";
	printf("\033[95mTest 1-O-\033[0m %ld ", strlcpy(dest_strlcpy1, src_strlcpy1, sizeof(dest_strlcpy1)));
	printf("%s\n", dest_strlcpy1);

//2
	char dest_strlcpy2[10];
	char *src_strlcpy2 = "This is one long String";
	printf("\033[94mTest 2-FT-\033[0m %ld ", ft_strlcpy(dest_strlcpy2, src_strlcpy2, sizeof(dest_strlcpy2)));
	printf("%s\t\t", dest_strlcpy2);

	char dest_strlcpy3[10];
	char *src_strlcpy3 = "This is one long String";
	printf("\033[95mTest 2-O-\033[0m %ld ", strlcpy(dest_strlcpy3, src_strlcpy3, sizeof(dest_strlcpy3)));
	printf("%s\n\n", dest_strlcpy3);


//STRLCAT
	printf("\033[107mStrlcat\033[0m\n");
//1
	char dest_strlcat[20] = "Hello";
	const char *src_strlcat = ", World";
	printf("\033[94mTest 1-FT-\033[0m %ld ", ft_strlcat(dest_strlcat, src_strlcat, sizeof(dest_strlcat)));
	printf("%s\t", dest_strlcat);

	char dest_strlcat1[20] = "Hello";
	const char *src_strlcat1 = ", World";
	printf("\033[95mTest 1-O-\033[0m %ld ", strlcat(dest_strlcat1, src_strlcat1, sizeof(dest_strlcat1)));
	printf("%s\n", dest_strlcat1);

//2
	char dest_strlcat2[10] = "Hi";
	const char *src_strlcat2 = ", this is a long string";;
	printf("\033[94mTest 2-FT-\033[0m %ld ", ft_strlcat(dest_strlcat2, src_strlcat2, sizeof(dest_strlcat2)));
	printf("%s\t\t", dest_strlcat2);

	char dest_strlcat3[10] = "Hi";
	char *src_strlcat3 = ", this is a long string";;
	printf("\033[95mTest 2-O-\033[0m %ld ", strlcat(dest_strlcat3, src_strlcat3, sizeof(dest_strlcat3)));
	printf("%s\n\n", dest_strlcat3);


//STRCHR
	printf("\033[107mStrchr\033[0m\n");
//1
	printf("\033[94mTest 1-FT-\033[0m %s\t\t", ft_strchr("Good Morning", 'o'));
	printf("\033[95mTest 1-O-\033[0m %s\n", strchr("Good Morning", 'o'));

//2
/* 	printf("\033[94mTest 2-FT-\033[0m %s\t", ft_strchr("Good Morning", 'c'));
	printf("\033[95mTest 2-O-\033[0m %s\n", strchr("Good Morning", 'c'));
	Can not happen because the return will be null
 */
//3
	printf("\033[94mTest 3-FT-\033[0m %s\t\t\t", ft_strchr("Good Morning", '\0'));
	printf("\033[95mTest 3-O-\033[0m %s\n\n", strchr("Good Morning", '\0'));


//STRRCHR
	printf("\033[107mStrrchr\033[0m\n");
//1
	printf("\033[94mTest 1-FT-\033[0m %s\t\t", ft_strrchr("Good Morning", 'o'));
	printf("\033[95mTest 1-O-\033[0m %s\n", strrchr("Good Morning", 'o'));

//2
/* 	printf("\033[94mTest 2-FT-\033[0m %s\t", ft_strchr("Good Morning", 'c'));
	printf("\033[95mTest 2-O-\033[0m %s\n", strchr("Good Morning", 'c'));
	Can not happen because the return will be null
 */

//3
	printf("\033[94mTest 3-FT-\033[0m %s\t\t\t", ft_strrchr("Good Morning", '\0'));
	printf("\033[95mTest 3-O-\033[0m %s\n\n", strrchr("Good Morning", '\0'));


//STRNCMP
	printf("\033[107mStrncmp\033[0m\n");
//1
	char strncmp1[] = "Hi";
	char strncmp2[] = "Hi";
	printf("\033[94mTest 1-FT-\033[0m %d\t\t\t", ft_strncmp(strncmp1, strncmp2, 3));
	printf("\033[95mTest 1-O-\033[0m %d\n", strncmp(strncmp1, strncmp2, 3));

//2
	char strncmp3[] = "Hias";
	char strncmp4[] = "Hib";
	printf("\033[94mTest 2-FT-\033[0m %d\t\t\t", ft_strncmp(strncmp3, strncmp4, 3));
	printf("\033[95mTest 2-O-\033[0m %d\n", strncmp(strncmp3, strncmp4, 3));

//3
	char strncmp5[] = "Hias";
	char strncmp6[] = "Hibs";
	printf("\033[94mTest 3-FT-\033[0m %d\t\t\t", ft_strncmp(strncmp5, strncmp6, 4));
	printf("\033[95mTest 3-O-\033[0m %d\n", strncmp(strncmp5, strncmp6, 4));

//4
	char strncmp7[] = "Hizs";
	char strncmp8[] = "Hias";
	printf("\033[94mTest 4-FT-\033[0m %d\t\t\t", ft_strncmp(strncmp7, strncmp8, 4));
	printf("\033[95mTest 4-O-\033[0m %d\n\n", strncmp(strncmp7, strncmp8, 4));


//MEMCHR
	printf("\033[107mMemchr\033[0m\n");
//1
	printf("\033[94mTest 1-FT-\033[0m %s\t\t", (char *)ft_memchr("Good Morning", 'o', 2));
	printf("\033[95mTest 1-O-\033[0m %s\n", (char*)memchr("Good Morning", 'o', 2));

//2
/* 	printf("\033[94mTest 2-FT-\033[0m %s\t", ft_strchr("Good Morning", 'c'));
	printf("\033[95mTest 2-O-\033[0m %s\n", strchr("Good Morning", 'c'));
	Can not happen because the return will be null
 */

//3
	printf("\033[94mTest 3-FT-\033[0m %s\t\t\t", (char *)ft_memchr("Good Morning", '\0', 20));
	printf("\033[95mTest 3-O-\033[0m %s\n\n", (char *)memchr("Good Morning", '\0', 20));

//4
/* 	printf("\033[94mTest 4-FT-\033[0m %s\t\t\t", (char *)ft_memchr("Good Morning", 'M', 5));
	printf("\033[95mTest 4-O-\033[0m %s\n\n", (char *)memchr("Good Morning", 'M', 5));
	does not allow to compile because the result would be NULL */

//MEMCMP
	printf("\033[107mMemcmp\033[0m\n");
//1
	char memcmp1[] = "Hi";
	char memcmp2[] = "Hi";
	printf("\033[94mTest 1-FT-\033[0m %d\t\t\t", ft_memcmp(memcmp1, memcmp2, 3));
	printf("\033[95mTest 1-O-\033[0m %d\n", memcmp(memcmp1, memcmp2, 3));

//2
	char memcmp3[] = "Hias";
	char memcmp4[] = "Hib";
	printf("\033[94mTest 2-FT-\033[0m %d\t\t\t", ft_memcmp(memcmp3, memcmp4, 3));
	printf("\033[95mTest 2-O-\033[0m %d\n", memcmp(memcmp3, memcmp4, 3));

//3
	char memcmp5[] = "Hias";
	char memcmp6[] = "Hibs";
	printf("\033[94mTest 3-FT-\033[0m %d\t\t\t", ft_memcmp(memcmp5, memcmp6, 4));
	printf("\033[95mTest 3-O-\033[0m %d\n", memcmp(memcmp5, memcmp6, 4));

//4
	char memcmp7[] = "Hizs";
	char memcmp8[] = "Hias";
	printf("\033[94mTest 4-FT-\033[0m %d\t\t\t", ft_memcmp(memcmp7, memcmp8, 4));
	printf("\033[95mTest 4-O-\033[0m %d\n\n", memcmp(memcmp7, memcmp8, 4));


//STRNSTR
	printf("\033[107mStrnstr\033[0m\n");
//1
	printf("\033[94mTest 1-FT-\033[0m %s\t\t\t", ft_strnstr("ola", "la", 3));
	printf("\033[95mTest 1-O-\033[0m %s\n", strnstr("ola", "la", 3));

//2
	printf("\033[94mTest 2-FT-\033[0m %s\t\t\t", ft_strnstr("ola", "ol", 2));
	printf("\033[95mTest 2-O-\033[0m %s\n", strnstr("ola", "ol", 2));

//3
	printf("\033[94mTest 3-FT-\033[0m %s\t\t", ft_strnstr("ola", "l", 1));
	printf("\033[95mTest 3-O-\033[0m %s\n\n", strnstr("ola", "l", 1));

//4
	/* printf("\033[94mTest 1-FT-\033[0m %s\t\t\t", ft_strnstr("ola", '\0', 4));
	printf("\033[95mTest 1-O-\033[0m %s\n", strnstr("ola", '\0', 4));
	not possible because it gets segmentation fault
 */


//ATOI
	printf("\033[107mAtoi\033[0m\n");
//1
	printf("\033[94mTest 1-FT-\033[0m %d\t\t\t", ft_atoi("Yellow"));
	printf("\033[95mTest 1-O-\033[0m %d\n", atoi("Yellow"));

//2
	printf("\033[94mTest 2-FT-\033[0m %d\t\t\t", ft_atoi("Yellow123"));
	printf("\033[95mTest 2-O-\033[0m %d\n", atoi("Yellow123"));

//3
	printf("\033[94mTest 3-FT-\033[0m %d\t\t\t", ft_atoi("321Yellow"));
	printf("\033[95mTest 3-O-\033[0m %d\n", atoi("321Yellow"));

//4
	printf("\033[94mTest 4-FT-\033[0m %d\t\t\t", ft_atoi("ye321llow"));
	printf("\033[95mTest 4-O-\033[0m %d\n", atoi("ye321llow"));

//5
	printf("\033[94mTest 5-FT-\033[0m %d\t\t\t", ft_atoi("ye-521llow"));
	printf("\033[95mTest 5-O-\033[0m %d\n\n", atoi("ye-521llow"));

//CALLOC
	printf("\033[107mCalloc\033[0m\n");
//1
	char	*calloc1 = ft_calloc(5,1);
	char	*calloc2 = calloc(5,1);
	printf("\033[94mTest 1-FT-\033[0m %s\t\t\t", calloc1);
	printf("\033[95mTest 1-O-\033[0m %s\n\n", calloc2);
	free(calloc1);
	free(calloc2);


//STRDUP
	printf("\033[107mStrdup\033[0m\n");
//1
	char	*strdup1 = ft_strdup("Ola");
	char	*strdup2 = strdup("Ola");
	printf("\033[94mTest 1-FT-\033[0m %s\t\t\t", strdup1);
	printf("\033[95mTest 1-O-\033[0m %s\n", strdup2);
	free(strdup1);
	free(strdup2);

//2
	char	*strdup3 = ft_strdup("");
	char	*strdup4 = ft_strdup("");
	printf("\033[94mTest 1-FT-\033[0m %s\t\t\t", strdup3);
	printf("\033[95mTest 1-O-\033[0m %s\n\n", strdup4);
	free(strdup3);
	free(strdup4);


//SUBSTR
	printf("\033[107mSubstr\033[0m\n");
//1
	char	*substr1 = ft_substr("Hello Hugo", 6, 4);
	printf("\033[94mResult\033[0m %s\t\t\t", substr1);
	printf("\033[95mExpected\033[0m Hugo\n");
	free(substr1);

//2
	char	*substr2 = ft_substr("Hello Hugo", 20, 4);
	printf("\033[94mResult\033[0m %s\t\t\t\t", substr2);
	printf("\033[95mExpected\033[0m \n");
	free(substr2);

//3
	char	*substr3 = ft_substr("Hello Hugo", 0, 5);
	printf("\033[94mResult\033[0m %s\t\t\t", substr3);
	printf("\033[95mExpected\033[0m Hello\n");
	free(substr3);

//4
	char	*substr4 = ft_substr("Hello Hugo", 0, 0);
	printf("\033[94mResult\033[0m %s\t\t\t\t", substr4);
	printf("\033[95mExpected\033[0m \n\n");
	free(substr4);


//STRJOIN
	printf("\033[107mStrjoin\033[0m\n");
//1
	char	*strjoin1 = ft_strjoin("Hello ", "Hugo");
	printf("\033[94mResult\033[0m %s\t\t", strjoin1);
	printf("\033[95mExpected\033[0m Hello Hugo\n");
	free(strjoin1);

//3
	char	*strjoin2 = ft_strjoin("Hello", "");
	printf("\033[94mResult\033[0m %s\t\t\t", strjoin2);
	printf("\033[95mExpected\033[0m Hello \n");
	free(strjoin2);

//4
	char	*strjoin3 = ft_strjoin("", "Hugo");
	printf("\033[94mResult\033[0m %s\t\t\t", strjoin3);
	printf("\033[95mExpected\033[0m Hugo \n\n");
	free(strjoin3);


//STRTRIM
	printf("\033[107mStrtrim\033[0m\n");
//1
	char	*strtrim1 = ft_strtrim("Hugo Filipe", "Filipe");
	printf("\033[94mResult\033[0m %s\t\t\t", strtrim1);
	printf("\033[95mExpected\033[0m Hugo \n");
	free(strtrim1);

//2
	char	*strtrim2 = ft_strtrim("Hugo Filipe", " ");
	printf("\033[94mResult\033[0m %s\t\t", strtrim2);
	printf("\033[95mExpected\033[0m Hugo Filipe \n");
	free(strtrim2);

//3
	char	*strtrim3 = ft_strtrim("xxHugox Filxipexx", "x");
	printf("\033[94mResult\033[0m %s\t\t", strtrim3);
	printf("\033[95mExpected\033[0m Hugox Filxipe \n");
	free(strtrim3);


//SPLIT
	printf("\033[107mSplit\033[0m\n");
//1
	char	**split1;
	split1 = ft_split("HotxDogxToday", 'x');
	int i = 0;
	while(split1[i] != NULL)
	{
		printf("\033[94mResult\033[0m %s ", split1[i]);
		free(split1[i++]);
	}
	printf("\033[95mExpected\033[0m Hot Dog Today\n\n");
	free(split1);


//ITOA
	printf("\033[107mItoa\033[0m\n");
//1
	char *itoa1 = ft_itoa(123213);
	printf("\033[94mResult\033[0m %s\t\t\t", itoa1);
	printf("\033[95mExpected\033[0m 123213 \n");
	free(itoa1);

//2
	char *itoa2 = ft_itoa(123213);
	printf("\033[94mResult\033[0m %s\t\t\t", itoa2);
	printf("\033[95mExpected\033[0m -123213 \n");
	free(itoa2);

//3
	char *itoa3 = ft_itoa(123213);
	printf("\033[94mResult\033[0m %s\t\t\t", itoa3);
	printf("\033[95mExpected\033[0m 123213 \n\n");
	free(itoa3);


//STRMAPI
	printf("\033[107mStmapi\033[0m\n");
//1
	char mapi1[10]= "blue";
	char *mapi2;
	mapi2 = ft_strmapi(mapi1, touppermapi);
	printf("\033[94mResult\033[0m %s\t\t\t", mapi2);
	printf("\033[95mExpected\033[0m BLUE \n\n");
	free(mapi2);

//STRITERI
	printf("\033[107mStriteri\033[0m\n");
//1
	char iteri1[10]= "blue";
	ft_striteri(iteri1, touperit);
	printf("\033[94mResult\033[0m %s\t\t\t", iteri1);
	printf("\033[95mExpected\033[0m BLUE \n\n");


//LSTNEW
	printf("\033[107mLstnew\033[0m\n");
//1
	int value = 42; 
    t_list *node = ft_lstnew(&value); 
    printf("Node created successfully!\n");
    printf("\033[94mContent:\033[0m %d\n", *(int *)(node->content));
    printf("\033[94mNext:\033[0m %p\n", node->next); 
    free(node);
	puts("");


//LSTADDFRONT
	printf("\033[107mLstadd_front\033[0m\n");
//1
	t_list *head = NULL;
	ft_lstadd_front(&head, ft_lstnew(strdup("First Node")));
    ft_lstadd_front(&head, ft_lstnew(strdup("Second Node")));
	t_list *current = head;
    while (current) 
	{
        printf("\033[94mNode content:\033[0m %s\n", (char *)current->content);
        current = current->next; 
    }
	puts("");


//LSTSIZE
	printf("\033[107mLstsize\033[0m\n");
//1
	
	int size = ft_lstsize(head);
    printf("\033[94mThe size of the list is:\033[0m %d\n", size);
	puts("");


//LSTLAST
	printf("\033[107mLstlast\033[0m\n");
//1
	t_list *last_node = ft_lstlast(head);
	printf("\033[94mThe last node's content is:\033[0m %s\n", (char *)last_node->content);
	puts("");


//LSTADDBACK
	printf("\033[107mLstadd_back\033[0m\n");
//1	
	ft_lstadd_back(&head, ft_lstnew(strdup("Third Node")));
	t_list *last_node1 = ft_lstlast(head);
	printf("\033[94mThe last node's content is:\033[0m %s\n", (char *)last_node1->content);
	puts("");


//LSTITER
	printf("\033[107mLstiter\033[0m\n");
//1	
	ft_lstiter(head, print_content);
	puts("");


//LSTCLEAR
	printf("\033[107mLstclear\033[0m\n");
//1	
	int size2 = ft_lstsize(head);
	printf("\033[94mThe size of the list is:\033[0m %d\n", size2);
	if (head) 
	{
		ft_lstclear(&head, del);
		printf("List cleared successfully.\n");
	} 
	else 
		printf("List is empty.\n");
	puts("");


//LSTMAP
	printf("\033[107mLstmap\033[0m\n");
//1	
	t_list *head2 = NULL;
	t_list *head3;
	ft_lstadd_front(&head2, ft_lstnew(strdup("First Node")));
    ft_lstadd_front(&head2, ft_lstnew(strdup("Second Node")));
	printf("\033[94mContent of head3: \033[0m");
	head3 = ft_lstmap(head2, print_content2, del);
	ft_lstiter(head3, print_content);
	puts("");


//LSTDELONE	
//1	
	printf("\033[107mLsdelone\033[0m\n");
	t_list *node_to_delete = head3->next;
	ft_lstdelone(node_to_delete, del);
	head3->next = NULL;
	printf("\033[94mHead3 content After delone: \033[0m");
	ft_lstiter(head3, print_content);
	ft_lstclear(&head2, del);
	ft_lstclear(&head3, del);
	puts("");


if (getenv("RUNNING_UNDER_VALGRIND") == NULL) 
	{
        setenv("RUNNING_UNDER_VALGRIND", "1", 1);
        system("valgrind --leak-check=full \
		--track-origins=yes \
		--show-leak-kinds=all \
		--errors-for-leak-kinds=all \
		--show-possibly-lost=yes \
		--track-fds=yes ./main");
    }
}	