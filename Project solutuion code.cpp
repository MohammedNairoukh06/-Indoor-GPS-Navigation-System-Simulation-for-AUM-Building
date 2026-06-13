#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std; 

class Node {
public:
    string officeCredentials;
    vector<Node*> leftChildren;
    Node* middleChild;
    vector<Node*> rightChildren;

    Node(string o) {
        officeCredentials = o;
        middleChild = nullptr;
    }

    void groundFloorAdmin(char side,string officeCredentials){
        if (side == 'L' || side == 'l') {
            bool found = false;
            // Using a range-based loop to check whether the office credential entered by the user already exists or not.
            // In each iteration the pointer pointing to a child node is assigned to the variable child (iterating over every element in the vector leftChildren).
            for (Node* child : leftChildren) {
                if (child&&child->officeCredentials == officeCredentials) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                Node* room = new Node(officeCredentials);
                leftChildren.push_back(room);
            }
            return;
        } else if (side == 'R' || side == 'r') {
            bool found = false;
            for (Node* child : rightChildren) {
                if (child&&child->officeCredentials == officeCredentials) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                Node* room = new Node(officeCredentials);
                rightChildren.push_back(room);
            }
            return;
        } else {
           return;
        }
    }

    void groundFloorInsertion() {
        char userChoice;
        cout << "-----------------------------------------------------------------------------------------------------\n";
        cout << "\t\t\tRoom Insertion Procedure (Ground Floor)\n";
        cout << "-----------------------------------------------------------------------------------------------------\n";
        cout << "Kindly select the side on which you would like to add the room (L for left side & R for right side):";
        cin >> userChoice;  
        cout << "\n";

        if (userChoice == 'L' || userChoice == 'l') {
            cout << "-----------------------------------------------------------------------------------------------------\n";
            cout << "\t\t\t\t\tInsertion At LHS\n";
            cout << "-----------------------------------------------------------------------------------------------------\n";
            string officeCredentials;
            cout << "Enter office credentials:";
            cin >> officeCredentials;
            bool found = false;
            cout << "\n";
            // Using a range-based loop to check whether the office credential entered by the user already exists or not.
            // In each iteration the pointer pointing to a child node is assigned to the variable child (iterating over every element in the vector leftChildren).
            for (Node* child : leftChildren) {
                if (child&&child->officeCredentials == officeCredentials) {
                    found = true;
                    cout << "-----------------------------------------------------------------------------------------------------\n";
                    cout << "\t\t\t\tThe room already exists\n";
                    cout << "-----------------------------------------------------------------------------------------------------\n";
                    break;
                }
            }
            if (!found) {
                Node* room = new Node(officeCredentials);
                leftChildren.push_back(room);
                cout << "-----------------------------------------------------------------------------------------------------\n";
                cout << "\t\t\t\tInsertion completed successfully\n";
                cout << "-----------------------------------------------------------------------------------------------------\n";
            }
            return;
        } else if (userChoice == 'R' || userChoice == 'r') {
            cout << "-----------------------------------------------------------------------------------------------------\n";
            cout << "\t\t\t\t\tInsertion At RHS\n";
            cout << "-----------------------------------------------------------------------------------------------------\n";
            string officeCredentials;
            cout << "Enter office credentials:";
            cin >> officeCredentials;
            bool found = false;
            cout << "\n";

            for (Node* child : rightChildren) {
                if (child&&child->officeCredentials == officeCredentials) {
                    found = true;
                    cout << "-----------------------------------------------------------------------------------------------------\n";
                    cout << "\t\t\t\tThe room already exists\n";
                    cout << "-----------------------------------------------------------------------------------------------------\n";
                    break;
                }
            }
            if (!found) {
                Node* room = new Node(officeCredentials);
                rightChildren.push_back(room);
                cout << "-----------------------------------------------------------------------------------------------------\n";
                cout << "\t\t\t\tInsertion completed successfully\n";
                cout << "-----------------------------------------------------------------------------------------------------\n";
            }
            return;
        } else {
            cout << "-----------------------------------------------------------------------------------------------------\n";
            cout << "\t\t\t\tInvalid selection. Please enter 'L' or 'R'.\n";
            cout << "-----------------------------------------------------------------------------------------------------\n";
        }
    }
    
