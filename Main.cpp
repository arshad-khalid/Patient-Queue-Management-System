//Arshad Khalid, Raja Zarifah, Mari Raimbekova (November, 2021)
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

void login();
void viewPatients();
void AddPatientWaitingList();
void ViewAllPatientWaitingList();
void SearchPatientByID();
void sortwaitinglist();
string converttoUpperCase(string data);
void searchPatientHistorybySicknessOrFname();
void sortAndDisplayPatientHistoryDescending();
void CallPatientToBeTreated();
void ChangePatientOrderWaitingList();
void searchPatientandModify();

struct patient {
    string PatientID;
    string Fname;
    string Lname;
    string gender;
    int age;
    string disability;
    int phoneNumber;
    string address;
    string sickness;
    string VisitDate;
    string VisitTime;
    string DoctorName;
    string status;
    patient* nextaddress; //go to the next address of node
    patient* prevaddress; //go to previous address of node
}*newnode, * current, * patientHead, * patientTail, * HistoryHead, * HistoryTail, 
* history, * tempHead, * tempTail, * temporary, * sorted, * sortedHead, * sortedTail;

int size = 0;

void doctor() {

    int choice;
    //options for menu choices
    const int VIEW_PATIENT = 1,
        SEARCH_MODIFY = 2,
        SORT_HISTORY = 3,
        SEARCH_PATIENT = 4,
        LOG_OUT = 5,
        QUIT_MENU = 6;
    cout << fixed << showpoint << setprecision(1); //sets to 1 decimal place
    do
    {
        cout << "\nHello doctor! Choose Option below: \n1. View Patient from waiting list (Full Page)\n";
        cout << "2. Search patient and modify\n3. Sort visit history (Page-by-Page)\n4. Search patient\n5. Log out\n6. Exit\nChoice: ";
        cin >> choice;
        //Validate menu selection
        while (choice < VIEW_PATIENT || choice > QUIT_MENU)
        {
            cout << "\nPlease enter a valid menu choice: ";
            cin >> choice;
        }
        //If user does not want to quit, proceed.
        if (choice != QUIT_MENU)
        {
            switch (choice)
            {
            case VIEW_PATIENT:
                viewPatients();
                break;
            case SEARCH_MODIFY:
                searchPatientandModify();
                break;

            case SORT_HISTORY:
                sortAndDisplayPatientHistoryDescending();
                break;

            case SEARCH_PATIENT:
                searchPatientHistorybySicknessOrFname();
                break;
            case LOG_OUT:
                login();
                break;
            }
        }
    } while (choice != QUIT_MENU);
    //1. viewPatient from waiting list (full page)
    //2. search patient from history list and modify record
    //3. sort and display visit history descending (PbP)
    //4. search visit history by sickness of fname
}


//view original patient waiting list
void viewPatients() {
    //call function from nurse as they both view same waiting list
    ViewAllPatientWaitingList();
}

