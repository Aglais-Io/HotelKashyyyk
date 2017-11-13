/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define true 1
#define false 0
#define notFalse 0

//Structure to store guests
struct guests {
	//UniqueID
	char* UID;

	//Name
	char *fName;
	char *sName;

	//DOB (Store as dd/mm/yyyy
	char DOB [10];

	//Guest numbers
	char adultNum = 0;
	char childNum = 0;

	//Board Type (0-BB;1- 1/2 Board;2- Full Board)
	char bType;//Shouldn't this be int?

	//Length of stay
	int lenStay = 0;

	//Newspaper
	char newspaper;
};

//2 file pointers
FILE *fp;
FILE *fp2;

//Initalise functions
void checkIn ();
void dining ();
void checkOut ();
int bill();
int calculateCost(int x);

int main ()
{
	srand(time(0));
	return 0;
}

void checkIn (){
	//Store any free locations
	char locFree = -1;

	//Open guest file and store RAM location in pointer
	fp = fopen("guest.txt","w");

	//Iterate through guests checking every 9th entry
	for (int i = 0; i < (4*9); i++)
	{
		//Temporary variable
		char temp [25];
		//Result boolean
		char compRes = false;

		fgets(temp, 25, fp);

		if(i % 9 == 0)
		{
			//Compare against null
			compRes = strcmp(temp, '\0');

			if (compRes == false)
			{
				//Store free location
				locFree = (int) i / 9;
				break;
			}
		}
	}

	//If nothing is found print failure and break
	if (locFree == -1)
	{
		printf("No places free");
		fclose(fp);
		break;
	}

	//Create a 'guests' structure
	struct guests guestStruct;

	//Create date characters
	char dayStr[2];
	char monthStr[2];
	char yearStr[4];

	//Create temporary # of adults + children, board type, stay length and newspaper variables
	char numAd = 0;
	char numCh = 0;
	char boardType [5];
	int lenStay = 0;
	char newspaperType [3];

	printf("Enter your 1st name");
	fgets(guestStruct.fName, 25, stdin);
	fflush(stdin);

	printf("Enter your surname name");
	fgets(guestStruct.sName, 25, stdin);
	fflush(stdin);

	printf("Enter your day of birth");
	fgets(dayStr, 2,stdin);
	fflush(stdin);

	printf("Enter your month of birth");
	fgets(monthStr, 2, stdin);
	fflush(stdin);

	printf("Enter your year of birth");
	fgets(yearStr, 4, stdin);
	fflush(stdin);

	guestStruct.DOB = strcat(strcat(dayStr,monthStr),yearStr);

	printf("Enter the number of adults");
	scanf("%d", &numAd);
	fflush(stdin);
	guestStruct.adultNum = numAd;

	printf("Enter the number of children");
	scanf("%d", &numCh);
	fflush(stdin);
	guestStruct.childNum = numCh;

	printf("Enter your board type");
	fgets(boardType, 5, stdin);
	fflush(stdin);

	if (strcmp(boardType, "B&B") == notFalse)
	{
		guestStruct.bType = 0;
	}

	if (strcmp(boardType, "Half") == notFalse)
	{
		guestStruct.bType = 1;
	}

	if (strcmp(boardType, "Full") == notFalse)
	{
		guestStruct.bType = 2;
	}

	printf("Enter the length of the stay");
	scanf("%d", &lenStay);
	fflush(stdin);
	guestStruct.lenStay = lenStay;

	printf("Would you like a newspaper?");
	fgets(boardType, 5, stdin);
	fflush(stdin);

	if (strcmp(boardType, "Yes") == notFalse)
	{
		guestStruct.newspaper = true;
	}

	if (strcmp(boardType, "No") == notFalse)
	{
		guestStruct.newspaper = false;
	}

	//Generate a random num and then print it to a variable (4 nums + 1 null)
	int randN = rand() % 2048;
	char randStr [5];
	sprintf(randStr, "%d", randN);
	guestStruct.UID = strcat(guestStruct.sName, randStr);

	fputs(guestStruct.UID, fp);
	fputs(guestStruct.fName, fp);
	fputs(guestStruct.sName, fp);
	fputs(guestStruct.DOB, fp);
	fprintf(fp,"%d",guestStruct.adultNum);
	fprintf(fp,"%d",guestStruct.childNum);
	fprintf(fp,"%d", guestStruct.bType);
	fprintf(fp,"%d",guestStruct.lenStay);
	fprintf(fp,"%d",guestStruct.newspaper);

	fclose(fp);
}

