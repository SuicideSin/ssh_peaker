SSH session peaker (really just a formatter for strace).

Usage:
	strace -e write -p SSHPID 2>&1|./ssh_peaker
