#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <seccomp.h>
#include <err.h>

void add_rule(scmp_filter_ctx seccomp_ctx, char * name)
{
    if (seccomp_rule_add_exact(seccomp_ctx, SCMP_ACT_KILL_PROCESS, seccomp_syscall_resolve_name(name), 0)) 
    {
        perror("seccomp_rule_add_exact failed");
        exit(1);
    }
}

void add_blacklist(scmp_filter_ctx seccomp_ctx)
{    
//1
    add_rule(seccomp_ctx, "io_setup");
    add_rule(seccomp_ctx, "io_destroy");
    add_rule(seccomp_ctx, "io_submit");
    add_rule(seccomp_ctx, "io_cancel");
    add_rule(seccomp_ctx, "io_getevents");
    add_rule(seccomp_ctx, "setxattr");
    add_rule(seccomp_ctx, "lsetxattr");
    add_rule(seccomp_ctx, "fsetxattr");
    add_rule(seccomp_ctx, "getxattr");
    add_rule(seccomp_ctx, "lgetxattr");
    add_rule(seccomp_ctx, "fgetxattr");
    add_rule(seccomp_ctx, "listxattr");
    add_rule(seccomp_ctx, "llistxattr");
    add_rule(seccomp_ctx, "flistxattr");
    add_rule(seccomp_ctx, "removexattr");
    add_rule(seccomp_ctx, "lremovexattr");
    add_rule(seccomp_ctx, "fremovexattr");
    add_rule(seccomp_ctx, "getcwd");
    add_rule(seccomp_ctx, "lookup_dcookie");
    add_rule(seccomp_ctx, "eventfd2");
    add_rule(seccomp_ctx, "epoll_create1");
    add_rule(seccomp_ctx, "epoll_ctl");
    add_rule(seccomp_ctx, "epoll_pwait");
    add_rule(seccomp_ctx, "dup");
    add_rule(seccomp_ctx, "dup3");
    add_rule(seccomp_ctx, "inotify_init1");
    add_rule(seccomp_ctx, "inotify_add_watch");
    add_rule(seccomp_ctx, "inotify_rm_watch");
    //!!!add_rule(seccomp_ctx, "ioctl");
    add_rule(seccomp_ctx, "ioprio_set");
    add_rule(seccomp_ctx, "ioprio_get");
    add_rule(seccomp_ctx, "flock");    
    add_rule(seccomp_ctx, "mknodat");
    add_rule(seccomp_ctx, "mkdirat");
    //!!!add_rule(seccomp_ctx, "unlinkat");
    add_rule(seccomp_ctx, "symlinkat");
    add_rule(seccomp_ctx, "linkat");
    add_rule(seccomp_ctx, "renameat");
    add_rule(seccomp_ctx, "umount2");
    add_rule(seccomp_ctx, "mount");
    add_rule(seccomp_ctx, "pivot_root");
    add_rule(seccomp_ctx, "nfsservctl");
    add_rule(seccomp_ctx, "fallocate");
    //!!!add_rule(seccomp_ctx, "faccessat");
    add_rule(seccomp_ctx, "chdir");
    add_rule(seccomp_ctx, "fchdir");
    add_rule(seccomp_ctx, "chroot");
    add_rule(seccomp_ctx, "fchmod");
    add_rule(seccomp_ctx, "fchmodat");
    add_rule(seccomp_ctx, "fchownat");
//2
    add_rule(seccomp_ctx, "fchown");
    //add_rule(seccomp_ctx, "openat");
    //add_rule(seccomp_ctx, "close");
    add_rule(seccomp_ctx, "vhangup");
    add_rule(seccomp_ctx, "pipe2");
    add_rule(seccomp_ctx, "quotactl");
    add_rule(seccomp_ctx, "getdents64");
    //add_rule(seccomp_ctx, "read");
    //add_rule(seccomp_ctx, "write");
    //!!!add_rule(seccomp_ctx, "readv");
    //!!!add_rule(seccomp_ctx, "writev");
    //!!!add_rule(seccomp_ctx, "pread64");
    //!!!add_rule(seccomp_ctx, "pwrite64");
    //!!!add_rule(seccomp_ctx, "preadv");
    //!!!add_rule(seccomp_ctx, "pwritev");
    add_rule(seccomp_ctx, "pselect6");
    add_rule(seccomp_ctx, "ppoll");
    add_rule(seccomp_ctx, "signalfd4");
    add_rule(seccomp_ctx, "vmsplice");
    add_rule(seccomp_ctx, "splice");
    add_rule(seccomp_ctx, "tee");
    add_rule(seccomp_ctx, "readlinkat");
    add_rule(seccomp_ctx, "sync");
    add_rule(seccomp_ctx, "fsync");
    add_rule(seccomp_ctx, "fdatasync");
    //!!!add_rule(seccomp_ctx, "sync_file_range2");
    //!!!add_rule(seccomp_ctx, "sync_file_range");
    add_rule(seccomp_ctx, "timerfd_create");
    add_rule(seccomp_ctx, "timerfd_settime");
    add_rule(seccomp_ctx, "timerfd_gettime");
    //!!!add_rule(seccomp_ctx, "utimensat");
    add_rule(seccomp_ctx, "acct");
    add_rule(seccomp_ctx, "capget");
    add_rule(seccomp_ctx, "capset");
    add_rule(seccomp_ctx, "personality");
    //!!!add_rule(seccomp_ctx, "exit");
    //!!!add_rule(seccomp_ctx, "exit_group");
    add_rule(seccomp_ctx, "waitid");
    add_rule(seccomp_ctx, "set_tid_address");
    add_rule(seccomp_ctx, "unshare");
    add_rule(seccomp_ctx, "futex");
    add_rule(seccomp_ctx, "set_robust_list");
    add_rule(seccomp_ctx, "get_robust_list");
    add_rule(seccomp_ctx, "nanosleep");
    add_rule(seccomp_ctx, "getitimer");
    add_rule(seccomp_ctx, "setitimer");
    add_rule(seccomp_ctx, "kexec_load");
    add_rule(seccomp_ctx, "init_module");
    add_rule(seccomp_ctx, "delete_module");
    add_rule(seccomp_ctx, "timer_create");
//3
    add_rule(seccomp_ctx, "timer_gettime");
    add_rule(seccomp_ctx, "timer_getoverrun");
    add_rule(seccomp_ctx, "timer_settime");
    add_rule(seccomp_ctx, "timer_delete");
    add_rule(seccomp_ctx, "clock_settime");
    add_rule(seccomp_ctx, "clock_gettime");
    add_rule(seccomp_ctx, "clock_getres");
    add_rule(seccomp_ctx, "clock_nanosleep");
    add_rule(seccomp_ctx, "syslog");
    add_rule(seccomp_ctx, "ptrace");
    add_rule(seccomp_ctx, "sched_setparam");
    add_rule(seccomp_ctx, "sched_setscheduler");
    add_rule(seccomp_ctx, "sched_getscheduler");
    add_rule(seccomp_ctx, "sched_getparam");
    add_rule(seccomp_ctx, "sched_setaffinity");
    add_rule(seccomp_ctx, "sched_getaffinity");
    add_rule(seccomp_ctx, "sched_yield");
    add_rule(seccomp_ctx, "sched_get_priority_max");
    add_rule(seccomp_ctx, "sched_get_priority_min");
    add_rule(seccomp_ctx, "sched_rr_get_interval");
    add_rule(seccomp_ctx, "restart_syscall");
    add_rule(seccomp_ctx, "kill");
    add_rule(seccomp_ctx, "tkill");
    add_rule(seccomp_ctx, "tgkill");
    add_rule(seccomp_ctx, "sigaltstack");
    //!!!add_rule(seccomp_ctx, "rt_sigsuspend");
    //!!!add_rule(seccomp_ctx, "rt_sigaction");
    //!!!add_rule(seccomp_ctx, "rt_sigprocmask");
    //!!!add_rule(seccomp_ctx, "rt_sigpending");
    //!!!add_rule(seccomp_ctx, "rt_sigtimedwait");
    //!!!add_rule(seccomp_ctx, "rt_sigqueueinfo");
    //!!!add_rule(seccomp_ctx, "rt_sigreturn");
    add_rule(seccomp_ctx, "setpriority");
    add_rule(seccomp_ctx, "getpriority");
    add_rule(seccomp_ctx, "reboot");
    add_rule(seccomp_ctx, "setregid");
    add_rule(seccomp_ctx, "setgid");
    add_rule(seccomp_ctx, "setreuid");
    add_rule(seccomp_ctx, "setuid");
    add_rule(seccomp_ctx, "setresuid");
    add_rule(seccomp_ctx, "getresuid");
    add_rule(seccomp_ctx, "setresgid");
    add_rule(seccomp_ctx, "getresgid");
    add_rule(seccomp_ctx, "setfsuid");
    add_rule(seccomp_ctx, "setfsgid");
    add_rule(seccomp_ctx, "times");
    add_rule(seccomp_ctx, "setpgid");
    add_rule(seccomp_ctx, "getpgid");
    add_rule(seccomp_ctx, "getsid");
    add_rule(seccomp_ctx, "setsid");
//4
    add_rule(seccomp_ctx, "getgroups");
    add_rule(seccomp_ctx, "setgroups");
    add_rule(seccomp_ctx, "uname");
    add_rule(seccomp_ctx, "sethostname");
    add_rule(seccomp_ctx, "setdomainname");
    add_rule(seccomp_ctx, "getrlimit");
    add_rule(seccomp_ctx, "setrlimit");
    add_rule(seccomp_ctx, "getrusage");
    add_rule(seccomp_ctx, "umask");
    //add_rule(seccomp_ctx, "prctl");
    add_rule(seccomp_ctx, "getcpu");
    add_rule(seccomp_ctx, "gettimeofday");
    add_rule(seccomp_ctx, "settimeofday");
    add_rule(seccomp_ctx, "adjtimex");
    //!!!add_rule(seccomp_ctx, "getpid");
    //!!!add_rule(seccomp_ctx, "getppid");
    //!!!add_rule(seccomp_ctx, "getuid");
    //!!!add_rule(seccomp_ctx, "geteuid");
    //!!!add_rule(seccomp_ctx, "getgid");
    //!!!add_rule(seccomp_ctx, "getegid");
    //!!!add_rule(seccomp_ctx, "gettid");
    add_rule(seccomp_ctx, "sysinfo");
    add_rule(seccomp_ctx, "mq_open");
    add_rule(seccomp_ctx, "mq_unlink");
    add_rule(seccomp_ctx, "mq_timedsend");
    add_rule(seccomp_ctx, "mq_timedreceive");
    add_rule(seccomp_ctx, "mq_notify");
    add_rule(seccomp_ctx, "mq_getsetattr");
    add_rule(seccomp_ctx, "msgget");
    add_rule(seccomp_ctx, "msgctl");
    add_rule(seccomp_ctx, "msgrcv");
    add_rule(seccomp_ctx, "msgsnd");
    add_rule(seccomp_ctx, "semget");
    add_rule(seccomp_ctx, "semctl");
    add_rule(seccomp_ctx, "semtimedop");
    add_rule(seccomp_ctx, "semop");
    add_rule(seccomp_ctx, "shmget");
    add_rule(seccomp_ctx, "shmctl");
    add_rule(seccomp_ctx, "shmat");
    add_rule(seccomp_ctx, "shmdt");
    add_rule(seccomp_ctx, "socket");
    add_rule(seccomp_ctx, "socketpair");
    add_rule(seccomp_ctx, "bind");
    add_rule(seccomp_ctx, "listen");
    add_rule(seccomp_ctx, "accept");
    add_rule(seccomp_ctx, "connect");
    add_rule(seccomp_ctx, "getsockname");
    add_rule(seccomp_ctx, "getpeername");
    add_rule(seccomp_ctx, "sendto");
    add_rule(seccomp_ctx, "recvfrom");
    add_rule(seccomp_ctx, "getresuid");
    add_rule(seccomp_ctx, "setresgid");
//5
    add_rule(seccomp_ctx, "setsockopt");
    add_rule(seccomp_ctx, "getsockopt");
    add_rule(seccomp_ctx, "shutdown");
    add_rule(seccomp_ctx, "sendmsg");
    add_rule(seccomp_ctx, "recvmsg");
    add_rule(seccomp_ctx, "readahead");
    //add_rule(seccomp_ctx, "brk");
    //add_rule(seccomp_ctx, "munmap");
    add_rule(seccomp_ctx, "mremap");
    add_rule(seccomp_ctx, "add_key");
    add_rule(seccomp_ctx, "request_key");
    add_rule(seccomp_ctx, "keyctl");
    //add_rule(seccomp_ctx, "clone");
    //add_rule(seccomp_ctx, "execve");
    add_rule(seccomp_ctx, "swapon");
    add_rule(seccomp_ctx, "swapoff");
    //add_rule(seccomp_ctx, "mprotect");
    add_rule(seccomp_ctx, "msync");
    add_rule(seccomp_ctx, "mlock");
    add_rule(seccomp_ctx, "munlock");
    add_rule(seccomp_ctx, "mlockall");
    add_rule(seccomp_ctx, "munlockall");
    add_rule(seccomp_ctx, "mincore");
    add_rule(seccomp_ctx, "madvise");
    add_rule(seccomp_ctx, "remap_file_pages");
    add_rule(seccomp_ctx, "mbind");
    add_rule(seccomp_ctx, "get_mempolicy");
    add_rule(seccomp_ctx, "set_mempolicy");
    add_rule(seccomp_ctx, "migrate_pages");
    add_rule(seccomp_ctx, "move_pages");
    add_rule(seccomp_ctx, "rt_tgsigqueueinfo");
    add_rule(seccomp_ctx, "perf_event_open");
    add_rule(seccomp_ctx, "accept4");
    add_rule(seccomp_ctx, "recvmmsg");
    //!!!add_rule(seccomp_ctx, "arch_specific_syscall");
    //add_rule(seccomp_ctx, "wait4");
    add_rule(seccomp_ctx, "prlimit64");
    add_rule(seccomp_ctx, "fanotify_init");
    add_rule(seccomp_ctx, "fanotify_mark");
    add_rule(seccomp_ctx, "name_to_handle_at");
    add_rule(seccomp_ctx, "open_by_handle_at");
    add_rule(seccomp_ctx, "clock_adjtime");
    add_rule(seccomp_ctx, "syncfs");
    add_rule(seccomp_ctx, "setns");
    add_rule(seccomp_ctx, "sendmmsg");
    add_rule(seccomp_ctx, "process_vm_readv");
    add_rule(seccomp_ctx, "process_vm_writev");
    add_rule(seccomp_ctx, "kcmp");
    add_rule(seccomp_ctx, "finit_module");
    add_rule(seccomp_ctx, "sched_setattr");
//6
    add_rule(seccomp_ctx, "sched_getattr");
    add_rule(seccomp_ctx, "renameat2");
    add_rule(seccomp_ctx, "seccomp");
    add_rule(seccomp_ctx, "getrandom");
    add_rule(seccomp_ctx, "memfd_create");
    add_rule(seccomp_ctx, "bpf");
    add_rule(seccomp_ctx, "execveat");
    add_rule(seccomp_ctx, "userfaultfd");
    add_rule(seccomp_ctx, "membarrier");
    add_rule(seccomp_ctx, "mlock2");
    add_rule(seccomp_ctx, "copy_file_range");
    add_rule(seccomp_ctx, "preadv2");
    add_rule(seccomp_ctx, "pwritev2");
    add_rule(seccomp_ctx, "pkey_mprotect");
    add_rule(seccomp_ctx, "pkey_alloc");
    add_rule(seccomp_ctx, "pkey_free");
    add_rule(seccomp_ctx, "statx");
    //!!!add_rule(seccomp_ctx, "syscalls");
    //add_rule(seccomp_ctx, "open");
    add_rule(seccomp_ctx, "link");
    add_rule(seccomp_ctx, "unlink");
    add_rule(seccomp_ctx, "mknod");
    add_rule(seccomp_ctx, "chmod");
    add_rule(seccomp_ctx, "chown");
    add_rule(seccomp_ctx, "mkdir");
    add_rule(seccomp_ctx, "rmdir");
    add_rule(seccomp_ctx, "lchown");
    //add_rule(seccomp_ctx, "access");
    //!!!add_rule(seccomp_ctx, "rename");
    add_rule(seccomp_ctx, "readlink");
    add_rule(seccomp_ctx, "symlink");
    add_rule(seccomp_ctx, "utimes");
    //!!!add_rule(seccomp_ctx, "syscalls");
    add_rule(seccomp_ctx, "pipe");
    //!!!add_rule(seccomp_ctx, "dup2");
    add_rule(seccomp_ctx, "epoll_create");
    add_rule(seccomp_ctx, "inotify_init");
    add_rule(seccomp_ctx, "eventfd");
    add_rule(seccomp_ctx, "signalfd");
    //!!!add_rule(seccomp_ctx, "syscalls");
    add_rule(seccomp_ctx, "sendfile");
    add_rule(seccomp_ctx, "ftruncate");
    add_rule(seccomp_ctx, "truncate");
    //add_rule(seccomp_ctx, "stat");
    add_rule(seccomp_ctx, "lstat");
    //add_rule(seccomp_ctx, "fstat");
    add_rule(seccomp_ctx, "fcntl");
    add_rule(seccomp_ctx, "fadvise64");
    //!!!add_rule(seccomp_ctx, "newfstatat");
    add_rule(seccomp_ctx, "fstatfs");
//7
    add_rule(seccomp_ctx, "statfs");
    //!!!add_rule(seccomp_ctx, "lseek");
    //add_rule(seccomp_ctx, "mmap");
    //!!!add_rule(seccomp_ctx, "syscalls");
    add_rule(seccomp_ctx, "alarm");
    add_rule(seccomp_ctx, "getpgrp");
    add_rule(seccomp_ctx, "pause");
    add_rule(seccomp_ctx, "time");
    add_rule(seccomp_ctx, "utime");
    add_rule(seccomp_ctx, "creat");
    add_rule(seccomp_ctx, "getdents");
    add_rule(seccomp_ctx, "futimesat");
    add_rule(seccomp_ctx, "select");
    add_rule(seccomp_ctx, "poll");
    add_rule(seccomp_ctx, "epoll_wait");
    add_rule(seccomp_ctx, "ustat");
    add_rule(seccomp_ctx, "vfork");
    //!!!add_rule(seccomp_ctx, "oldwait4");
    //!!!add_rule(seccomp_ctx, "recv");
    //!!!add_rule(seccomp_ctx, "send");
    //!!!add_rule(seccomp_ctx, "bdflush");
    //!!!add_rule(seccomp_ctx, "umount");
    add_rule(seccomp_ctx, "uselib");
    add_rule(seccomp_ctx, "_sysctl");
    add_rule(seccomp_ctx, "fork");
    //!!!add_rule(seccomp_ctx, "syscalls");
    add_rule(seccomp_ctx, "fcntl");
    add_rule(seccomp_ctx, "statfs");
    add_rule(seccomp_ctx, "fstatfs");
    add_rule(seccomp_ctx, "truncate");
    add_rule(seccomp_ctx, "ftruncate");
    //!!!add_rule(seccomp_ctx, "lseek");
    add_rule(seccomp_ctx, "sendfile");
    //!!!add_rule(seccomp_ctx, "newfstatat");
    //add_rule(seccomp_ctx, "fstat");
    //add_rule(seccomp_ctx, "mmap");
    add_rule(seccomp_ctx, "fadvise64");
    //add_rule(seccomp_ctx, "stat");
    add_rule(seccomp_ctx, "lstat");
    //!!!add_rule(seccomp_ctx, "fcntl64");
    //!!!add_rule(seccomp_ctx, "statfs64");
    //!!!add_rule(seccomp_ctx, "fstatfs64");
    //!!!add_rule(seccomp_ctx, "truncate64");
    //!!!add_rule(seccomp_ctx, "ftruncate64");
    //!!!add_rule(seccomp_ctx, "llseek");
    //!!!add_rule(seccomp_ctx, "sendfile64");
    //!!!add_rule(seccomp_ctx, "fstatat64");
    //!!!add_rule(seccomp_ctx, "fstat64");
    //!!!add_rule(seccomp_ctx, "mmap2");
    //!!!add_rule(seccomp_ctx, "fadvise64_64");
//8
    //!!!add_rule(seccomp_ctx, "stat64");
    //!!!add_rule(seccomp_ctx, "lstat64");

}

static void sandbox(void)
{
    /* allow all syscalls by default */
    scmp_filter_ctx seccomp_ctx = seccomp_init(SCMP_ACT_ALLOW);
    if (!seccomp_ctx)
    {
        err(1, "seccomp_init failed");
    }

    add_blacklist(seccomp_ctx);

    /* apply the composed filter */
    if (seccomp_load(seccomp_ctx)) {
        perror("seccomp_load failed");
        exit(1);
    }

    /* release allocated context */
    seccomp_release(seccomp_ctx);
}

int main(void)
{
    sandbox();
    system("./exec");

    return 0;
}
