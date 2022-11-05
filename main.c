#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd;
    char    *line;

    fd = open("text.txt", O_RDWR);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    // printf("\n|%s|", get_next_line(fd));
    // printf("\n|%s|", get_next_line(fd));
    // printf("\n|%s|", get_next_line(fd));
    return (0);
}