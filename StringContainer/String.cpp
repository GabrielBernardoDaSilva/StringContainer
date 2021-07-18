#include "String.h"

char* deepCopy(char* dst, int size, char* src) {
	for (int i = 0; i < size; i++)
		dst[i] = src[i];
	return dst;
}


gbLib::String::String() : str(nullptr)
{
	str = new char[1];
	str[0] = '\0';
}

gbLib::String::String(const char* string) {
	unsigned int size = strlen(string) + 1;
	str = new char[size];
	strcpy_s(str, size, string);
}

gbLib::String::String(const String& another)
{
	if (str == nullptr)
		delete[] str;
	unsigned int len = strlen(another.str);
	str = new char[len];
	strcpy_s(str, len, another.str);
}

gbLib::String::String(String&& another) noexcept
{
	*this = std::move(another);
}

gbLib::String::~String()
{
	std::cout << "Destroying\n";
	delete str;
}

gbLib::String& gbLib::String::operator=(String&& another) noexcept
{
	if (this == &another) return *this;
	std::swap(str, another.str);
	return *this;
}

gbLib::String& gbLib::String::operator=(const char* string) noexcept
{
	if (str != nullptr)
		delete str;
	unsigned int size = strlen(string) + 1;
	str = new char[size];
	strcpy_s(str, size, string);
	return *this;
}

gbLib::String gbLib::String::operator+(const String& another)
{
	unsigned int len1 = strlen(str);
	unsigned int len2 = strlen(another.str);
	unsigned int len = len1 + len2;

	char* newString = new char[len];
	for (size_t i = 0; i < len; i++)
	{
		if (i < len1)
			newString[i] = str[i];
		else
			newString[i] = another.str[i - len1];
	}
	newString[len] = '\0';


	return gbLib::String(std::move(newString));
}



void gbLib::String::Reverse()
{
	unsigned int size = strlen(str);
	char* aux = new char[size];
	aux = deepCopy(aux, size, str);
	int index = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		str[index++] = aux[i];
	}
	delete[] aux;

}

const char* gbLib::String::GetString() const noexcept
{
	return str;
}


std::ostream& operator <<(std::ostream& output, const gbLib::String& str) {
	output << str.GetString() << "";
	return output;
}





