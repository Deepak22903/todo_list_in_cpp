#include "header.h"

int main(int argc, char *argv[]) {
  // std::cout << argc << "\n";
  // for (int i = 0; i < argc; i++) {
  //   std::cout << argv[i] << "\n";
  // }
  // if (std::string(argv[1]) == "-h") {
  //   std::cout << "True" << "\n";
  // }
  std::ifstream inputFile("tasks.json");
  if (!inputFile.is_open()) {
    std::cout << "Error opening the tasks.json file" << "\n";
    return 1;
  }

  json j;
  inputFile >> j;
  inputFile.close();
  // cout << j.at("tasks")[0].at("id").get<int>() << "\n";
  cout << j["tasks"].back().at("id").get<int>();

  return 0;
}
