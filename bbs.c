#include <stdio.h>
#include <stdlib.h>
#define FNAME "comments.txt"

char* url_decode(char*, long);

int main(void){
    long  len;
    char* clen;
    char* data;
    char* comment;
    int   i;
    FILE* fp;

    clen = getenv("CONTENT_LENGTH");
    len  = atol(clen);
    data = malloc(len + 1);

    scanf("%s", data);

    for(i = 0; i < len; i++){
        if(data[i] == '='){
            data = data + (i + 1);
            len  = len - (i + 1);
            break;
        }
    }

    comment = url_decode(data, len);
    free(data);

    fp = fopen(FNAME, "a");

    if(fp == NULL){
        return 1;
    }

    fprintf(fp, "%s\n", comment);
    fclose(fp);

    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("<head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"></head>\n");
    printf("<body>\n");
    printf("書き込みました<br>\n");
    printf("<a href=\"http://bbs.hibinotatsuya.com/\">戻る</a>\n");
    printf("</body></html>\n");

    return 1;
}        

char* url_decode(char* data, long len){
    char* comment;
    char  buf;
    int   i, j;
    
    comment = malloc(len + 1);

    for(i = 0, j = 0; i < len; i++, j++){
        if(data[i] == '+'){
            comment[j] = ' ';
            continue;
        }

        if(data[i] != '%'){
            comment[j] = data[i];
            continue;
        }

        buf = data[++i] >= 'A' ? data[i] - 'A' + 10 : data[i] - '0';
        buf = buf * 16;
        buf += data[++i] >= 'A' ? data[i] - 'A' + 10 : data[i] - '0';

        comment[j] = buf;
    }

    comment[i] = '\0';

    return comment;
}
