#pragma once
#include "LookUp.h"
#include <vector>
#include <fstream>
#include <string>


class LookUpArr {
private:
	std::vector<LookUp> arr_;

public:
	LookUpArr(const std::string name, const std::string owner, const std::string number, const std::string adress, const std::string business_activity)
		: arr_(1, LookUp(name, owner, number, adress, business_activity)) {}

	
	/*==== Setters ====*/
	void set_name(const std::string& name, size_t index);
	void set_owner(const std::string& owner, size_t index);
	void set_number(const std::string& number, size_t index);
	void set_adress(const std::string& adress, size_t index);
	void set_business_activity(const std::string& business_activity, size_t index);


	/*==== Getters ====*/
	std::string get_name(size_t index) const { return arr_.at(index).get_name(); }
	std::string get_owner(size_t index) const { return arr_.at(index).get_owner(); }
	std::string get_number(size_t index) const { return arr_.at(index).get_number(); }
	std::string get_adress(size_t index) const { return arr_.at(index).get_adress(); }
	std::string get_business_activity(size_t index) const { return arr_.at(index).get_business_activity(); }


	/*==== add/remove ====*/
	void add(const std::string name, const std::string owner, const std::string number, const std::string adress, const std::string business_activity);
	void remove(size_t index);


	/*==== Show ====*/
	void show_all() const;


	/*==== Search ====*/
	size_t search_by_name(const std::string& name) const;
	size_t search_by_owner(const std::string& owner) const;
	size_t search_by_number(const std::string& number) const;
	size_t search_by_business_activity(const std::string& business_activity) const;

	friend struct LookUpIO;

	/*==== Save/Load ====*/
	bool save_to_file(const std::string& filename) const;
	bool load_from_file(const std::string& filename);
};


//Реализовать следующие возможности :
//
//Поиск по названию
//Поиск по владельцу
//Поиск по номеру телефона
//Поиск по роду деятельности
//Показ всех записей и добавление
//Вся информация, должна сохранятся в файле, должна быть реализована возможность добавления новых данных.