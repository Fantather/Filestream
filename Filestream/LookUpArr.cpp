#include "LookUpArr.h"

/*==== Setters ====*/
void LookUpArr::set_name(const std::string& name, size_t index)
{
	if (!arr_.empty()) {
		arr_.at(index).set_name(name);
	}
}

void LookUpArr::set_owner(const std::string& owner, size_t index)
{
	if (!arr_.empty()) {
		arr_.at(index).set_owner(owner);
	}
}

void LookUpArr::set_number(const std::string& number, size_t index)
{
	if (!arr_.empty()) {
		arr_.at(index).set_number(number);
	}
}

void LookUpArr::set_adress(const std::string& adress, size_t index)
{
	if (!arr_.empty()) {
		arr_.at(index).set_adress(adress);
	}
}

void LookUpArr::set_business_activity(const std::string& business_activity, size_t index)
{
	if (!arr_.empty()) {
		arr_.at(index).set_business_activity(business_activity);
	}
}



/*==== add ====*/
void LookUpArr::add(const std::string name, const std::string owner, const std::string number, const std::string adress, const std::string business_activity)
{
	arr_.emplace_back(name, owner, number, adress, business_activity);
}


/*==== remove ====*/
void LookUpArr::remove(size_t index)
{
	if (index < arr_.size()) {
		arr_.erase(arr_.begin() + index);
	}
}


/*==== show ====*/
void LookUpArr::show_all() const
{
	for (const auto& item : arr_) {
		item.print();
	}
}


/*==== Search ====*/
size_t LookUpArr::search_by_name(const std::string& name) const
{
	for (size_t i = 0; i < arr_.size(); ++i) {
		if (arr_[i].get_name() == name) {
			return i;
		}
	}
	return arr_.size(); // Return size if not found
}

size_t LookUpArr::search_by_owner(const std::string& owner) const
{
	for (size_t i = 0; i < arr_.size(); ++i) {
		if (arr_[i].get_owner() == owner) {
			return i;
		}
	}
	return arr_.size(); // Return size if not found
}

size_t LookUpArr::search_by_number(const std::string& number) const
{
	for (size_t i = 0; i < arr_.size(); ++i) {
		if (arr_[i].get_number() == number) {
			return i;
		}
	}
	return arr_.size(); // Return size if not found
}

size_t LookUpArr::search_by_business_activity(const std::string& business_activity) const
{
	for (size_t i = 0; i < arr_.size(); ++i) {
		if (arr_[i].get_business_activity() == business_activity) {
			return i;
		}
	}
	return arr_.size(); // Return size if not found
}


/*==== Save and Load ====*/
bool LookUpArr::save_to_file(const std::string& filename) const
{
	std::ofstream ofs(filename);
	if (!ofs) return false;

	ofs << arr_.size() << "\n";

	for (const auto& c : arr_) {
		c.saveToFile(ofs);
	}

	return true;
}

bool LookUpArr::load_from_file(const std::string& filename)
{
	std::ifstream ifs(filename);
	if (!ifs) return false;

	size_t count;
	if (!(ifs >> count))
		return false;

	std::string dummy;
	std::getline(ifs, dummy);	// Read \n

	arr_.clear();
	arr_.reserve(count)
		;
	for (size_t i = 0; i < count; ++i) {
		arr_.emplace_back();
		if (!arr_.back().loadFromFile(ifs))
			return false;
	}

	return true;
}



