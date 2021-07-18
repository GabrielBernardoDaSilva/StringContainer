#pragma once
#include <string.h>
#include <iostream>
#include <memory>





namespace gbLib {



	class String
	{
	private:
		char* str = nullptr;
	public:
		//constructors
		String();
		String(const char* string);
		String(const String& another);
		String(String&& another) noexcept;
		//destructor
		~String();
		//operators
		String& operator= (String&& another) noexcept;
		String& operator= (const char* string) noexcept;
		String operator+(const String& another);



		void Reverse();
		const char* GetString() const noexcept;
	};

}

std::ostream& operator <<(std::ostream& output, const gbLib::String& str);

