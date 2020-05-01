/*
Check if the characters in a string form a Palindrome in O(1) extra space

Given a string str. The string may contain lower-case letters, special characters, digits or even white-spaces. The task is to check, whether only the letters present in the string are forming a Palindromic combination or not without using any extra space.

Note: It is not allowed to use extra space to solve this problem. Also, the letters present in the string are in lower-case and the string may contain special characters, digits or even white-spaces along with lowercase letters.

Examples:



Input : str = “m a 343 la y a l am”
Output : YES
The characters in the string form the sequence “malayalam”, which is a palindrome.

Input : str = “malayalam”
Output : YES
*/

#include"AllHeader.h"

int isPalindrome(string &str)
{
	int len = str.length();
	int i = 0, j = len - 1;
	while ( i != j)
	{
		if (str[i] < 'a' || str[i] > 'z')
		{
			i++;
			continue;
		}

		if(str[j] < 'a' || str[j] > 'z')
		{
			j--;
			continue;
		}

		if (str[i] != str[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int main()
{
	// string str("m a 343 la y a l am");
	string str("malayalam");
	cout << "Is Palindrome: " << isPalindrome(str) << endl;
	return 0;
}