    void groundFloorDeletion(){
        char userChoice;
        cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\t\t\t\tRoom Deletion Procedure (Ground Floor)\n";
        cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        cout<<"Please select the side from which you would like to remove/delete a room from (L for left side & R for right side): ";
        cin>>userChoice;
        cout<<"\n";

        if(userChoice =='L'||userChoice =='l') {
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
            cout<<"\t\t\t\t\t\tDeletion At LHS\n";
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
            string officeCredentials;
            cout<<"Please enter the credentials of the office you wish to delete:";
            cin>>officeCredentials;
            bool found =false;
            cout<<"\n";

        for(auto p=leftChildren.begin();p!=leftChildren.end();++p){
            if(*p&&(*p)->officeCredentials==officeCredentials){
                delete *p;
                leftChildren.erase(p);
                found=true;
                cout<<"---------------------------------------------------------------------------------------------------------------------\n";
                cout<<"\t\t\t\t\tDeletion Completed Successfully\n";
                cout<<"---------------------------------------------------------------------------------------------------------------------\n";
                break;
            }
        }

        if(!found){
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
            cout<<"\t\t\t\tThe room you are trying to delete does not exist\n";
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        }
        return;
    }else if(userChoice=='R'||userChoice=='r'){
        cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t\tDeletion At RHS\n";
        cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        string officeCredentials;
        cout<<"Please enter the credentials of the office you wish to delete:";
        cin>>officeCredentials;
        bool found=false;
        cout<<"\n";

        for(auto p=rightChildren.begin();p!=rightChildren.end();++p){
            if (*p&&(*p)->officeCredentials==officeCredentials){
                delete *p;
                rightChildren.erase(p);
                found=true;
                cout<<"---------------------------------------------------------------------------------------------------------------------\n";
                cout<<"\t\t\t\t\tDeletion Completed Successfully\n";
                cout<<"---------------------------------------------------------------------------------------------------------------------\n";
                break;
            }
        }

        if(!found){
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
            cout<<"\t\t\t\tThe room you are trying to delete does not exist\n";
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        }
        return;
    }else{
        cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\t\t\tInvalid selection. Please enter 'L' or 'R'.\n";
        cout<<"---------------------------------------------------------------------------------------------------------------------\n";
    }
}

    void firstFloorAdmin(char side,string officeCredentials){
        if (side == 'L' || side == 'l') {
            bool found = false;
            // Using a range-based loop to check whether the office credential entered by the user already exists or not.
            // In each iteration the pointer pointing to a child node is assigned to the variable child (iterating over every element in the vector leftChildren).
            for (Node* child : leftChildren) {
                if (child&&child->officeCredentials == officeCredentials) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                Node* room = new Node(officeCredentials);
                leftChildren.push_back(room);
            }
            return;
        } else if (side == 'R' || side == 'r') {
            bool found = false;
            for (Node* child : rightChildren) {
                if (child&&child->officeCredentials == officeCredentials) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                Node* room = new Node(officeCredentials);
                rightChildren.push_back(room);
            }
            return;
        } else {
           return;
        }
    }

