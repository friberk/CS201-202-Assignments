#include "Graph.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

std::string* tokenizer(const std::string& str, const char& delimiter, int& sizeOut) {
    int numOfTokens = 0;

    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == delimiter) {
            numOfTokens++;
        }
    }

    if (numOfTokens == 0) {
        sizeOut = 0;
        return NULL;
    }

    sizeOut = numOfTokens + 1;
    std::string* tokens = new std::string[numOfTokens + 1];
    int counter = 0;
    std::string token = "";

    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == delimiter) {
            tokens[counter] = token;
            counter++;
            token = "";
        }

        else {
            token += str[i];
        }
    }
    tokens[counter] = token;

    return tokens;
}

void parser(const std::string& fileName, int& graphSize, int& opCount, std::string*& opList) {
    std::ifstream file;
    file.open(fileName.c_str(), std::ios_base::in);

    if (!file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        file.close();
        return;
    }

    std::string grS = "";
    getline(file, grS);
    graphSize = strtol(grS.c_str(), NULL, 10);

    std::string opC = "";
    getline(file, opC);
    opCount = strtol(opC.c_str(), NULL, 10);

    if (opCount < 1) {
        opList = NULL;
    } else {
        opList = new std::string[opCount];
        int i = 0;
        for (std::string line; i < opCount && getline(file, line); i++) {
            opList[i] = line;
        }
    }

    file.close();
}

int main(int argc, char const* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./hw4 <fileName>" << std::endl;
        return 1;
    } else {
        int graphSize = 0, opCount = 0;
        std::string* opList = NULL;

        parser(argv[1], graphSize, opCount, opList);

        if (graphSize < 1) {
            std::cout << "Graph size must be greater than 0. Skipping all other instructions, if there is any."
                      << std::endl;

            if (opList != NULL) {
                delete[] opList;
            }

            return 0;
        }

        else {
            Graph graph(graphSize);

            if (opList == NULL) {
                std::cout << "No operations to perform." << std::endl;
            }

            else {
                for (int i = 0; i < opCount; i++) {
                    std::string op = opList[i];
                    int sizeOut = 0;
                    std::string* tokens = tokenizer(op, ' ', sizeOut);

                    switch (op[0]) {
                    case 'I':
                        if (sizeOut < 4) {
                            std::cout << "Invalid number of arguments for operation " << op << "."
                                      << std::endl;
                        } else {
                            int from = strtol(tokens[1].c_str(), NULL, 10);
                            int to = strtol(tokens[2].c_str(), NULL, 10);
                            int weight = strtol(tokens[3].c_str(), NULL, 10);

                            graph.addEdge(from, to, weight, false);
                        }

                        break;
                    case 'L':
                        if (sizeOut < 2) {
                            std::cout << "Invalid number of arguments for operation " << op << "."
                                      << std::endl;
                        } else {
                            int vertexId = strtol(tokens[1].c_str(), NULL, 10);

                            graph.listEdges(vertexId);
                        }
                        break;
                    case 'S':
                        if (sizeOut < 3) {
                            std::cout << "Invalid number of arguments for operation " << op << "."
                                      << std::endl;
                        } else {
                            int from = strtol(tokens[1].c_str(), NULL, 10);
                            int to = strtol(tokens[2].c_str(), NULL, 10);

                            graph.shortestPath(from, to);
                        }
                        break;
                    case 'M':
                        graph.minimizeCosts();
                        break;
                    default:
                        std::cout << "Invalid operation." << std::endl;
                        break;
                    }

                    if (tokens != NULL) {
                        delete[] tokens;
                    }
                }
            }

            if (opList != NULL) {
                delete[] opList;
            }

            return 0;
        }
    }
}
