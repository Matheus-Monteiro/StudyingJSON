#include "ext/json/single_include/nlohmann/json.hpp"
#include <iostream>
#include <string>

void dfs(std::string vertex, nlohmann::json tree, int d)
{
    std::cout << std::string(d, ' ') << vertex << std::endl;
    if(tree.dump() == "[]") return;
    for(auto it : tree["childreen"].items())
        dfs(it.value()["vertex"], it.value(), d + 2);
}

int main()
{
    nlohmann::json tree =  R"(
            {
                "vertex": "root",
                "childreen":[
                    {
                        "vertex": "a",
                        "childreen":[
                            {
                                "vertex": "c",
                                "childreen":[
                                    {
                                        "vertex": "e",
                                        "childreen":[]
                                    }
                                ]
                            },
                            {
                                "vertex": "d",
                                "childreen":[]
                            }
                        ]
                    },
                    {
                        "vertex": "b",
                        "childreen":[]
                    }
                ]
            }
        )"_json;

    dfs("root", tree, 0);

    return 0;
}