    void firstFloorInsertion() {
        char userChoice;
        cout << "-----------------------------------------------------------------------------------------------------\n";
        cout << "\t\tRoom Insertion Procedure (First Floor)\n";
        cout << "-----------------------------------------------------------------------------------------------------\n";
        cout << "Kindly select the side on which you would like to add the room (L for left side & R for right side):";
        cin >> userChoice;
        cout << "\n";

        if (userChoice == 'L' || userChoice == 'l') {
            cout << "-----------------------------------------------------------------------------------------------------\n";
            cout << "\t\t\t\t\tInsertion At LHS\n";
            cout << "-----------------------------------------------------------------------------------------------------\n";
            string officeCredentials;
            cout << "Enter office credentials:";
            cin >> officeCredentials;
            bool found = false;
            cout << "\n";
            // Using a range-based loop to check whether the office credential entered by the user already exists or not.
            // In each iteration the pointer pointing to a child node is assigned to the variable child (iterating over every element in the vector leftChildren).
            for (Node* child : leftChildren) {
                if (child&&child->officeCredentials == officeCredentials) {
                    found = true;
                    cout << "-----------------------------------------------------------------------------------------------------\n";
                    cout << "\t\t\t\tThe room already exists\n";
                    cout << "-----------------------------------------------------------------------------------------------------\n";
                    break;
                }
            }
            if (!found) {
                Node* room = new Node(officeCredentials);
                leftChildren.push_back(room);
                cout << "-----------------------------------------------------------------------------------------------------\n";
                cout << "\t\t\t\tInsertion completed successfully\n";
                cout << "-----------------------------------------------------------------------------------------------------\n";
            }
            return;
        } else if (userChoice == 'R' || userChoice == 'r') {
            cout << "-----------------------------------------------------------------------------------------------------\n";
            cout << "\t\t\t\t\tInsertion At RHS\n";
            cout << "-----------------------------------------------------------------------------------------------------\n";
            string officeCredentials;
            cout << "Enter office credentials:";
            cin >> officeCredentials;
            bool found = false;
            cout << "\n";

            for (Node* child : rightChildren) {
                if (child&&child->officeCredentials == officeCredentials) {
                    found = true;
                    cout << "-----------------------------------------------------------------------------------------------------\n";
                    cout << "\t\t\t\tThe room already exists\n";
                    cout << "-----------------------------------------------------------------------------------------------------\n";
                    break;
                }
            }
            if (!found) {
                Node* room = new Node(officeCredentials);
                rightChildren.push_back(room);
                cout << "-----------------------------------------------------------------------------------------------------\n";
                cout << "\t\t\t\tInsertion completed successfully\n";
                cout << "-----------------------------------------------------------------------------------------------------\n";
            }
            return;
        } else {
            cout << "-----------------------------------------------------------------------------------------------------\n";
            cout << "\t\t\t\tInvalid selection. Please enter 'L' or 'R'.\n";
            cout << "-----------------------------------------------------------------------------------------------------\n";
        }
    }

    void firstFloorDeletion() {
        char userChoice;
        cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\t\t\t\tRoom Deletion Procedure (First Floor)\n";
        cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        cout<<"Please select the side from which you would like to remove/delete a room from (L for left side & R for right side): ";
        cin>>userChoice;
        cout<<"\n";

        if(userChoice =='L'||userChoice =='l') {
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
            cout<<"\t\t\t\t\t\tDeletion At LHS\n";
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
            string officeCredentials;
            cout<<"Please enter the credentials of the office you wish to delete:";
            cin>>officeCredentials;
            bool found =false;
            cout<<"\n";

        for(auto p=leftChildren.begin();p!=leftChildren.end();++p){
            if(*p&&(*p)->officeCredentials==officeCredentials){
                delete *p;
                leftChildren.erase(p);
                found=true;
                cout<<"---------------------------------------------------------------------------------------------------------------------\n";
                cout<<"\t\t\t\t\tDeletion Completed Successfully\n";
                cout<<"---------------------------------------------------------------------------------------------------------------------\n";
                break;
            }
        }

        if(!found){
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
            cout<<"\t\t\t\tThe room you are trying to delete does not exist\n";
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        }
        return;
    }else if(userChoice=='R'||userChoice=='r'){
        cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t\tDeletion At RHS\n";
        cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        string officeCredentials;
        cout<<"Please enter the credentials of the office you wish to delete:";
        cin>>officeCredentials;
        bool found=false;
        cout<<"\n";

        for(auto p=rightChildren.begin();p!=rightChildren.end();++p){
            if (*p&&(*p)->officeCredentials==officeCredentials){
                delete *p;
                rightChildren.erase(p);
                found=true;
                cout<<"---------------------------------------------------------------------------------------------------------------------\n";
                cout<<"\t\t\t\t\tDeletion Completed Successfully\n";
                cout<<"---------------------------------------------------------------------------------------------------------------------\n";
                break;
            }
        }

        if(!found){
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
            cout<<"\t\t\t\tThe room you are trying to delete does not exist\n";
            cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        }
        return;
    }else{
        cout<<"---------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\t\t\tInvalid selection. Please enter 'L' or 'R'.\n";
        cout<<"---------------------------------------------------------------------------------------------------------------------\n";
    }
    }
     
