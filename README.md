# ICS612 Operating Systems Project 1
Authors: Kjetil Vaagen and Oda Kiese

## Notes
This shell is able to execute commands, redirect the standard input or standard output of commands to files, pipe the output of commands to other commands, and put commands in the background. The shell also prints a prompt when it is ready to accept commands. The shell also terminates when "exit" is typed in.

## Issues
We did not fully implement nested special characters. The shell crashes when special characters are grouped together in the same commandline. For instance:
(not working) cat > test.txt < result.txt | wc -l
(working) cat test.txt | wc -l
