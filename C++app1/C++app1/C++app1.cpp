// C++app1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

string logMeIn(string name, int age) { //void if no return
    cout << "Hello " << name << " you are " << age << "years old";
    return "you have been logged in"; //RETURN breaks out of function
    cout << "some dead code here"; //ignored :(
}

int getMax(int num1, int num2, int num3) {
int result;
if (num1 >= num2 && num1 >= num3) {
    result = num1;
}
else if (num2>=num1 && num2>=num3) {
    result = num2;
}
else { result = num3; }
return result;
}

string decoder(string encryptedText) {
    int decoderIndex=0;
    do
    {
    std::random_shuffle(encryptedText.begin(), encryptedText.end());
    cout << encryptedText << endl;
    decoderIndex++;
    } while (encryptedText.find("heilhitler", 0)); //operates until condition is true
    cout << decoderIndex<< endl;
    return encryptedText;
}



int main()
{

    //variables


    string characterName = "John";
    int characterAge;
    char grade = 'A';
    double gpa = -2.2;
    bool isMale = true;
    characterAge = -35;

    cout << "Hello World!\n" << endl; //endl = newline
    cout << "There once was a man named " << characterName << endl;
    cout << "He was " << characterAge << " years old" << endl;


    //string functions

    cout << characterName.length() << endl;   //length
    cout << characterName[0] << endl;     //select char in string
    characterName[0] = 'B';      //modify 1 char
    cout << characterName.substr(0, 2) << endl;   // substring (start index, howmany chars) create-> nwesub=...
    cout << characterName.find("on", 0) << endl;   //search for substr in string, start search @index
    cout << "There once was a man named " << characterName << endl;

    //numbers
    cout << 10 % 3 << endl;
    cout << (4 + 5) * 10 << endl;
    int num1 = 5;
    double num2 = 5.5;
    num1++; //(increment) num+=80; (+x)
    cout << 5.5 + 9 << endl; //(int+int=int. decimal+int=decimal)

    //<cmath>
    cout << pow(2, 5); //2^5
    sqrt(36); //squareroot
    round(4.3); //round down/up OPT: ceil() / floor()
    fmax(3, 10); //largest #? OPT: fmin

    //userinput
    int age; //declare string / char / int
    cout << "Enter your age" << endl;
    cin >> age; //NOTE: arrow direction for cin -> variable passes to
    cout << "You are" << age << "years old" << endl;

    //arrays
    int luckyNums[20] = { 4, 8 ,15, 16 }; //create integer array (20 elements or blank for N)
    luckyNums[0] = 19; //change element
    cout << luckyNums[0]; //index of element (n-1)

    //Functions
    cout << logMeIn("Immy", 60); //calling above function, passing in this string. NOTE: function declared first
    //as a stub, or paste function ABOVE the call.

    //Logic statements: IF

    bool isTall = true;

    if (isMale && isTall) { //see earlier BOOL declaration. Search boolean operators
        cout << "You are a tall male." << endl;
    }
    else if (isMale && !isTall) {
        cout << "You are short male." << endl;
    }
    else {
        cout << "You are not male";
    }
    cout << getMax(1, 10, 5);

    int binary = 1;
    string onOff;


    switch (binary) {
    case 0:
        onOff = "off";
        cout << onOff;
        break; //get out of loop
    case 1:
        onOff = "on";
        cout << onOff;
        break;
    default: return 0;
    }

    //Logic statements: WHILE

    int index = 1;
    while (index <= 5) {
        cout << index << endl;
        index++;   // OPT: do while loop (same)
    }

    decoder("liehhitler");

    //Logic statements: FOR

    for (int i = 1; i <= 5; i++) { //has index variable, condition, iteration math
        cout << i << endl;   // good for iteration through array (use array[i] in function
    }

    //2D Array / Matrix (array in array). R x C, n-1 for index

    int numbergrid[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

    //Nested FOR loop: good for working with 2D arrays

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << numbergrid[i][j];
        }
        cout << endl;
    }

    //Pointers

    int age1 = 19;
    cout << &age1;  //prints RAM address of variable (&)
    int *pAge = &age; // create pointer variable. pointer data type = variable data type
    cout << *pAge; //* DEREFERENCES pointervariable: index -> contents


    //Classes and objects

    class Yugiohcard { //making a new data type / model, the blueprint / template
    private:
     //   int stars;   //encapsulation: private to constructor, set using public method.
    public:
        string monsterName;
        string description;
        int stars;

        Yugiohcard(string aMonsterName, string aDescription, int aStars) {       //OPT: constructor: activates when template is called (orange yugioh card)
            monsterName = aMonsterName;
            description = aDescription;
            setStars(aStars);

        }      // OPT: SECOND constructor: creates an overload. eg. if no values, create a blank template /w default values

        bool specialSummon()
        {
            if (stars >= 4)
            {
                return true;
            }
            return false;
        }

        void setStars(int aStars) {    // GET and SET for access control to objects
            if (aStars == 1 || aStars == 2 || aStars == 3 || aStars == 4) {    //CHECK passed in VAR
                stars = aStars;                                                //OK to set
            }
            else { cout << "cannot normal summon"; };
        }

        int getStars() {              //GETTER: returns var to MAIN function for calls
            return stars;
        }
    };

    class EffectMonster : public Yugiohcard {  // Inheritance: extension on a basic object. eg. yugioh card object -> effect card
    public:
        void activateEffect() {
            cout << "Special ability activated!";
        }
 // Trapcard trapcard; ... Trapcard.setFaceDown();       can OVERRIDE methods of original class /w copy
        
    };

    Yugiohcard card1("Dark Magician", "The master of the dark arts", 7);// the 'object'

 //   card1.monsterName = "Dark Magician";      //this 3 line method obsolete due to constructor
 //   card1.description = "The master of the dark arts";
  //  card1.stars = 7;                          // can be used to change variables

 //   Yugiohcard card2;

    cout << card1.monsterName;
    card1.setStars(4);          //going through SETrating setter
    cout << card1.getStars() << endl;;

    cout << card1.specialSummon();

//    EffectMonster effectMonster1("Mirror wall", "a wall", 4);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
