#include "Serializer.hpp"

void setData(Data* data, std::string name, int age)
{
    data->name = name;
    data->age = age;
}

void PrintDataInfo(Data data)
{
    std::cout << "name: " << data.name << std::endl;
    std::cout << "age: " << data.age << std::endl;
}

int main(void)
{
    uintptr_t serializedAddress;
    struct Data* afterPerson;
    struct Data person;

    setData(&person, "JANE", 19);
    PrintDataInfo(person);
    std::cout << "person's before address: " << &person << std::endl << std::endl;

    serializedAddress = Serializer::serialize(&person);
    std::cout << serializedAddress << std::endl;
    afterPerson = Serializer::deserialize(serializedAddress);
    std::cout << "person's after address: " << afterPerson << std::endl;
    PrintDataInfo(*afterPerson);
    return (0);
}
