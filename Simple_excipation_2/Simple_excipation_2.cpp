#include <iostream>
#include <windows.h>

using std::string;
using std::cout;
using std::cin;

class error : public std::exception {

public:
   error(string str) {};
   const char* what() const override { return "Вы ввели слово запретной длины! До свидания\n"; }

};


int  function(string str, int forbidden_length) {

   if (str.length() != forbidden_length)
      return str.length();
   else
      throw error(str);

}


int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   int ban_number{};
   string str;

   cout << "Введите запретную длинну: ";
   cin >> ban_number;

   do {
      std::cout << "\nВведите слово : ";
      cin >> str;

      try {
         cout << "Длина слова " << str << " равна " << function(str, ban_number) << "\n";
      }
      catch (const error& er) {
         cout << er.what();
         break;
      }
      catch (...) {
         cout << "Что-то пошло не так ";
         break;
      }
   } while (1);

   return 0;
}