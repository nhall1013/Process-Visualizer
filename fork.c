#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


 pid_t Fork(void){
    pid_t pid;

    if((pid = fork()) < 0){
        printf("error");
    }
    return pid;
}

int main(){
    
    int number;
    pid_t pid;
    int level = 0; 
    printf("How many fork calls: ");
    scanf("%d", &number);

    FILE *fp;
    fp = fopen("output.csv", "w+");
    fprintf(fp, "ppid,pid,level\n");
    fflush(fp);

    for(int i = 0; i < number; i++){
        

        pid = Fork();

        
        if(pid == 0){
            if(getppid() < getpid()){
                level = level + 1;  
            }
            fprintf(fp, "%d,%d,%d\n", getppid(), getpid(), level);
            fflush(fp);
        }

        waitpid(pid, NULL, 0);
    }
    fclose(fp);
    return 0;
}