//doctor search and modify
void searchPatientandModify()
{
    int x,y;
    string keyword = "";
    cout << endl;
    cout << "\nEnter Patient ID to search and modify details or press 0 to exit: ";
    cin >> keyword;
    while (keyword !="0")
    {
        if (keyword != "")
        {
            current = HistoryHead; //search patient
            cout << "\nPatient: " << keyword << " shown below:" << endl;

            while (current != NULL)
            {
                if (current->PatientID.find(keyword) != string::npos) //check whether until the end of the string have the keyword
                {
                    cout << "Name: " << current->Fname + " " + current->Lname << endl;
                    cout << "Gender: " << current->gender << endl;
                    cout << "Age: " << current->age << endl;
                    cout << "Disability: " << current->disability << endl;
                    cout << "Contact No: " << current->phoneNumber << endl;
                    cout << "Address: " << current->address << endl;
                    cout << "Sickness/Illness: " << current->sickness << endl;
                    cout << "Visit Date: " << current->VisitDate << endl;
                    cout << "Visit Time: " << current->VisitTime << endl;
                    cout << "Doctor Name: " << current->DoctorName << endl;
                }
                current = current->nextaddress;
            }
        }
        cout << "\nUpdate patient details? Type: 1 for Yes, 0 for No. \n"; //update details of patient
        cin >> x;
        while (x != 0)
        {
                cout << "\nUpdate, or press 0 to exit: \n1. Contact No\n2. Address\n3. Sickness\n4. Doctor Name\nOption: ";
                cin >> y;
                string modify = "";
                int num;
                while (y != 0)
                {
                    if (y == 1)
                    {
                        cout << "Enter updated number: ";
                        cin >> num;
                        HistoryHead->phoneNumber = num;
                        break;
                    }
                    else if (y == 2)
                    {
                        cout << "Enter updated Address: ";
                        cin >> modify;
                        HistoryHead->address = modify;
                        break;
                    }
                    else if (y == 3)
                    {
                        cout << "Enter updated sickness: ";
                        cin >> modify;
                        HistoryHead->address = modify;
                        break;
                    }
                    else if (y == 4)
                    {
                        cout << "Enter updated Doctor: ";
                        cin >> modify;
                        HistoryHead->DoctorName = modify;
                        break;
                    }
                    else
                    {
                        cout << "\nIncorrect input, try again\n";
                        cout << "\nUpdate: \n1. Contact No\n2. Address\n3. Sickness\n4. Doctor Name\nOption: ";
                        cin >> y;
                    }
                }
                doctor();
        }doctor();
    }doctor();
}

//doctor can search by sickness or first name
void searchPatientHistorybySicknessOrFname() {
    int decision;
    cout << endl;
    cout << "\n Search patient from visit history, or press 0 to exit\n Search by:\n 1. Sickness\n 2. First name\nChoice: ";
    cin >> decision;
    string keyword = "";

    while (decision != 0)
    {

        if (decision == 1)
        {
            cout << "\nEnter sickness (or any relevant keyword): ";
            cin >> keyword;
            if (keyword != "")
            {
                current = HistoryHead; //search
                cout << "\nPatient(s) with " << "'" << keyword << "'" << " shown below:" << endl;

                while (current != NULL)
                {
                    if (current->sickness.find(keyword) != string::npos) //check whether until the end of the string have the keyword
                    {
                        cout << "Name: " << current->Fname + " " + current->Lname << endl;
                        cout << "Patient ID: " << current->PatientID << endl;
                        cout << "Gender: " << current->gender << endl;
                        cout << "Age: " << current->age << endl;
                        cout << "Disability: " << current->disability << endl;
                        cout << "Contact No: " << current->phoneNumber << endl;
                        cout << "Address: " << current->address << endl;
                        cout << "Sickness/Illness: " << current->sickness << endl;
                        cout << "Visit Date: " << current->VisitDate << endl;
                        cout << "Visit Time: " << current->VisitTime << endl;
                        cout << "Doctor Name: " << current->DoctorName << endl;
                    }
                    current = current->nextaddress;
                }
            }
        }
        else if (decision == 2) {
            cout << " Enter first name (or any keyword): ";
            cin >> keyword;
            if (keyword != "")
            {
                current = HistoryHead; //search
                cout << "\nPatient(s) with first name " << "'" << keyword << "'" << " shown below:" << endl;

                while (current != NULL)
                {
                    if (current->Fname.find(keyword) != string::npos) //check whether until the end of the string have the keyword
                    {
                        cout << "Name: " << current->Fname + " " + current->Lname << endl;
                        cout << "Patient ID: " << current->PatientID << endl;
                        cout << "Gender: " << current->gender << endl;
                        cout << "Age: " << current->age << endl;
                        cout << "Disability: " << current->disability << endl;
                        cout << "Contact No: " << current->phoneNumber << endl;
                        cout << "Address: " << current->address << endl;
                        cout << "Sickness/Illness: " << current->sickness << endl;
                        cout << "Visit Date: " << current->VisitDate << endl;
                        cout << "Visit Time: " << current->VisitTime << endl;
                        cout << "Doctor Name: " << current->DoctorName << endl;
                    }
                    current = current->nextaddress;
                }
            }
        }
        cout << "\n Search patient from visit history, or press 0 to exit\n Search by:\n 1. Sickness\n 2. First name\n";
        cin >> decision;
    }
    return;
}

