/* 
Dylan Kieran
C15321906
BSc in Computer Science (DT228/1)
Compiler: Dev-C++ 5.11
Programming CA 
Program that emulates a Lotto game. Program must be modularised and each task must be dealt with in a seperate function.
The program should have a menu that re-appears after each option is complete.
The program must use pointer notation to access array elements.
*/

#include <stdio.h>
#include <stdlib.h>

#define NUMUSER 6
#define NUMWINNING 7
#define LOTTONUMS 42

//Prototypes
void exit_program(void);
void user_lotto_numbers(int *);
void display_user_numbers(int *);
void sort_array(int *);
void compare_lotto_nums(int *);
void all_frequency(int *, int *);

main()
{
	//Declare variables
	int i = 0;
	int options = 0;
	int complete_step1 = 0;
	int user_entered_lotto_nums[NUMUSER];
	int winning_lotto_numbers[NUMWINNING];
	int frequency[LOTTONUMS];
	
	//Initialise all frequencies to 0 at the beginning of the program
	for(i=0; i<LOTTONUMS; i++)
	{
		*(frequency + i) = 0;
	}
	
	do
	{
		//Menu
		printf("\nMain Menu \n");
		printf("Press 1 to enter you lotto numbers\n");
		printf("Press 2 to re-display the lotto numbers you have entered\n");
		printf("Press 3 to sort the numbers you have entered in increasing order\n");
		printf("Press 4 to compare your lotto numbers to the winning lotto numbers\n");
		printf("Press 5 to display the frequancy total of all user entered lotto numbers\n");
		printf("Press 6 to exit\n");
		printf("Option: ");
		scanf("%d",&options);
		
		//getchar() is here to stop the infinite loop of the default statement in the switch if a character variable is entered
		getchar();
		
		switch (options)
		{
			case 1:
				{	
					system("cls");
					user_lotto_numbers(user_entered_lotto_nums);
					
					//Increment counter to show user has completed option 1
					complete_step1 = 1;
					break;
				}
			case 2:
				{
					//If statement to make sure option 1 is complete before entering other options
					if(complete_step1 == 1)
					{
						system("cls");
						display_user_numbers(user_entered_lotto_nums);
						break;
					}
					else
					{
						system("cls");
						printf("Please start with option 1 and enter your lotto numbers");
						break;
					}
				}
			case 3:
				{
					if(complete_step1 == 1)
					{
						system("cls");
						sort_array(user_entered_lotto_nums);
						break;
					}
					else
					{
						system("cls");
						printf("Please start with option 1 and enter your lotto numbers");
						break;
					}
				}
			case 4:
				{
					if(complete_step1 == 1)
					{
						system("cls");
						compare_lotto_nums(user_entered_lotto_nums);
						break;
					}
					else
					{
						system("cls");
						printf("Please start with option 1 and enter your lotto numbers");
						break;
					}
				}
			case 5:
				{
					if(complete_step1 == 1)
					{
						system("cls");
						all_frequency(user_entered_lotto_nums, frequency);
						break;
					}
					else
					{
						system("cls");
						printf("Please start with option 1 and enter your lotto numbers");
						break;
					}
				}
			case 6:
				{
						system("cls");
						exit_program();
						break;
				}
			default:
				{
					system("cls");
					printf("\nError you have entered an invlid input please try again \n\n");
					break;
				}
				
		}//End switch

	}//End do
	while (options != 6);
	
}//End main()

//Implement functions
//

//Option 1: Read users lotto numbers
void user_lotto_numbers(int *temp_array)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int lotto_num = 1;
	int duplicate = 0;
	
	printf("Please enter your lottery numbers (They must be between 1 and 42 and you cannot repeat a number twice)\n\n");
	
	//for loop that allows user to enter each lotto number into an array
	for(i=0; i<NUMUSER; i++)
	{
		//Ask user for lotto numbers and enter them into the array
		printf("Please enter lotto number %d: ",lotto_num);
		scanf("%d",&*(temp_array+i));

		//Error Check to make sure number is between 1 and 42
		if(*(temp_array+i)<1 || *(temp_array+i)>42)
		{
			printf("Invalid number please try again\n");
			i--;
			lotto_num--;
		}//End if
		
		//Error check to make sure number is not a duplicate
		else
		{
			//Outer loop gets initialized to 1 so we make sure that in the comparison that takes place in the inner loop we're always comparing the current value against a previous one
			for(j=1; j<=i; j++)
			{
				//internal loop goes through all the previous entries
				for(k=0; k<j; k++)
				{
					if(*(temp_array+j) == *(temp_array+k))
					{
						printf("%d is a duplicate value. Please try again\n", *(temp_array+i));
						i--;
						lotto_num--;
					}//end if
					
				}//end for
			}//end for
		}//end else
		
		//If there is no error the lotto number increases by 1 and the user enters their next number
		lotto_num++;
		
		//Getchar stops looping if a string or character is entered
		getchar();
	}//End for
		
}//End function 1

