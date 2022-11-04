#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd;
    char    *line;

    fd = open("text.txt", O_RDWR);
    line = get_next_line(fd);
    printf("%s\n",line);
    free(line);
    return (0);
}