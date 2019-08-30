# include <stdio.h>
#define PI 3.14159265358979323846

// Always put the funciton declerations first!
float input(char prompt[], float lower, float upper){
	float userInput;
	for (; ;) {
		printf("What is the measurement of the %s: ", prompt);
		scanf("%f", &userInput);
		if ((userInput >= lower) && (userInput <= upper)) {
			return userInput;
		}
		printf("The value must be between %f and %f \n", lower, upper);
	}
}


int main() {
	
	int again = 1;

	while(again) {

		// Hot tub

		// Input
		printf("Hot Tub Dimensions (feet): \n");
		printf("-------------------------- \n");
		float tubDepth = input("depth", 3, 5);
		float tubWidth = input("width", 8, 14);


		// Caluclations

		float tubVolume = (tubDepth - 0.5) * (tubWidth / 2) * (tubWidth / 2) * PI;
		float tubGallons = tubVolume *  7.481;
		float tubCost = tubGallons * 4 * 0.07;
		
		// Pool
		

		// Input
		printf("Pool Dimensions (feet): \n");
		printf("----------------------- \n");
		
		float poolShallowEndDepth = input("shallow end depth", 0, 5);
		float poolDeepEndDepth = input("deep end depth", 6, 15);
		float poolWidth = input("width", 15, 30);
		float poolLength = input("length", 30, 50);
		float poolWalkInLength = input("walk in length", 5, poolLength / 3);
		float poolShallowEndLength = input("shallow end length", 10, poolLength / 2);
		float poolDeepEndLength = input("deep end length", 12, poolLength / 2);
		

		// Calculations

		float poolVolume = 	(
						(poolDeepEndDepth) * (poolDeepEndLength) +
						0.5 * (poolLength - (poolWalkInLength + poolDeepEndLength + poolShallowEndLength)) * ((poolDeepEndDepth) + (poolShallowEndDepth)) + 
						poolShallowEndLength * poolShallowEndDepth + 
						0.5 * poolShallowEndDepth * poolWalkInLength
					) * poolWidth - (0.5 * poolLength * poolWidth);


		float poolGallons = poolVolume * 7.481;
		float poolCost = poolGallons * 4 * 0.07;

		// Output
		printf("Pool Volume: \n");
		printf("------------ \n");

		printf("Total volume of pool: %f \n", poolVolume);
		printf("Gallons of water to fill: %f \n", poolGallons);

		printf("Hot Tub Volume: \n");
		printf("--------------- \n");

		printf("Total volume of hot tub: %f \n", tubVolume);
		printf("Gallons of water to fill: %f \n", tubGallons);

		printf("Total gallons for both: %f \n", tubGallons + poolGallons);
		printf("Total cost for both: %f \n", tubCost + poolCost);
		
		// Looping

		printf("Would you like to calculate another volume? (1 = Yes, 0 = No): ");
		scanf("%i", &again);
		again = (int)again;

	}

	
}


