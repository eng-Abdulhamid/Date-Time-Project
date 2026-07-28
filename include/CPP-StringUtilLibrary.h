#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class clsString
{
private:
    string _strValue = "";
    char _chValue;
public:
    enum enWhatTOCount {Small = 0 , Capital = 1 , space = 2 , SpicalChar= 3 , Number = 4, all=5};
    enum enWhatToTrim {All = 0 , right = 1 , left = 2};

    clsString()
    {
        
    }
    clsString(string Value)
    {
        _strValue = Value;
    }
    clsString (char cValue)
    {
        _chValue = cValue;
    }
    clsString(string strValue , char cValue)
    {
        _strValue = strValue;
        _chValue = cValue;
    }
    void SetstrValue(string Value)
    {
        _strValue = Value;
    }
    string strValue()
    {
        return _strValue;
    }
    void SetCharValue(char Value)
    {
        _chValue = Value;
    }
    char  CharValue()
    {
        return _chValue;
    }


    static int length(string s1)
    {
        return s1.length();
    }
    int length()
    {
        return _strValue.length();
    }


    
    // void GetFirstLetterOfEachWord1(string Str)
    // {
    //     cout << Str[0] << endl;
    //     for (int i = 0; i < Str.length();i++)
    //     {
    //         if (Str[i] == ' ') 
    //         {
    //             cout << Str[i+1] << endl;
    //         }
    //     }
    // }
    // void GetFirstLetterOfEachWord1()
    // {
    //     GetFirstLetterOfEachWord(_strValue);
    // }
    static void GetFirstLetterOfEachWord(string Str)
    {
        bool isFirstLetter = true;
        for (int i = 0; i < Str.length();i++)
        {
            if (Str[i] != ' ' && isFirstLetter) 
            {
                cout << Str[i] << endl;
            }
            isFirstLetter = (Str[i] == ' ' ? true : false);
        }
    }
    // void GetFirstLetterOfEachWord()
    // {
    //     GetFirstLetterOfEachWord(_strValue);
    // }

    static bool isUpper(char c)
    {
        return c >= 65 && c <= 90;
    }
    bool isUpper()
    {
        return isUpper(_chValue);
    }

    static char GetUpperCase(char c)
    {
        return char(c - 32);
    }
    void GetUpperCase()
    {
        _chValue = GetUpperCase(_chValue);
    }



    static string UpperFirstLetterOfEachWord(string st)
    {
        bool IsFirstLetter = true;
        for (int i = 0; i < st.length();i++)
        {
        
            if (st[i] != ' ' && IsFirstLetter)
            {
                st[i] = toupper(st[i]);        
            }
            IsFirstLetter = (st[i] == ' ' ?  true : false);
        }
        return st;
    }
    void UpperFirstLetterOfEachWord()
    {
        _strValue = UpperFirstLetterOfEachWord(_strValue);
    }

    static string toUpper(string str)
    {
        for (int i = 0;i<str.length();i++)
        {
            if (str[i] >= 97 && str[i] <= 122)
            {
                str[i] -= 32;
            }
        }
        return str;
    }
    void toUpper()
    {
        _strValue = toUpper(_strValue);
    }

    static string toLower(string str)
    {
        for (int i = 0;i<str.length();i++)
        {
            if (str[i] >= 65 && str[i] <= 90)
            {
                str[i] += 32;
            }
        }
        return str;
    }
    void toLower()
    {
        _strValue = toLower(_strValue);
    }
   static  char invertCharacterCase(char c)
    {
        return isupper(c) ? tolower(c) : toupper(c);
    }
    void invertCharacterCase()
    {
        _chValue =  invertCharacterCase(_chValue);
    }

    static string invertStringCase(string str)
    {
        for (int i = 0;i<str.length();i++)
        {
            str[i] = invertCharacterCase(str[i]);
        }
        return str;
    }
    void invertStringCase()
    {
        _strValue = invertStringCase(_strValue);
    }

    static string lowerFirstLetterInEachWord(string st , int unlessWord_index = 1000) 
    {
        bool isFirstLetter = true;
        
        for (int i = 0;i<st.length();i++)
        {
            if ((st[i] != ' ' && isFirstLetter) && !(i == unlessWord_index))
            {
                st[i] = tolower(st[i]);
            }
            isFirstLetter = (st[i] == ' ' ? true : false);
        }
        return st;
    }
    void lowerFirstLetterInEachWord(int unlessWord_index = 1000) 
    {
        _strValue = lowerFirstLetterInEachWord(_strValue , unlessWord_index);
    }

    static int CountOfSmallLetterOn(string st)
    {
        int Small = 0;
        for (char &i : st)
        {
            if (islower(i) ) Small++;
        }
        return Small;
    }
    int CountOfSmallLetterOn()
    {
       return CountOfSmallLetterOn(_strValue);
    }
    static int CountOfCapitalLetterIn(string st)
    {
        int Capital = 0;
        for(char &i : st)
        {
            if (isUpper(i) ) Capital++;
        }
        return Capital;
    }
    int CountOfCapitalLetterIn()
    {
        return CountOfCapitalLetterIn(_strValue);
    }

    static bool ispunc(char i )
    {
        return (i >= 33 && i <= 47) || (i >= 58 && i <= 64) || (i >= 91 && i <= 96);
    }
    bool ispunc()
    {
        return ispunc(_chValue);
    }

    static bool isSpace(char i)
    {
        return i == 32;
    }
    bool isSpace()
    {
        return  isSpace(_chValue);
    }

    static bool isNumber(char i)
    {
        return i >= 48 && i <= 57;
    }
    bool isNumber()
    {
        return isNumber(_chValue);
    }

    static short ConutString(string st , short whatToCount_1small_2Capital_3space_4spicalChar_5Numbers_6all = 6)
    {
        enWhatTOCount whatToCount[6] = {enWhatTOCount::Small , enWhatTOCount::Capital , enWhatTOCount::space , enWhatTOCount::SpicalChar, enWhatTOCount::Number , enWhatTOCount::all};
        if (whatToCount[whatToCount_1small_2Capital_3space_4spicalChar_5Numbers_6all - 1] == enWhatTOCount::all) return st.length();
        
        int Counter = 0;
        for(char &i : st)
        {
            if (whatToCount[whatToCount_1small_2Capital_3space_4spicalChar_5Numbers_6all - 1] == enWhatTOCount::Capital    && isupper(i) ) Counter++;
            if (whatToCount[whatToCount_1small_2Capital_3space_4spicalChar_5Numbers_6all - 1] == enWhatTOCount::Small      && islower(i) ) Counter++;
            if (whatToCount[whatToCount_1small_2Capital_3space_4spicalChar_5Numbers_6all - 1] == enWhatTOCount::SpicalChar && ispunc(i)) Counter++;
            if (whatToCount[whatToCount_1small_2Capital_3space_4spicalChar_5Numbers_6all - 1] == enWhatTOCount::Number     && isNumber(i)) Counter++;
            if (whatToCount[whatToCount_1small_2Capital_3space_4spicalChar_5Numbers_6all - 1] == enWhatTOCount::space      && isSpace(i) ) Counter++;

        }
        return Counter;
    }
    short ConutString(short whatToCount_1small_2Capital_3space_4spicalChar_5Numbers_6all = 6)
    {
        return ConutString(_strValue , whatToCount_1small_2Capital_3space_4spicalChar_5Numbers_6all);
    }

    static bool isNaN(string st)
    {
        for (char &c : st)
        {
            if (isNumber(c)) return false;
        }
        return true;
    }
    bool isNaN()
    {
        return isNaN(_strValue);
    }

    static string trim_string(string st , short WhatToTrim_1All_2right_3left = 1 , char char_to_Trim = ' ')
    {
        enWhatToTrim WhatToTrim[3] = {enWhatToTrim::All , enWhatToTrim::right , enWhatToTrim::left};

        string Result = "";
        int first_Characters = 0;
        int Last_Characters  = 0;

        for (int i = 0;i < st.length() / 2;i++)
        {
            if (st[i] != char_to_Trim) break;
            first_Characters++;
        }
        for (int i = st.length()-1;i > 0;i--)
        {              
            if (st[i] != char_to_Trim) break;
            Last_Characters++;
        }
        if (WhatToTrim[WhatToTrim_1All_2right_3left - 1] == enWhatToTrim::All)
        {
            for (int i = first_Characters;i<st.length() - Last_Characters;i++)
            {
                Result += st[i];
            }
        }
        if (WhatToTrim[WhatToTrim_1All_2right_3left - 1]  == enWhatToTrim::right)
        {
            for (int i = first_Characters; i < st.length();i++)
            {
                Result += st[i];
            }
        }
        if (WhatToTrim[WhatToTrim_1All_2right_3left - 1]  == enWhatToTrim::left)
        {
            for (int i = 0;i<st.length()- Last_Characters;i++)
            {
                Result += st[i];
            }
        }
        
        return Result;
    }
    void trim_string(short WhatToTrim_1All_2right_3left = 1)
    {
        _strValue = trim_string(_strValue , WhatToTrim_1All_2right_3left , _chValue);
    }
    static string right_trim_string(string st , char char_to_Trim = ' ')
    {
        string Result = "";
        bool if_Next_Char = true;
        for (int i = 0;i < st.length();i++)
        {
            if (st[i] == char_to_Trim  && if_Next_Char) continue;
            Result += st[i];
            if_Next_Char = (st[i + 1] != char_to_Trim) ? true : false;
        }
        return Result;
    }
    void right_trim_string()
    {
        _strValue = right_trim_string(_strValue , _chValue);

    }
    static string Left_trim_string(string st,  char char_to_Trim = ' ')
    {
        string Result = "";
        bool if_Next_Char = true;
        for (int i = st.length() - 1;i > 0;i--)
        {
            if (st[i] == char_to_Trim  && if_Next_Char) continue;
            Result += st[st.length() - i];
            if_Next_Char = (st[i - 1] != char_to_Trim) ? true : false;
        }
        return Result;
    }
    void Left_trim_string()
    {
        _strValue = Left_trim_string(_strValue , _chValue);
    }

    // static short CountSpicificLetter(string st , char whatToCount = ' ') 
    // {
    //     short Counter = 0;
    //     for (char &c : st)
    //     {
    //         if (c == whatToCount) Counter++;
    //     }
    //     return Counter;
    // }
    // short CountSpicificLetter() 
    // {
    //     return CountSpicificLetter(_strValue, _chValue);
    // }

    static short CountSpicificLetter(string st , char whatToCount = ' ' , bool MachCase = true) 
    {
        short Counter = 0;
        for (char &c : st)
        {
            if ((tolower(c) == tolower(whatToCount)) && !MachCase) Counter++;
            else
            {
                if (c == whatToCount) Counter++;
            }
        }
        return Counter;
    }
    short CountSpicificLetter(bool MachCase = true) 
    {
        return CountSpicificLetter(_strValue , _chValue , MachCase);
    }
    static bool isVowel(char c)
    {
        c = tolower(c);
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'u') || (c == 'o');
    }
    bool isVowel()
    {
        return isVowel(_chValue);
    }

    static short CountVowel(string st){
        short Counter = 0;
        for (int i = 0;i<st.length();i++)
        {
            if (isVowel(st[i])) Counter++;
        }
        return Counter;
    } 
    short CountVowel()
    {
        return CountVowel(_strValue);
    }

    static string StoredAllVstringowelInString(string st ,bool Space = false , string _Space = " " ,bool indexOfVowel = false)
    {
        string AllOfVowel = "";
        for (int i = 0;i<st.length();i++)
        {
            if (isVowel(st[i]))
            {
                if(indexOfVowel) AllOfVowel += to_string(i) + "|";
                                AllOfVowel += st[i];
                if (Space)       AllOfVowel += _Space;
            }
        }
        return AllOfVowel;
    }
    void StoredAllVstringowelInString(bool Space = false , string _Space = " " ,bool indexOfVowel = false)
    {
        _strValue = StoredAllVstringowelInString(_strValue ,Space ,  _Space ,indexOfVowel);
    }
    static void PrintEachWordInString(string st)
    {
        string delim = " "; // Delimiter فراغ
        short position = 0;
        string sWord = "";
        while ((position = st.find(delim)) != std::string::npos /*st.npos (TOO!)*/)
        {
            sWord = st.substr(0 , position); // store the word in variable 
            if (sWord != "")
            {
                cout << sWord << endl;
            }
            st.erase(0 , position + delim.length());
        }
        if (st != "")
        {
            cout << st << endl; // last word in string after print all of word (after out from while loop)...
        }
    }
    void PrintEachWordInString()
    {
        PrintEachWordInString(_strValue);
    }

    static void PrintUserNameInGmailAddressInString(string st)
    {
        string delim = "@";
        short posOfDelim = 0;
        short posOfSpace = 0;
        short sizeOfUserName = 0;
        string sUserName = "";

        posOfDelim = st.find(delim);
        for (int i = posOfDelim; i > 0;i--)
        {
            if (st[i] == ' ') 
            {
                posOfSpace = i + 1;;
                break;
            }
        }
        sizeOfUserName = posOfDelim - posOfSpace;
        sUserName = st.substr(posOfSpace , sizeOfUserName);
        cout << sUserName;
    }
    void PrintUserNameInGmailAddressInString()
    {
        PrintUserNameInGmailAddressInString(_strValue);
    }

    static void PrintWipsiteOfGmailAddressInString(string st)
    {
        string delim = "@";
        short posOfDelim = 0;
        short posOfSpace = 0;
        short sizeOfUserName = 0;
        string sUserName = ""; 

        posOfDelim = st.find(delim);

        for (short i = posOfDelim; i < st.length();i++)
        {
            if (st[i + 1] == ' ' || i+1 == st.length() - 1) 
            {
                posOfSpace = i;
                break;
            }
        }
        sizeOfUserName = posOfSpace - posOfDelim;
        sUserName = st.substr(posOfDelim + 1 , sizeOfUserName);
        cout << sUserName;
    }
    void PrintWipsiteOfGmailAddressInString()
    {
        PrintWipsiteOfGmailAddressInString(_strValue);
    }

    static short CountEachWordInString(string st)
    {
        string delim = " "; // Delimiter فراغ
        short position = 0;
        short Counter = 0;
        while ((position = st.find(delim)) != std::string::npos /*st.npos (TOO!)*/)
        {
            Counter++;
            st.erase(0 , position + delim.length());
        }
        return position == st.length() - 1 ? Counter : Counter + 1;
    }
    short CountEachWordInString()
    {
        return CountEachWordInString(_strValue);
    }

    static short CountWords(string st)
    {
        string delim = " "; // Delimiter فراغ
        short position = 0;
        string sWord = "";
        short Counter = 0;
        while ((position = st.find(delim)) != std::string::npos /*st.npos (TOO!)*/)
        {
            sWord = st.substr(0 , position); // store the word in variable 
            if (sWord != "")
            {
                Counter++;
            }
            st.erase(0 , position + delim.length());
        }
        if (st != "")
        {
            Counter++; // Count last word in string after Count all of word (after out from while loop)...
        }
        return Counter;
    }
    short CountWords()
    {
        return CountWords(_strValue);
    }

    static vector<string> Split(string st , string delim = " ")
    {
        vector<string> Tokens;

        short position = 0;
        string sWord = "";
        
        while ((position = st.find(delim)) != std::string::npos /*st.npos (TOO!)*/)
        {
            sWord = st.substr(0 , position); // store the word in variable 
            // if (sWord != "")
            // {
                Tokens.push_back(sWord);
            // }
            st.erase(0 , position + delim.length());
        }
        if (st != "")
        {
        Tokens.push_back(st);
        }
        return Tokens;
    }
    vector<string> Split(string delim = " ")
    {
        return Split(_strValue , delim);
    }
    static string Trim_right(string st , char trim)
    {
        short pos = 0;
        for (int i = st.length() - 1; i > 0; i--)
        {       
            if (st[i] != trim)
            {
                break;
            }        
            pos++;
        }  
        return st.erase(st.length() - 1 - pos, st.length() - 1);
    }
    void Trim_right(char trim = ' ')
    {
        _strValue = Trim_right(_strValue , trim);
    }

    static string Trim_left(string st , char trim)
    {
        short pos = 0;
        for (short i = 0; i < st.length(); i++)
        {       
            if (st[i] != trim)
            {
                break;
            }
            pos++;
        }  
        return st.erase(0, pos);
    }
    void Trim_left(char trim = ' ')
    {
        _strValue = Trim_left(_strValue , trim);
    }

    static string Trim(string st , char trim ,short WhatToTrim_1All_2right_3left = 1)
    {
        enWhatToTrim WhatToTrim[3] = {enWhatToTrim::All , enWhatToTrim::right , enWhatToTrim::left};

        switch (WhatToTrim[WhatToTrim_1All_2right_3left])
        {
        case enWhatToTrim::right:
            st = Trim_right(st ,trim);
            return st;
        case enWhatToTrim::left:
            st = Trim_left(st , trim);
            return st;
        default:
            st = Trim_right(st, trim);
            st = Trim_left(st , trim);
            return st;
        }
    }
    void Trim(char trim = ' ' ,short WhatToTrim_1All_2right_3left = 1)
    {
        _strValue = Trim(_strValue, trim, WhatToTrim_1All_2right_3left);
    }
    static string Trimleft(string st , char trim)
    {
        for (int i = 0; i< st.length() - 1;i++)
        {
            if (st[i] != trim)
            {
                return st.substr(i , st.length() - i);
            }
        }
        return "";
    }
    void Trimleft(char trim = ' ')
    {
        _strValue = Trimleft(_strValue , trim);
    }

    static string Trimright(string st , char trim)
    {
        for (short i = st.length() - 1; i >= 0;i--)
        {
            if (st[i] != trim)
            {
                return st.substr(0 , i + 1);
            }
        }
        return "";
    }
    void Trimright(char trim = ' ')
    {
        _strValue = Trimright(_strValue , trim);
    }
    static string Trim(string st , char trim)
    {
        return Trimright(Trimleft(st , trim) , trim);
    }

    static string join(vector<string> stArr, string Delimiter) // aginest of Split 
    {
        string stJoin = "";
        for (string &c : stArr) // for each 
        {
            stJoin += c + Delimiter;
        }   
        return stJoin.substr(0 , stJoin.length() - Delimiter.length());
    }
    static string join(string stArr[] , short length , string Delimiter) // overLoding -> same fuction but deffirent signture
    {
        string stJoin = "";
        for (int i = 0;i<length;i++) // for each 
        {
            stJoin += stArr[i] + Delimiter;
        }   
        return stJoin.substr(0 , stJoin.length() - Delimiter.length());
    }
    static string ReverseWords(string st)
    {
        string Reverse = "";
        short pos = 0;
        // if Find Function don't Return a value ,will Return 'std::string::npos'
        while ((pos = st.rfind(' ')) != std::string::npos)  
        {
            // Add last word to first string "Reverse"------------
            short length_of_Word = st.length() - (pos + 1);
            Reverse += st.substr(pos + 1 , length_of_Word) + ' ';

            // Omit added Word from string "st"-------------------
            short last = st.length() - 1;
            st.erase(pos, last);
        }
        
        Reverse += st; // Add Final Word To Reverse string Variable....
        return Reverse; // Return Reverse String :-) 
        // The `END`
    }
    void ReverseWords()
    {
        _strValue = ReverseWords(_strValue);
    }
    static string ReverseWordInString(string st)
    {
        string Reverse = ""; 
        vector<string> vString;
        vString = Split(st , " ");
        vector<string>::iterator iter = vString.end();
        while(iter != vString.begin())
        {
            iter--;
            Reverse += *iter + ' ';
        }
        return Reverse.substr(0, Reverse.length() - 1); //remove last space=
    } 
    void ReverseWordInString()
    {
        _strValue = ReverseWordInString(_strValue);
    }

    static string VaporWave(string st)
    {
        string Result = "";

        for (int i = 0;i<st.length();i++)
        {
            if (st[i] != ' '){

            if (st[i] >= 97 && st[i] <= 122)
            {
                Result += toupper(st[i]);
            }
            else 
            {
                Result += st[i];
            }
            Result += "  ";
            }
        }
        return Result.substr(0 , Result.length() - 2);
    }
    void VaporWave()
    {
        _strValue = VaporWave(_strValue);
    }
    // string Replace2(string st , string WordToReplace , string To)
    // {
    //     short pos = 0;
    //     while ((pos = st.find(WordToReplace)) != std::string::npos)
    //     {
    //         st = st.replace(pos , WordToReplace.length(),To);
    //     }
    //     return st;

    // }
    // string Replace2(string WordToReplace , string To)
    // {
    //     return Replace2(_strValue , WordToReplace , To);
    // }

    static int ReverseDigite(int digite)
    {
        short Reverse = 0;
        while (digite != 0)
        {
            Reverse += digite % 10;
            digite /= 10;
            Reverse = Reverse * 10;
        }
        return Reverse / 10;
    }
    static vector<int> digitize(int digit)
    {
        digit = ReverseDigite(digit);
        vector<int> d;
        short remaind = 0;
        while (digit != 0)
        {
            remaind = digit % 10;
            d.push_back(remaind);
            digit /= 10;
        }
        return d;
    }
    static string Replace(string st , string WordToReplace ,string To , bool MachCase = true) 
    {
        if (!MachCase)
        {
            WordToReplace = toLower(WordToReplace);
            st = toLower(st);
        }
        vector<string> vString = Split(st," ");
        vector<string>::iterator iter = vString.begin();
        while(iter != vString.end())
        {
            iter++;
            if (*iter == WordToReplace)
            {
                *iter = To;
            }
        }
        return join(vString ," ");
    }
    void Replace(string WordToReplace , string To)
    {
        _strValue = Replace(_strValue , WordToReplace , To);
    }

    // string Replace3(string st , string wordToReplace , string to , bool machCase = true)
    // {
    //     vector<string> vString = Split(st);
    //     for (string &s : vString)
    //     {
    //         if (machCase)
    //         {
    //             if (wordToReplace == s)
    //             {
    //                 s = to;
    //             }
    //         }
    //         else 
    //         {
    //             if(toLower(s) == toLower(wordToReplace))
    //             {
    //                 s = to;
    //             }
    //         }
    //     }
    //     return join(vString , " ");
    // }
    static string RemovePunctuations(string st)
    {
        string Result = "";
        for (short i = 0;i<st.length();i++)
        {
            if(!ispunc(st[i])){
                Result += st[i];
            }
        }
        return Result;
    }
    void RemovePunctuations()
    {
        _strValue = RemovePunctuations(_strValue);
    }
    // static string subString(string st , short PosStart , short PosEnd , bool inc_end = true , bool countSpace = true)
    // {
    //     string str = "";
    //     for (int i = PosStart;(inc_end ? i <= PosEnd : i < PosEnd);i++)
    //     {
    //         if (!countSpace && st[i] == ' '){
    //             PosEnd++;
    //         }
    //         str += st[i];
    //     }
    //     return str;
    // }
    // string subString(short PosStart , short PosEnd , bool inc_end = true , bool countSpace = true)
    // {
    //     return subString(_strValue , PosStart , PosEnd , inc_end , countSpace);
    // }

    static string subString(string st ,short posStart , short size ,  bool countSpace = true , string IgnoreChar = "")
    {
        string str = "";
        bool IgnoreCharacter = false;
        if (isalpha(IgnoreChar[0]))
        {
            IgnoreCharacter = true;
        }
        for (int i = posStart;i <= posStart + size ;i++)
        {
            if (!countSpace && st[i] == ' ') 
            {
                size++;
            }
            if (IgnoreCharacter && st[i] == IgnoreChar[0]) continue;   
            
            str += st[i];
        }
        return str;

    }
    static string parse_string(string st)
    {
        string Result = "";
        for (int i = 0;i<st.length();i++)
        {
            if (st[i] == '=')
            {
                Result += ": ";
                continue;
            }
            if (st[i] == '&')
            {
                Result += '\n';
                continue;
            }
            Result += st[i];
        }
        return Result;
    }
    void parse_string()
    {
        _strValue = parse_string(_strValue);
    }
    static string CleanString(string st ,bool spaceInstedOfPunc = false, bool countNumber = true , bool countUnderScore = false)
    {
        string Result = "";
        for (int i = 0;i<st.length();i++)
        {

            if (isupper(st[i]))
            {
                Result += st[i];
            }
            else if (islower(st[i]))
            {
                Result += st[i];
            }
            else if (countNumber && isNumber(st[i]))
            {
                Result += st[i];
            }
            else if (countUnderScore && st[i] == '_')
            {
                Result += st[i];
            }
            if (spaceInstedOfPunc && ispunc(st[i]))
            {
                Result += ' ';
            }
            
        }
        return Result;
    }
    void CleanString(bool spaceInstedOfPunc = false, bool countNumber = true , bool countUnderScore = false)
    {
        _strValue = CleanString(_strValue,spaceInstedOfPunc,countNumber ,countUnderScore);
    }
    // void ProgramToMarketing(string st)
    // {
    //     fstream file;
    //     file.open("Client Emails.txt" , ios::out | ios::app);
    //     string sEmail = "";
    //     vector<string> str = Split(st , "\n");
    //     for (string &s : str)
    //     {
    //         sEmail = "";
    //         for (int i = 0;i<s.length();i++)
    //         {
    //             if (s[i] != ',' || s[i] != ' ')
    //             {
    //                 sEmail += s[i]; 
    //             }
    //         }
    //         file << sEmail + '\n';
    //     }
        
    // }
    // int countWords(string st , char sep = ' ')
    // {
    //     int counter = 0;
    //     bool inWord = false;
    //     for (int i = 0; i < st.length();i++)
    //     {
    //         if (st[i] == sep)
    //         {
    //             if (inWord) // Before the separator was there a word?
    //             {
    //                 // if yes (true)
    //                 counter++;
    //                 inWord = false; // Reset Flag
    //             }
    //         }
    //         else 
    //         {
    //             inWord = true; // Set Flag that I'am in word
    //         }
    //     }
    //     if (inWord)
    //     {
    //         counter++;
    //     }
    //     return counter;
    // }
    // int countWords(char sep = ' ')
    // {
    //     return CountWords(_strValue , sep);
    // }
    // bool is_first_letter_capital(string st)
    // {
    //     short Pos = 0;
    //     while((Pos = st.find(' ')) != std::string::npos)
    //     {
    //         if (!isupper(st[0]) && !isspace(st[0]) && !ispunc(st[0])) return false;
    //         st.erase(0, Pos + 1);
    //     } 
    //     if (!isupper(st[0]) && !isspace(st[0]) && !ispunc(st[0])) return false;
        
    //     return true;
    // } 
    // bool is_first_letter_capital(string st)
    // {

    // }
    static bool isFirstLetterCapital(string st)
    {
        bool isWord = true;
        for (int i = 0;i<st.length();i++)
        {
            if(isWord && !isspace(st[i]) && !ispunc(st[i]) && !isupper(st[i]))
            {
                return false;
            }

            if (st[i] == ' ') isWord = true;
            else              isWord = false;

        }
        return true;
    }
    bool isFirstLetterCapital()
    {
        return isFirstLetterCapital(_strValue);
    }
};