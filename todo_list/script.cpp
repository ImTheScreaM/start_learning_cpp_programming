#include <ctime>
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <clocale>
#include <locale>
#include <nlohmann/detail/macro_scope.hpp>
#include <stdexcept>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include <chrono>

enum class MenuOption {
	ADD_TASK = 1,
	EDIT_TASK = 2,
	EDIT_TASK_COMPELETED = 3,
	DELETE_TASK = 4,
	SEE_ALL_TASKS = 5,
	CLOSE_APP = 6
};

using json = nlohmann::json;

struct Tasks {
	std::string description;
	bool completed;
	std::string time;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Tasks,description,completed,time)

class TasksFunction {
	private:
		std::vector<Tasks>& tasks;
		
	public:
		TasksFunction(std::vector<Tasks>& task): tasks(task) {};
		
		static MenuOption int_to_menu_option(int value) {
			switch (value) {
				case 1: return MenuOption::ADD_TASK;
				case 2: return MenuOption::EDIT_TASK;
				case 3: return MenuOption::EDIT_TASK_COMPELETED;
				case 4: return MenuOption::DELETE_TASK;
				case 5: return MenuOption::SEE_ALL_TASKS;
				case 6: return MenuOption::CLOSE_APP;
				default: throw std::invalid_argument("[Ошибка] Неверный пункт меню\n");
			}
		}
		
		void load_from_json(const std::string& filename)
		{
			std::ifstream file(filename);
			if(file.is_open()) {

				if (file.peek() == std::ifstream::traits_type::eof()) {
					std::cout << "[Инфо] Файл пустой!\n";
					tasks.clear();
				} else {
					json j;
					file >> j;
					tasks = j.get<std::vector<Tasks>>();
				}

			} else {
				std::cout << "[Инфо] Заметок в БД нет!\n";
			}
		}

		void save_to_json(const std::string& filename)
		{
			std::ofstream file(filename);
			if(file.is_open()) {
				json j = tasks;
				file << j.dump(4);
				file.close();
			} else {
				std::cout << "[Инфо] Не удалось сохранить";
 			}
		}

		/*
		 *
		 * @brief tasks -> Массив заметок
		 * @brief desc -> Описание для заметки
		 *
		*/

		void add_task_to_list(const std::string desc)
		{add_task_to_list_(desc);}

		/*
		 *
		 * @brief tasks -> Массив заметок
		 * @brief desc -> Номер заметки
		 *
		*/

		void edit_task(const int index_task)
		{edit_task_(index_task);}

		/*
		 *
		 * @brief tasks -> Массив заметок
		 * @brief desc -> Номер заметки
		 *
		*/

		void edit_task_completed(const int index_task)
		{edit_task_completed_(index_task);}

		/*
		 *
		 * @brief tasks -> Массив заметок
		 * @brief desc -> Номер заметки
		 *
		*/

		void delete_task(const int index_task)
		{delete_task_(index_task);}

		/*
		 *
		 * @brief tasks -> Массив заметок
		 *
		*/

		void see_list_tasks()
		{see_list_tasks_();}

		/*
		 *
		 * @brief Меню туду листа
		 *
		*/

		void show_menu() {
	    std::cout << "\n|TODO LIST|\n";
	    std::cout << "[1] Добавить задачу\n";
	    std::cout << "[2] Редактировать задачу\n";
	    std::cout << "[3] Изменить статус задачи\n";
	    std::cout << "[4] Удалить задачу\n";
	    std::cout << "[5] Показать задачи\n";
	    std::cout << "[6] Выйти\n";
	    std::cout << "Выберите действие: ";
		}

 	private:  
  	std::string get_current_time() 
   {
   		auto now = std::chrono::system_clock::now();
     	std::time_t now_time = std::chrono::system_clock::to_time_t(now);
      std::tm* local_time = std::localtime(&now_time);

      char buf[100];
      std::strftime(buf,sizeof(buf),"%d.%m.%Y %H:%M:%S",local_time);
      return std::string(buf);
   	}
   
