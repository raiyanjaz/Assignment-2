#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output

using namespace std; 

int main() {
    // Provided arrays and constants

    const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
    const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
    const int ID_LENGTH = 8;
    unsigned int age[NUM_PATIENTS] = {50, 22, 22, 89, 15, 16, 22, 32, 15, 66}; // 1D int array age of each patient
    char id[NUM_PATIENTS][ID_LENGTH + 1] = {"10854893", "10983922", "98333894", "57290888", "14899822", "79278282", "44293822", "62911023", "28399020", "33212322"}; // 1D int array identification #
    char firstName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"allison", "michael", "michael", "johnny", "sabrina", "helen", "ignacio", "melissa", "hassan", "melody"}; // 2D char array: first names for patients
    char lastName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"pratt", "xiao", "barkley", "wu", "sappal", "mcdonald", "garza", "tran", "nahas", "baker"}; // 2D char array: last names for patients
    char sex[NUM_PATIENTS] = {'f','m','m','m','f','f','m','f','m','f'}; // 1D char array sex of the patient

   // PART 1: Select a primary sorting category from user input 

    cout << "Please enter the sorting category (Age, ID, First, Last, Sex): ";

    int count = 0;
    char userInput[count]; 

    char category[5][6] = {"Age", "ID", "First", "Last", "Sex"};

    bool validInputCheck = true;

    while (validInputCheck) {

        char input = cin.get(); // Stores the first character that user inputs
        
        count = 0; 
    
        while (input != '\n') { // While statement that stores the first character into the first element of char array userInput and does the same for sequential characters
            userInput[count] = input;
            count++;
            input = cin.get();
        }
        userInput[count] = 0;

        int userInputValue;

        if (userInput[0] >= 97 && userInput[0] <= 122) { // If statement that changes the first element in userInput into a capital letter
            userInputValue = userInput[0];
            userInputValue -= 32;
            userInput[0] = userInputValue;
        }

        for (int i = 1; i <= count; i++) { // For loop that changes every element in userInput after the first element into a lowercase value
            if (userInput[i] >= 65 && userInput[i] <= 90) {
                userInputValue = userInput[i];
                userInputValue += 32;
                userInput[i] = userInputValue;
            }
        }

        if (userInput[0] == 73) { // If statement that ensures any input of ID is shown as ID
                userInputValue = userInput[1];
                userInputValue -= 32;
                userInput[1] = userInputValue;
        }

        int compare;
        int check = 0;
        while (check < 5) {
            compare = strcmp(userInput, category[check]);
            if (compare > 0 || compare < 0) {
                check++; 
            } else if (compare == 0) {
                validInputCheck = false;
                break;
            }
        }
        if (check == 5) {
            cout << "Unexpected input. Please input either Age, ID, First, Last, or Sex: ";
            cin.clear(); 
        }  
    }

    int counter = strlen(userInput) - 1;
    
    int caseNumber;
    
    switch (counter) {
        case 1: // If user inputs ID
            caseNumber = 2;
            break;
        case 2: // If user inputs Age or Sex
            if (userInput[0] == 65) {
                caseNumber = 1;
                break; 
            } else if (userInput[0] == 83) {
                caseNumber = 3;
                break;
            }
        case 3: // If user inputs Last
            caseNumber = 4;
            break;
        case 4: // If user inputs First
            caseNumber = 5;
            break;
    }

    cout << "Case " << caseNumber << ", sorting by ";
    for (int i = 0; i <= count; i++)
        cout << userInput[i];
    if (caseNumber == 4 || caseNumber == 5)
        cout << " Name";
    cout << "." << endl;

    // PART 3/4: Sorting patient records

    if (caseNumber == 1) { // Sorting for Age
        for (int i = 0; i < NUM_PATIENTS-1; i++) {
          for (int i2 = 0; i2 < NUM_PATIENTS - 1; i2++) {
                if (age[i2] > age[i2+1] || age[i2] == age[i2+1]) {
                    int temp = age[i2];
                    age[i2] = age[i2+1];
                    age[i2+1] = temp;
                
                    for (int i3 = 0; i3 < ID_LENGTH + 1; i3++) { // Orders ID according to Age
                        char temp2[NUM_PATIENTS][ID_LENGTH+1];
                        temp2[i2][i3] = id[i2][i3];
                        id[i2][i3] = id[i2+1][i3];
                        id[i2+1][i3] = temp2[i2][i3];
                    }  
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders First Name according to Age
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = firstName[i2][i3];
                        firstName[i2][i3] = firstName[i2+1][i3];
                        firstName[i2+1][i3] = temp2[i2][i3];
                    }
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders Last Name according to Age
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = lastName[i2][i3];
                        lastName[i2][i3] = lastName[i2+1][i3];
                        lastName[i2+1][i3] = temp2[i2][i3];
                    }       
                                
                    char temp2[NUM_PATIENTS];  // Orders sex according to Age
                    temp2[i2] = sex[i2];
                    sex[i2] = sex[i2+1];
                    sex[i2+1] = temp2[i2];
                }    
            }
        }
    }

    if (caseNumber == 1) { // Sorting for Age
        for (int i = 0; i < NUM_PATIENTS-1; i++) {
          for (int i2 = 0; i2 < NUM_PATIENTS - 1; i2++) {
                if (age[i2] > age[i2+1] || age[i2] == age[i2+1]) {
                    int temp = age[i2];
                    age[i2] = age[i2+1];
                    age[i2+1] = temp;
                
                    for (int i3 = 0; i3 < ID_LENGTH + 1; i3++) { // Orders ID according to Age
                        char temp2[NUM_PATIENTS][ID_LENGTH+1];
                        temp2[i2][i3] = id[i2][i3];
                        id[i2][i3] = id[i2+1][i3];
                        id[i2+1][i3] = temp2[i2][i3];
                    }  
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders First Name according to Age
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = firstName[i2][i3];
                        firstName[i2][i3] = firstName[i2+1][i3];
                        firstName[i2+1][i3] = temp2[i2][i3];
                    }
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders Last Name according to Age
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = lastName[i2][i3];
                        lastName[i2][i3] = lastName[i2+1][i3];
                        lastName[i2+1][i3] = temp2[i2][i3];
                    }       
                                
                    char temp2[NUM_PATIENTS];  // Orders sex according to Age
                    temp2[i2] = sex[i2];
                    sex[i2] = sex[i2+1];
                    sex[i2+1] = temp2[i2];
                }    
            }
        }
    }
    
     
  
    // PART 2: Outputting patient records to terminal in tabular form

    cout << setw(12) << "Age: "; // Prints out the Age row and all its values with a fixed width of 12 using a for loop
    for (int i = 0; i < 10; i++)
        cout << setw(10) << age[i];
    cout << "" << endl;

    cout << setw(12) << "ID: "; // Prints out the ID row and all its values with a fixed width of 12 using a for loop
    for (int i = 0; i < 10; i++)
        cout << setw(10) << id[i];
    cout << "" << endl;

    cout << setw(10) << "First Name: "; // Prints out the First Name row and all its values with a fixed width of 10 using a for loop
    for (int i = 0; i < 10; i++)
        cout << setw(10) << firstName[i];
    cout << "" << endl;

    cout << setw(12) << "Last Name: "; // Prints out the Last Name row and all its values with a fixed width of 12 using a for loop
    for (int i = 0; i < 10; i++)
        cout << setw(10) << lastName[i];
    cout << "" << endl;

    cout << setw(12) << "Sex: "; // Prints out the Sex row and all its values with a fixed width of 12 using a for loop
    for (int i = 0; i < 10; i++)
        cout << setw(10) << sex[i];
    cout << "" << endl;

    return 0;
}

