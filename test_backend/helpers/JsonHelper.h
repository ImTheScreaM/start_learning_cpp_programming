#pragma once

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <nlohmann/detail/macro_scope.hpp>
#include <stdexcept>
#include <vector> 
#include <cstdint>
#include <stdexcept> 
 
#include "../includes/data_type.h"

using json = nlohmann::json;

class JsonHelper {
	private:
		std::string filename;
		std::vector<User>& datas;
		
	public:
		JsonHelper(std::string name,
							std::vector<User>& data):
							filename(name),datas(data) {};

		void save_to_json() {save();}
		void load_from_json() {load();}
		
	private:
		void save() 
		{			
			std::ofstream file(filename);
			if(!file.is_open()) {
				throw std::runtime_error("Error open file");
			} 
				json j = datas;
				file << j.dump(4);
		};
		
	 	void load() 
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
};
