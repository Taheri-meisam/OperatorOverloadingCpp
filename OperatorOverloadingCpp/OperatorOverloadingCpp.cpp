#include <iostream>
#include <string>
#include <cstring>
/* Compares the string */

class CompareString {
private:
	std::string Mystring;
public:
	CompareString();
	CompareString(const std::string);
	CompareString(const CompareString& RefObj); // 
	~CompareString();
	/*This prints the string stored in the class*/
	void Show() const;
	int GetLenght() const;
	void setVal(std::string);
	CompareString& operator ->* (const CompareString& Ref);
	///CompareString& operator * (const CompareString& Ref);
	int a = 100;
	CompareString& operator*=(int a);
	void operator |= (const CompareString& Ref2);
};

int main()
{
	CompareString Cstr1;
	CompareString Cstr2{"Nothing"};
	CompareString CstrCopy{Cstr2};
	CstrCopy.Show();
	Cstr1.setVal("!!! This is a test !!!");
	Cstr1->*Cstr2;

	Cstr2 *= 6;
	Cstr2.Show();

	Cstr1 |= Cstr2;

}

CompareString::CompareString()
{

}

CompareString::CompareString(const std::string newStr)
{
	this->Mystring = newStr;
}

CompareString::CompareString(const CompareString& RefObj)
{
	this->Mystring = RefObj.Mystring;
}

CompareString::~CompareString()
{
}

void CompareString::Show() const
{
	std::cout << this->Mystring << std::endl;
}

int CompareString::GetLenght() const
{
	return this->Mystring.length();
}

void CompareString::setVal(std::string newStr)
{
	this->Mystring = newStr;
}

CompareString& CompareString::operator->*(const CompareString& Ref)
{
	bool check = this->Mystring.length() > Ref.Mystring.length() ? true : false;

	if (check) {
		std::cout << this->Mystring << "Is greater" << std::endl;
	}
	else {
		std::cout << Ref.Mystring << "Is greater" << std::endl;
	}

	return *this;
}

CompareString& CompareString::operator*=(int a)
{
	// TODO: insert return statement here
	std::string temp = Mystring;
	for(int i = 0; i < a ;i++)
	{
		Mystring += temp;
	}

	return *this;
}

void CompareString::operator|=(const CompareString& Ref2)
{
	std::cout << "Operator assignment overloading" << std::endl;
	if (this == &Ref2) {
		std::cout << "They are equal";
	}

	// this->st = ref.st;

	for (auto i : Ref2.Mystring) {
		this->Mystring += i;
	}
	std::cout << "Operator assignment overloading" << std::endl;
	this->Show();

}
