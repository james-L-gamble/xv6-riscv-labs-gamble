#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

int main(int argc, char **argv)
{
    struct pstat uproc[NPROC];
    int nprocs;
    int i;
    char *state;
    static char *states[] = {
        [SLEEPING] "sleeping",
        [RUNNABLE] "runnable",
        [RUNNING] "running ",
        [ZOMBIE] "zombie  "};

    nprocs = getprocs(uproc);
    if (nprocs < 0)
        exit(-1);

    int age;

    printf("pid\tstate\t\tsize\tppid\tname\tpriority\tage\n");
    for (i = 0; i < nprocs; i++)
    {
        age = uptime() - uproc[i].readytime;
        state = states[uproc[i].state];
        printf("%d\t%s\t%l\t%d\t%s\t%d\t%d\n", uproc[i].pid, state,
               uproc[i].size, uproc[i].ppid, uproc[i].name, uproc[i].priority, age);
    }

    exit(0);
}
