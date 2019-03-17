#include <stdio.h>
#define FNAME "comments.txt"

int main(void){
    FILE* fp;
    char buf[1000];

    fp = fopen(FNAME, "r");
    if(fp == NULL){
        return 1;
    }

    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("<head>\n");
    printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n");
    printf("<title>たつや掲示板</title>\n");
    printf("</head>\n");
    printf("<body>\n");
    printf("<h1>たつや掲示板</h1>\n");
    printf("<form method=\"post\" action=\"/bbs.cgi\">\n");
    printf("<input type=\"text\" name=\"comment\">\n");
    printf("<input type=\"submit\" value=\"送信\">\n");
    printf("</form>\n");

    while(fgets(buf, 1000, fp) != NULL){
        printf("%s<br>\n", buf);
    }

    printf("</body>\n");
    printf("</html>\n");

    return 0;
}
