#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include "include/CPP-DateTimeLibrary.h"

using namespace std;

class clsScreen
{
public:
    static void Clear()
    {
        system("cls");
    }

    static void Pause()
    {
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    static void PrintHeader(string Title)
    {
        Clear();
        cout << "====================================================\n";
        cout << "            " << Title << "\n";
        cout << "====================================================\n\n";
    }

    static short ReadOption(short From, short To)
    {
        short Choice = 0;
        cout << "Choose an option [" << From << " - " << To << "]: ";
        while (!(cin >> Choice) || Choice < From || Choice > To)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between " << From << " and " << To << ": ";
        }
        return Choice;
    }

    static clsDate InputDate()
    {
        short Day, Month, Year;
        cout << "Enter Day: ";
        cin >> Day;
        cout << "Enter Month: ";
        cin >> Month;
        cout << "Enter Year: ";
        cin >> Year;
        return clsDate(Day, Month, Year);
    }
};

class clsFormattingModule
{
public:
    static void Show()
    {
        clsScreen::PrintHeader("Formatting & Initialization System");

        clsDate SystemDate = clsDate::GetSystemDate();
        cout << "System Date: ";
        SystemDate.printDate();

        string StringDate = "25/12/2025";
        clsDate ParsedDate = clsDate::ConvertStringToDate(StringDate);
        cout << "Parsed String Date: " << ParsedDate.DateToString() << "\n";

        clsDate DateFromDayOrder(100, 2026);
        cout << "Date From Day Order (100, 2026): " << DateFromDayOrder.DateToString() << "\n";

        clsDate CustomTimeDate(1, 1, 2026);
        CustomTimeDate.SetHour(14);
        CustomTimeDate.SetMintue(30);
        CustomTimeDate.SetSeconds(45);
        cout << "Custom Time: " << CustomTimeDate.Hour() << ":" << CustomTimeDate.Mintue() << ":" << CustomTimeDate.Second() << "\n";

        cout << "Formatted (yyyy-mm-dd): " << CustomTimeDate.FormatDate(CustomTimeDate, "yyyy-mm-dd") << "\n";
        cout << "Formatted (dd/mm/yyyy): " << CustomTimeDate.FormatDate(CustomTimeDate, "dd/mm/yyyy") << "\n";

        long int NumberToTextValue = 1234567;
        cout << "Number To Text (" << NumberToTextValue << "): " << clsDate::ConvertNumberToText(NumberToTextValue) << "\n";

        clsScreen::Pause();
    }
};

class clsCalendarModule
{
public:
    static void Show()
    {
        clsScreen::PrintHeader("Calendar & Year Statistics Module");

        clsDate Date = clsScreen::InputDate();

        cout << "\n--- Year Statistics ---\n";
        cout << "Is Leap Year: " << (Date.IsLeapYear() ? "Yes" : "No") << "\n";
        cout << "Days in Year: " << Date.NumberOfDayInYear() << "\n";
        cout << "Hours in Year: " << Date.NumberOfHoursInYear() << "\n";
        cout << "Minutes in Year: " << Date.NumberOfMinuteInYear() << "\n";
        cout << "Seconds in Year: " << Date.NumberOfSecondsInYear() << "\n";
        Date.printDurationInCertainYear();

        cout << "\n--- Month Statistics ---\n";
        cout << "Month Name: " << clsDate::IndexOfShortMonthName(Date.month()) << "\n";
        cout << "Days in Month: " << Date.NumberOfDaysInMonth() << "\n";
        cout << "Hours in Month: " << Date.NumberOfHoursInMonth() << "\n";
        cout << "Minutes in Month: " << Date.NumberOfMinuteInMonth() << "\n";
        cout << "Seconds in Month: " << Date.NumberOfSecondsInMonth() << "\n";
        Date.PrintDurationsInCeratinMonthInCeartainYear();

        cout << "\n--- Day Statistics ---\n";
        short DayOrder = Date.DayOfWeekOrder();
        string DayName = clsDate::GetDayNameByDayOrderInWeek(DayOrder);
        cout << "Day Order: " << DayOrder << "\n";
        cout << "Day Name: " << DayName << "\n";
        cout << "Total Days From Beginning of Year: " << Date.TotalDaysFromBeginningTheYear() << "\n";

        Date.PrintInfoOfBirthday(DayOrder, DayName);

        cout << "\n--- Month Calendar ---\n";
        Date.PrintMonthCalender();

        cout << "\nDo you want to display the full year calendar? (1: Yes, 0: No): ";
        short ShowYear;
        cin >> ShowYear;
        if (ShowYear == 1)
        {
            Date.PrintYearCalender();
        }

        clsScreen::Pause();
    }
};

