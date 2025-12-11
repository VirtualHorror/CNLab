// Using TCP/IP sockets, write a client-server program to make client send the file name and the server to send back the contents of the requested file name “sample.txt” with the following contents: “Hello we are at Computer Networks Lab” Display suitable error message in case the file is not present in the server.

// server.c
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(8080), INADDR_ANY};
    bind(sd, (struct sockaddr*)&addr, sizeof(addr));
    listen(sd, 1);
    int cd = accept(sd, NULL, NULL);
    char fname[100], buf[1000];
    read(cd, fname, 100);
    FILE *f = fopen(fname, "r");
    if (f) {
        fread(buf, 1, 1000, f);
        write(cd, buf, strlen(buf));
        fclose(f);
    } else {
        write(cd, "Error: File not found", 21);
    }
    close(cd);
    close(sd);
    return 0;
}

//client.c
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(8080)};
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    connect(sd, (struct sockaddr*)&addr, sizeof(addr));
    char fname[100], buf[1000] = {0};
    printf("Enter filename: ");
    scanf("%s", fname);
    write(sd, fname, strlen(fname) + 1);
    read(sd, buf, 1000);
    printf("Server response:\n%s\n", buf);
    close(sd);
    return 0;
}
