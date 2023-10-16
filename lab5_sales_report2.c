#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the maximum number of doubles you expect in the file.
    // Adjust this value according to your needs.
    int max_doubles = 100;
  
    double doubles[]={23458.01,40112.00,56011.85,37820.88,37904.67,60200.22,72400.31,56210.89,67230.84,68233.12,80950.34,95225.22};
    int count=sizeof(doubles)/sizeof(doubles[0]);
    printf("Monthy Sales report for 2022\n\n");
    printDoublesWithMonths(doubles,count);
    printf("--------------------\n Sales Summary:\n\n");
    printMinMaxAvg(doubles,count);
    printf("--------------------\nSix Month Moving Average Report:\n\n");
    calculateMovingAverage(doubles,count);
    printf("--------------------\nSales Report Highest to Lowest:\n\n");
    printValuesByMonthDescending(doubles,count);

    return 0;
}


void printDoublesWithMonths(const double doubles[], int numDoubles) {
    const char *months[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    for (int i = 0; i < numDoubles && i < 12; i++) {
        printf("%s: %.2lf\n", months[i], doubles[i]);
    }
}

void printMinMaxAvg(const double values[], int numValues) {
    if (numValues <= 0) {
        printf("No values to process.\n");
        return;
    }
     const char *months[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    double min = values[0];
    double max = values[0];
    double sum = values[0];
    int min_index;
    int max_index;

    for (int i = 1; i < numValues; i++) {
        if (values[i] < min) {
            min = values[i];
            min_index=i;
        }
        if (values[i] > max) {
            max = values[i];
            max_index=i;
        }
        sum += values[i];
    }

    double average = sum / numValues;

    printf("Minimum: %.2lf\n", min);
    printf("Maximum: %.2lf\n", max);
    printf("Average: %.2lf\n", average);
}

void calculateMovingAverage(const double doubles[], int numDoubles) {
    if (numDoubles < 6) {
        printf("Not enough data to calculate a 6-month moving average.\n");
        return;
    }
    const char *months[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    printf("6-Month Moving Averages:\n");

    for (int i = 0; i <= numDoubles - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += doubles[j];
        }
        double average = sum / 6;

        printf("%s - %s: %.2lf\n", months[i], months[i + 5], average);
    }
}

void printValuesByMonthDescending(const double doubles[], int numDoubles) {
    // Check if the number of doubles and months match.
    if (numDoubles != 12) {
        printf("The number of doubles doesn't match the number of months.\n");
        return;
    }
    const char *months[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    // Create an array of indexes and initialize them with values 0 to 11.
    int indexes[12];
    for (int i = 0; i < 12; i++) {
        indexes[i] = i;
    }

    // Sort the indexes array based on the corresponding double values in descending order.
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (doubles[indexes[i]] < doubles[indexes[j]]) {
                int temp = indexes[i];
                indexes[i] = indexes[j];
                indexes[j] = temp;
            }
        }
    }

    // Print the values in descending order by month.
   
    for (int i = 0; i < 12; i++) {
        int index = indexes[i];
        printf("%s: %.2lf\n", months[index], doubles[index]);
    }
}
