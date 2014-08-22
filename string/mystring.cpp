#include "mystring.h"
#include <string>

int main()
{
	String str("hello");
    String str1(str);
	String str2 = str1;  //zheyibu yeshi diaoyong copy gouzao hanshu
	String s;
	s = str2;    //diaoyong fuzhi gouzao hanshu 
	string ss;
	cin >> ss;
	cout << ss << endl;

	String sss;
	cin >> sss;
	cout << sss << endl;

	cout << str << "\t" << str1 << "\t" << str2 << "\t" << s << endl;
	return 0;
}