//doctor view in descending (patient id) page by page
void sortAndDisplayPatientHistoryDescending() {
    if (HistoryHead == NULL)
    {
        return;
    }
    current = HistoryTail;
    int i = 1, decision = 1;
    system("cls");
    while (decision != 0)
    {
        cout << "\n Patient details as below (By Patient ID):" << endl;
        cout << "\n====================================================================\n";
        cout << " " << i << ". " << current->Fname + " " + current->Lname << " - " << current->PatientID;
        cout << "\n====================================================================\n";
        cout << " Gender: " << current->gender;
        cout << endl;
        cout << " Age: " << current->age;
        cout << endl;
        cout << " Disability: " << current->disability;
        cout << endl;
        cout << " Phone number: " << current->phoneNumber;
        cout << endl;
        cout << " Address: " << current->address;
        cout << endl;
        cout << " Visit date: " << current->VisitDate;
        cout << endl;
        cout << " Visit time: " << current->VisitTime;
        cout << endl;
        cout << " Doctor name: " << current->DoctorName;
        cout << "\n====================================================================\n";
        cout << " 1. Previous patient\t 2. Next patient\t 0.exit";
        cout << "\n====================================================================\n";
        cout << " Select your option: ";
        cin >> decision;

        if (decision == 1 && current->nextaddress != NULL)
        {
            current = current->nextaddress;
            i--;
        }
        else if (decision == 2 && current->prevaddress != NULL)
        {
            current = current->prevaddress;
            i++;
        }
        else if (decision == 0)
        {
            return;
        }
        else if (decision != 1 && decision != 2 && decision != 0)
        {
            cout << "\nInvalid selected option!" << endl;
            system("pause");
        }
        else
        {
            cout << "\nThere are no more patients !" << endl;
            system("pause");
        }
        system("cls");
    }
}

//-----------------------------------------------------------------------------------------------
void nurse() {
    int choice;
    //options for menu choices
    const int ADD_PATIENT = 1,
        CHANGE_ORDER = 2,
        VIEW_PATIENT = 3,
        CALL_PATIENT = 4,
        SEARCH_PATIENT = 5,
        SORT_VISIT = 6,
        LOG_OUT = 7,
        QUIT_MENU = 8;

    cout << fixed << showpoint << setprecision(1); //sets to 1 decimal place
    do
    {
        cout << "\nHello nurse! Choose Option below: \n1. Add patient to waiting list\n2. Change patient order\n";
        cout << "3. View patients(Full page)\n4.Call patient to be treated\n5.Search patient by patient ID from waiting list";
        cout<<"\n6.Sort by visit time(Page - by - Page view)\n7.Log out\n8.Exit\nChoice: ";
        cin >> choice;

        //Validate menu selection
        while (choice < ADD_PATIENT || choice > QUIT_MENU)
        {
            cout << "\nPlease enter a valid menu choice: ";
            cin >> choice;
        }
        //If user does not want to quit, proceed.
        if (choice != QUIT_MENU)
        {
            switch (choice)
            {
            case ADD_PATIENT:
                AddPatientWaitingList();                
                break;

            case CHANGE_ORDER:
                ChangePatientOrderWaitingList();
                break;

            case VIEW_PATIENT:
                ViewAllPatientWaitingList();           
                break;

            case CALL_PATIENT:
                CallPatientToBeTreated();
                break;
            case SEARCH_PATIENT:
                SearchPatientByID();                    
                break;
            case SORT_VISIT:
                sortwaitinglist();                     
            case LOG_OUT:
                login();                            
                break;
            }
        }
        return;
    } while (choice != QUIT_MENU);

    //1. AddPatientWaitingList()
    //2. change patient order in waiting list
    //3. view patients.
    //4. call patient
    //5. search patientwaitinglistbypatientid
    //6. sort waiting list by visit time (page by page)
}

