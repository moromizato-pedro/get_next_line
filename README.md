This project has been created as part of the 42 curriculum by pedrohe3

# Description
Get_new_line is a project with the objective of teaching about static variables through the implementation of a program that given a file descriptor it will return only one line from it, being possible to execute the function more than once to retrieve the consecutive lines.

# Instructions
This project only contains 2 programs and one header.

In order to be able to call the get_next_line function the header must be included in file where the main function will be located.

Secondly, to compile correctly it is needed to have all of the files at the same directory as the file containing the main, compile all the .c files get_next_line.c get_next_line_utils.c, as the example bellow, and finally execute the program.
Example: cc <main_file.c> get_next_line.c get_next_line_utils.c

# Resources
- www.opengroup.org
- AI was used to help understanding how to attack and search for potential reasons for the leaks. It was also used to make the code cleaner, direct and shorter, helping to refactor the code to reduce the amount of lines and remove redundant code.

# Algorithm
- The decision to use static variables was based in the indication made by the project guidelines. It allowed to keep track of the buffer used even in between different calls of the get_next_line function, and was a key aspect for the completion of the project.
- The use of while loops was chosen to guarantee that new reads were made everytime the end of the buffer was reached and the end of line was not reached yet, it was also used to iterate through the buffer while looking for the end of the buffer ('\0') or for the end of line ('\n') markers.
