#
#============================================================================
#Name : 1A.sh
#Author : Sameer
#Description : 1. Create the following types of a files using (i) shell command (ii) system call
#a. soft link (symlink system call)
#b. hard link (link system call)
#c. FIFO (mkfifo Library Function or mknod system call)
#Date: 28th Aug, 2025.
#============================================================================


echo "Hello World" > softlinkshell.txt

ln -s softlinkshell.txt softlinkshell

ls -l softlinkshell.txt softlinkshell

#Output
#sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$ ./1A.sh
#lrwxrwxrwx 1 sameer sameer 17 Sep  7 18:00 softlinkshell -> softlinkshell.txt
#-rw-rw-r-- 1 sameer sameer 12 Sep  7 18:00 softlinkshell.txt