//nurse adds patient to end of waiting list
void createAndInsertnewNodeToEnd(string PatientID, string Fname, string Lname,
    string gender, int age, string disability, int phoneNumber, string address,
    string sickness, string VisitDate, string VisitTime, string DoctorName, string status) {
    newnode = new patient;
    newnode->PatientID = PatientID;
    newnode->Fname = Fname;
    newnode->Lname = Lname;
    newnode->gender = gender;
    newnode->age = age;
    newnode->disability = disability;
    newnode->phoneNumber = phoneNumber;
    newnode->address = address;
    newnode->sickness = sickness;
    newnode->VisitDate = VisitDate;
    newnode->VisitTime = VisitTime;
    newnode->DoctorName = DoctorName;
    newnode->status = status;
    newnode->nextaddress = NULL;
    newnode->prevaddress = NULL;
    ::size++;

    if (patientHead == NULL) { //if list is empty
        patientHead = patientTail = newnode;
    }
    else
    {//list not empty
        newnode->prevaddress = patientTail;
        patientTail->nextaddress = newnode;
        patientTail = newnode;
    }
}

//add patient to history list
void createAndInsertHistoryToEnd(string PatientID, string Fname, string Lname,
    string gender, int age, string disability, int phoneNumber, string address,
    string sickness, string VisitDate, string VisitTime, string DoctorName, string status) {
    history = new patient;
    history->PatientID = PatientID;
    history->Fname = Fname;
    history->Lname = Lname;
    history->gender = gender;
    history->age = age;
    history->disability = disability;
    history->phoneNumber = phoneNumber;
    history->address = address;
    history->sickness = sickness;
    history->VisitDate = VisitDate;
    history->VisitTime = VisitTime;
    history->DoctorName = DoctorName;
    history->status = status;
    history->nextaddress = NULL;
    history->prevaddress = NULL;

    if (HistoryHead == NULL) { //if list is empty
        HistoryHead = HistoryTail = history;
    }
    else
    {//list not empty
        history->prevaddress = HistoryTail;
        HistoryTail->nextaddress = history;
        HistoryTail = history;
    }
}

//nurse adds patient to list
void AddPatientWaitingList() {
    string PatientID, Fname, Lname, gender, address, disability, sickness, VisitDate, VisitTime, DoctorName, status;
    int age, phoneNumber;

    system("cls");
    cout << "Enter Patient ID (Manual Enter): ";
    cin.ignore();
    getline(cin, PatientID);
    cout << "Enter patient's first name: ";
    getline(cin, Fname);
    cout << "Enter patient's last name: ";
    getline(cin, Lname);
    cout << "Gender (Male/Female/Other): ";
    getline(cin, gender);
    cout << "Age: ";
    cin >> age;
    cin.ignore();
    cout << "Is patient disabled? (True/False): ";
    getline(cin, disability);
    cout << "Enter patient's phone number: ";
    cin >> phoneNumber;
    cin.ignore();
    cout << "Enter patient's address: ";
    getline(cin, address);
    cout << "Enter patient's sickness/disease: ";
    getline(cin, sickness);
    cout << "Visit Date (dd/mm/yyyy): ";
    getline(cin, VisitDate);
    cout << "Appointment Time: ";
    getline(cin, VisitTime);
    cout << "Enter patient's Doctor: ";
    getline(cin, DoctorName);
    cout << "Has patient been seen by doctor? (True/False) "; //true- history list, false-waiting list
    getline(cin, status);

    if (status == "True")
    {
        createAndInsertHistoryToEnd(PatientID, Fname, Lname, gender, age, disability, phoneNumber, address, sickness, VisitDate, VisitTime, DoctorName, status);
    }
    else
    {
        createAndInsertnewNodeToEnd(PatientID, Fname, Lname, gender, age, disability, phoneNumber, address, sickness, VisitDate, VisitTime, DoctorName, status);
    }
}