    void search(){
        cout<<"----------------------------------------------------------------------------\n";
        cout<<"\t\t\t\tSearching Procedure\n";
        cout<<"----------------------------------------------------------------------------\n";
        string targetRoom;
        cout<<"Please enter the credentials of the office you are searching for:";
        cin>>targetRoom;
        if(targetRoom=="Second-Floor"){
            cout<<"----------------------------------------------------------------------------\n";
            cout<<"Unauthorized Access: This Level Is Restricted to Authorized Personnel Only.\n";
            cout<<"----------------------------------------------------------------------------\n";
            return;
        }
        vector<string> route;
        bool found=recursiveSearch(targetRoom,route);
        if(found){
            cout<<"----------------------------------------------------------------------------\n";
            cout<<"\t\tSpecified room has been successfully located\n";
            cout<<"----------------------------------------------------------------------------\n";
            cout<<"Navigation route: ";
            for(auto i=route.begin();i!=route.end();i++){
                cout<<*i;
                if(next(i)!=route.end()){
                    cout<<" --> ";
                }
            }
            cout<<"\n----------------------------------------------------------------------------\n";
        }else{
            cout<<"----------------------------------------------------------------------------\n";
            cout<<"\t\t\tNo such office was found\n";
            cout<<"----------------------------------------------------------------------------\n";
        }  
        }

    bool recursiveSearch(string targetroom,vector<string>& route){
        route.push_back(officeCredentials);
        if(officeCredentials==targetroom){
            return true;
        }
        if(middleChild&&middleChild->recursiveSearch(targetroom,route)){
            return true;
        }
        for(Node* child:leftChildren){
            if(child&&child->recursiveSearch(targetroom,route)){
                return true;
            }
        }
        for(Node* child:rightChildren){
            if(child&&child->recursiveSearch(targetroom,route)){
                return true;
            }
        }
        route.pop_back();
        return false;
    }

    void traverse(){
        cout<<officeCredentials<<endl;
        for(Node* child:leftChildren){

            if(child!=nullptr){
                child->traverse();
            }
        }
        for(Node* child:rightChildren){
            if(child!=nullptr){
                child->traverse();
            }
        }
        if(middleChild!=nullptr){
            middleChild->traverse();
        }
    }
};

