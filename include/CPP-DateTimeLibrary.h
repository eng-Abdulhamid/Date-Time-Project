#pragma once
// #pragma warning (disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "CPP-StringUtilLibrary.h"
#include "CPP-UtilitiesLibrary.h"

class clsDate
{
private:
    short _year = 0;
    short _month = 0;
    short _day = 0;
    short _Hour = 0;
    short _Mintue = 0;
    short _Seconds = 0;

protected:
    static void PrintDaysHeader(short month) // for PrintMonthCalender
    {
        if (month > 12 || month < 1)
        {
            cout << "Ivalid Month!" << endl;
            return;
        }
        // Print the current month name
        cout << "\n\n   __________________" << IndexOfShortMonthName(month) << "___________________\n\n";
        // Show the Days in week (COLOMNS)
        cout << setw(6) << "Sun";
        cout << setw(6) << "Mon";
        cout << setw(6) << "Tue";
        cout << setw(6) << "Wed";
        cout << setw(6) << "Thu";
        cout << setw(6) << "Fri";
        cout << setw(6) << "Sat" << endl;
    }
    static void PrintMonthDates(short year, short month) // for PrintMonthCalender
    {
        // index of the day from 0 to 6
        short CurrentDayIndex = DayOfWeekOrder(year, month, 1);

        short NumberOfDays = NumberOfDaysInMonth(year, month);

        int j;
        // Print appropriate Spaces
        for (j = 0; j < CurrentDayIndex; j++)
        {
            printf("      ");
        }
        for (short date = 1; date <= NumberOfDays; date++)
        {
            printf("%6d", date);
            if (++j == 7)
            {
                j = 0;
                cout << endl;
            }
        }
    }

public:
    clsDate()
    {
        *this = GetSystemDate();
    }
    clsDate(short DaysNumber, short Year)
    {
        *this = dayDataFromNumberOfDayFromBeginningTheYear(Year, DaysNumber);
    }
    clsDate(short day, short month, short year)
    {
        _day = day;
        _month = month;
        _year = year;
    }
    clsDate(string Date__MM_dd_yyyy)
    {
        *this = ConvertStringToDate(Date__MM_dd_yyyy);
    }
    void SetHour(short Hour)
    {
        _Hour = Hour;
    }
    short Hour()
    {
        return _Hour;
    }
    void SetMintue(short Mintue)
    {
        _Mintue = Mintue;
    }
    short Mintue()
    {
        return _Mintue;
    }
    void SetSeconds(short Second)
    {
        _Seconds = Second;
    }
    short Second()
    {
        return _Seconds;
    }

    void SetDay(short Day)
    {
        _day = Day;
    }
    void SetMonth(int Month)
    {
        _month = Month;
    }
    void SetYear(int Year)
    {
        _year = Year;
    }
    short day()
    {
        return _day;
    }
    short month()
    {
        return _month;
    }
    short year()
    {
        return _year;
    }

    vector<string> Split(string st, string delim = " ");