//nurse changes the waiting list based on disability
void ChangePatientOrderWaitingList()
{
    //return when the list is empty
    if (patientHead == NULL || patientHead->nextaddress == NULL) {
        return;
    }
    //assign the current pointer to the end of the linked list
    current = patientTail;
    int i = ::size; //to iterate according to number of patients
    temporary = current->prevaddress;

    while (i > 0) {
        if (current->disability == "True" && current->prevaddress != NULL) {
            if (current->nextaddress == NULL) {
                current->prevaddress->nextaddress = NULL;
                patientTail = current->prevaddress;
            }
            else {
                current->prevaddress->nextaddress = current->nextaddress;
                current->nextaddress->prevaddress = current->prevaddress;
            }
            current->nextaddress = patientHead;
            patientHead->prevaddress = current;
            current->prevaddress = NULL;
            patientHead = current;
        }
        current = temporary;
        if (temporary != NULL) {
            temporary = temporary->prevaddress;
        }
        i--;
    }
}

//nurse views patient waiting list
void ViewAllPatientWaitingList() {
    current = patientHead;
    system("cls");
    cout << "\nPatient details as below: " << endl;
    cout << "\n===================================================================================================================================================================================\n";
    cout << "\n\tNo.  Patient ID   Name\t\tGender  Age  Disability\tPhone Number\t\tAddress\t\t\t\tSickness\t\tVisit Date    Visit Time\tDoctor Name";
    cout << "\n===================================================================================================================================================================================\n";

    current = patientHead;
    int no = 0;
    while (current != NULL)
    {
        no++;
        cout << "\t" << no << ".\t" << current->PatientID << "\t" << current->Fname << " " << current->Lname << "\t" << current->gender << "\t" << current->age << "\t" << current->disability
            << "\t" << current->phoneNumber << "\t" << current->address << "\t\t" << current->sickness << "\t\t" << current->VisitDate << "\t" << current->VisitTime << "\t\t" << current->DoctorName,
            cout << "\n" << endl;
        current = current->nextaddress;
    }

    cout << "====================================================================================================================================================================================\n";
    cout << endl;
    system("pause");
    system("cls");
}

//nurse to search by patient ID
void SearchPatientByID()
{
    int decision;
    cout << endl;
    cout << "\nSearch patient by ID? Type: 1 for Yes, 0 for No. \nChoice: ";
    cin >> decision;
    string keyword = "";

    while (decision != 0)
    {
        cout << "\nEnter Patient ID:";
        cin >> keyword;

        if (keyword != "")
        {
            current = patientHead; //search
            cout << "\nPatient: " << keyword << " details shown below:" << endl;

            while (current != NULL)
            {
                if (current->PatientID.find(keyword) != string::npos) //check whether until the end of the string have the keyword
                {
                    cout << "Name: " << current->Fname + " " + current->Lname << endl;
                    cout << "Gender: " << current->gender << endl;
                    cout << "Age: " << current->age << endl;
                    cout << "Disability: " << current->disability << endl;
                    cout << "Contact No: " << current->phoneNumber << endl;
                    cout << "Address: " << current->address << endl;
                    cout << "Sickness/Illness: " << current->sickness << endl;
                    cout << "Visit Date: " << current->VisitDate << endl;
                    cout << "Visit Time: " << current->VisitTime << endl;
                    cout << "Doctor Name: " << current->DoctorName << endl;
                }
                current = current->nextaddress;
            }
        }
        cout << "\nSearch patient by ID? Type: 1 for Yes, 0 for No. \nChoice: ";
        cin >> decision;
    }return;
}

