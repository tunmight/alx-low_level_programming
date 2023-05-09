#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename:  A pointer to the name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
int des, res, i;

if (filename == NULL)
return (-1);

des = open(filename, O_WRONLY | O_APPEND);
if (des == -1)
return (-1);

if (text_content != NULL)
{
for (i = 0; text_content[i] != '\0'; i++)
;
res = write(des, text_content, i);
if (res == -1)
{
close(des);
return (-1);
}
}

close(des);
return (1);
}
