int main(int argc, char *argv[]) {
    for(;;) { 
        printf("isnide23:");

        char buf[MAX_CHARACTERS];
        char* command_string[MAX_WORDS];
        int i = 0;

        fgets(buf, MAX_CHARACTERS, stdin);
        char* token = strtok(buf, " \n");
        while (token != NULL) {
            printf("%s\n", token);
            command_string[i] = token;
            i++;
            token = strtok(NULL, " ");
        }

        command_string[i] = NULL;
        i = 0;

        while (command_string[i] != NULL) {
            printf("command string %d: %s\n", i, command_string[i]);
            i++;
        }

        execvp(command_string[0], command_string);

        perror("exec");

        printf("This line shouldn't printed if execvp() runs correctly\n");
        return 0;
    }

    return 0;
}