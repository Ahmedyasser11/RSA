#include "biginteger.h"



biginteger::biginteger()
{
}

string biginteger::addition(string s1, string s2)
{
	string result = {};
	char carry = 0;
	int l1 = s1.length();
	int l2 = s2.length();
	if (s1.length() <= s2.length())
	{
		for (int i = l1 - 1, j = l2 - 1; i >= 0; i--, j--) {

			int sum = (s1[i] - '0') + (s2[j] - '0') + carry;
			result.push_back(sum % 10 + '0');
			carry = sum / 10;


		}
		for (int i = l2 - l1 - 1; i >= 0; i--) {

			int sum = (s2[i] - '0') + carry;
			result.push_back(sum % 10 + '0');
			carry = sum / 10;
		}
		if (carry!=0) {
			result.push_back(carry + '0');

		}
	}
	else {
		for (int i = l2 - 1, j = l1 - 1; i >= 0; i--, j--) {

			int sum = (s1[j] - '0') + (s2[i] - '0') + carry;
			result.push_back(sum % 10 + '0');
			carry = sum / 10;


		}
		for (int i = l1 - l2 - 1; i >= 0; i--) {

			int sum = (s1[i] - '0') + carry;
			result.push_back(sum % 10 + '0');
			carry = sum / 10;
		}
		if (carry!=0) {
			result.push_back(carry + '0');

		}
	}
	reverse(result.begin(), result.end());
	return result;
}

string biginteger::multpication(string s1, string s2)
{

	string result = {};
	int l1 = s1.length();
	int l2 = s2.length();
	int n = l1, mid;
	if (l2 >= l1)
	{
		n = l2;
		for (int i = l2 - l1; i > 0; i--)
		{
			s1 = '0' + s1;
		}
	}
	else
	{
		n = l1;
		for (int i = l1 - l2; i > 0; i--)
		{
			s2 = '0' + s2;
		}
	}
	mid = (n / 2) + (n % 2);
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		string resul = {};
		int mul = (s1[0] - '0')*(s2[0] - '0');
		if (mul == 0)
		{
			return "0";
		}
		resul = to_string(mul);
		return resul;
	}
	string b = s1.substr(0, mid);      /////str1= b-a
	string a = s1.substr(mid, n);
	string d = s2.substr(0, mid);    ////str2=d-c
	string c = s2.substr(mid, n);
	string eq0 = multpication(a, c);
	string eq1 = multpication(addition(b, a), addition(d, c));
	string eq2 = multpication(b, d);
	string eq3 = subtrication(eq1, addition(eq0, eq2));

	for (int i = 0; i < n - n % 2; i++)
	{
		if (i < mid - n % 2)
		{

			eq3.push_back('0');
		}

		eq2.push_back('0');

	}
	result = addition(eq0, addition(eq3, eq2));


	return result;
}


string biginteger::subtrication(string s1, string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	string s3 = "";
	int borrow = 0;
	int sub;
	int mark = 0;
	if (s1 == s2)
		return "0";

	if (l1 == l2) {
		for (int i = 0; i < l1; i++) {
			if (s2[i] > s1[i]) {
				mark = 1;
				break;
			}
			else if (s1[i] > s2[i]) {
				mark = 2;
				break;
			}
		}
	}

	if (l2 > l1 || mark == 1) {
		int j = l2 - 1;
		for (int i = l1 - 1; i >= 0; i--) {
			sub = ((s2[j] - '0') - (s1[i] - '0') - borrow);

			if (sub < 0) {
				sub += 10;
				borrow = 1;
			}
			else {
				borrow = 0;
			}
			j--;
			s3.push_back(sub + '0');
		}
		for (int i = l2 - l1 - 1; i >= 0; i--) {
			int sub = ((s2[i] - '0') - borrow);
			if (sub < 0)
			{
				sub = sub + 10;
				borrow = 1;
			}
			else
				borrow = 0;

			if (i > 0)
				s3.push_back(sub + '0');
			else if (sub != 0)
				s3.push_back(sub + '0');
		}
	}
	else {
		int j = l1 - 1;
		for (int i = l2 - 1; i >= 0; i--) {
			sub = ((s1[j] - '0') - (s2[i] - '0') - borrow);

			if (sub < 0) {
				sub += 10;
				borrow = 1;
			}
			else
				borrow = 0;
			j--;
			s3.push_back(sub + '0');
		}
		for (int i = l1 - l2 - 1; i >= 0; i--) {
			int sub = ((s1[i] - '0') - borrow);
			if (sub < 0)
			{
				sub = sub + 10;
				borrow = 1;
			}
			else
				borrow = 0;
			if (i > 0)
				s3.push_back(sub + '0');
			else if (sub != 0)
				s3.push_back(sub + '0');
		}
	}

	reverse(s3.begin(), s3.end());

	return s3;
}


biginteger::~biginteger()
{
}