    static clsDate GetSystemDate()
    {
        short day, month, year, hour, min, sec;
        time_t nowTime = time(0);
        tm *now = localtime(&nowTime);

        day = now->tm_mday;
        month = 1 + now->tm_mon;
        year = 1900 + now->tm_year;
        hour = now->tm_hour;
        min = now->tm_min;
        sec = now->tm_sec;

        clsDate Now(day, month, year);

        Now.SetHour(hour);
        Now.SetMintue(min);
        Now.SetSeconds(sec);
        return Now;
    }
    static clsDate ConvertStringToDate(string &date)
    {
        clsDate stDate;
        vector<string> vDate = clsString::Split(date, "/");
        stDate.SetDay(stoi(vDate[0]));
        stDate.SetMonth(stoi(vDate[1]));
        stDate.SetYear(stoi(vDate[2]));
        return stDate;
    }
    static string DateToString(clsDate Date)
    {
        string strDate = "";
        strDate = to_string(Date.day());
        strDate += "/";
        strDate += to_string(Date.month());
        strDate += "/";
        strDate += to_string(Date.year());
        return strDate;
    }
    string DateToString()
    {
        return DateToString(*this);
    }
    void printDate()
    {
        cout << DateToString(*this) << endl;
    }
    static string ConvertNumberToText(long int Number) // التفقيط
    {
        if (Number == 0)
        {
            return "";
        }
        if (Number >= 1 && Number <= 19)
        {
            string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
            return arr[Number] + " ";
        }
        if (Number >= 20 && Number <= 99)
        {
            string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
            return arr[Number / 10] + " " + ConvertNumberToText(Number % 10); // Recursive - Recursion
        }
        if (Number >= 100 && Number <= 199)
        {
            return "One Hundred " + ConvertNumberToText(Number % 100);
        }
        if (Number >= 200 && Number <= 999)
        {
            return ConvertNumberToText(Number / 100) + "Hundreds " + ConvertNumberToText(Number % 100);
        }
        if (Number >= 1000 && Number <= 1999)
        {
            return "One Thousand " + ConvertNumberToText(Number % 1000);
        }
        if (Number >= 2000 && Number <= 999999)
        {
            return ConvertNumberToText(Number / 1000) + "Tousand " + ConvertNumberToText(Number % 1000);
        }
        if (Number >= 1000000 && Number <= 1999999)
        {
            return "One Million " + ConvertNumberToText(Number % 1000000);
        }
        if (Number >= 2000000 && Number <= 999999999)
        {
            return ConvertNumberToText(Number / 1000000) + "Million " + ConvertNumberToText(Number % 1000000);
        }
        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return "One Billion " + ConvertNumberToText(Number % 1000000000);
        }
        else
        {
            return ConvertNumberToText(Number / 1000000000) + " " + ConvertNumberToText(Number % 1000000000);
        }
        return " ";
    }
    static bool IsLeapYear(short year)
    {
        // one exprssion
        return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    }
    bool IsLeapYear()
    {
        return IsLeapYear(_year);
    }
    static short NumberOfDayInYear(short year)
    {
        return IsLeapYear(year) ? 366 : 365;
    }
    short NumberOfDayInYear()
    {
        return NumberOfDayInYear(_year);
    }

    static short NumberOfHoursInYear(short year)
    {
        return NumberOfDayInYear(year) * 24;
    }
    short NumberOfHoursInYear()
    {
        return NumberOfHoursInYear(_year);
    }

    static int NumberOfMinuteInYear(short year)
    {
        return NumberOfHoursInYear(year) * 60;
    }
    int NumberOfMinuteInYear()
    {
        return NumberOfMinuteInYear(_year);
    }

    static int NumberOfSecondsInYear(short year)
    {
        return NumberOfMinuteInYear(year) * 60;
    }
    int NumberOfSecondsInYear()
    {
        return NumberOfSecondsInYear(_year);
    }

    static void printDurationInCertainYear(short year)
    {
        cout << "Number Of Days----in year [" << year << "] is " << NumberOfDayInYear(year) << endl;
        cout << "Number of Hours---in year [" << year << "] is " << NumberOfHoursInYear(year) << endl;
        cout << "Number of Minutes-in year [" << year << "] is " << NumberOfMinuteInYear(year) << endl;
        cout << "Number of Seconds-in year [" << year << "] is " << NumberOfSecondsInYear(year) << endl;
    }
    void printDurationInCertainYear()
    {
        printDurationInCertainYear(_year);
    }

    // static short NumberOfDaysInMonth(short year, short month)
    // {
    //     if (month > 12 || month < 1)
    //         return 0;

    //     if (month == 2)
    //     {
    //         return IsLeapYear(year) ? 29 : 28;
    //     }

    //     short arrMonthWith31Day[7] = {1,3,5,7,8,10,12};
    //     for (short i = 0; i <= 7; i++)
    //     {
    //         if (month == arrMonthWith31Day[i - 1])
    //             return 31;
    //     }
    //     // 1, 3, 5, 7,8,10 ,12 -> 31 |||||| 4, 6, 9, 11 -> 30 ||||| 2 leap year or no
    //     return 30;
    // }
    // short NumberOfDaysInMonth()
    // {
    //     return NumberOfDaysInMonth(_year , _month);
    // }

    static short NumberOfDaysInMonth(short year, short month)
    {
        if (month > 12 || month < 1)
            return 0;
        // in two line...
        short arrDaysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrDaysInMonth[month];
    }
    short NumberOfDaysInMonth()
    {
        return NumberOfDaysInMonth(_year, _month);
    }
    static short NumberOfHoursInMonth(short year, short month)
    {
        return NumberOfDaysInMonth(year, month) * 24;
    }
    short NumberOfHoursInMonth()
    {
        return NumberOfHoursInMonth(_year, _month);
    }

    static int NumberOfMinuteInMonth(short year, short month)
    {
        return NumberOfHoursInMonth(year, month) * 60;
    }
    int NumberOfMinuteInMonth()
    {
        return NumberOfMinuteInMonth(_year, _month);
    }

    static int NumberOfSecondsInMonth(short year, short month)
    {
        return NumberOfMinuteInMonth(year, month) * 60;
    }
    int NumberOfSecondsInMonth()
    {
        return NumberOfSecondsInMonth(_year, _month);
    }
    static void PrintDurationsInCeratinMonthInCeartainYear(short year, short month)
    {
        cout << "Number Of Days----in certain month [" << year << "] is " << NumberOfDaysInMonth(year, month) << endl;
        cout << "Number of Hours---in certain month [" << year << "] is " << NumberOfHoursInMonth(year, month) << endl;
        cout << "Number of Minutes-in certain month [" << year << "] is " << NumberOfMinuteInMonth(year, month) << endl;
        cout << "Number of Seconds-in certain month [" << year << "] is " << NumberOfSecondsInMonth(year, month) << endl;
    }
    void PrintDurationsInCeratinMonthInCeartainYear()
    {
        return PrintDurationsInCeratinMonthInCeartainYear(_year, _month);
    }
    static short DayOfWeekOrder(short year, short month, short day)
    {
        short a = ((14 - month) / 12);
        short y = year - a;
        short m = month + 12 * a - 2;
        short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
        return d;
    }

    static int DayOfWeekOrder(clsDate date)
    {
        return DayOfWeekOrder(date.year(), date.month(), date.day());
    }
    int DayOfWeekOrder()
    {
        return DayOfWeekOrder(*this);
    }
    static string GetDayNameByDayOrderInWeek(short IndexOfDay)
    {
        /*
        => Day of week order:
            0 → Sunday
            1 → Monday
            2 → Tuesday
            3 → Wednesday
            4 → Thursday
            5 → Friday
            6 → Saturday
        */
        string ShortNameOfDays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return ShortNameOfDays[IndexOfDay];
    }
    static void PrintInfoOfBirthday(short year, short month, short day, short IndexOfDay, string NameOfDay)
    {
        cout << "Date      : " << day << '/' << month << '/' << year << endl;
        cout << "Day Order : " << IndexOfDay << endl;
        cout << "Day Name  : " << NameOfDay << endl;
    }
    void PrintInfoOfBirthday(short IndexOfDay, string NameOfDay)
    {
        return PrintInfoOfBirthday(_year, _month, _day, IndexOfDay, NameOfDay);
    }
    static string IndexOfShortMonthName(short month)
    {
        if (month > 12 || month < 1)
        {
            return "Ivalid Month!";
        }
        string MonthName[13] = {"", "Jan", "Feb", "March", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        return MonthName[month];
    }
    static void PrintMonthCalender(short year, short month)
    {
        if (month > 12 || month < 1)
        {
            printf("Ivalid Month!");
            return;
        }
        if (year < 1)
        {
            printf("Invalid <Year>!");
        }
        PrintDaysHeader(month);
        PrintMonthDates(year, month);
        cout << endl
             << "   ________________________________________" << endl;
    }
    void PrintMonthCalender()
    {
        return PrintMonthCalender(_year, _month);
    }
    static void PrintYearCalender(short year)
    {
        printf("\t_______________________________\n\n");
        printf("\t        PrintMonthCalender - %d\n", year);
        printf("\t_______________________________\n");

        for (short i = 1; i <= 12; i++)
        {
            // Reosabilite
            PrintMonthCalender(year, i);
            cout << endl;
        }
        return;
    }
    void PrintYearCalender()
    {
        return PrintYearCalender(_year);
    }
    static short TotalDaysFromBeginningTheYear(short day, short month, short year)
    {
        short TotalDays = 0;
        for (short i = 1; i < month; i++)
        {
            TotalDays += NumberOfDaysInMonth(year, i);
        }
        TotalDays += day;
        return TotalDays;
    }
    short TotalDaysFromBeginningTheYear()
    {
        return TotalDaysFromBeginningTheYear(_day, _month, _year);
    }
    static clsDate ReadFullDate()
    {
        short day, month, year;
        day = clsUtil::ReadIntNumber("Enter day?--");
        month = clsUtil::ReadIntNumber("Enter Month?--");
        year = clsUtil::ReadIntNumber("Enter Year?--");
        return clsDate(day, month, year);
    }
    static clsDate dayDataFromNumberOfDayFromBeginningTheYear(short year, short DayOrderInYear)
    {
        short day, month;
        short RemainingDay = DayOrderInYear;
        short monthDay = 0;
        month = 1;
        while (true)
        {
            monthDay = NumberOfDaysInMonth(year, month);

            if (RemainingDay > monthDay)
            {
                RemainingDay -= monthDay;
                month++;
            }
            else
            {
                day = RemainingDay;
                break;
            }
        }
        return clsDate(day, month, year);
    }
    clsDate dayDataFromNumberOfDayFromBeginningTheYear(short DayOrderInYear)
    {
        return dayDataFromNumberOfDayFromBeginningTheYear(_year, DayOrderInYear);
    }
    // clsDate AddDaysToDate_mySultion(clsDate date, short numOfDayToAdd)
    // {
    //     short CurrentMonth = NumberOfDaysInMonth(date.year , date.month);
    //     short numOfday = numOfDayToAdd - (CurrentMonth - date.day);
    //     while (numOfday > 0)
    //     {
    //         if ((CurrentMonth = NumberOfDaysInMonth(date.year,++date.month)) < numOfday)
    //         {
    //             numOfday -= CurrentMonth;
    //         }
    //         else
    //         {
    //             date.day = numOfday;
    //             break;
    //         }
    //         if (date.month > 12)
    //         {
    //             date.year++;
    //             date.month = 0; // It will be increase one every loop ....
    //         }
    //     }
    //     return date;
    // }
    static clsDate AddDaysToDate(clsDate Date, short DayToAdd)
    {
        short day, month, year;
        short RemaniningDays = DayToAdd + TotalDaysFromBeginningTheYear(day, month, year);
        short MonthDays = 0;
        bool IsMoreThanYear;
        month = 1;
        while (true)
        {
            IsMoreThanYear = (RemaniningDays > NumberOfDayInYear(year));
            MonthDays = NumberOfDaysInMonth(year, month);

            if (RemaniningDays > MonthDays)
            {
                if (IsMoreThanYear)
                {
                    RemaniningDays -= NumberOfDayInYear(year);
                    month += 12;
                }
                else
                {
                    RemaniningDays -= MonthDays;
                    month++;
                }

                if (month > 12)
                {
                    year++;
                    month = 1;
                }
            }
            else
            {
                day = RemaniningDays;
                break;
            }
        }
        Date.SetDay(day);
        Date.SetMonth(month);
        Date.SetYear(year);
        return Date;
    }
    clsDate AddDaysToDate(short DayToAdd)
    {
        return AddDaysToDate(*this, DayToAdd);
    }
    static bool isDate1BeforeThanDate2(clsDate Date1, clsDate Date2)
    {
        if (Date1.year() < Date2.year())
        {
            return true;
        }
        else if (Date1.month() < Date2.month())
        {
            return true;
        }
        else if (Date1.day() < Date2.day())
        {
            return true;
        }
        return false;
    }
    bool isDateBeforeDate2(clsDate date)
    {
        return isDate1BeforeThanDate2(*this, date);
    }
    // static bool isDate1LessThanDate2_Sultion2(clsDate Date1 , clsDate Date2)
    // {
    //     // if: year ,else: month ,else: day ,else: false
    //     // Short If Statemnt Short Hand If
    //     return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : ((Date1.month == Date2.month ? Date1.day < Date2.day : false))) : false);
    // }
    // bool isDate1LessThanDate2_Sultion2()
    // {
    //     return isDate1LessThanDate2_Sultion2(_Date1 , _Date2);
    // }
    static bool isDate1EqualToDate2(clsDate Date1, clsDate Date2)
    {
        // Ternary Short If Statment
        return ((Date1.year() == Date2.year()) ? ((Date1.month() == Date2.month()) ? ((Date1.day() == Date2.day()) ? true : false) : false) : false);
        // return condition ? true : false;
    }
    bool isThisDateEqualToDate2(clsDate Date2)
    {
        return isDate1EqualToDate2(*this, Date2);
    }
    static bool isLastDayInMonth(clsDate Date)
    {
        return (Date.day() == NumberOfDaysInMonth(Date.year(), Date.month()));
    }
    bool isLastDayInMonth()
    {
        return isLastDayInMonth(*this);
    }
    static bool isLastMonthInYear(short month)
    {
        return (month == 12);
    }
    bool isLastMonthInYear()
    {
        return isLastMonthInYear(_month);
    }
    static clsDate AddOneDay(clsDate &date)
    {
        short day, month, year;
        day = date.day();
        month = date.month();
        year = date.year();

        if (isLastDayInMonth(date))
        {
            if (isLastMonthInYear(month))
            {
                year++;
                day = 1;
                month = 1;
            }
            else
            {
                day = 1;
                month++;
            }
        }
        else
        {
            day++;
        }
        date = clsDate(day, month, year);
        return date;
    }
    clsDate AddOneDay()
    {
        return AddOneDay(*this);
    }
    static void SwapDates(clsDate &date1, clsDate &date2)
    {
        clsDate temp;
        temp = date1;
        date1 = date2;
        date2 = temp;
    }
    void SwapDates(clsDate &Date2)
    {
        SwapDates(*this, Date2);
    }
    static long int GetDifferenceInDays(clsDate date1, clsDate date2, bool includeEndDay = false)
    {
        int days = 0;
        short SwapFlagValue = 1;
        if (!isDate1BeforeThanDate2(date1, date2))
        {
            SwapDates(date1, date2);
            SwapFlagValue = -1;
        }
        while (isDate1BeforeThanDate2(date1, date2))
        {
            days++;
            date1 = AddOneDay(date1);
        }
        return (includeEndDay ? ++days : days) * SwapFlagValue;
    }
    long int GetDifferenceInDays(clsDate Date2, bool includeEndDay = false)
    {
        return GetDifferenceInDays(*this, Date2, includeEndDay);
    }
    static int CalculateMyAgeInDays(clsDate birthDay)
    {
        clsDate nowDate = GetSystemDate();
        return GetDifferenceInDays(birthDay, nowDate, true);
    }
    int CalculateMyAgeInDays()
    {
        return CalculateMyAgeInDays(*this);
    }
    int CalculateYearNumberByNumberOfDays(int DaysNumber)
    {
        return DaysNumber / 365;
    }
    int CalculateMyAgeInYears()
    {
        return CalculateYearNumberByNumberOfDays(CalculateMyAgeInDays(*this));
    }
    static clsDate AddXDays(clsDate &DateToIncrease, short numberOfDay_X)
    {
        for (short i = 0; i < numberOfDay_X; i++)
        {
            DateToIncrease = AddOneDay(DateToIncrease);
        }
        return DateToIncrease;
    }
    void AddXDays(short numberOfDay_X)
    {
        AddXDays(*this, numberOfDay_X);
    }
    static clsDate AddOneWeeks(clsDate &DateToIncrease)
    {
        DateToIncrease = AddXDays(DateToIncrease, 7);
        return DateToIncrease;
    }
    void AddOneWeeks()
    {
        AddOneWeeks(*this);
    }
    static clsDate AddXWeeks(clsDate &DateToIncrease, short numberOfWeeks)
    {
        for (short i = 0; i < numberOfWeeks; i++)
        {
            DateToIncrease = AddOneWeeks(DateToIncrease);
        }
        return DateToIncrease;
    }
    void AddXWeeks(short numberOfWeeks)
    {
        AddXWeeks(*this, numberOfWeeks);
    }
    static clsDate AddOneMonth(clsDate DateToIncrease)
    {
        short day = DateToIncrease.day(), month = DateToIncrease.month(), year = DateToIncrease.year();
        if (month == 12)
        {
            month = 1;
            year++;
        }
        else
        {
            month++;
        }
        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(year, month);
        if (day > NumberOfDaysInCurrentMonth)
        {
            day = NumberOfDaysInCurrentMonth;
        }
        DateToIncrease = clsDate(day, month, year);
        return DateToIncrease;
    }
    void AddOneMonth()
    {
        AddOneMonth(*this);
    }
    static clsDate AddXMonth(clsDate DateToIncrease, short NumberOfMonth)
    {
        for (short i = 0; i < NumberOfMonth; i++)
        {
            DateToIncrease = AddOneMonth(DateToIncrease);
        }
        return DateToIncrease;
    }
    void AddXMonth(short NumberOfMonth)
    {
        AddXMonth(*this, NumberOfMonth);
    }
    static clsDate AddOneYear(clsDate DateToIncrease)
    {
        short year = DateToIncrease.year();
        year++;
        DateToIncrease.SetYear(year);
        return DateToIncrease;
    }
    void AddOneYear()
    {
        AddOneYear(*this);
    }
    // clsDate AddxYear(clsDate DateToIncrease , short NumberOfyear)
    // {
    //     for (short i = 0;i<NumberOfyear;i++)
    //     {
    //         DateToIncrease = AddOneYear(DateToIncrease);
    //     }
    //     return DateToIncrease;
    // }
    static clsDate AddxYear(clsDate DateToIncrease, short NumberOfyear) // _faster
    {
        short year = DateToIncrease.year();
        year += NumberOfyear;
        DateToIncrease.SetYear(year);
        return DateToIncrease;
    }
    void AddxYear(short NumberOfyear)
    {
        AddxYear(*this, NumberOfyear);
    }
    static clsDate AddOneDecade(clsDate DateToIncrease)
    {
        short year = DateToIncrease.year();
        year += 10;
        DateToIncrease.SetYear(year);
        return DateToIncrease;
    }
    void AddOneDecade()
    {
        AddOneDecade(*this);
    }
    // static clsDate AddXDecades(clsDate DateToIncrease , short NumberOfDecade)
    // {
    //     for (short i = 0;i<NumberOfDecade * 10;i++)
    //     {
    //         DateToIncrease = AddOneYear(DateToIncrease);
    //     }
    //     return DateToIncrease;

    // }
    static clsDate AddXDecades(clsDate DateToIncrease, short NumberOfDecade) // _faster
    {

        short year = DateToIncrease.year();
        year += NumberOfDecade * 10;
        DateToIncrease.SetYear(year);
        return DateToIncrease;
    }
    void AddXDecades(short NumberOfDecade)
    {
        AddXDecades(*this, NumberOfDecade);
    }

    static clsDate AddOneCentury(clsDate DateToIncrease)
    {
        short year = DateToIncrease.year();
        year += 100;
        DateToIncrease.SetYear(year);
        return DateToIncrease;
    }
    void AddOneCentury()
    {
        AddOneCentury(*this);
    }
    static clsDate AddOneMillennium(clsDate DateToIncrease)
    {
        short year = DateToIncrease.year();
        year += 1000;
        DateToIncrease.SetYear(year);
        return DateToIncrease;
    }
    void AddOneMillennium()
    {
        AddOneMillennium(*this);
    }
    static bool isFirstDayInMonth(clsDate date)
    {
        return date.day() == 1;
    }
    bool isFirstDayInMonth()
    {
        return isFirstDayInMonth(*this);
    }
    static bool isFirstMonthInTheYear(clsDate date)
    {
        return (date.day() == 1 && date.month() == 1);
    }
    bool isFirstMonthInTheYear()
    {
        return isFirstMonthInTheYear(*this);
    }
    static clsDate DecreaseOneDay(clsDate date)
    {
        short day = date.day(), month = date.month(), year = date.year();
        if (isFirstDayInMonth(date))
        {
            if (isFirstMonthInTheYear(date))
            {

                year--;
                day = 31;
                month = 12;
            }
            else
            {
                month--;
                day = NumberOfDaysInMonth(year, month);
            }
        }
        else
        {
            day--;
        }
        date.SetDay(day);
        date.SetMonth(month);
        date.SetYear(year);
        return date;
    }
    void DecreaseOneDay()
    {
        DecreaseOneDay(*this);
    }
    static clsDate DecreasexDays(short daysToSubtracting, clsDate &date)
    {
        for (short i = 0; i < daysToSubtracting; i++)
        {
            date = DecreaseOneDay(date);
        }
        return date;
    }
    void DecreasexDays(short daysToSubtracting)
    {
        DecreasexDays(daysToSubtracting, *this);
    }
    static clsDate DecreaseOneWeeks(clsDate date)
    {
        date = DecreasexDays(7, date);
        return date;
    }
    void DecreaseOneWeeks()
    {
        DecreaseOneWeeks(*this);
    }
    static clsDate DecreaseXWeeks(short numOfWeeks, clsDate Date)
    {
        for (short i = 0; i < numOfWeeks; i++)
        {
            Date = DecreaseOneWeeks(Date);
        }
        return Date;
    }
    void DecreaseXWeeks(short numOfWeeks)
    {
        DecreaseXWeeks(numOfWeeks, *this);
    }
    static clsDate DecreaseOneMonth(clsDate date)
    {
        short day = date.day(), month = date.month(), year = date.year();
        if (month == 1)
        {
            month = 12;
            year--;
        }
        else
        {
            month--;
        }

        /*
            Last Check day in date should not exceed max days in the current month
            example if date is 31/3/2024 decreasing one month should not be 31/2/2024,it should be 28/2/2024..
        */
        short numberOfdayInCurrentMonth = NumberOfDaysInMonth(year, month);
        if (day > numberOfdayInCurrentMonth)
        {
            day = numberOfdayInCurrentMonth;
        }

        date.SetDay(day);
        date.SetMonth(month);
        date.SetYear(year);
        return date;
    }
    void DecreaseOneMonth()
    {
        DecreaseOneMonth(*this);
    }
    static clsDate DecreaseXMonth(short numberOfMonth, clsDate date)
    {
        for (short i = 0; i < numberOfMonth; i++)
        {
            date = DecreaseOneMonth(date);
        }
        return date;
    }
    void DecreaseXMonth(short numberOfMonth)
    {
        DecreaseXMonth(numberOfMonth, *this);
    }

    static clsDate DecreaseOneYear(clsDate date)
    {

        date.SetYear(date.year() - 1);
        return date;
    }
    void DecreaseOneYear()
    {
        DecreaseOneYear(*this);
    }
    // static clsDate DecreaseXYear(short numOfYear,clsDate date)
    // {
    //     for (short i = 0;i<numOfYear;i++)
    //     {
    //         date = DecreaseOneYear(date);
    //     }
    //     return date;
    // }
    static clsDate DecreaseXYear(short numOfYear, clsDate date) //_faster
    {
        date.SetYear(date.year() - numOfYear);
        return date;
    }
    void DecreaseXYear(short numOfYear)
    {
        DecreaseXYear(numOfYear, *this);
    }

    static clsDate DecreaseOneDecade(clsDate date)
    {
        // period of 10 year
        date.SetYear(date.year() - 10);
        return date;
    }
    void DecreaseOneDecade()
    {
        DecreaseOneDecade(*this);
    }
    // clsDate DecreaseXDecades(clsDate date , short numOfDecade)
    // {
    //     for (short i = 0;i<numOfDecade;i++)
    //     {
    //         date = DecreaseOneDecade(date);
    //     }
    //     return date;
    // }
    static clsDate DecreaseXDecades(clsDate date, short numOfDecade) // _faster
    {
        date.SetYear(date.year() - numOfDecade * 10);
        return date;
    }
    void DecreaseXDecades(short numOfDecade)
    {
        DecreaseXDecades(*this, numOfDecade);
    }
    static clsDate DecreaseOneCentury(clsDate date)
    {
        // Period of 100 years
        date.SetYear(date.year() - 100);
        return date;
    }
    void DecreaseOneCentury()
    {
        DecreaseOneCentury(*this);
    }
    static clsDate DecreaseOneMillennium(clsDate date)
    {
        date.SetYear(date.year() - 1000);
        return date;
    }
    void DecreaseOneMillennium()
    {
        DecreaseOneMillennium(*this);
    }
    static bool isEndOfWeek(clsDate date)
    {
        short indexOfDayInWeek = DayOfWeekOrder(date);
        return indexOfDayInWeek == 6;
    }
    bool isEndOfWeek()
    {
        return isEndOfWeek(*this);
    }
    static bool isWeekend(clsDate date)
    {
        // Weekends are Fri and Sat
        short indexOfDayInWeek = DayOfWeekOrder(date);
        return (indexOfDayInWeek == 5 || indexOfDayInWeek == 6);
    }
    bool isWeekend()
    {
        return isWeekend(*this);
    }
    static bool isBusinessDay(clsDate date)
    {
        // business Days are Sun, Mon, Thu, Wed and Thur <<
        // short indexOfDayInWeek = DayOfWeekOrder(date.year , date.month , date.day);
        // return (indexOfDayInWeek >= 5 && indexOfDayInWeek <= 4); // 4, 5 days are the weekend else are business days

        // every days in week regardless weekend are the business days <<
        // shorter method is to invert the isWeekend
        return !isWeekend(date);
    }
    bool isBusinessDay()
    {
        return isBusinessDay(*this);
    }
    static short DaysUntilEndOfWeek(clsDate date)
    {
        short indexOfDayInWeek = DayOfWeekOrder(date);
        return 6 - indexOfDayInWeek;
    }
    short DaysUntilEndOfWeek()
    {
        return DaysUntilEndOfWeek(*this);
    }
    short DaysUntilEndOfMonth(clsDate date)
    {
        clsDate EndofMonth;
        EndofMonth.SetDay(NumberOfDaysInMonth(date.year(), date.month()));
        EndofMonth.SetMonth(date.month());
        EndofMonth.SetYear(date.year());
        return GetDifferenceInDays(date, EndofMonth, true);
    }
    short DaysUntilEndOfMonth()
    {
        return DaysUntilEndOfMonth(*this);
    }
    static short DaysUntilEndOfYear(clsDate date)
    {
        clsDate EndOfYear;
        EndOfYear.SetDay(31);
        EndOfYear.SetMonth(12);
        EndOfYear.SetYear(date.year());

        return GetDifferenceInDays(date, EndOfYear, true);
    }
    short DaysUntilEndOfYear()
    {
        return DaysUntilEndOfYear(*this);
    }
    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
    {
        short vactionDays = 0;
        while (isDate1BeforeThanDate2(DateFrom, DateTo))
        {
            if (isBusinessDay(DateFrom))
                ++vactionDays;
            DateFrom = AddOneDay(DateFrom);
        }
        return vactionDays;
    }
    clsDate returnEndvactionDate(clsDate DateFrom, short VactionDays) // Simple Solution
    {
        while (VactionDays >= 0)
        {
            DateFrom = AddOneDay(DateFrom);
            if (!isWeekend(DateFrom))
            {
                --VactionDays;
            }
        }
        return DateFrom;
    }
    // in this Fuction We learn how does  for loop work ,, in some cases you can make it dynamic (by make the condtion long)
    // and athor cases you will make it fixed
    // clsDate returnEndvactionDate(clsDate DateFrom , short VactionDays) // Quit Complex Solution
    // {
    //     short WeekEndCounter = 0;

    //     // omit The begin weekend days then return to continue the code
    //     while (isWeekend(DateFrom))
    //     {
    //         DateFrom = AddOneDay(DateFrom);
    //     }

    //     for (int i = 1;i<VactionDays+WeekEndCounter;i++)
    //     {
    //         if (isWeekend(DateFrom))
    //             WeekEndCounter++;

    //         DateFrom = AddOneDay(DateFrom);

    //     }
    //     while (isWeekend(DateFrom))
    //     {
    //         DateFrom = AddOneDay(DateFrom);
    //     }
    //     return DateFrom;

    // }
    // bool isDate1AfterDate2_1(clsDate date1 , clsDate date2)
    // {
    //     return (!isDate1BeforeThanDate2(date1 , date2) && !isDate1EqualToDate2(date1 , date2));
    // }
    static bool isDate1AfterDate2(clsDate date1, clsDate date2)
    {
        return (date1.year() > date2.year() ? true : ((date1.year() == date2.year()) ? ((date1.month() > date2.month()) ? true : ((date1.month() == date2.month()) ? ((date1.day() > date2.day()) ? true : false) : false)) : false));
    }
    bool isDateAfterDate2(clsDate Date2)
    {
        return isDate1AfterDate2(*this, Date2);
    }

    // short C1ompareDate(clsDate date1 , clsDate date2)
    // {
    //     return (isDate1BeforeThanDate2(date1 , date2) ? -1 : (isDate1AfterDate2(date1 ,date2) ? 1 : 0));
    // }
    enum enCompareDate
    {
        befor = -1,
        Equal = 0,
        after = 1
    };

    static enCompareDate CompareDate(clsDate date1, clsDate date2)
    {
        if (isDate1AfterDate2(date1, date2))
        {
            return enCompareDate::after;
        }
        else if (isDate1BeforeThanDate2(date1, date2))
        {
            return enCompareDate::befor;
        }
        return enCompareDate::Equal;
    }
    enCompareDate CompareDate(clsDate Date2)
    {
        return CompareDate(*this, Date2);
    }
    static bool isValid(clsDate date)
    {
        if (date.day() < 1 || (date.month() > 12 || date.month() < 1))
            return false;

        if (date.day() > NumberOfDaysInMonth(date.year(), date.month()))
            return false;

        return true;
    }
    bool isValid()
    {
        return isValid(*this);
    }
    int charToInt(char ch)
    {
        switch (ch)
        {
        case 48:
            return 0;
        case 49:
            return 1;
        case 50:
            return 2;
        case 51:
            return 3;
        case 52:
            return 4;
        case 53:
            return 5;
        case 54:
            return 6;
        case 55:
            return 7;
        case 56:
            return 8;
        case 57:
            return 9;
        default:
            return 0;
        }
    }
    string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
    {
        short pos = S1.find(StringToReplace);

        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);

            pos = S1.find(StringToReplace); // find next
        }
        return S1;
    }
    string FormatDate(clsDate date, string Format = "dd/mm/yyyy")
    {
        string FormattedDateString = "";
        FormattedDateString = ReplaceWordInString(Format, "dd", to_string(date.day()));
        FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(date.month()));
        FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(date.year()));
        return FormattedDateString;
    }

    friend class clsPeriod;
};