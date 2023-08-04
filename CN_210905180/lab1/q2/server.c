#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORTNO 10200

/* struct in_addr {
   unsigned long int s_addr;
   };

   struct sockaddr_in {
   short int sin_family;
   struct in_addr sin_addr;
   };
   */
void duplicate(char *str, char *new_str) {
	char words[6][16];
	int count = 0;

	int i, j, k, l;
	i = j = k = l = 0;

	while (str[i] != '\0') {
        if (str[i] == ' ') {
            words[k][j] = '\0';
            k++;
            j = 0;
        }
        else {
            words[k][j] = str[i];
            j++;
        }
        i++;
    }
    words[k][j] = '\0';

	j = 0;
    for (i = 0; i < k; i++) {
        int present = 0;
        for (l = 1; l < k + 1; l++) {
            if (words[l][j] == '\0' || l == i)
                continue;

            if (strcmp(words[i], words[l]) == 0) {
                words[l][j] = '\0';
                present = present + 1;
            }
        }
    }

	j = 0;
    for (i = 0; i < k + 1; i++) {
        if (words[i][j] == 0)
            continue;
        else {
			for(int m = 0; m < strlen(words[i]); m++) {
				new_str[count++] = words[i][m];
			}
			new_str[count++] = ' ';
		}
    }

}
int main() {
	int sockfd, newsockfd, portno, clilen, n = 1;
	struct sockaddr_in seraddr, cliaddr;
	int i, value;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("172.16.48.59");
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));

	listen(sockfd,5);

	while(1) {
		char buf[256];
		printf("server waiting");

		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr*)&cliaddr, &clilen);

        char new_str[256];
        n = read(newsockfd, buf, sizeof(buf));
		n = write(newsockfd, buf, sizeof(buf));

        duplicate(buf, new_str);


	}
}

