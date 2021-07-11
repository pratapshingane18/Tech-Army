
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>
#include <windows.h>
int correct = 0;

using namespace std;
map<int, int> pass_factors;
class security_pass
{
protected:
    string str;
    int key;
    string file_name;
    int count = 0;
    float percentage;
    int cchoice;
    int fchoice, factor_no;
   int loop  ;
public:
    void factors();
    void suggetion();
};

void security_pass::factors()
{   count=0 ;
     loop = 0 ;
     pass_factors.clear();
    factor_no = 10;
    
         
    do
    {
        cout << endl
         << "Enter  use of which charecter for your password  is not permited in your application// (website)   " << endl;
        if(loop!=0){
        cout << endl
             << "0) remaining all are ok " << endl;
        }
        if(pass_factors.find(1)==pass_factors.end()){
        cout << endl
             << "1) Uppercase alphabets " << endl;
        }
        if(pass_factors.find(2)==pass_factors.end()){
        cout << endl
             << "2) lowercase alphabets " << endl;
        }
        if(pass_factors.find(3)==pass_factors.end()){
        cout << endl
             << "3) special charecters " << endl;
        }
        if(pass_factors.find(4)==pass_factors.end()){
        cout << endl
             << "4) Digits 0 to 1 " << endl;
        }
        
        if(loop==0){
        cout << endl
             << "5) All above listed can include" << endl;}
        cout << endl
             << "Enter the choices " << endl;
        cin >> fchoice;
        if (fchoice < 5 && fchoice != 0)
        {
            factor_no--;
            pass_factors[fchoice] = 1;
            loop++ ;
        }
        else if(fchoice!=5&&fchoice!=0){
            cout<<endl<<"You entered wrong choice "<<endl ;
             factors();
        }
        
        
             
    } while (fchoice != 0&&fchoice!=5);
}
void security_pass::suggetion()
{
    cout << endl
         << "suggetion >>>  TCltY#6uv12"
         << " " << endl;
}
class security_check : public security_pass
{
public:
    void check_length();
    void check_number();
    void check_special();
    void check_uppercase();
    void check_lowercase();
    void check_uppercase_repete();
    void check_repete_number();
    void check_repete_special();
    void check_lowercase_repete();
    void strength();
    int option();

    void getpass()
    {   
        factors();
        system("CLS");
        cout << endl
             << "Now you enter your password " << endl;
        cin >> str;
        cout<<endl<<" Recomendetion "<<endl;
        check_length();
    }
};
int security_check::option()
{
    cout << endl
         << "1) Try another combination " << endl;
    cout << endl
         << "2) Back " << endl;
    cout << endl
         << "Enter the choice" << endl;
    cin >> cchoice;
    if (cchoice == 1)
    {
        getpass();
    }
    else if (cchoice == 2)
    {
        correct = 1;
    }
    else
    {
        cout << endl
             << "wrong choice" << endl;
        option();
    }
}
void security_check ::strength()
{  
    percentage = (float)(100 * count) / factor_no;
    if (percentage <= 15)
    {

        cout << endl
             << "Your password is too weak " << endl;
        
    }
    else if (percentage <= 30)
    {
        cout << endl
             << "your pass is weak  " << endl;
    }
    else if (percentage <= 70)
    {
        cout << endl
             << "Your pass is moderate" << endl;
    }
    else if (percentage <= 90)
    {
        cout << endl
             << "Your pass is storng " << endl;
    }
    else if (percentage == 100)
    {
        cout << endl
             << "Your password is secure " << endl;
    }
    cout << endl
         << "Strength of password = " << percentage << " % " << endl;
}
void security_check::check_length()
{    
    int a = str.length();
    if (a < 8)
    {
        cout << "Password is to short " << endl;

        cout << endl
             << "TO make strong Password  keep length  atleast greter than  8 charectetrs " << endl;
             count-- ;
            
    }
    else if (a > 30)
    {
        cout << "Password is two long " << endl
             << endl
             << " It will be difficult to remember for you " << endl;     
    }
    else if (str.length() >= 13)
    {
        count += 2;
        
    }
    else
    {
        count++;
        
    }
    check_number();
    
}
void security_check::check_number()
{

    if (pass_factors.find(4) == pass_factors.end())
    {
        int check = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 48 && str[i] <= 57)
            {
                check = 1;
            }
        }
        if (check != 1)
        {
            cout << endl
                 << "To make password strong  try to include  atleast one number " << endl
                 << endl;
        }
        else
        {
            count++;
        }
    }
    check_special();
}
void security_check::check_special()
{

    if (pass_factors.find(3) == pass_factors.end())
    {
        int check = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 32 && str[i] <= 47 || str[i] >= 58 && str[i] <= 64 || str[i] >= 91 && str[i] <= 96 || str[i] >= 123 && str[i] <= 126)
            {
                check = 1;
            }
        }
        if (check != 1)
        {
            cout << endl
                 << "To make password strong  try to include  atleast one special charecter  " << endl
                 << endl;
        }
        else
        {
            count++;
        }
    }
    check_uppercase();
}
void security_check::check_uppercase()
{
    if (pass_factors.find(1) == pass_factors.end())
    {
        int check = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 65 && str[i] <= 90)
            {
                check = 1;
            }
        }
        if (check != 1)
        {
            cout << endl
                 << "To make password strong  try to include  atleast one uppercase later  " << endl
                 << endl;
                 count-- ;
        }
        else
        {
            count++;
        }
    }
    check_lowercase();
}
void security_check::check_lowercase()
{
    if (pass_factors.find(2) == pass_factors.end())
    {
        int check = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 97 && str[i] <= 122)
            {
                check = 1;
            }
        }
        if (check != 1)
        {
            cout << endl
                 << "To make password strong  try to include  atleast one lowercase later  " << endl
                 << endl;
                 count-- ;
        }
        else
        {
            count++;
        }
    }
    check_uppercase_repete();
}
void security_check::check_uppercase_repete()
{
    if (pass_factors.find(1) == pass_factors.end())
    {
        int check = 0;

        for (int i = 0; i < str.length() - 2; i++)
        {
            if ((str[i] >= 48 && str[i] <= 57 )&& (str[i + 1] >= 48 && str[i + 1] <= 57))
            {
                if (str[i + 2] >= 48 && str[i + 2] <= 57)
                {
                    check = 1;
                }
            }
        }
        if (check == 1)
        {
            cout << endl
                 << "To make strong password try to avoid consecutely using uppercase charecter more than 2 times ";
                 count-- ;
        }
        else
        {
            count++;
        }
    }
    check_lowercase_repete();
}

