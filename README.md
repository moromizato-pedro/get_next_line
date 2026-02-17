_This project has been created as part of the 42 curriculum by pedrohe3_

# Description
Get_new_line is a project with the objective of teaching about static variables through the implementation of a program that given a file descriptor it will return the next line from it, being possible to execute the function more than once to retrieve the consecutive lines.

# Instructions
To be able to compile and execute the program some steps are needed.
- Including the necessary libraries
- Compilation
- Run the program

### Including the necessary libraries
The only library necessary in your source code is the "get_next_line.h" and just add the line bellow in the source file to include it:

    #include "get_next_line.h"

If no source code is already prepared, the code bellow is an example that can be used to test the get_next_line function for any text file. For the matter of this guide we will refer to "main.c" as the source code that uses the get_next_line function:
```
#include "get_next_line.h"

# This is an auxiliary function to allow you to see if a '\n' or '\0' is present in your string
void	ft_putstr(char *buff)
{
	int	i;

	i = 0;
	if (!buff)
	{
		printf("(null)\n");
		return ;
	}
	printf("\"");
	while(1)
	{
		if (buff[i] == '\n')
			printf("\\n");
		else if (buff[i] == '\0')
		{
			printf("\\0");
			break ;
		}
		else
			printf("%c", buff[i]);
		i++;
	}
	printf("\"\n");
}

int	main(void)
{
	# Opens the file in Read Only mode, in order to read it.
	# Substitute 'test' for your testing text file
	int		fd = open("PUT_YOUR_PATH_HERE/get_next_line/test", O_RDONLY);
	char	*res;
	int		depth = 0;
	
	# Will try to read the next 11 lines
	while (depth < 11)
	{
		# Resets the res pointer
		res = NULL;
		printf("\n\nCalling get_next_line - depth (%d)\n", depth);
		res = get_next_line(fd);
		if (!res)
		{
			printf("End of program\n");
			break;
		}
		# Prints the line returned and its size
		printf("len: %d | res: ", ft_strlen(res));
		ft_putstr(res);
		depth++;
	} 
	close(fd);
	return (0);
}
```

### Compilation and Linking
To build the executable from the source code, you need the following command:

    cc -Wall -Werror -Wextra main.c -o test

The command above temporary creates the compiled object from "main.c" to produce the final executable named "test". All of that can be viewed in smaller fragments:
- The `-Wall -Werror -Wextra` are some flags that 42 requires to compile a source file. They ensure to explicit block the compilation and tell the user if something in the code might cause a problem if it is compiled as it is.
- The `cc main.c` compiles the source code (creates an object file, the .o, for the main.c)
    - The object file is the source code transformed to machine code, which is the only language that the computer understands, and copy it into the executable that will be created.
- The `-o test` flag indicates that we want to choose the word after the flag to be name of the executable created.
    - This executable will be a standalone binary, that means a file that contains all the machine code necessary to work properly


### Run the program
Finally, after the executable is created, you just need to run the command bellow using the name chosen for the executable:
    `./test`

# Resources
- www.opengroup.org
- AI was used to help understanding how to attack and search for potential reasons for the leaks. It was also used to make the code cleaner, direct and shorter, helping to refactor the code to reduce the amount of lines and remove redundant code.

# Algorithm
- The decision to use static variables was based in the indication made by the project guidelines. It allowed to keep track of the buffer used even in between different calls of the get_next_line function, and was a key aspect for the completion of the project.
- The use of while loops was chosen to guarantee that new reads were made everytime the end of the buffer was reached and the end of line was not reached yet, it was also used to iterate through the buffer while looking for the end of the buffer ('\0') or for the end of line ('\n') markers.
