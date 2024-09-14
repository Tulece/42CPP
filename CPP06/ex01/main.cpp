#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.id = 42;
	data.name = "Test";
	data.value = 3.14f;

	std::cout << "Original Data address: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);

	std::cout << "Serialized Data: " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "Deserialized Data address: " << deserializedData << std::endl;

	if (deserializedData == &data)
	{
		std::cout << "Pointers are equal." << std::endl;
	}
	else
	{
		std::cout << "Pointers are not equal." << std::endl;
	}

	std::cout << "Deserialized Data contents:" << std::endl;
	std::cout << "id: " << deserializedData->id << std::endl;
	std::cout << "name: " << deserializedData->name << std::endl;
	std::cout << "value: " << deserializedData->value << std::endl;

	return 0;
}
