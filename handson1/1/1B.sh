#
#============================================================================
#Name : 1b.sh
#Author : Sameer
#Description : 1. Create the following types of a files using (i) shell command (ii) system call
#a. soft link (symlink system call)
#b. hard link (link system call)
#c. FIFO (mkfifo Library Function or mknod system call)
#Date: 28th Aug, 2025.
#============================================================================


echo "Hello World" > hardlinkshell.txt

ln hardlinkshell.txt hardlinkshell

ls -l hardlinkshell.txt hardlinkshell

#Output
#sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$ chmod +x 1B.sh
#sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$ ./1B.sh
#-rw-rw-r-- 2 sameer sameer 12 Sep  7 18:06 hardlinkshell
#-rw-rw-r-- 2 sameer sameer 12 Sep  7 18:06 hardlinkshell.txt


