#include <iostream>

using namespace std;

struct SDate
{
    short Year;
    short Month;
    short Day;
};

bool IsLeapYear(short Year)
{

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);

}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;


    int NumberOfDays[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

bool IsDate1BeforeDate2(SDate Date1, SDate Date2)
{

    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}

bool IsLastDayInMonth(SDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));

}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

SDate IncreaseDateByOneDay(SDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

int GetDifferenceInDays(SDate Date1, SDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days : Days;
}

short ReadDay()
{
    short Day;
    cout << "\n Please Enter a Day ?";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    cout << "\n Please Enter a Month ?";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "\n Please Enter a Year ?";
    cin >> Year;
    return Year;
}

SDate ReadFullDate()
{
    SDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

int main()
{
    SDate Date1 = ReadFullDate();
    SDate Date2 = ReadFullDate();

    cout << "\n Difference is : " << GetDifferenceInDays(Date1, Date2) << " Day(s).";
    cout << "\n Difference (Including End Day) is : " << GetDifferenceInDays(Date1, Date2 , true) << " Day(s).";

    cout << endl;
	return 0;
}