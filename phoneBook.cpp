
#include<iostream>
#include<string>
using namespace std;
class Contact{
  private:
    string fname;
    string lname;
    string nickName;
    string phoneNumber;
    string darksetSecret;
    int id;
    bool is_empty;
  public:
    Contact()
    {
      is_empty = false;
    }
    void fillInfo(int i)
    {
      cout << "enter first name : ";
      //getline(cin, fname);
      cin >> fname ;
       cout << "enter last name : ";
    // getline(cin, lname);
     cin >> lname;
       cout << "enter nick name : ";
      // getline(cin, nickName);
      cin >> nickName;
      while(1)
      {
        cout << "enter phoneNumber : ";
       // getline(cin, phoneNumber);
      cin >> phoneNumber;
        if (check_number(phoneNumber))
          break;
        cout << "invalid number \n";
      }
      cout << "enter darksetSecret : ";
     // getline(cin, darksetSecret);
    cin >> darksetSecret;
    cout << "\n";
      is_empty = true;
    id = i;
    }
    void print()
    {
cout << "|";
cout << id << "         |";
printrow(fname);
printrow(lname);
printrow(nickName);
cout << "\n";
cout << "+----------+----------+----------+----------+\n";
    }
    void printrow(string s)
    {

      int i = 0;
      while(i < 10)
      {
        if (s[i])
        {
          cout << s[i];
        }
        else
        {
           cout << " ";
        }
        i++;
      }
      cout << "|";
    }
    int check_empty()
    {
      if (is_empty == false)
        return 1;
      return 0;
    }
    int check_number(string n)
    {
      int i = 0;
      while((n[i] >= '0' && n[i] <= '9') || n[i] == 32)
      {
        i++;
      }
      if (n[i] != 0)
        return (0);
      return (1);
    }
    int getId()
    {
      return id;
    }
 void   printAllData()
 {
   cout << fname << "\n";
   cout << lname << "\n";
   cout << nickName << "\n";
   cout << phoneNumber << "\n";
   cout << darksetSecret << "\n";
 }
};
class Phone {
  private :
    Contact data[8];
  public :
    void add()
    {
      cout << "\n";
      static int i;
      if (i < 8)
      {
        data[i].fillInfo(i);
        i++;
      }
      else
      {
          data[7].fillInfo(7);
      }
    }
    void search()
    {
      cout << "+----------+----------+----------+----------+\n";
      cout << "| id       |first name|last name |nick name |\n";
      cout << "+----------+----------+----------+----------+\n";
    int j = 0;
      while(j < 8)
      {
        if (data[j].check_empty())
          break;
         data[j++].print();
      }
     int nim = -55;
    cout << "index : ";
    cin >> nim;
   // getline(cin , nim);
   if (nim == -55)
   {
     cout << "invalid\n";
     return ;
   }
   else
   {
     j = 0;
    while(j < 8)
    {
      if (data[j].check_empty())
        break;
      if(data[j].getId() == nim)
      {
        data[j].printAllData();
        break;
      }
      j++;
    }
   }
   }
};
void printIntroMessage()
{
  cout << "| Wellcome in phoneBook |\n";
  cout << "enter : ADD | EXIT | SEARCH \n \n";
}
int main()
{
  Phone data;
  string input;
  printIntroMessage();
  while(1)
  {
    cout << "-> ";
    cin >> input;
    if (!input.compare("EXIT"))
      break;
    else if (!input.compare("ADD"))
     data.add();
    else if (!input.compare("SEARCH"))
     data.search();
  }
}