//nurse to sort waiting list page by page
void sortwaitinglist()
{
    sorted = new patient;
    sorted->PatientID = newnode->PatientID;
    sorted->Fname = newnode->Fname;
    sorted->Lname = newnode->Lname;
    sorted->gender = newnode->gender;
    sorted->age = newnode->age;
    sorted->disability = newnode->disability;
    sorted->phoneNumber = newnode->phoneNumber;
    sorted->address = newnode->address;
    sorted->sickness = newnode->sickness;
    sorted->VisitDate = newnode->VisitDate;
    sorted->VisitTime = newnode->VisitTime;
    sorted->DoctorName = newnode->DoctorName;
    sorted->status = newnode->status;
    sorted->nextaddress = newnode->nextaddress;
    sorted->prevaddress = newnode->prevaddress;

    //step 2: insert section
    //situation 1: list is empty
    if (sortedHead == NULL)
    {
        sortedHead = sortedTail = sorted;
    }
    //situation 2: visit time is smaller than the head->visit time
    else if (converttoUpperCase(sorted->VisitTime) < converttoUpperCase(sortedHead->VisitTime))
    {
        sorted->nextaddress = sortedHead;
        sortedHead->prevaddress = sorted;
        sortedHead = sorted;
    }
    //situation 3: visit time is bigger than head->book_id and also bigger than tail->visit time
    else if (converttoUpperCase(sorted->VisitTime) > converttoUpperCase(sortedTail->VisitTime))
    {
        sortedTail->nextaddress = sorted;
        sorted->prevaddress = sortedTail;
        sortedTail = sorted;
    }
    //situation 4: visit time bigger than head->visit time but lesser than tail->visit time
    else
    {
        current = sortedHead->nextaddress; //start from 2nd node

        while (converttoUpperCase(sorted->VisitTime) > converttoUpperCase(current->VisitTime))
        {
            current = current->nextaddress;
        }
        current->prevaddress->nextaddress = sorted;
        sorted->prevaddress = current->prevaddress;
        current->prevaddress = sorted;
        sorted->nextaddress = current;
    }
    if (sortedHead == NULL)
    {
        return;
    }
    current = sortedHead;
    int i = 1, decision = 1;
    system("cls");
    while (decision != 0)
    {
        cout << "\nPatient details as below (By Visit Time):" << endl;
        cout << "\n====================================================================\n";
        cout << " " << i << ". " << current->Fname + " " + current->Lname << " - " << current->VisitTime;
        cout << "\n====================================================================\n";
        cout << " Gender: " << current->gender;
        cout << endl;
        cout << " Age: " << current->age;
        cout << endl;
        cout << " Disability: " << current->disability;
        cout << endl;
        cout << " Phone number: " << current->phoneNumber;
        cout << endl;
        cout << " Address: " << current->address;
        cout << endl;
        cout << " Visit date: " << current->VisitDate;
        cout << endl;
        cout << " Patient ID: " << current->PatientID;
        cout << endl;
        cout << " Doctor name: " << current->DoctorName;
        cout << "\n====================================================================\n";
        cout << " 1. Previous patient\t 2. Next patient\t 0.exit";
        cout << "\n====================================================================\n";
        cout << " Select your option: ";
        cin >> decision;

        if (decision == 1 && current->nextaddress != NULL)
        {
            current = current->nextaddress;
            i--;
        }
        else if (decision == 2 && current->prevaddress != NULL)
        {
            current = current->prevaddress;
            i++;
        }
        else if (decision == 0)
        {
            return;
        }
        else if (decision != 1 && decision != 2 && decision != 0)
        {
            cout << "\nInvalid selected option!" << endl;
            system("pause");
        }
        else
        {
            cout << "\nThere are no more patients !" << endl;
            system("pause");
        }
        system("cls");
    }
}

//nurse calls patient to be treated- moves from waiting list to history list
void CallPatientToBeTreated() {
    //if  the list is empty, end the function.
    if (patientHead == NULL) {
        return;
    }
    //assign the current pointer to the head of the list 
    current = patientHead;
    patientHead = patientHead->nextaddress;
    if (patientHead == NULL) {
        patientTail = NULL;
    }
    else {
        patientHead->prevaddress = NULL;
    }
    if (HistoryHead == NULL) {
        HistoryHead = HistoryTail = current;
        current->prevaddress = NULL;
        current->nextaddress = NULL;
        cout << "\nPatient " <<"'"<<patientHead->PatientID<<"' "<< "has been removed from the waiting list and sent into the visit history list\n" << endl;
    }
    else {
        current->nextaddress = NULL;
        HistoryTail->nextaddress = current;
        current->prevaddress = HistoryTail;
        HistoryTail = current;
        cout << "\nPatient " << "'" << HistoryTail->PatientID << "' " << "has been removed from the waiting list and sent into the visit history list\n" << endl;
    }
    ::size--;
}

