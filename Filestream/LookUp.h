#pragma once
#include <iostream>

//Создать класс СПРАВОЧНИК со следующими полями :
//
//Название фирмы
//Владелец
//Телефон
//Адрес
//Род деятельности

//Реализовать следующие возможности :
//
//Поиск по названию
//Поиск по владельцу
//Поиск по номеру телефона
//Поиск по роду деятельности
//Показ всех записей и добавление
//Вся информация, должна сохранятся в файле, должна быть реализована возможность добавления новых данных.

class LookUp {
private:
	std::string name_;
	std::string owner_;
	std::string number_;
	std::string adress_;
	std::string business_activity_;

public:
	// Constructor
	LookUp() = default;
	LookUp(const std::string name, const std::string owner, const std::string number, const std::string adress, const std::string business_activity)
		: name_(name), owner_(owner), number_(number), adress_(adress), business_activity_(business_activity) {}

	// Setter
	void set(const std::string name, const std::string owner, const std::string number, const std::string adress, const std::string business_activity)
	{
		name_ = name;
		owner_ = owner;
		number_ = number;
		adress_ = adress;
		business_activity_ = business_activity;
	}

	void set_name(const std::string& name) { name_ = name; }
	void set_owner(const std::string& owner) { owner_ = owner; }
	void set_number(const std::string& number) { number_ = number; }
	void set_adress(const std::string& adress) { adress_ = adress; }
	void set_business_activity(const std::string& business_activity) { business_activity_ = business_activity; }

	// Getters
	std::string get_name() const { return name_; }
	std::string get_owner() const { return owner_; }
	std::string get_number() const { return number_; }
	std::string get_adress() const { return adress_; }
	std::string get_business_activity() const { return business_activity_; }

	// Print
	void print() const
	{
		std::cout << "Name of company: " << name_ << "\n";
		std::cout << "Owner of company: " << owner_ << "\n";
		std::cout << "Number of company: " << number_ << "\n";
		std::cout << "Adress of company: " << adress_ << "\n";
		std::cout << "Business activity: " << business_activity_ << "\n";
	}

	// Save and Load
	bool saveToFile(std::ostream& os) const;
	bool loadFromFile(std::istream& is);
};