void security_check::check_lowercase_repete()
{
    if (pass_factors.find(2) == pass_factors.end())
    {
        int check = 0;
        for (int i = 0; i < str.length() - 2; i++)
        {
            if ((str[i] >= 97 && str[i] <= 122 )&& (str[i + 1] >= 97 && str[i + 1] <= 122))
            {
                if (str[i + 2] >= 97 && str[i + 2] <= 122)
                {
                    check = 1;
                }
            }
        }
        if (check == 1)
        {
            cout << endl
                 << "To make strong password try to avoid consecutely using lowercase charecter more than 2 times ";
        }
        else
        {
            count++;
        }
    }
    check_repete_special();
}
void security_check::check_repete_special()
{
    if (pass_factors.find(3) == pass_factors.end())
    {
        int check = 0;
        for (int i = 0; i < str.length() - 2; i++)
        {
            if (str[i] >= 32 && str[i] <= 47 || str[i] >= 58 && str[i] <= 64 || str[i] >= 91 && str[i] <= 96 || str[i] >= 123 && str[i] <= 126)
            {
                if (str[i + 1] >= 32 && str[i + 1] <= 47 || str[i + 1] >= 58 && str[i + 1] <= 64 || str[i + 1] >= 91 && str[i + 1] <= 96 || str[i + 1] >= 123 && str[i + 1] <= 126)
                {
                    check = 1;
                }
            }
        }
        if (check == 1)
        {
            cout << endl
                 << "To make strong password try to avoid consecutely use of special  charecter  ";
        }
        else
        {
            count++;
        }
    }
    check_repete_number();
}

void security_check::check_repete_number()
{
    if (pass_factors.find(4) == pass_factors.end())
    {
        int check = 0;
        for (int i = 0; i < str.length() - 2; i++)
        {
            if ((str[i] >= 48 && str[i] <= 57 ))
            {if((str[i + 1] >= 48 && str[i + 1] <= 57)){
                if (str[i + 2] >= 48 && str[i + 2] <= 57)
                {
                    check = 1;
                }}
            }
        }
        if (check == 1)
        {
            cout << endl
                 << "To make strong password try to avoid consecutely using numbers  charecter more than 2 times ";
        }
        else
        {
            count++;
        }
    }
    strength();
    suggetion();
    option();
}
class encrypt_decrypt : public security_pass
{
public:
    void getfile_name();
    void encryption();
    void decryption();
};

void encrypt_decrypt::getfile_name()
{
    cout << "Enter the file name \n"
         << endl;
    cin >> file_name;
    cout << "Enter the key" << endl;
    cin >> key;
}
void encrypt_decrypt::encryption()
{
    string out;
    char k;
    ifstream take;
    take.open(file_name.c_str(), ios::binary);
    ofstream give;
    cout << endl
         << "Enter the name for Encrypted file" << endl;
    cin >> out;
    give.open(out.c_str(), ios::binary);
    while (take.eof() == 0)
    {
        take >> noskipws >> k;
        int temp = (k + key);
        give << (char)temp;
    }
    take.close();
    give.close();
}
void encrypt_decrypt::decryption()
{
    char k;
    string out;
    ifstream take;
    take.open(file_name.c_str(), ios::binary);
    ofstream give;
    cout << endl
         << "Enter the name for decrypted file" << endl;
    cin >> out;
    give.open(out.c_str(), ios::binary);
    while (take.eof() == 0)
    {
        take >> noskipws >> k;
        int temp = k - key;
        give << (char)temp;
    }
    take.close();
    give.close();
}

int main()
{
    system("CLS");
    system("color 74");
    string pass;
    int a;
    int selected;
    security_check c1;
    encrypt_decrypt e1;
    int  choice;
    do
    {
        cout << endl
             << "Choose required service" << endl;
        cout << endl
             << "1)Password analyser." << endl;
        cout << endl
             << "2)File encryption " << endl;
        cout << endl
             << "3)File decryption " << endl;
        cout << endl
             << "4)Exit" << endl;
        cout << endl
             << "Enter the choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:

            do
            {
                c1.getpass();
                 
            } while (correct != 1);

            
            break;
        case 2:
            e1.getfile_name();
            e1.encryption();
            break;

        case 3:
            e1.getfile_name();
            e1.decryption();
            break;

        case 4:
            cout << endl
                 << " !! Closing the application !!" << endl;
            cout << endl
                 << " <<Thank you for using our application>>" << endl;
            exit(0);
            break;
        
         default:
         cout<<"Wrong choice"<<endl;
        }

    } while (choice != 4);
 
    return 0;
}