//convert letters to uppercase to sort
string converttoUpperCase(string data) {
    std::for_each(data.begin(), data.end(), [](char& c) {
        c = ::toupper(c);
        });
    return data;
}

//login page
void login() {

    //hardcoding doctor&nurse login
    string doctorUsername = "doctor";
    string doctorPass = "doctorclinic";
    string nurseUsername = "nurse";
    string nursePass = "nurseclinic";
    string user, pass;

    cout << "\n\nHello! Please enter your login details below, or enter 'x' in both to exit";
    cout << "\nUsername: ";
    cin >> user;
    cout << "\nPassword: ";
    cin >> pass;

    while (user != "x" && pass != "x")
    {
        if (user == doctorUsername && pass == doctorPass) {
            doctor();
        }
        else if (user == nurseUsername && pass == nursePass) {
            nurse();
        }
        else {
            cout << "\nIncorrect Credentials!, Try again.";
            break;
        }
    }
    return;
}
//creates a pre defined record
void createPreDefinedRecords() {
    newnode = current = patientHead = patientTail = HistoryHead = HistoryTail = tempHead = tempTail = temporary = sorted = sortedHead = sortedTail = NULL;

    //insert in history
    createAndInsertHistoryToEnd("P001", "Dorian", "Grey", "Male", 29, "False", 0433563423, "9, Jalan Cemur, 50400, KL", "Anemia", "12/11/2021", "10.00", "Dr. Low", "True");

    createAndInsertHistoryToEnd("P002", "Ali", "Khan", "Male", 21, "True", 0124405066, "3, Jalan Klang, 50403, Selangor", "Diabetes", "13/11/2021", "15.00", "Dr. Sofia", "True");

    createAndInsertHistoryToEnd("P003", "Bayan", "Rasul", "Female", 35, "False", 0122353576, "4, DT Ampang, 50422, Selangor", "Malaria", "13/11/2021", "11.00", "Dr.Sofia", "True");

    createAndInsertHistoryToEnd("P004", "Lee", "Dickson", "Female", 21, "True", 0145264536, "17, Jalan Bukit, 50600, KL", "Cancer", "13/11/2021", "12.30", "Dr.Sofia", "True");

    createAndInsertHistoryToEnd("P005", "Jason", "Bourne", "Male", 44, "False", 0112534534, "12, Bukit Bintang, 50900, KL", "Checkup", "15/12/2021", "17.30", "Dr.Low", "True");


    //insert in waiting
    createAndInsertnewNodeToEnd("P006", "Yong", "Chong", "Female", 33, "False", 0136532245, "11, Batu Caves, 51400, KL", "Dengue", "4/02/2020", "14.00", "Dr.Sofia", "False");

    createAndInsertnewNodeToEnd("P007", "Nadia", "Aleem", "Female", 22, "True", 0115243777, "4, Jalan Bandar, 50660, KL", "Flu", "27/07/2021", "12.30", "Dr.Low", "False");

    createAndInsertnewNodeToEnd("P008", "Ali", "Mohsin", "Male", 12, "False", 0111353437, "8, Sunway Lagoon, 52500, KL", "Diarrhea", "15/09/2020", "16.15", "Dr.Low", "False");

    createAndInsertnewNodeToEnd("P009", "Liya", "Gonsalves", "Female", 52, "True", 0111122341, "10, Bukit Jalil, 50500, KL", "Nausea", "21/07/2021", "01.00", "Dr.Low", "False");

    createAndInsertnewNodeToEnd("P010", "Jameel", "Daud", "Male", 19, "False", 0111566342, "15, Port Dickson, 50310, KL", "Tetanus", "18/04/2020", "18.45", "Dr.Sofia", "False");


}

//main function where the program will begin
int main()
{
    createPreDefinedRecords();
    login();
    return 0;
}