  	void add_task_to_list_(const std::string desc)
		{
			if(desc == "") {
				std::cout << "Нет заметки\n";
			} else {
				const std::string time = get_current_time();
				tasks.push_back({desc,false,time});
				std::cout << "Заметка добавлена!\n";
			}
		}

		void edit_task_(const int index_task)
		{
			if (index_task - 1 < 0 || index_task - 1 >= tasks.size()) {
				std::cout << "Не верный номер заметки\n";
			} else {
				std::cout << "Старый текст:" << tasks[index_task - 1].description << std::endl;
				std::cout << "Новое название заметки:";
				
				std::string new_desc;
				std::getline(std::cin,new_desc);

				if(!new_desc.empty()) {
					tasks[index_task - 1].description = new_desc;
					std::cout << "Заметка обновлена\n";
				}
			}
		}

		void edit_task_completed_(const int index_task)
		{
			if (index_task - 1 < 0 || index_task - 1 >= tasks.size()) {
				std::cout << "Не верный номер заметки\n" << std::endl;
			} else {
				tasks[index_task - 1].completed = !tasks[index_task - 1].completed;
				std::cout << "Статус задачи №" << index_task << " был изменен\n";
			}
		}

		void delete_task_(const int index_task)
		{
			if (index_task - 1 < 0 || index_task - 1 >= tasks.size()) {
				std::cout << "Не верный номер заметки\n";
			} else {
				tasks.erase(tasks.begin() + (index_task - 1));
			}
		}

		void see_list_tasks_()
		{
			if(tasks.empty()) {
				std::cout << "Список пуст" << std::endl;
			} else {
				for(size_t index = 0; index < tasks.size(); index++) {
					std::cout << index + 1 << ") " << "[" << (tasks[index].completed ? "X" : "") << "] " << tasks[index].description << " Дата:" << tasks[index].time << std::endl;
				}
			}
		}
};

int main()
{
	setlocale(LC_ALL,"Russian");

	std::vector<Tasks> tasks;
	TasksFunction task_function(tasks);
	std::string DB = "user_tasks.json";

	std::cout << "Выбери задачу";
	int choise = 0;

	task_function.load_from_json(DB);

	while(true) {
		task_function.show_menu();
		
		if (!(std::cin >> choise)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "[Ошибка] Введите число\n";
			continue;
		}
		
		MenuOption option = TasksFunction::int_to_menu_option(choise);
	 
		switch(option) {
			case MenuOption::ADD_TASK: {
				std::cout << "Введите заметку\n";

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				
				std::string desc;
				std::getline(std::cin,desc);

				task_function.add_task_to_list(desc);
				task_function.save_to_json(DB);
				break;
			}
			case MenuOption::EDIT_TASK: {
				std::cout << "Введите номер заметки\n";

				int index_task;
				std::cin >> index_task;
				std::cin.ignore();

				task_function.edit_task(index_task);
				task_function.save_to_json(DB);
				break;
			}
			case MenuOption::EDIT_TASK_COMPELETED: {
				task_function.see_list_tasks();

				std::cout << "Введите номер заметки\n";

				int index_task;
				std::cin >> index_task;
				std::cin.ignore();

				task_function.edit_task_completed(index_task);
				task_function.save_to_json(DB);
				break;
			}
			case MenuOption::DELETE_TASK: {
				std::cout << "Введите номер заметки\n";

				int index_task;
				std::cin >> index_task;
				std::cin.ignore();

				task_function.delete_task(index_task);
				task_function.save_to_json(DB);

				break;
			}
			case MenuOption::SEE_ALL_TASKS: {
				task_function.see_list_tasks();
				break;
			}
			case MenuOption::CLOSE_APP: {
				std::cout << "Выход!\n";
				break;
			}
			default: {
				std::cout << "Неверный пункт меню\n";
			}
		}
	};
	return 0;
}
