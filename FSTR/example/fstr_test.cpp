#include <FSTR.h>
#include <FSTR_stream.h>
STR mystr("hello world!");
int count;

int main(){
  //testing STR constructor
  STR mystr2(mystr, 1000);
  std::cout << mystr2 << std::endl;

  //testing string and char concatenation
  mystr2 += ' ';
  mystr2 += mystr;
  std::cout << mystr2 << std::endl;

  //testing + operator
  mystr2 = mystr + " goodbye world!";
  std::cout << mystr2 << std::endl;
  mystr2 += " stupid world!";
  //testing insert STR
  STR mystr3("... NOT! ", 10);
  mystr2.insert(mystr3, 13);
  std::cout << mystr2 << '\n';

  std::cout << mystr2.substr(13)  << std::endl;

  //testing count() and find()
  STR mystr4("world!", 7);
  CNT cnt = mystr2.count(mystr4);
  std::cout << "found " << cnt.count << " occurences of \"world!\"" << '\n';
  std::cout << "found \"world!\" string at : ";
  for(uint8_t pos = 0; pos < cnt.count; pos++){
    std::cout << cnt.occ[pos] << ", ";
  }
  std::cout << '\n';

  //testing replace
  mystr2.replace(mystr4, "fishy!");
  std::cout << mystr2 << '\n';
  mystr2.replace('l', 'L');
  std::cout << mystr2 << '\n';
  mystr2.replace("fishy", "Mr. Clownfish");
  std::cout << mystr2 << '\n';
  std::cout << mystr2.find("fish") << '\n';
  mystr2.replace("Mr. Clownfish!", mystr4);
  mystr2.replace('L', 'l');
  std::cout << mystr2 << '\n';
  std::cout << mystr2.length() << '\n';
  //testing remove() and == operator
  mystr2.remove(12, 100);
  if(mystr2 == mystr){
    std::cout << "string 1 and string 2 both say \"" << mystr2 << '"' << std::endl;
  }
  else{
    std::cout << "string 1 and string 2 are not the same" << '\n';
    std::cout << "string 1 : " << mystr << '\n' << "length : " << mystr.length() << '\n';
    std::cout << "string 2 : " << mystr2 << '\n' << "length : " << mystr2.length() << '\n';
  }

  //testing large concatenation of single chars
  mystr2 = '\0';
  count = 0;
  while(count < 1000){
   mystr2 += 'a';
   count++;
  }
  std::cout << mystr2 << std::endl;

  //testing count char
  std::cout << "occurences of the letter \"a\" : " << mystr2.count('a').count << '\n';

  //testing pop + filling with character
  mystr2.pop(201);
//  std::cout << mystr2.length() << '\n';
  mystr2.insert('b', 90, 90);
//  std::cout << mystr2.length() << '\n';
  std::cout << mystr2 << std::endl;
  mystr2.insert("NOT A!!!!", 80);
  std::cout << mystr2 << std::endl;
  std::cout << "occurences of the letter \"b\" : ";
  std::cout << mystr2.count('b').count << '\n';
  return 0;
}
