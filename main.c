#include <stdio.h>
#include <string.h>
#include <Lmcons.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <dirent.h>
#include <direct.h>

void cmd_ls() {
    struct dirent *entry;
    DIR *dp = opendir(".");
    if (dp == NULL) {
        printf("Folder Cannot Be Opened.\n");
        return;
    }
    while ((entry = readdir(dp))) {
        printf("%s\n", entry->d_name);
    }
    closedir(dp);
}

void cmd_cd() {
    char newdir[256];
    scanf("%s", newdir);
    printf("\n");
    _chdir(newdir);
}

void cmd_mkdir() {
    char newfldr[256];
    scanf("%s", newfldr);
    printf("\n");
    _mkdir(newfldr);
}

void cmd_title() {
    char newtitle[256];
    scanf("%s", newtitle);
    printf("\n");
    SetConsoleTitle(newtitle);
}

void cmd_mkfl() {
    char newfile[256];
    scanf("%s", newfile);
    printf("\n");
    FILE *fptr;
    fptr = fopen(newfile, "w");
    fclose(fptr);
}

int main() {
    bool exit = false;
    while (!exit)
    {
        char cmdinput[256];
        char usrname[256];
        DWORD cch = UNLEN + 1;
        GetUserName(usrname, &cch);
        printf("%s> ", usrname);
        fflush(stdin); // stdin'i temizle (bazı durumlarda gerekebilir)
        if (fgets(cmdinput, sizeof(cmdinput), stdin) == NULL) {
            continue;
        }
        // Satır sonu karakterini kaldır
        cmdinput[strcspn(cmdinput, "\n")] = 0;

        if(strcmp(cmdinput, "exit") == 0) {
            exit = true;
        } else if(strcmp(cmdinput, "ls") == 0) {
            cmd_ls();
        } else if(strcmp(cmdinput, "cd") == 0) {
            cmd_cd();
        } else if(strcmp(cmdinput, "cls") == 0) {
            system("cls");
        } else if(strcmp(cmdinput, "clear") == 0) {
            system("cls");
        } else if (strcmp(cmdinput, "whereami") == 0){
            char cwd[512];
            if (_getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("%s\n", cwd);
            } else {
                perror("Unable to Retrieve Directory.");
            }
        } else if (strcmp(cmdinput, "mkdir") == 0) {
            cmd_mkdir();
        } else if (strcmp(cmdinput, "reboot") == 0) {
            system("shutdown -r -t 0");
        } else if (strcmp(cmdinput, "title") == 0) {
            cmd_title();
        } else if (strcmp(cmdinput, "mkfl") == 0) {
            cmd_mkfl();
        } else if (strcmp(cmdinput, "lcmdhelp") == 0) {
            printf("> > > LCMD HELP < < <");
            printf("\nwhereami - Prints out the directory you are in");
            printf("\nmkfl - Creates a file\n");
        } else {
            system(cmdinput);
        }
    }
}