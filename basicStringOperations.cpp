#include <iostream>
#include <algorithm>
#include <string>
 
int main()
{
    std::string s = "This is an example";
    std::cout << s << '\n';
 
    s.insert(5, 1, 'w');
    std::cout << s << '\n';
    
    s.replace(6, 1, "a");
    std::cout << s << '\n';
    
    s.erase(6, 1);
    std::cout << s << '\n';
    
    s.replace(5, 1, 'i');  //ERROR HERE AS replace() does not accept "char" as 3rd argument, 3rd arg must be a string
    std::cout << s << '\n';
    
    s.replace(5, 1, "i");  
    std::cout << s << '\n'; // will work fine and print [This is an example]
 
    return 0;
}

// Output:
// This is an example
// This wis an example
// This was an example
// This ws an example
// This is an example