class clsArithmeticModule
{
public:
    static void Show()
    {
        clsScreen::PrintHeader("Date Arithmetic Engine");

        clsDate Date = clsScreen::InputDate();
        cout << "Base Date: ";
        Date.printDate();

        cout << "\n--- Performing Addition Operations ---\n";
        Date = clsDate::AddDaysToDate(Date, 10);
        cout << "After AddDaysToDate (10): ";
        Date.printDate();

        Date.AddDaysToDate(5);
        cout << "After AddDaysToDate instance (5): ";
        Date.printDate();

        Date.AddOneDay();
        cout << "After AddOneDay: ";
        Date.printDate();

        Date.AddXDays(3);
        cout << "After AddXDays (3): ";
        Date.printDate();

        Date.AddOneWeeks();
        cout << "After AddOneWeeks: ";
        Date.printDate();

        Date.AddXWeeks(2);
        cout << "After AddXWeeks (2): ";
        Date.printDate();

        Date.AddOneMonth();
        cout << "After AddOneMonth: ";
        Date.printDate();

        Date.AddXMonth(2);
        cout << "After AddXMonth (2): ";
        Date.printDate();

        Date.AddOneYear();
        cout << "After AddOneYear: ";
        Date.printDate();

        Date.AddxYear(3);
        cout << "After AddxYear (3): ";
        Date.printDate();

        Date.AddOneDecade();
        cout << "After AddOneDecade: ";
        Date.printDate();

        Date.AddXDecades(2);
        cout << "After AddXDecades (2): ";
        Date.printDate();

        Date.AddOneCentury();
        cout << "After AddOneCentury: ";
        Date.printDate();

        Date.AddOneMillennium();
        cout << "After AddOneMillennium: ";
        Date.printDate();

        cout << "\n--- Performing Subtraction Operations ---\n";
        Date.DecreaseOneMillennium();
        cout << "After DecreaseOneMillennium: ";
        Date.printDate();

        Date.DecreaseOneCentury();
        cout << "After DecreaseOneCentury: ";
        Date.printDate();

        Date.DecreaseXDecades(2);
        cout << "After DecreaseXDecades (2): ";
        Date.printDate();

        Date.DecreaseOneDecade();
        cout << "After DecreaseOneDecade: ";
        Date.printDate();

        Date.DecreaseXYear(3);
        cout << "After DecreaseXYear (3): ";
        Date.printDate();

        Date.DecreaseOneYear();
        cout << "After DecreaseOneYear: ";
        Date.printDate();

        Date.DecreaseXMonth(2);
        cout << "After DecreaseXMonth (2): ";
        Date.printDate();

        Date.DecreaseOneMonth();
        cout << "After DecreaseOneMonth: ";
        Date.printDate();

        Date.DecreaseXWeeks(2);
        cout << "After DecreaseXWeeks (2): ";
        Date.printDate();

        Date.DecreaseOneWeeks();
        cout << "After DecreaseOneWeeks: ";
        Date.printDate();

        Date.DecreasexDays(3);
        cout << "After DecreasexDays (3): ";
        Date.printDate();

        Date.DecreaseOneDay();
        cout << "After DecreaseOneDay: ";
        Date.printDate();

        clsScreen::Pause();
    }
};

class clsVacationModule
{
public:
    static void Show()
    {
        clsScreen::PrintHeader("Business & Vacation Management");

        clsDate Date1 = clsScreen::InputDate();

        cout << "\n--- Day Properties ---\n";
        cout << "Is End Of Week: " << (Date1.isEndOfWeek() ? "Yes" : "No") << "\n";
        cout << "Is Weekend: " << (Date1.isWeekend() ? "Yes" : "No") << "\n";
        cout << "Is Business Day: " << (Date1.isBusinessDay() ? "Yes" : "No") << "\n";

        cout << "\n--- Remaining Days ---\n";
        cout << "Days Until End Of Week: " << Date1.DaysUntilEndOfWeek() << "\n";
        cout << "Days Until End Of Month: " << Date1.DaysUntilEndOfMonth() << "\n";
        cout << "Days Until End Of Year: " << Date1.DaysUntilEndOfYear() << "\n";

        cout << "\n--- Business Days Between Two Dates ---\n";
        cout << "Enter Second Date:\n";
        clsDate Date2 = clsScreen::InputDate();
        cout << "Business Days Count: " << clsDate::CalculateBusinessDays(Date1, Date2) << "\n";

        cout << "\n--- End Vacation Calculation ---\n";
        short VacationDays = 0;
        cout << "Enter Vacation Duration (Days): ";
        cin >> VacationDays;
        clsDate EndVacationDate = Date1.returnEndvactionDate(Date1, VacationDays);
        cout << "Vacation Ends On: ";
        EndVacationDate.printDate();

        clsScreen::Pause();
    }
};

