//编写类string的构造函数，析够函数和赋值函数
#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
	//注意构造函数：参数提供默认参数，并且如果为空时，
	//分配一个字节的空间，并赋值为'\0',否则赋值字符串
	String(const char *s = NULL)
	{
		if (s == NULL)
		{
		    str = new char[1];
			*str = '\0';
		}
		else
		{
			str = new char[strlen(s)+1]();
			strcpy(str, s);
        }
	}

	//不应该令拷贝构造函数调用赋值构造函数，因为赋值构造函数作用在一个已经初始化的对象，而调用
	//拷贝构造函数的时候对象还未初始化完成，所以是不成功的。
	String(const String &other)
	{
		cout << "String copy" << endl; 
        str = new char[strlen(other.str)+1]();
		strcpy(str, other.str);
	}

	//调用赋值构造函数是在对象已经初始化完成时调用，所以可以删除str
	String &operator=(const String &rhs)
	{
		cout << "operator ==" << endl;
	    if (this == &rhs)
			return *this;
		delete [] str;  //注意删除的是数组
		str = new char[strlen(rhs.str)+1]();
		strcpy(str, rhs.str);
		return *this;
	}

	~String()
	{
		delete [] str;
		str = NULL;
	}

	//输入输出操作符重载为友元函数
	friend ostream& operator<<(ostream& os, const String &o)
	{
		os << o.str;
		return os;
	}
	
	friend istream& operator>>(istream& in, String &s)
	{
		in >> s.str;
		if (!in)
			s = String();  //gouzao yige linshi duixing fuwei
		return in;
	}
private:
    char *str;
};

