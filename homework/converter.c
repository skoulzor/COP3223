// Hailey Simpson
// May 24, 2026

#include <stdio.h> 

const double C_TO_F_SCALE  = 9.0 / 5.0;
const double C_TO_F_OFFSET = 32.0;
const double MI_TO_KM      = 1.60934;
const double LB_TO_KG      = 0.453592;

void convert_temperature(void);
void convert_distance(void);
void convert_weight(void);
void convert_speed(void);

int main(void)  {
    int choice;
     
    do {
        printf("\n= Unit Conversion Station =\n");
        printf("1. Temperature  (Celsius <-> Fahrenheit)\n");
        printf("2. Distance     (Miles <-> Kilometers)\n");
        printf("3. Weight       (Pounds <-> Kilograms)\n");
        printf("4. Speed        (MPH <-> KPH)\n");
        printf("5. Quit\n");

        do {
            printf("Enter choice (1-5): ");
            fscanf(stdin, "%d", &choice);

            if (choice < 1 || choice > 5) {
                printf("Invalid choice. Try again.\n");
            }
        } while (choice < 1 || choice > 5);
        
        switch (choice) {
            case 1: convert_temperature(); break;
            case 2: convert_distance();    break;
            case 3: convert_weight();      break;
            case 4: convert_speed();       break;
            case 5: printf("Goodbye!\n");  break;
        } 
    } while (choice != 5);

    return 0;
}

void convert_temperature(void) {
    int direction;
    double value;
    double result;

    printf("\n--- Temperature ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    
    do {
        printf("Enter direction (1-2): ");
        fscanf(stdin, "%d", &direction);

        if (direction < 1 || direction > 2) {
            printf("Invalid direction. Try again.\n");
        }

    } while (direction < 1 || direction > 2);

    if (direction == 1) {
        printf("\nEnter the temperature in Celcius: ");
        fscanf(stdin, "%lf", &value);
        
        result = value * C_TO_F_SCALE + C_TO_F_OFFSET;
        
        printf("%.2f°C = %.2f°F\n", value, result);
    } else {
        printf("\nEnter the temperature in Fahrenheit: ");
        fscanf(stdin, "%lf", &value);
        
        result = (value - C_TO_F_OFFSET) * (5.0 / 9.0);

        printf("%.2f°F = %.2f°C\n", value, result);
    }
}

void convert_distance(void) {
    int direction;
    double value;
    double result;

    printf("\n--- Distance ---\n");
    printf("1. Miles to Kilometers\n");
    printf("2. Kilometers to Miles\n");
    
    do {
        printf("Enter direction (1-2): ");
        fscanf(stdin, "%d", &direction);

        if (direction < 1 || direction > 2) {
            printf("Invalid direction. Try again.\n");
        }

    } while (direction < 1 || direction > 2);

    if (direction == 1) {
        printf("\nEnter the distance in miles: ");
        fscanf(stdin, "%lf", &value);
        
        result = value * MI_TO_KM;
        
        printf("%.2f miles = %.2f km\n", value, result);
    } else {
        printf("\nEnter the distance in kilometers: ");
        fscanf(stdin, "%lf", &value);
        
        result = value / MI_TO_KM;

        printf("%.2f km = %.2f miles\n", value, result);
    }
}

void convert_weight(void) {
    int direction;
    double value;
    double result;

    printf("\n--- Weight ---\n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");
    
    do {
        printf("Enter direction (1-2): ");
        fscanf(stdin, "%d", &direction);

        if (direction < 1 || direction > 2) {
            printf("Invalid direction. Try again.\n");
        }

    } while (direction < 1 || direction > 2);

    if (direction == 1) {
        printf("\nEnter the weight in pounds: ");
        fscanf(stdin, "%lf", &value);
        
        result = value * LB_TO_KG;
        
        printf("%.2f lbs = %.2f kg\n", value, result);
    } else {
        printf("\nEnter the weight in kilograms: ");
        fscanf(stdin, "%lf", &value);
        
        result = value / LB_TO_KG;

        printf("%.2f kg = %.2f lbs\n", value, result);
    }
}

void convert_speed(void) {
    int direction;
    double value;
    double result;

    printf("\n--- Speed ---\n");
    printf("1. MPH to KPH\n");
    printf("2. KPH to MPH\n");
    
    do {
        printf("Enter direction (1-2): ");
        fscanf(stdin, "%d", &direction);

        if (direction < 1 || direction > 2) {
            printf("Invalid direction. Try again.\n");
        }

    } while (direction < 1 || direction > 2);

    if (direction == 1) {
        printf("\nEnter the speed in mph: ");
        fscanf(stdin, "%lf", &value);
        
        result = value * MI_TO_KM;
        
        printf("%.2f mph = %.2f kph\n", value, result);
    } else {
        printf("\nEnter the speed in kph: ");
        fscanf(stdin, "%lf", &value);
        
        result = value / MI_TO_KM;

        printf("%.2f kph = %.2f mph\n", value, result);
    }
}