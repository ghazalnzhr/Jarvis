// This program is called Jarvis, it's a general porpuse program with
// loads of functionalities and can do many stuff
#include <iostream>
using namespace std;

// For generating random numbers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Programs
void calculator();
void bmiCalculator();
void wordConvertor();
void dateConvertor();
void playlistPicker();
void info();

// Utils
void program(char);
void showMenu();
void Action(char);
void showExample(char);
void split(string, char);

// Options list
char a, b, c, d, f, i;
// This is input from the user
char input;

int main()
{
    cout << "\033[36m----------------------------------------------\n";
    cout << "\033[32mWelcome\n";
    cout << "\033[36mThank you for using my program :)\n";
    cout << "----------------------------------------------\n";
    cout << "\033[0mPlease enter a\n";
    system(0);
    cin >> input;
    if (input == 'a')
    {
        // Run the main program
        showMenu();
    }
    else
    {
        cout << "not valid";
    }
    return 0;
}

// Utils
void program(char input)
{
    system("clear");
    if (input == 'a')
    {
        calculator();
    }
    else if (input == 'b')
    {
        bmiCalculator();
    }
    else if (input == 'c')
    {
        wordConvertor();
    }
    else if (input == 'd')
    {
        dateConvertor();
    }
    else if (input == 'f')
    {
        playlistPicker();
    }
    else if (input == 'i')
    {
        info();
    }
    else
    {
        cout << "invalid input";
    }
}

void showMenu()
{
    system("clear");
    cout << "OPTIONS:\n";
    cout << "\033[35ma: calculator\n";
    cout << "b: BMI💪🏻\n";
    cout << "c: word convertor\n";
    cout << "d: date convertor\n";
    cout << "f: random playlists🌜\n";
    cout << "i: info ℹ\n";
    cout << "\033[0mPress one key:";
    cin >> input;
    program(input);
}

void afterAction(char functionId)
{
    cout << "Please select one option:\n";
    cout << "z: back to menu\n";
    cout << "c: continue\n";
    cout << "e: exit\n";
    cin >> input;
    system("clear");

    if (input == 'z')
    {
        showMenu();
    }
    else if (input == 'e')
    {
        exit(0);
    }
    else if (input == 'c')
    {
        if (functionId == 'a')
        {
            calculator();
        }
        else if (functionId == 'b')
        {
            bmiCalculator();
        }
        else if (functionId == 'c')
        {
            wordConvertor();
        }
        else if (functionId == 'd')
        {
            dateConvertor();
        }
        else if (functionId == 'f')
        {
            playlistPicker();
        }
        else if (functionId == 'i')
        {
            info();
        }
    }
}
void showExample(char functionId)
{
    if (functionId == 'a')
    {
        cout << "input: 2 + 4\n";
        cout << "output: 2+4=6\n";
    }
    if (functionId == 'b')
    {
        cout << "input: 54 170\n";
        cout << "output: Your BMI: 18.7";
    }
    if (functionId == 'c')
    {
        cout << "input: hEllO\n";
        cout << "output: HeLLo\n";
    }
    if (functionId == 'd')
    {
        cout << "input: 1400 11 9\n";
        cout << "output: 2022 1 29\n";
    }
}

// This function splits a string
void split(string str, char del)
{
    // declaring temp string to store the curr "word" upto del
    string temp = "";

    for (int i = 0; i < (int)str.size(); i++)
    {
        // If cur char is not del, then append it to the cur "word", otherwise
        // you have completed the word, print it, and start a new word.
        if (str[i] != del)
        {
            temp += str[i];
        }
        else
        {
            cout << temp << " ";
            temp = "";
        }
    }

    cout << temp[2];
}
// END OF UTILS

// Programs
void calculator()
{
    float num1;
    char op;
    float num2;
    cout << "\033[36mEnter two numbers and an oprator:";
    showExample('a');
    cin >> num1 >> op >> num2;

    float result;
    if (op == '+')
    {
        result = num1 + num2;
    }
    else if (op == '-')
    {
        result = num1 - num2;
    }
    else if (op == '*')
    {
        result = num1 * num2;
    }
    else if (op == '/')
    {
        result = num1 / num2;
    }
    else if (op == '%')
    {
        result = int(num1) % int(num2);
    }
    cout << num1 << op << num2 << '=' << result << endl;

    afterAction('a');
}