int main(){
    Node* entrance=new Node("Entrance");
    Node* groundFloor=new Node("Ground-Floor");
    Node* stairsToFirstFloor=new Node("Stairs");
    Node* firstFloor=new Node("First-Floor");
    Node* stairsToSecondFloor=new Node("Stairs");
    Node* secondFloor=new Node("Second-Floor");

    //Building the Tree
    entrance->middleChild=groundFloor;
    groundFloor->middleChild=stairsToFirstFloor;
    stairsToFirstFloor->middleChild=firstFloor;
    firstFloor->middleChild=stairsToSecondFloor;
    stairsToSecondFloor->middleChild=secondFloor;

    //Ground Floor RHS
    groundFloor->groundFloorAdmin('r',"SB-G01");
    groundFloor->groundFloorAdmin('r',"SB-G02");
    groundFloor->groundFloorAdmin('r',"SB-G03");
    groundFloor->groundFloorAdmin('r',"SB-G04");
    groundFloor->groundFloorAdmin('r',"SB-G05");
    groundFloor->groundFloorAdmin('r',"SB-G06");
    groundFloor->groundFloorAdmin('r',"SB-G07");
    groundFloor->groundFloorAdmin('r',"SB-G08");
    groundFloor->groundFloorAdmin('r',"SB-G09");
    groundFloor->groundFloorAdmin('r',"SB-G10");
    groundFloor->groundFloorAdmin('r',"SB-G11");
    groundFloor->groundFloorAdmin('r',"SB-G12");
    groundFloor->groundFloorAdmin('r',"SB-G13");
    groundFloor->groundFloorAdmin('r',"SB-G14");
    groundFloor->groundFloorAdmin('r',"SB-G15");
    groundFloor->groundFloorAdmin('r',"SB-G16");
    groundFloor->groundFloorAdmin('r',"SB-G17");
    groundFloor->groundFloorAdmin('r',"SB-G18");
    groundFloor->groundFloorAdmin('r',"Electrical-Panel-Room");
    groundFloor->groundFloorAdmin('r',"SB-G20");
    groundFloor->groundFloorAdmin('r',"Toilet");

    //Ground Floor LHS  
    groundFloor->groundFloorAdmin('l',"SB-G25");
    groundFloor->groundFloorAdmin('l',"SB-G26");
    groundFloor->groundFloorAdmin('l',"SB-G27");
    groundFloor->groundFloorAdmin('l',"SB-G28");
    groundFloor->groundFloorAdmin('l',"SB-G29");
    groundFloor->groundFloorAdmin('l',"SB-G30");
    groundFloor->groundFloorAdmin('l',"SB-G31");
    groundFloor->groundFloorAdmin('l',"SB-G32");
    groundFloor->groundFloorAdmin('l',"SB-G33");
    groundFloor->groundFloorAdmin('l',"SB-G34");
    groundFloor->groundFloorAdmin('l',"SB-G35");
    groundFloor->groundFloorAdmin('l',"SB-G36");
    groundFloor->groundFloorAdmin('l',"SB-G37");
    groundFloor->groundFloorAdmin('l',"SB-G38");
    groundFloor->groundFloorAdmin('l',"SB-G39");
    groundFloor->groundFloorAdmin('l',"SB-G40");
    groundFloor->groundFloorAdmin('l',"SB-G41");
    groundFloor->groundFloorAdmin('l',"SB-G42");
    groundFloor->groundFloorAdmin('l',"Electrical-Panel-Room");
    groundFloor->groundFloorAdmin('l',"SB-G44");
    groundFloor->groundFloorAdmin('l',"Toilet");

    //First Floor RHS
    firstFloor->firstFloorAdmin('r',"SB-F01");
    firstFloor->firstFloorAdmin('r',"SB-F02");
    firstFloor->firstFloorAdmin('r',"SB-F03");
    firstFloor->firstFloorAdmin('r',"SB-F04");
    firstFloor->firstFloorAdmin('r',"SB-F05");
    firstFloor->firstFloorAdmin('r',"SB-F06");
    firstFloor->firstFloorAdmin('r',"SB-F07");
    firstFloor->firstFloorAdmin('r',"SB-F08");
    firstFloor->firstFloorAdmin('r',"SB-F09");
    firstFloor->firstFloorAdmin('r',"SB-F10");
    firstFloor->firstFloorAdmin('r',"SB-F11");
    firstFloor->firstFloorAdmin('r',"SB-F12");
    firstFloor->firstFloorAdmin('r',"SB-F13");
    firstFloor->firstFloorAdmin('r',"SB-F14");
    firstFloor->firstFloorAdmin('r',"SB-F15");
    firstFloor->firstFloorAdmin('r',"SB-F16");
    firstFloor->firstFloorAdmin('r',"SB-F17");
    firstFloor->firstFloorAdmin('r',"SB-F18");
    firstFloor->firstFloorAdmin('r',"Electrical-Panel-Room");
    firstFloor->firstFloorAdmin('r',"SB-F20");
    firstFloor->firstFloorAdmin('r',"Toilet");

    //First Floor LHS
    firstFloor->firstFloorAdmin('l',"SB-F25");
    firstFloor->firstFloorAdmin('l',"SB-F26");
    firstFloor->firstFloorAdmin('l',"SB-F27");
    firstFloor->firstFloorAdmin('l',"SB-F28");
    firstFloor->firstFloorAdmin('l',"SB-F29");
    firstFloor->firstFloorAdmin('l',"SB-F30");
    firstFloor->firstFloorAdmin('l',"SB-F31");
    firstFloor->firstFloorAdmin('l',"SB-F32");
    firstFloor->firstFloorAdmin('l',"SB-F33");
    firstFloor->firstFloorAdmin('l',"SB-F34");
    firstFloor->firstFloorAdmin('l',"SB-F35");
    firstFloor->firstFloorAdmin('l',"SB-F36");
    firstFloor->firstFloorAdmin('l',"SB-F37");
    firstFloor->firstFloorAdmin('l',"SB-F39");
    firstFloor->firstFloorAdmin('l',"SB-F40A");
    firstFloor->firstFloorAdmin('l',"SB-F40B");
    firstFloor->firstFloorAdmin('l',"SB-F41");
    firstFloor->firstFloorAdmin('l',"SB-F42");
    firstFloor->firstFloorAdmin('l',"Electrical-Panel-Room");
    firstFloor->firstFloorAdmin('l',"SB-F44");
    firstFloor->firstFloorAdmin('l',"Toilet");

    cout<<"---------------------------------------------------------------------------------------------------\n";
    cout<<"\t\t\tWelcome to the SB Building Indoor Navigation System\n";
    cout<<"---------------------------------------------------------------------------------------------------\n";
    bool runAgain=true;
    while(runAgain){
        cout<<"Select desired action from the list provided below by entering the corresponding number down below:\n\n";
        cout<<"\t\t1. Search\n";
        cout<<"\t\t2. Room Insertion\n";
        cout<<"\t\t3. Room Deletion\n";
        cout<<"\t\t4. traverse\n\n";
        int userChoice;
        cout<<"\tDesired Action:";
        cin>>userChoice;
        switch (userChoice){
            case 1:entrance->search();
            break;
            case 2:
                int choice;
                cout<<"---------------------------------------------------------------------------------------------------------\n";
                cout<<"Please specify whether you would like to insert a new office room on the ground floor or the first floor\n(Enter 0 for the ground floor and 1 for the first floor):\n\n";
                cout<<"\tDesired Choice:";
                cin>>choice;
                cout<<"---------------------------------------------------------------------------------------------------------\n";
                if(choice==0){
                    groundFloor->groundFloorInsertion();
                }else if(choice==1){
                    firstFloor->firstFloorInsertion();
                }else{
                    cout<<"\t\t\t\tInvalid Input. Please try again.\n";
                    cout<<"---------------------------------------------------------------------------------------------------------\n";
                }
                break;
            case 3:
                cout<<"---------------------------------------------------------------------------------------------------------\n";
                cout<<"Please specify whether you would like to delete an office room from the ground floor or the first floor\n(Enter 0 for the ground floor and 1 for the first floor):\n\n";
                cout<<"\tDesired Choice:";
                cin>>choice;
                cout<<"---------------------------------------------------------------------------------------------------------\n";
                if(choice==0){
                    groundFloor->groundFloorDeletion();
                }else if(choice==1){
                    firstFloor->firstFloorDeletion();
                }else{
                    cout<<"\t\t\t\tInvalid Input. Please try again.\n";
                    cout<<"---------------------------------------------------------------------------------------------------------\n";
                }
                break;
            case 4:
                cout<<"---------------------------------------------------------------------------------------------------------\n";
                cout<<"\tTraversing the tree structure:\n\n";
                entrance->traverse();
                cout<<"---------------------------------------------------------------------------------------------------------\n";
                break;
            default:
                cout<<"---------------------------------------------------------------------------------------------------------\n";
                cout<<"\t\t\t\tInvalid Input. Please try again.\n\n";
                cout<<"\t\t\t\t\tProgram Terminated\n";
                cout<<"---------------------------------------------------------------------------------------------------------\n";
            break;
    }
        if(runAgain){
            int user;
            cout<<"---------------------------------------------------------------------------------------------------------\n";
            cout<<"Would you like to perform another action (Enter 1 for yes and 0 for no)?\n\n";
            cout<<"\tAnswer:";
            cin>>user;
            cout<<"---------------------------------------------------------------------------------------------------------\n";
            if(user==1){   
                runAgain=true;
            }else if(user==0){
                runAgain=false;
                cout<<"Terminating Program\n";
                cout<<"---------------------------------------------------------------------------------------------------------\n";
            }else{
                cout<<"Invalid Input. Terminating Program.\n";
                exit(0);
            }
        }
    }
    }
