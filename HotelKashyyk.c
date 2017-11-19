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
	//Structure to store guests
	struct guests {
		//UniqueID
		char UID[29];

		//Name
		char fName[25];
		char sName[25];

		//DOB (Store as dd/mm/yyyy
		char DOB [10];

		//Guest numbers
		char adultNum;
		char childNum;

		//Board Type (0-BB;1-1/2 Board;2-Board)
		char bType;

		//Length of stay
		int lenStay;

		//Newspaper
		char newspaper;
	};

	//Store any free locations
	char locFree = -1;

	//Open guest file and store RAM location in pointer
	fp = fopen("guest.txt","w");

	//Iterate through guests checking every 9th entry
	for (int i = 0; i < 36; i++)
	{
		//Temporary variable
		char temp [29];

		fgets(temp, 29, fp);

		if(i % 9 == 0)
		{
			//Compare against null
			if (strcmp(temp, "\0") == false)
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
		printf("No places free\n");
		fclose(fp);
		return 0;
	}

	//Create a 'guests' structure
	struct guests guestStruct;

	//Create date characters
	char monthStr[2];
	char yearStr[4];

	//Create temporary # of adults + children, board type, stay length and newspaper variables
	unsigned int numAd = 5;
	unsigned int numCh = 5;
	char boardType [6];
	int lenStay = -1;

	printf("Enter your 1st name: \n>> ");
	fgets(guestStruct.fName, 25, stdin);
	fflush(stdin);
	printf("\n");

	int i = 0;
	while(i < 25)
	{
		//Check that the name is not digits
		if(isdigit(guestStruct.fName[i]))
		{
			printf("Name contains digits, try again\n");

			printf("Enter your 1st name: \n>> ");
			fgets(guestStruct.fName, 25, stdin);
			fflush(stdin);
			printf("\n");
			i = -1;
		}

		//Convert to lowercase
		tolower(guestStruct.fName[i]);
		i++;
	}

	printf("Enter your surname: \n>> ");
	fgets(guestStruct.sName, 25, stdin);
	fflush(stdin);
	printf("\n");

	while(i < 25)
	{
		//Check that the name is not digits
		if(isdigit(guestStruct.sName[i]))
		{
			printf("Name contains digits, try again\n");

			printf("Enter your surname: \n>> ");
			fgets(guestStruct.sName, 25, stdin);
			fflush(stdin);
			printf("\n");
			i = -1;
		}
		//Convert to lowercase
		tolower(guestStruct.sName[i]);

		i++;
	}

	printf("Enter your day of birth: \n>> ");
	fgets(guestStruct.DOB, 2, stdin);
	fflush(stdin);
	printf("\n");
	/*
	//Append a 0 to the end
	if (guestStruct.DOB[1] == '\0')
	{
		guestStruct.DOB[1] = guestStruct.DOB[0];
		guestStruct.DOB[0] = '0';
	}

	i = 0;
	while (i < 2)
	{
		if(guestStruct.DOB[i] > 47 || guestStruct.DOB[i] < 58)
		{
			printf("The day you entered contained things other than digits\n");

			printf("Enter your day of birth: \n>> ");
			fgets(guestStruct.DOB, 2, stdin);
			fflush(stdin);
			printf("\n");
			i = -1;
		}

	if ((((guestStruct.DOB[0] == '3') && (guestStruct.DOB[1] == '0' && guestStruct.DOB[1] == '1')) || (guestStruct.DOB[0] == '0' || guestStruct.DOB[0] == '1' || guestStruct.DOB[0] == '2')) == false)
	{
			printf("The day you entered was too large or contained something that is not a digit\n");

			printf("Enter your day of birth: \n>> ");
			fgets(guestStruct.DOB, 2, stdin);
			fflush(stdin);
			i = -1;
		}
		i++;
	}*/

	printf("Enter your month of birth: \n>> ");
	fgets(monthStr, 2, stdin);
	fflush(stdin);
	printf("\n");
	/*
	//Append a 0 to the end
	if (monthStr[1] == '\0')
	{
		monthStr[1] = monthStr[0];
		monthStr[0] = '0';
	}

	i = 0;
	while (i < 2)
	{
		if(isdigit(monthStr[i]) == false)
		{
			printf("The month you entered contained things other than digits\n");

			printf("Enter your month of birth: \n>> ");
			fgets(monthStr, 2, stdin);
			fflush(stdin);
			printf("\n");
			i = -1;
		}

		if((monthStr[0] == '0') || (monthStr[0] == '1' && (monthStr[1] == '0' || monthStr[1] == '1' || monthStr[1] == '2')))
		{
			printf("The month you entered was too large\n");

			printf("Enter your month of birth: \n>> ");
			fgets(monthStr, 2, stdin);
			fflush(stdin);
			printf("\n");
			i = -1;
		}
		i++;
	}
*/
	strcat(guestStruct.DOB, monthStr);

	printf("Enter your year of birth: \n>> ");
	fgets(yearStr, 4, stdin);
	fflush(stdin);
	printf("\n");
/*
	i = 0;
	while (i < 4)
	{
		if(isdigit(yearStr[i]) == false)
		{
			printf("Enter your day of birth: \n>> ");
			fgets(yearStr, 4, stdin);
			fflush(stdin);
			printf("\n");
			i = -1;
		}
		i++;
	}*/
	strcat(guestStruct.DOB, yearStr);

	printf("Enter the number of adults: \n>> ");
	scanf("%d", &numAd);
	fflush(stdin);
	printf("\n");

	while (numAd > 5)
	{
		printf("Too many adults entered");

		printf("Enter the number of adults: \n>> ");
		scanf("%d", &numAd);
		fflush(stdin);
		printf("\n");
	}

	guestStruct.adultNum = numAd;

	printf("Enter the number of children: \n>> ");
	scanf("%d", &numCh);
	fflush(stdin);
	printf("\n");

	while ((numAd + numCh) > 5)
	{
		printf("Too many people entered");

		printf("Enter the number of children: \n>> ");
		scanf("%d", &numCh);
		fflush(stdin);
		printf("\n");
	}

	guestStruct.childNum = numCh;

	do{
		printf("Enter your board type: \n>> ");
		fgets(boardType, 5, stdin);
		fflush(stdin);
		printf("\n");

		for (int i = 0; i < 6; i++)
		{
			tolower(boardType[i]);
		}

		if ((strcmp(boardType, "b&b") == notFalse) || (strcmp(boardType, "bandb") == notFalse))
		{
			guestStruct.bType = 0;
		}

		if (strcmp(boardType, "half") == notFalse)
		{
			guestStruct.bType = 1;
		}

		if (strcmp(boardType, "full") == notFalse)
		{
			guestStruct.bType = 2;
		}
		else
		{
			guestStruct.bType = -1;
		}
	} while (guestStruct.bType == -1);

	printf("Enter the length of the stay: \n>> ");
	scanf("%d", &lenStay);
	fflush(stdin);
	printf("\n");

	while (lenStay > 0)
	{
		printf("Enter the length of the stay: \n>> ");
		scanf("%d", &lenStay);
		fflush(stdin);
		printf("\n");
	}

	guestStruct.lenStay = lenStay;

	do
	{
		//Recycle board type as newspaper
		printf("Would you like a newspaper?: \n>> ");
		fgets(boardType, 5, stdin);
		fflush(stdin);
		printf("\n");

		for (int i = 0; i < 5; i++)
		{
			tolower(boardType[i]);
		}

		if (strcmp(boardType, "yes") == notFalse)
		{
			guestStruct.newspaper = true;
		}

		if (strcmp(boardType, "no") == notFalse)
		{
			guestStruct.newspaper = false;
		}
		else
		{
			guestStruct.newspaper = -1;
		}
	} while(guestStruct.newspaper == -1);

	//Generate a random num and then print it to a variable (4 nums + 1 null)
	int randN = rand() % 2048;
	char randStr [5];
	sprintf(randStr, "%d", randN);
	strcat(guestStruct.UID, guestStruct.sName);
	strcat(guestStruct.UID, randStr);

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

int bill()
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

