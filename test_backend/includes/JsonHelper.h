#pragma once


#include <vector> 

 
#include "../includes/data_type.h"



class JsonHelper {
	private:
		std::string filename;
		std::vector<User>& datas;
		
		void save();
		void load();

	public:
		JsonHelper(std::string name,
							std::vector<User>& data);
		void save_to_json();
		void load_from_json();



};