class clsComparisonModule
{
public:
    static void Show()
    {
        clsScreen::PrintHeader("Date Comparison & Validation Engine");

        cout << "Enter First Date:\n";
        clsDate Date1 = clsScreen::InputDate();

        cout << "Enter Second Date:\n";
        clsDate Date2 = clsScreen::InputDate();

        cout << "\n--- Validation Checks ---\n";
        cout << "Date 1 Is Valid: " << (Date1.isValid() ? "Yes" : "No") << "\n";
        cout << "Date 2 Is Valid: " << (Date2.isValid() ? "Yes" : "No") << "\n";

        cout << "\n--- Boundary Checks (Date 1) ---\n";
        cout << "Is First Day In Month: " << (Date1.isFirstDayInMonth() ? "Yes" : "No") << "\n";
        cout << "Is First Month In Year: " << (Date1.isFirstMonthInTheYear() ? "Yes" : "No") << "\n";
        cout << "Is Last Day In Month: " << (Date1.isLastDayInMonth() ? "Yes" : "No") << "\n";
        cout << "Is Last Month In Year: " << (Date1.isLastMonthInYear() ? "Yes" : "No") << "\n";

        cout << "\n--- Relationship Comparisons ---\n";
        cout << "Is Date 1 Before Date 2: " << (Date1.isDateBeforeDate2(Date2) ? "Yes" : "No") << "\n";
        cout << "Is Date 1 Equal To Date 2: " << (Date1.isThisDateEqualToDate2(Date2) ? "Yes" : "No") << "\n";
        cout << "Is Date 1 After Date 2: " << (Date1.isDateAfterDate2(Date2) ? "Yes" : "No") << "\n";

        clsDate::enCompareDate CompareResult = Date1.CompareDate(Date2);
        cout << "Compare Result (-1: Before, 0: Equal, 1: After): " << CompareResult << "\n";

        cout << "\n--- Swap Operation ---\n";
        Date1.SwapDates(Date2);
        cout << "After Swapping:\n";
        cout << "Date 1: ";
        Date1.printDate();
        cout << "Date 2: ";
        Date2.printDate();

        clsScreen::Pause();
    }
};

class clsAgeModule
{
public:
    static void Show()
    {
        clsScreen::PrintHeader("Age & Duration Calculator");

        cout << "Enter Birth Date:\n";
        clsDate BirthDate = clsDate::ReadFullDate();

        cout << "\n--- Age Information ---\n";
        cout << "Age in Days: " << BirthDate.CalculateMyAgeInDays() << "\n";
        cout << "Age in Years: " << BirthDate.CalculateMyAgeInYears() << "\n";

        cout << "\n--- Custom Difference Calculation ---\n";
        cout << "Enter Target Date:\n";
        clsDate TargetDate = clsScreen::InputDate();

        long int DiffDays = BirthDate.GetDifferenceInDays(TargetDate, true);
        cout << "Difference In Days (Including End Day): " << DiffDays << "\n";
        cout << "Equivalent In Years: " << BirthDate.CalculateYearNumberByNumberOfDays(DiffDays) << "\n";

        clsScreen::Pause();
    }
};

class clsMainSystem
{
private:
    static void ShowMenu()
    {
        clsScreen::PrintHeader("Date & Time Utility Suite");
        cout << "[1] Formatting & Initialization Module\n";
        cout << "[2] Calendar & Year Statistics Module\n";
        cout << "[3] Date Arithmetic Engine\n";
        cout << "[4] Business & Vacation Management Module\n";
        cout << "[5] Date Comparison & Validation Engine\n";
        cout << "[6] Age & Duration Calculator Module\n";
        cout << "[7] Exit System\n";
        cout << "====================================================\n";
    }

    static void PerformOption(short Option)
    {
        switch (Option)
        {
        case 1:
            clsFormattingModule::Show();
            break;
        case 2:
            clsCalendarModule::Show();
            break;
        case 3:
            clsArithmeticModule::Show();
            break;
        case 4:
            clsVacationModule::Show();
            break;
        case 5:
            clsComparisonModule::Show();
            break;
        case 6:
            clsAgeModule::Show();
            break;
        case 7:
            clsScreen::Clear();
            cout << "System shutting down successfully.\n";
            break;
        }
    }

public:
    static void Run()
    {
        short Option = 0;
        do
        {
            ShowMenu();
            Option = clsScreen::ReadOption(1, 7);
            PerformOption(Option);
        } while (Option != 7);
    }
};

int main()
{
    clsMainSystem::Run();
    return 0;
}