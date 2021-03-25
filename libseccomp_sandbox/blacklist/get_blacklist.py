import os.path
import subprocess

get_syscalls_command = "cat /usr/include/asm-generic/unistd.h | grep -oP \"(?<=__NR_)[^,]*(?= )\""
get_syscalls_subprocess = subprocess.Popen(get_syscalls_command, shell=True, stdout=subprocess.PIPE)
syscalls = get_syscalls_subprocess.stdout.read()

#os.system("strace ./good -f -o strace_good.txt")

get_approved_syscalls_command = "cat strace_good.txt | grep -oP \"(?<=)[[:alpha:]]*(?=\()\""
get_approved_syscalls_subprocess = subprocess.Popen(get_approved_syscalls_command, shell=True, stdout=subprocess.PIPE)
approved_syscalls = get_approved_syscalls_subprocess.stdout.read()

"""
print("\n****** syscalls: ******")
print(syscalls)
print("\n****** approved_syscalls: ******")
print(approved_syscalls)
"""
counter = 0

with open("blacklist.txt", "w") as blacklist:
    for syscall in syscalls.splitlines():
        if counter % 50 == 0:
            blacklist.write("//" + str(counter/50 + 1) + "\n")
        if syscall in approved_syscalls:
            blacklist.write("    //add_rule(seccomp_ctx, \""+ syscall.strip() + "\");\n")
        else:
            blacklist.write("    add_rule(seccomp_ctx, \""+ syscall.strip() + "\");\n")
        counter += 1

#os.system("cat blacklist.txt")





