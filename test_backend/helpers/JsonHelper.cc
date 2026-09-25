#include "../includes/JsonHelper.h"

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <nlohmann/detail/macro_scope.hpp>
#include <cstdint>
#include <stdexcept>

using json = nlohmann::json;

JsonHelper::JsonHelper(std::string name,
                            std::vector<User>& data):
                            filename(name),datas(data) {};

void JsonHelper::load_from_json() {load();};
void JsonHelper::save_to_json() {save();};

void JsonHelper::save()
{
  std::ofstream file(filename);
  if(!file.is_open()) {
    throw std::runtime_error("Error open file");
  }
  json j = datas;
  file << j.dump(4);
};

void JsonHelper::load()
{
  std::ifstream file(filename);
  if(!file.is_open()) {
    throw std::runtime_error("Error open file");
  }
  if(file.peek() == std::ifstream::traits_type::eof()) {
    datas.clear();
    return;
  }
  json j;
  file >> j;
  std::cout << "[ FILE ] " << j << std::endl;
  datas = j.get<std::vector<User>>();
};
