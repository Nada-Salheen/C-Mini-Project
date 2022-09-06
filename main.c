/*==========================================================================================================
Name: NADA Sayed Sayed
Project Name: Mini Vehicle Control system using C
===========================================================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include"functions.h"

#define ON 1
#define OFF 0

/*Global Variables that I will use in multiple functions */
int engine_state=ON;
int AC_state=OFF;
int vehicle_speed=0;
float room_temperature=0.0;
int Engine_Temperature_Controller=OFF;
float engine_temperature=0.0;

/*Main function*/

int main(void){
	/*the main only calls the first function to start the program*/
	What_To_Do_W_Choice();
	return (0);
}

void What_To_Do_W_Choice(){
	/* choice variable holds the user entered choice*/
	char choice;
	int FLAG=ON;
	/*This loop checks if the entered character from the user matches any of the given options*/
	do{
		printf("a. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n\n");
		fflush(stdout);
		scanf(" %c",&choice);
		if(choice=='a'|| choice=='A' || choice=='b'|| choice=='B'|| choice=='c' || choice=='C'){
			FLAG=OFF;}
	}while(FLAG);

/*if the user chose 'b' the program asks what to do again*/
	while(choice =='b'|| choice =='B')
	{
		printf("a. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n\n");
		fflush(stdout);
		scanf(" %c",&choice);
	}

	if(choice=='c'||choice=='C'){
		printf("You chose to Quit the system\n");
		fflush(stdout);
		vehicle_speed=0;
		engine_state=OFF;
		/*The program displays the vehicle state when an option is chosen*/
		Display_The_Current_Vehicle_State();
		/*This return returns to the main function then quit the program*/
		return;
	}
	else if(choice=='a'|| choice=='A'){
		printf("You chose to Turn on the vehicle engine\n");
		fflush(stdout);
		/*The program displays the vehicle state when an option is chosen*/
		Display_Sensors_Set_Menu();
		return;

	}
}

/*This second function displays multiple options when choosing to turn ON the engine*/
void Display_Sensors_Set_Menu(){

	char choice_2;
	int FLAG=ON;

	/*This function is always waiting for the user to choose an option unless the user chose to turn OFF
	 the engine*/
	while(engine_state==ON){
		/*This loop checks if the entered character from the user matches any of the given options*/
		do{
			printf("a. Turn off the engine\n");
			printf("b. Set the traffic light color\n");
			printf("c. Set the room temperature (Temperature Sensor)\n");
			printf("d. Set the engine temperature (Engine Temperature Sensor)\n\n");
			fflush(stdout);
			scanf(" %c",&choice_2);
			if(choice_2=='a'|| choice_2=='A' || choice_2=='b'|| choice_2=='B'|| choice_2=='c' || choice_2=='C'|| choice_2=='d'|| choice_2=='D'){
				FLAG=OFF;
			}
		}while(FLAG);
		if(choice_2=='b'||choice_2=='B'){
			Set_The_Traffic_Light_Colour();
		}
		else if(choice_2=='c'||choice_2=='C'){
			Set_The_Room_Temperature();
		}
		else if(choice_2=='d'||choice_2=='D'){
			Set_The_Engine_Temperuture();
		}
		else{
			printf("The current Car State is \n");
			/*The program displays the vehicle state when choosing to turn OFF the engine and goes back
			 to the second function*/
			Display_The_Current_Vehicle_State();
			What_To_Do_W_Choice();
		}
	}
}

/*This function takes the traffic light color from the user and set the vehicle speed according to it*/
void Set_The_Traffic_Light_Colour(){

	unsigned char light_colour;
	int FLAG=ON;

	/*This loop checks if the entered character from the user matches any of the given options*/
	do{
		printf("Please enter the traffic colour light \n");
		fflush(stdout);
		scanf(" %c",&light_colour);
		if(light_colour=='g'|| light_colour=='G'|| light_colour=='o'|| light_colour=='O'|| light_colour=='r'||light_colour=='R'){
			FLAG=OFF;}
	}while(FLAG);


	if(light_colour =='g'|| light_colour =='G'){
		vehicle_speed=100;
	}
	else if(light_colour =='o'|| light_colour =='O'){
		vehicle_speed=30;
	}
	else{
		vehicle_speed=0;
	}

	if(vehicle_speed==30){
		/*When the speed is 30 km/hr a function is called to automatically setup the settings*/
		Controlling_By_Vehicle_Speed();
	}
}

/*This function takes the room temperature from the user and set the AC value according to it*/
void Set_The_Room_Temperature(){

		printf("Please enter the room temperature \n");
		fflush(stdout);
		scanf(" %f",&room_temperature);


	if(room_temperature<10.0){
		room_temperature=20.0;
		AC_state= ON;
		printf("\nAC is turned ON\n");
		fflush(stdout);

	}
	else if(room_temperature>30.0){
		room_temperature=20.0;
		AC_state= ON;
		printf("\nAC is turned ON\n");
		fflush(stdout);

	}
	else{
		AC_state= OFF;
		printf("\nAC is turned OFF\n");
		fflush(stdout);

	}
}

/*This function takes the engine temperature from the user and set the new engine temperature
  according to it by turning ON or OFF the Engine Temperature Controller */
void Set_The_Engine_Temperuture(){

		printf("Please enter the Engine temperature \n");
		fflush(stdout);
		scanf(" %f",&engine_temperature);



	if(engine_temperature<100.0){
		Engine_Temperature_Controller=ON;
		engine_temperature=125.0;
		printf("\nEngine Temperature Controller is ON\n");
		fflush(stdout);

	}
	else if(engine_temperature>150.0){
		Engine_Temperature_Controller=ON;
		engine_temperature=125.0;
		printf("\nEngine Temperature Controller is ON\n");
		fflush(stdout);


	}
	else{
		Engine_Temperature_Controller=OFF;
		printf("\nEngine Temperature Controller is OFF\n");
		fflush(stdout);
	}
}

/*This function controls the AC, engine temperature and room temperature when the vehicle speed
  is 30 km/hr using the below formulas*/
void Controlling_By_Vehicle_Speed(){

	if(AC_state==OFF){
		AC_state=ON;
	}

	if(Engine_Temperature_Controller==OFF){
		Engine_Temperature_Controller=ON;
	}

	room_temperature= room_temperature*(5.0/4.0)+1.0;
	engine_temperature= engine_temperature*(5.0/4.0)+1.0;
}

/*This functions displays the vehicle State*/
void Display_The_Current_Vehicle_State(){

	if(engine_state==OFF){
		printf("The current Engine State is OFF\n");
	}
	else{
		printf("The current Engine State is ON\n");

	}
	if(AC_state==OFF){
		printf("The current AC State is OFF\n");
	}
	else{
		printf("The current AC State is ON\n");

	}
	printf("The current Vehicle Speed is %d Km/hr\n",vehicle_speed);
	printf("The current room temperature is %.2f Celsuis\n",room_temperature);

	if(Engine_Temperature_Controller==OFF)
		printf("The current Engine Temperature Controller State is OFF\n");
	else
		printf("The current Engine Temperature Controller State is ON\n");

	printf("The current Engine Temperature is %.2f Celsuis\n",engine_temperature);
}








