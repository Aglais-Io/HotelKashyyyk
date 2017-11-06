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

	//Board Type (0-BB;1-1/2 Board;2-Board)
	char bType;

	//Length of stay
	int lenStay = 0;

	//Newspaper
	char newspaper;
};

//2 file pointers
FILE *fp;
FILE *fp2;

int main()
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
		printf("No booking places found");
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

	if (strcmp(boardType, "B&B"))
	{
		guestStruct.bType = 0;
	}

	if (strcmp(boardType, "Half"))
	{
		guestStruct.bType = 1;
	}

	if (strcmp(boardType, "Full"))
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

	if (strcmp(boardType, "Yes"))
	{
		guestStruct.newspaper = true;
	}

	if (strcmp(boardType, "No"))
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

}

void checkOut (){

}
