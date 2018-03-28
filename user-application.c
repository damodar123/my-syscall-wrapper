#include <unistd.h>
#include <fcntl.h>
 
int main(void)
{
    int fd = open("testfile.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
 
    if (fd < 0) {
        return -1;
    }
 
    if (write(fd, "Hello world\n", 12) != 12) {
        write(2, "error writing to testfile.txt\n", 30);
        return -1;
    }
 
    return 0;
}