//Option 2: Display contents of user entered lotto numbers
void display_user_numbers(int *temp_display)
{
	int i = 0;
	printf("The numbers you have entered are: ");
	
	//Displays the content of the array which is the lotto numbers
	for(i=0; i<NUMUSER; i++)
	{
		printf("%d, ",*(temp_display+i));
	}
	printf("\n\n");
}

//Option 3: Sort the contents of the array in increasing order
void sort_array(int *temp_array3)
{
	int i = 0;
	int j = 0;
	int a = 0;
	
	//Bubble sort algorithm to sort the lotto numbers in increasing order
	for (i = 0; i < NUMUSER; ++i)
    {
        for (j = i + 1; j < NUMUSER; ++j)
        {
        	//Find the smallest number
            if (*(temp_array3+i) > *(temp_array3+j))
            {
            	//Store smallest number
                a =  *(temp_array3+i);
                //Swap smallest number with current number
                *(temp_array3+i) = *(temp_array3+j);
                //Swap number back to array 
                *(temp_array3+j) = a;
            }
        }
    }
    printf("The numbers arranged in increasing order are given below\n");
    
    //Re-display the lotto numbers in order
    for (i = 0; i<NUMUSER; i++)
    {
    	printf("%d, ",*(temp_array3+i));
	}
}

//Option 4: Compare user entered numbers with winning lotto numbers
void compare_lotto_nums(int *user_numbers)
{
	int i = 0;
	int match_num = 0;
	int bonus_num = 0;
	
	//Compares each element to winning numbers to see if you get a match and increments counter
	for (i=0; i<NUMUSER; i++)
	{
		if(*(user_numbers+i) == 1)
		{
			match_num++;
		}
		if(*(user_numbers+i) == 3)
		{
			match_num++;
		}
		if(*(user_numbers+i) == 5)
		{
			match_num++;
		}
		if(*(user_numbers+i) == 7)
		{
			match_num++;
		}
		if(*(user_numbers+i) == 9)
		{
			match_num++;
		}
		if(*(user_numbers+i) == 11)
		{
			match_num++;
		}
		if(*(user_numbers+i) == 42)
		{
			bonus_num++;
		}//End if
	}//End for
	
	printf("You have %d winning numbers\n",match_num);
	
	//If bonus number is incremented print that user has got a bonus number
	if(bonus_num == 1)
	{
		printf("You have 1 bonus number\n");
	}
	
	//If match number is incremented and/or bonus number then show user what they have won
	if(match_num == 6)
	{
		printf("You have won the Jackpot congratulations\n");
	}
	
	else if (match_num == 5 && bonus_num == 1)
	{
		printf("You have won a New Car congratulations\n");
	}
	
	else if (match_num == 5)
	{
		printf("You have won a Holiday congratulations\n");
	}
	
	else if (match_num == 4 && bonus_num == 1)
	{
		printf("You have won a Weekend Away congratulations\n");
	}
	
	else if (match_num == 4)
	{
		printf("You have won a Night Out congratulations\n");
	}
	
	else if (match_num == 3 && bonus_num == 1)
	{
		printf("You have won a Cinema Ticket congratulations\n");
	}
	
}

//Option 5: Frequency
void all_frequency(int *user_numbers, int *frequency)
{
	int i;
	
	//Increment the frequency for the numbers the user has entered in the frequency array by 1 
	for( i = 0 ; i < NUMUSER ; i++ )
	{
		*(frequency + (*(user_numbers + i) - 1)) = *(frequency + (*(user_numbers + i) - 1)) + 1;
	}//end for
	
	//Show the user the frequency for the numbers they have entered in the program so far
	for( i = 0 ; i < LOTTONUMS ; i++)
	{
		if( *(frequency + i) > 0 )
		{
			printf("\nThe number %d has been selected %d times\n", i + 1, *(frequency + i));
		}//end if
	}//end for  
	
}

//Option 6: exit()
void exit_program()
{
	//Gracefully end the program
	printf("Thank you for playing. This program will now end\n");
	exit(0);
}

