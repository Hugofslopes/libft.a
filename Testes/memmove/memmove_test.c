#include <stdio.h>

#include <string.h> // For comparison with standard memmove


void *ft_memmove(void *dst, const void *src, size_t len);


int main() {

    char source[] = "Hello, World!";

    char destination[20]; // Ensure this is large enough to hold the result


    // Test ft_memmove

    printf("Source before ft_memmove: %s\n", source);

    

    // Case 1: Non-overlapping regions

    ft_memmove(destination, source, 13); // Move the entire string

    printf("Destination after ft_memmove (non-overlapping): %s\n", destination);


    // Case 2: Overlapping regions (src before dst)

    char overlap_src[] = "1234567890";

    printf("Overlap source before ft_memmove: %s\n", overlap_src);

    ft_memmove(overlap_src + 2, overlap_src, 8); // Move part of the string within the same array

    printf("Overlap source after ft_memmove: %s\n", overlap_src);


    // Case 3: Overlapping regions (dst before src)

    char overlap_dst[] = "ABCDEFGHIJ";

    printf("Overlap destination before ft_memmove: %s\n", overlap_dst);

    ft_memmove(overlap_dst, overlap_dst + 2, 8); // Move part of the string within the same array

    printf("Overlap destination after ft_memmove: %s\n", overlap_dst);


    return 0;

}