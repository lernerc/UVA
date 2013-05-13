#include <iostream>
using namespace std;

int number(const char &a);

int main()
{
   string num;
   while(cin >> num)
   {
      // initallizing digit
      bool digit[62]={false};
      for(string::size_type i=0;i<num.size();i++)
      {
	 digit[number(num[i])]=true;
      }

      //initiallizing base
      int base=2;
      for(int i=2;i<62;i++)
      {
	 if(digit[i])
	 {
	    base=i+1;
	 }
      }
      // does not always give the lowest answer(starting point works
      // checking all the bases that are possible
      int ranbase=0;
      for(string::size_type i=0;i<num.size();i++)
      {
	 ranbase=(ranbase*base+number(num[i]))%(base-1);
      }
      while(base<63 && ranbase%(base-1)!=0)
      {
	 base++;
	 ranbase=0;
	 for(string::size_type i=0;i<num.size();i++)
	 {
	    ranbase=(ranbase*base+number(num[i]))%(base-1);
	 }
      }

      if (ranbase%(base-1)==0)
      {
	 cout << base << endl;
      }
      else
      {
	 cout << "such number is impossible!" << endl;
      }
   }
   return 0;
}
int number(const char &a)
{
   switch(a)
   {
      case '0':
	 return 0;
      case '1':
	 return 1;
      case '2':
	 return 2;
      case '3':
	 return 3;
      case '4':
	 return 4;
      case '5':
	 return 5;
      case '6':
	 return 6;
      case '7':
	 return 7;
      case '8':
	 return 8;
      case '9':
	 return 9;
      case 'A':
	 return 10;
      case 'B':
	 return 11;
      case 'C':
	 return 12;
      case 'D':
	 return 13;
      case 'E':
	 return 14;
      case 'F':
	 return 15;
      case 'G':
	 return 16;
      case 'H':
	 return 17;
      case 'I':
	 return 18;
      case 'J':
	 return 19;
      case 'K':
	 return 20;
      case 'L':
	 return 21;
      case 'M':
	 return 22;
      case 'N':
	 return 23;
      case 'O':
	 return 24;
      case 'P':
	 return 25;
      case 'Q':
	 return 26;
      case 'R':
	 return 27;
      case 'S':
	 return 28;
      case 'T':
	 return 29;
      case 'U':
	 return 30;
      case 'V':
	 return 31;
      case 'W':
	 return 32;
      case 'X':
	 return 33;
      case 'Y':
	 return 34;
      case 'Z':
	 return 35;
      case 'a':
	 return 36;
      case 'b':
	 return 37;
      case 'c':
	 return 38;
      case 'd':
	 return 39;
      case 'e':
	 return 40;
      case 'f':
	 return 41;
      case 'g':
	 return 42;
      case 'h':
	 return 43;
      case 'i':
	 return 44;
      case 'j':
	 return 45;
      case 'k':
	 return 46;
      case 'l':
	 return 47;
      case 'm':
	 return 48;
      case 'n':
	 return 49;
      case 'o':
	 return 50;
      case 'p':
	 return 51;
      case 'q':
	 return 52;
      case 'r':
	 return 53;
      case 's':
	 return 54;
      case 't':
	 return 55;
      case 'u':
	 return 56;
      case 'v':
	 return 57;
      case 'w':
	 return 58;
      case 'x':
	 return 59;
      case 'y':
	 return 60;
      case 'z':
	 return 61;
      default:
	 return 0;
   };
}
