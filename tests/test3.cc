#include <iostream>
#include <yaml-cpp/yaml.h>

void printNode(const YAML::Node& node, int indent = 0) {
    std::cout <<node.Type() << "--";
    switch (node.Type()) {
        case YAML::NodeType::Null:
            std::cout << std::string(indent, ' ') << "null" << std::endl;
            break;
        case YAML::NodeType::Scalar:
            std::cout << std::string(indent, ' ') << node.Scalar() << std::endl;
            break;
        case YAML::NodeType::Sequence:
            for (std::size_t i = 0; i < node.size(); i++) {
                std::cout << std::string(indent, ' ') << "- ";
                printNode(node[i], indent + 2);
            }
            break;
        case YAML::NodeType::Map:
            for (YAML::const_iterator it = node.begin(); it != node.end(); ++it) {
                std::cout << std::string(indent, ' ') << it->first.as<std::string>() << ": ";
                printNode(it->second, indent + 2);
            }
            break;
        case YAML::NodeType::Undefined:
            std::cout << std::string(indent, ' ') << "undefined" << std::endl;
            break;
    }
}

int main() {
    YAML::Node config = YAML::LoadFile("/home/dulred/sylar/bin/conf/example.yml");
    printNode(config);
    
    return 0;
}
