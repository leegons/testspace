#include <cstdio>
#include <string.h>
#include <string>
#include <memory>
#include <map>
#include <set>

struct node_t {
    node_t* next[26];
    std::set<int>* dict;
    node_t() {
        for (int _i = 0; _i < 26; ++_i)
            next[_i] = NULL;
        dict = NULL;
    }
};

inline void insert_words(const char* words, int dict_id, node_t* head) {
    const char* st = words;
    node_t* np = head;
    while (*st != '\0') {
        /*
        if(np->dict != NULL) {
            if (np->dict->count(dict_id) > 0) {
                //fprintf(stderr, "pass string:%s\n", st);
                break;
            }
        }
        */
        if (np->next[*st - 'a'] == NULL) {
            np->next[*st - 'a'] = new node_t();
        }
        np = np->next[*st - 'a'];
        st++;
    }
    if (np->dict == NULL) {
        np->dict = new std::set<int>();
    } /*else {
        //fprintf(stderr, "shared dict\n");
    }*/
    np->dict->insert(dict_id);
}

inline void find_words(const char* words, const node_t* head, std::set<int>* res) {
    const char* st = words;
    const char* stp;
    const node_t* np;
    while (*st != '\0') {
        stp = st;
        np = head;
        while (*stp != '\0') {
            if (np->next[*stp - 'a'] == NULL) {
                np = NULL;
                break;
            }
            np = np->next[*stp - 'a'];
            if (np->dict != NULL) {
                for (auto it: *(np->dict)) {
                    res->insert(it);
                }
            }
            stp++;
        }
        st++;
    }
}

/*
inline int cmp(const void* a, const void* b) {
    return strlen((const char*)a) - strlen((const char*)b);
}
*/

int main() {
    int dict_num, query_num;
    scanf("%d%d", &dict_num, &query_num);
    std::string dict_names[dict_num];
    node_t* nodetree = new node_t();
    char buff[258];

    for (int idx = 0; idx < dict_num; ++idx) {
        int words_num;
        scanf("%s%d", &buff, &words_num);
        dict_names[idx] = buff;

        for (int _i = 0; _i < words_num; ++_i) {
            scanf("%s", &buff);
            insert_words(buff, idx, nodetree);
        }
    }
    //fprintf(stderr, "create done\n");

    for (int idx = 0; idx < query_num; ++idx) {
        std::set<int> res;

        scanf("%s", &buff);
        find_words(buff, nodetree, &res);

        printf("%d", res.size());
        for (auto it: res) {
            printf(" %s", dict_names[it].c_str());
        }
        puts("");
    }
    //fprintf(stderr, "query done\n");

    //system("cat /proc/$(ps aux |grep test2 |grep -v grep |cut -c8-15 |sed 's# ##g')/status > ./stat.tmp");

    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
