```markdown
# Patients’ Queue Based Management System

## Overview
developed a patient queue-based management system. This system will be built in C++ and will utilize two linked lists to manage patient information effectively.

## Features

### User Roles
The system supports two user roles:
1. Nurses
2. Doctors

### Nurses Functionality
Nurses will have access to the following options:
1. Add a New Patient: Add patients to the waiting list.
2. Change Patient Order: Adjust the order of patients based on priority (e.g., disabled patients).
3. View Waiting List: Display all patients in the waiting list in a single page view.
4. Call Patient for Treatment: Remove a patient from the waiting list and store their information in the visit history list.
5. Search Patient: Locate a patient using Patient ID or First Name.
6. Sort Waiting List: Sort patients by current visit time in ascending order, with page-by-page browsing.
7. Login/Logout: Secure access to the system.

### Doctors Functionality
Doctors will be able to:
1. View Waiting List: Access the complete waiting list in a single page view.
2. Search Patient Records: Find and modify records in the patient's visit history.
3. Sort Visit History: Display all records in descending order, with page-by-page browsing.
4. Search by Sickness Description: Locate patients based on their sickness description or first name.
5. Login/Logout: Secure access to the system.

## Data Structure
The system will utilize two linked lists:
1. Waiting List
2. Patient's Visit History List

### Patient Information
Both lists will include the following attributes:
- Patient ID
- First Name
- Last Name
- Age
- Gender
- Phone
- Address
- Sickness Description
- Current Visit Date
- Current Visit Time
- Disability Option
- Doctor Name (default: NULL)
- Medicine Information (default: NULL)

### Pre-defined Records
The system will include 5 to 10 pre-defined patient records hard-coded into the program.

## Implementation Notes
- No Database: The use of SQL databases or text-based documents is prohibited; all values will be hard-coded.
- Searching Algorithms: Users will be able to search patient records efficiently using suitable searching algorithms.
- Sorting Algorithms: Implemented suitable sorting algorithms for options 1.6 and 2.4.
- User Navigation: Nurses and doctors can navigate back and forth between patient records.
- Record Modification: Only doctors can modify patient records (including doctor name and medicine information).