void bmiCalculator()
{
    float weight;
    float height;
    cout << "\033[36mCalculates your bmi. To find out more about this metric\n";
    cout << "\033[32mvisit: https://en.wikipedia.org/wiki/Body_mass_index\n";
    // Show example
    cout << "\033[0mPlease enter your weight(in kg):";
    cin >> weight;
    cout << "\033[0mPlease enter your height(in m):";
    cin >> height;
    float result;

    result = weight / (height * height);
    cout << "Your BMI is:" << result;
    afterAction('b');
}

void wordConvertor()
{
    string word;
    int len;

    cout << "\033[36mThis program will reverse the capitalization of alphabet in a word\n";
    showExample('c');
    cout << "\033[0mPlease enter a word:";
    cin >> word;

    len = word.length();

    for (int i = 0; i < len; i++)
    { // Loop through all of the characters
        if (word[i] >= 97 && word[i] <= 122)
        { // Check if the character is lower case
            word[i] -= 32;
        }
        else if (word[i] >= 65 && word[i] <= 90)
        {
            word[i] += 32;
        }
        else
        {
            cout << "\033[31minvalid word";
        }
    }
    cout << word << endl;

    afterAction('c');
}

void dateConvertor()
{
    long y, m, d;
    cout << "\033[36mThis program will turn Shamsi dates to Miladi\n";
    showExample('d');
    cout << "\033[0mPlease enter a date(s):";
    cin >> y >> m >> d;

    // Do the math to get the day count
    y = (y - 1) * 365;
    m = (m - 1) * 31;
    // 345 kabise
    int date = y + m + d + 345;
    date += 226899;
    // Reset the conuts
    y = 0;
    m = 0;
    d = 0;

    // Now work backwards and turn the date into miladi
    date -= 500;
    y = date / 365;
    y += 1;

    m = date % 365;
    // Count the number of times we encremented 30 to get the month
    int counter = 0;
    // How many days are there in a miladi month
    int daysInMonth[12] = {31,
                           28,
                           31,
                           30,
                           31,
                           30,
                           31,
                           31,
                           30,
                           31,
                           30,
                           31};
    // There are 12 months in a year
    for (i = 0; i <= 12; i++)
    {
        // We continue to decrement the number of months until
        // the result is less than the maximum days in a month
        while (m >= 31)
        {
            m -= daysInMonth[i];
            counter++;
        }
    }
    // The result of the last operation is the day
    d = m;
    // The number of iterations in the while loop is the month
    m = counter + 1;

    cout << y << " " << m << " " << d << endl;
    afterAction('d');
}

void playlistPicker()
{
    string playlists[6] = {"https://open.spotify.com/playlist/37i9dQZF1DXcBWIGoYBM5M?si=17ad62a4b6b34ec1",
                           "https://open.spotify.com/playlist/37i9dQZF1DX07Bg0Q5GozA?si=c31bb01a436b4e18",
                           "https://open.spotify.com/playlist/37i9dQZF1E4oLwlqvXisyU?si=7853594b7eae4801",
                           "https://open.spotify.com/playlist/37i9dQZF1DX5Ejj0EkURtP?si=9777d62646654160",
                           "https://open.spotify.com/playlist/37i9dQZF1DWUa8ZRTfalHk?si=aab29033741d4287",
                           "https://open.spotify.com/playlist/37i9dQZF1DX3csziQj0d5b?si=099ff5e7778e4093"};
    cout << "\033[36mFinds you a random Spotify playlist for beats to listen to :)\n";
    cout << "\033[0mEnter p to get started:";
    cin >> input;
    if (input == 'p')
    {
        srand(time(0));
        unsigned int random = rand();
        random = random % 6;
        string result = playlists[random];
        cout << "\033[33mI have chosen this playlist for you✨\n";
        cout << result << endl;
    }

    afterAction('f');
}

void info()
{
    cout << "\033[35mThe author of this program is Ghazal\n";
    cout << "\033[0mAny suggestions? email me:\n";
    cout << "\033[32mghazal.nzhr@gmail.com\n";
    cout << "\033[0mHave fun👋🏼!";

    afterAction('i');
}