void dining (){
	
	int ID[10];
	printf("Input booking ID:");
	scanf("%d",ID);
	//CHECK FOR EXISTING USER
	//IF EXISTING USER------
	
	
	//tables- 1 = in use, 0 = available
	int tables7[10];int tables9[10];
	//Endor = table 1
	tables7[0]=0;tables9[0]=0;
	//Naboo = table 2
	tables7[1]=0;tables9[1]=0;
	//Tatooine = table 3
	tables7[2]=0;tables9[2]=0;
	int time;
	printf("Would you like to book a table for 7pm or 9pm?\nInput 7 for 7pm\nInput 9 for 9pm\n");
	scanf("%d",&time);
	if(time==7)
	{
		if((bType==1)||(bType==2)&&((tables7[0]==0)||(tables7[1]==0)||(tables7[2]==0)))
		{
			printf("Please select a table to dine at from.\n");
			if(tables7[0]==0)
			{
				printf("(1)Endor Table \n");	
			}
			if(tables7[1]==0)
			{
				printf("(2)Naboo Table\n");
			}
			if(tables7[2]==0)
			{
				printf("(3)Tatooine Table\n");
			}
			printf(":");
			int T;
			scanf("%d",&T);
			
			switch(T)
			{
				case 1:
					printf("Endor table has been booked for your party for 7pm\n");
					tables7[0]==1;
					break;
				case 2:
					printf("Naboo table has been booked for your party for 7pm\n");
					tables7[1]==1;
					
					break;
				case 3:
					printf("Tatooine table has been booked for your party for 7pm\n");
					tables7[2]==1;
					break;
				default:
					printf("Error");
			}
		}
	}
	else if(time==9)
	{
		
		if((bType==1)||(bType==2)&&((tables9[0]==0)||(tables9[1]==0)||(tables9[2]==0)))
		{
			printf("Please select a table to dine at from.\n");
			if(tables9[0]==0)
			{
				printf("(1)Endor Table \n");	
			}
			if(tables9[1]==0)
			{
				printf("(2)Naboo Table\n");
			}
			if(tables9[2]==0)
			{
				printf("(3)Tatooine Table\n");
			}
			printf(":");
			int T;
			scanf("%d",&T);
			
			switch(T)
			{
				case 1:
					printf("Endor table has been booked for your party for 9pm\n");
					tables9[0]==1;
					break;
				case 2:
					printf("Naboo table has been booked for your party for 9pm\n");
					tables9[1]==1;
					
					break;
				case 3:
					printf("Tatooine table has been booked for your party for 9pm\n");
					tables9[2]==1;
					break;
				default:
					printf("Error");
			}
		}
	}
}
}

void checkOut (){

}

int bill(//all the things)
{
    char checkoutID[//];
    int initial, onePerson, totalChild, totalRoom, totalBoard, boardCost, totalCost, newspaperCost = 0;
    int room1 = 100, room2 = 85, room3 = 75, room4 = 50;  
    
    printf("enter your bookingID");
    gets(checkoutID);
    
    if(checkoutID //);
    //error check bookingID
    //get full name name from file

                 
    if (roomType == roomone){
         initial = cost(room1);
    }
    else if(roomType == roomtwo){
         initial = cost(room2);
         }
    else if(roomType == roomthree){
         initial = cost(room3);
         }
    else if(roomType == roomfour){
         initial = cost(room4);
         }
    else{
         //error
    }
    
    onePerson = initial / totalPeople;
    if(children != 0 && over65s != 0){
         totalChild = (onePerson * 0.5) * children)) + (onePerson * (totalPeople - children));
         totalRoom = totalChild * 0.9; 
    }
    else if( != 0){
         totalRoom = initial * 0.9;
    }
    else if(d != 0){
         totalRoom = (onePerson * 0.5) * children)) + (onePerson * (totalPeople - 1));
    }
    else {
         
    }
    if(boardtype = "full board"){
         boardCost = cost(20)
    } 
    else if(boardtype = "boardtype"){
         boardCost = cost(15)
    }
    else if(boardtype = "B&B"){
         boardCost = cost(5)
    }
    totalBoard = lengthofstay * boardCost
        
    int totalCost;
    totalBoard = lengthofstay * boardrate
    totalCost = totalBoard + totalRoom
    if(newpspaper != 0){
         totalCost + 5.50; 
         newspaperCost = 5.50   
    }
    
    return totalCost
    /*OUTPUT: full name, bookingID, total room cost, total board cost, newspaper cost (if x>0), overall total*/ 
}

int calculateCost(int x)
{
    int cost;
    cost = lengthofstay * x
    return cost
}

