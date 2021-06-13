#include "hdd/object.h"

using namespace ARL;

std::string* Object::Get_Name()
{
	return &name;
}

void Object::Set_Name(std::string new_name)
{
	name = new_name;
}

std::string* Object::Get_Description()
{
	return &description;
}

void Object::Set_Description(std::string new_description)
{
	description = new_description;
}

void Object::Mod_Description(std::string description_mod)
{
	description = description + description_mod;
}
