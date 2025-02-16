#include "parser.hpp"
#include <fstream>
#include <iostream>
#include <istream>
#include <stdexcept>

bool check_graph(const tp::Graph& graph1, const tp::Graph& graph2) {
    if (graph1.size() != graph2.size()) {
        return false;
    }
    for (const auto& [key, value] : graph1) {
        if (graph2.find(key) == graph2.end()) {
            return false;
        }
        const auto& vec1 = value;
        const auto& vec2 = graph2.at(key);
        if (vec1.size() != vec2.size()) {
            return false;
        }
        auto sortedVec1 = vec1;
        auto sortedVec2 = vec2;
        std::sort(sortedVec1.begin(), sortedVec1.end());
        std::sort(sortedVec2.begin(), sortedVec2.end());
        if (sortedVec1 != sortedVec2) {
            return false;
        }
    }
    return true;
}
void printGraph(const tp::Graph& g)
{
    for (const auto& [node, edges] : g) {
        std::cout << node << " -> ";
        for (const auto& [neighbor, weight] : edges)
        {
            std::cout << "(" << neighbor << ", " << weight << ") ";
        }
        std::cout << std::endl;
    }
}

bool test_parseGraph(std::istream& input, const tp::Graph& model)
{
    cli::Parser parser;
    tp::Graph g = parser.parseGraph(input);
    printGraph(g);
    return check_graph(g, model);
}

int main()
{
    const tp::Graph graph1 = {
        {"A", {{"B", 40}, {"C", 41}, {"D", 46}, {"E", 14}}},
        {"B", {{"A", 40}, {"C", 38}, {"D", 22}, {"E", 43}}},
        {"C", {{"A", 41}, {"B", 38}, {"D", 55}, {"E", 16}}},
        {"D", {{"A", 46}, {"B", 22}, {"C", 55}, {"E", 43}}},
        {"E", {{"A", 14}, {"B", 43}, {"C", 16}, {"D", 43}}}
    };
    const tp::Graph graph2 = {
        {"A", {{"B", 25}, {"C", 48}, {"D", 29}, {"E", 43}}},
        {"B", {{"A", 25}, {"C", 47}, {"D", 13}, {"E", 18}}},
        {"C", {{"A", 48}, {"B", 47}, {"D", 24}, {"E", 28}}},
        {"D", {{"A", 29}, {"B", 13}, {"C", 24}, {"E", 18}}},
        {"E", {{"A", 43}, {"B", 18}, {"C", 28}, {"D", 18}}}
    };
    const tp::Graph graph3 = {
        {"A", {{"B", 36}, {"C", 31}, {"D", 56}, {"E", 13}}},
        {"B", {{"A", 36}, {"C", 58}, {"D", 35}, {"E", 10}}},
        {"C", {{"A", 31}, {"B", 58}, {"D", 57}, {"E", 48}}},
        {"D", {{"A", 56}, {"B", 35}, {"C", 57}, {"E", 28}}},
        {"E", {{"A", 13}, {"B", 10}, {"C", 48}, {"D", 28}}}
    };
    const tp::Graph graph4 = {
        {"A", {{"B", 14}, {"C", 23}, {"D", 22}, {"E", 36}}},
        {"B", {{"A", 14}, {"C", 13}, {"D", 34}, {"E", 33}}},
        {"C", {{"A", 23}, {"B", 13}, {"D", 41}, {"E", 27}}},
        {"D", {{"A", 22}, {"B", 34}, {"C", 41}, {"E", 35}}},
        {"E", {{"A", 36}, {"B", 33}, {"C", 27}, {"D", 35}}}
    };
    const tp::Graph graph5 = {
        {"A", {{"B", 29}, {"C", 45}, {"D", 55}, {"E", 49}}},
        {"B", {{"A", 29}, {"C", 11}, {"D", 17}, {"E", 50}}},
        {"C", {{"A", 45}, {"B", 11}, {"D", 22}, {"E", 46}}},
        {"D", {{"A", 55}, {"B", 17}, {"C", 22}, {"E", 17}}},
        {"E", {{"A", 49}, {"B", 50}, {"C", 46}, {"D", 17}}}
    };

    const tp::Graph graph6 = {
        {"A", {{"B", 29}, {"C", 45}, {"D", 55}, {"E", 49}, {"F", 33}, {"G", 42}, {"H", 19}, {"I", 25}, {"J", 14}}},
        {"B", {{"A", 29}, {"C", 11}, {"D", 17}, {"E", 50}, {"F", 27}, {"G", 38}, {"H", 21}, {"I", 30}, {"J", 12}}},
        {"C", {{"A", 45}, {"B", 11}, {"D", 22}, {"E", 46}, {"F", 18}, {"G", 37}, {"H", 24}, {"I", 31}, {"J", 13}}},
        {"D", {{"A", 55}, {"B", 17}, {"C", 22}, {"E", 17}, {"F", 26}, {"G", 39}, {"H", 20}, {"I", 32}, {"J", 15}}},
        {"E", {{"A", 49}, {"B", 50}, {"C", 46}, {"D", 17}, {"F", 28}, {"G", 40}, {"H", 23}, {"I", 33}, {"J", 16}}},
        {"F", {{"A", 33}, {"B", 27}, {"C", 18}, {"D", 26}, {"E", 28}, {"G", 14}, {"H", 34}, {"I", 35}, {"J", 36}}},
        {"G", {{"A", 42}, {"B", 38}, {"C", 37}, {"D", 39}, {"E", 40}, {"F", 14}, {"H", 41}, {"I", 42}, {"J", 43}}},
        {"H", {{"A", 19}, {"B", 21}, {"C", 24}, {"D", 20}, {"E", 23}, {"F", 34}, {"G", 41}, {"I", 44}, {"J", 45}}},
        {"I", {{"A", 25}, {"B", 30}, {"C", 31}, {"D", 32}, {"E", 33}, {"F", 35}, {"G", 42}, {"H", 44}, {"J", 46}}},
        {"J", {{"A", 14}, {"B", 12}, {"C", 13}, {"D", 15}, {"E", 16}, {"F", 36}, {"G", 43}, {"H", 45}, {"I", 46}}}
    };

    std::ifstream input_graph1("../../data/graph_1.txt");
    std::ifstream input_graph2("../../data/graph_2.txt");
    std::ifstream input_graph3("../../data/graph_3.txt");
    std::ifstream input_graph4("../../data/graph_4.txt");
    std::ifstream input_graph5("../../data/graph_5.txt");
    std::ifstream input_graph6("../../data/graph_6.txt");
    
    if (!input_graph1) throw std::runtime_error("Failed to open graph_1.txt");
    if (!input_graph2) throw std::runtime_error("Failed to open graph_2.txt");
    if (!input_graph3) throw std::runtime_error("Failed to open graph_3.txt");
    if (!input_graph4) throw std::runtime_error("Failed to open graph_4.txt");
    if (!input_graph5) throw std::runtime_error("Failed to open graph_5.txt");
    if (!input_graph6) throw std::runtime_error("Failed to open graph_6.txt");

    assert(test_parseGraph(input_graph1, graph1));
    assert(test_parseGraph(input_graph2, graph2));
    assert(test_parseGraph(input_graph3, graph3));
    assert(test_parseGraph(input_graph4, graph4));
    assert(test_parseGraph(input_graph5, graph5));
    assert(test_parseGraph(input_graph6, graph6));
}

