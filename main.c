#include <stdio.h>
#include <stdlib.h>

int doubleCrey(int a ){
    int result = a * 2;
    return result;
}
int main (int argc, char* argv[])
{

    //----------TASK 1 ----------------

    // //making sure command line inputs are not more than 1
    if(argc == 1){
        printf("wrong number of arguments");
        return 1;
    }
    //initializing array to input numbers to be doubled
    int* numToBeDoubled = (int*) malloc (argc * sizeof(int));

    //initializing array to store numbers already doubled
    int* alreadDoubledNums = (int*) malloc(argc * sizeof(int));

    

    // for (int i = 1; i < argc; i++)
    // {

    //     //storing the numbers in the array
    //     numToBeDoubled[i] = atoi(argv[i]);
    //     int answer = doubleCrey(atoi(argv[i]));//that atoi is how we will type cast
    //     //storing already doubled numbers in the array
    //     alreadDoubledNums[i] = answer;
    //     // printf("%s x 2 = %d\n", argv[i], answer);
    // }
    

    // ///formatting and showing users the number they put in an array
    //  printf("you inputted these numbers[");
    // for (int i = 1; i < argc; i++) {
    //     if (i < argc - 1) {
    //         printf("%d, ", numToBeDoubled[i]);
    //     } else {
    //         printf("%d", numToBeDoubled[i]);
    //     }
    // }
    // printf("]\n");


    // //formatting and showing users the answers
    //  printf("the result is [");
    // for (int i = 1; i < argc; i++) {
    //     if (i < argc - 1) {
    //         printf("%d, ", alreadDoubledNums[i]);//checks if the element is the last in the array to put the comma
    //     } else {
    //         printf("%d", alreadDoubledNums[i]); //if it isnt the element is left alst without a comma.
    //     }
    // }
    // printf("]\n");

    // // freeing  the array
    // free(numToBeDoubled);
    // free(alreadDoubledNums);

    // --------- END OF TASK 1 ------------

    // READING A FILE
    // int buffer_size = 20000;
    // FILE *file_pointer;

    // char buffer[buffer_size];
    // file_pointer = fopen(argv,"r");

    // int iter = 1;

    // while(fgets(buffer,buffer_size,file_pointer) != NULL){
    //     printf("%s",buffer);
    // }

    // fclose(file_pointer);

    //writing to a file
    // FILE *file_pointer;

    // file_pointer = fopen("numbers.txt","w");

    // //writing in the file using fputs()

    // fputs("this is line one\n",file_pointer);
    // fputs("this is line one\n",file_pointer);

    // //writing with formats
    // for(int index = 0; index < 100; index ++){
    //     fprintf(file_pointer,"%d\n",index);
    // }

    // //closing the file using f close()
    // fclose(file_pointer);


    //--------TASK 2---------
    // READING THE  FILE
    int buffer_size = 20000;
    FILE *file_pointer;

    char buffer[buffer_size];
    file_pointer = fopen(argv[1],"r");//assigning file from the command line

    int numbersFound = 0;//keeping track of numbers in the file

    while(fgets(buffer,buffer_size,file_pointer) != NULL){
        numbersFound++;
         //storing the numbers in the array
        numToBeDoubled[numbersFound] = atoi(buffer);
        int answer = doubleCrey(atoi(buffer));//that atoi is how we will type cast
        //storing already doubled numbers in the array
        alreadDoubledNums[numbersFound] = answer;
        
    }
    fclose(file_pointer);

    file_pointer = fopen("doubledNumbers.txt","w");

    //writing in the file using fputs()

    fputs("The result of the numbers doubled in  are: \n",file_pointer);
    

    // //writing with formats
    // for(int index = 0; index < 100; index ++){
    //     fprintf(file_pointer,"%d\n",index);
    // }


    //formatting and showing users the answers and writing to  file
   
    for (int i = 1; i <= numbersFound; i++) {
        fprintf(file_pointer,"%d\n",alreadDoubledNums[i]);//writing results to file
        
    }

    // freeing  the array
    free(numToBeDoubled);
    free(alreadDoubledNums);

    fclose(file_pointer);




    
    //task 1 : just like this , create 2 arrays ,one array to store the arguments of the user input through command line and the othher one to store the results
    //task2: just like in task 1  but different,the numbers to double will be stored in a file and the user will type the name of the file to double and after the user types it , the program will go to the file and collect all the numbers and double it,put it in an array and create a new file and push it to a new file


    return 0;
}