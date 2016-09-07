#include <cstdio>
#include <string>
#include <memory>
#include <map>
#include <set>

typedef std::map<std::string, std::shared_ptr<std::set<int>>> WordsMap;

void readstr(std::string* s) {
    char buf[256];
    if (scanf("%s", &buf) != EOF) {
        s->assign(buf);
    }
}

void insertwords(const std::string& words, int dict_id, WordsMap* words_map) {
    auto it = words_map->find(words);
    if (it == words_map->end()) {
        std::shared_ptr<std::set<int>> v(new std::set<int>());
        v->insert(dict_id);
        words_map->insert(WordsMap::value_type(words, v));
    } else {
        it->second->insert(dict_id);
    }
}

int main() {
    int dict_num, query_num;
    if (scanf("%d%d", &dict_num, &query_num) == EOF) {
        return 0;
    }
    std::string dict_names[dict_num];
    std::string tmp_words;
    WordsMap words_map;
    for (int idx = 0; idx < dict_num; ++idx) {
        readstr(&dict_names[idx]);
        int words_num;
        scanf("%d", &words_num);
        while (words_num--) {
            readstr(&tmp_words);
            insertwords(tmp_words, idx, &words_map);
        }
    }
    while (query_num--) {
        std::set<int> res;
        readstr(&tmp_words);
        for (auto it: words_map) {
            if (int(tmp_words.find(it.first)) >= 0) {
                for (auto dict_id: *(it.second)) {
                    res.insert(dict_id);
                }
            }
        }
        printf("%d", res.size());
        for (auto it: res) {
            printf(" %s", dict_names[it].c_str());
        }
        puts("");
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
