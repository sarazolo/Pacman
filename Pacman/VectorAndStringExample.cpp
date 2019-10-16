#include <vector>
#include <string>
#include <iostream>
#include <fstream>

int main()
{
    std::string s1 = "Hello world!";
    std::string s2("Hello world!");

    std::cout << s1[5] << '\n';
    std::cout << s1.size() << '\n';

    std::string s3 = s1 + " - " + s2;
    std::cout << s3 << '\n';
    std::cout << s3.size() << '\n';

    std::ifstream eula(R"(C:\Program Files (x86)\Notepad++\license.txt)");

    std::vector<std::string> eulaText;
    std::string line;
    while (getline(eula, line))
    {
        std::cout << line.size() << '\n';
        eulaText.push_back(line);
    }

    std::cout << "Row count of eula file: " << eulaText.size() << '\n';

    std::cout << "The 2nd char in the 1st line is: " << eulaText[0][1] << '\n';

    std::vector<int> vi;
    vi.push_back(7);
    
    vi.clear();
    if (vi.empty())
    {
        std::cout << "The vector is empty\n";
    }
}