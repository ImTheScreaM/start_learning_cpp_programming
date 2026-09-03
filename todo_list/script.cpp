#include <iostream>
#include <clocale>
#include <vector>
#include <string>

struct Tasks {
	std::string description;
	bool completed;
};

/*
 * 
 * @brief tasks -> Массив заметок
 * @brief desc -> Описание для заметки
 * 
 */

void add_task_to_list(std::vector<Tasks>& tasks,
	                    const std::string desc)
{
	if(desc == "") {
		std::cout << "Нет заметки\n";
	} else {
		tasks.push_back({desc,false});
		std::cout << "Заметка добавлена!\n";
	}
}

/*
 * 
 * @brief tasks -> Массив заметок
 * @brief desc -> Номер заметки
 * 
 */

void edit_task(std::vector<Tasks>& tasks,
	             const int index_task)
{
	if (index_task - 1 < 0 || index_task - 1 >= tasks.size()) {
		std::cout << "Не верный номер заметки\n";
	} else {
		std::cout << "Старый текст" << tasks[index_task - 1].description << std::endl;
		std::cout << "Новое название заметки:";
		std::string new_desc;
		std::getline(std::cin,new_desc);

		if(!new_desc.empty()) {
			tasks[index_task - 1].description = new_desc;
			std::cout << "Заметка обновлена\n";
		} 
	}
}

/*
 * 
 * @brief tasks -> Массив заметок
 * @brief desc -> Номер заметки
 * 
 */

void edit_task_competed(std::vector<Tasks>& tasks,
	                      const int index_task)
{
	if (index_task - 1 < 0 || index_task - 1 >= tasks.size()) {
		std::cout << "Не верный номер заметки\n" << std::endl;
	} else {
		tasks[index_task - 1].completed = !tasks[index_task - 1].completed;
		std::cout << "Статус задачи №" << index_task << " был изменен\n";
	}
}

/*
 * 
 * @brief tasks -> Массив заметок
 * @brief desc -> Номер заметки
 * 
 */

void delete_task(std::vector<Tasks>& tasks,
	              const int index_task)
{
	if (index_task - 1 < 0 || index_task - 1 > tasks.size()) {
		std::cout << "Не верный номер заметки\n";
	} else {
		tasks.erase(tasks.begin() + (index_task - 1));
	}
}

/*
 * 
 * @brief tasks -> Массив заметок
 * 
 */

void see_list_tasks(const std::vector<Tasks>& tasks)
{
	if(tasks.empty()) {
		std::cout << "Список пуст" << std::endl;
	} else {
		for(size_t index = 0; index < tasks.size(); index++) {
			std::cout << index + 1 << ") " << "[" << (tasks[index].completed ? "X" : "") << "] " << tasks[index].description  << std::endl;
		}
	}
}

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

int main()
{
	setlocale(LC_ALL,"Russian");
	std::vector<Tasks> tasks;
	std::cout << "Выбери задачу";
	int choise = 0;

	while(choise != 6) {
		show_menu();
		std::cin >> choise;
		std::cin.ignore();

		switch(choise) {
			case 1: {
				std::cout << "Введите заметку\n";
				std::string desc;
				std::getline(std::cin,desc);
				add_task_to_list(tasks,desc);
				break;
			}
			case 2:
				std::cout << "Введите номер заметки\n";
				int index_task;
				std::cin >> index_task;
				std::cin.ignore();
				edit_task(tasks,index_task);
				break;
			case 3: {
				see_list_tasks(tasks);
				std::cout << "Введите номер заметки\n";
				int index_task;
				std::cin >> index_task;
				edit_task_competed(tasks,index_task);
				break;
			}
			case 4: {
				std::cout << "Введите номер заметки\n";
				int index_task;
				std::cin >> index_task;
				delete_task(tasks,index_task);
				break;
			}
			case 5:
				see_list_tasks(tasks);
				break;
			case 6:
				std::cout << "Выход!\n";
				break;
			default:
				std::cout << "Неверный пункт меню\n";
		}
	};
	return 0;
}
