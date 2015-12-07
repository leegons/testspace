#include <cstring>
#include <cstdio>
#include <sys/types.h>
#include <regex.h>

/* 取子串的函数 */
static char* substr(const char*str, unsigned start, unsigned end)
{
    unsigned n = end - start;
    static char stbuf[256];
    strncpy(stbuf, str + start, n);
    stbuf[n] = 0;
    return stbuf;
}

/* 主程序 */
int main(int argc, char** argv)
{
    char * pattern;
    int x, z, lno = 0, cflags = 0;
    char ebuf[128], lbuf[256];
    regex_t reg;
    regmatch_t pm[10];
    const size_t nmatch = 10;
    /* 编译正则表达式*/
    pattern = argv[1];
    z = regcomp(&reg, pattern, REG_NOSUB | REG_EXTENDED);
    if (z != 0){
        regerror(z, &reg, ebuf, sizeof(ebuf));
        fprintf(stderr, "%s: pattern '%s' \n",ebuf, pattern);
        return 1;
    }
    /* 逐行处理输入的数据 */
    while(fgets(lbuf, sizeof(lbuf), stdin))
    {
        ++lno;
        if ((z = strlen(lbuf)) > 0 && lbuf[z-1] == '\n')
            lbuf[z - 1] = 0;
        /* 对每一行应用正则表达式进行匹配 */
        z = regexec(&reg, lbuf, 0, nullptr, 0);
        if (z == REG_NOMATCH) continue;
        else if (z != 0) {
            regerror(z, &reg, ebuf, sizeof(ebuf));
            fprintf(stderr, "%s: regcom('%s')\n", ebuf, lbuf);
            return 2;
        }
        printf("org:%s pattern:%s match[%d]\n", lbuf, pattern, nmatch);

        /* 输出处理结果 *
        for (x = 0; x < nmatch && pm[x].rm_so != -1; ++ x)
        {
            if (!x) printf("%04d: %s\n", lno, lbuf);
            printf(" $%d='%s'\n", x, substr(lbuf, pm[x].rm_so, pm[x].rm_eo));
        }
        //*/
    }
    /* 释放正则表达式 */
    regfree(&reg);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
