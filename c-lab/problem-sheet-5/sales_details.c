#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberOfSalesPeople, minSales, maxSales, totalSales = 0, salesAbove, salesAboveCount = 0;
    int maxSalesIndex = 0, minSalesIndex = 0;
    double averageSales;
    printf("Enter number of sales people: ");
    scanf("%d", &numberOfSalesPeople);
    int *salesAmounts = (int *)malloc(numberOfSalesPeople * sizeof(int));

    for (int i = 0; i < numberOfSalesPeople; i++)
    {
        scanf("%d", &salesAmounts[i]);
        maxSales = (i == 0 || salesAmounts[i] > maxSales) ? (maxSalesIndex = i, salesAmounts[i]) : maxSales;
        minSales = (i == 0 || salesAmounts[i] < minSales) ? (minSalesIndex = i, salesAmounts[i]) : minSales;
        totalSales += salesAmounts[i];
    }

    averageSales = totalSales / (double)numberOfSalesPeople;

    for (int i = 0; i < numberOfSalesPeople; i++)
    {
        printf("Salesperson %d: Amount of Sales = %d\n", i + 1, salesAmounts[i]);
    }

    printf("Total Sales = %d\n", totalSales);
    printf("Average Sales = %.2f\n", averageSales);
    printf("Salesperson %d had the highest sale with %d\n", maxSalesIndex + 1, maxSales);
    printf("Salesperson %d had the lowest sale with %d\n", minSalesIndex + 1, minSales);

    printf("Salespeople with sales above: ");
    scanf("%d", &salesAbove);

    for (int i = 0; i < numberOfSalesPeople; i++)
    {
        if (salesAmounts[i] > salesAbove)
        {
            printf("Salesperson %d: Amount of Sales = %d\n", i + 1, salesAmounts[i]);
            salesAboveCount++;
        }
    }
    printf("Total number of salespeople with sales above %d is %d\n", salesAbove, salesAboveCount);

    free(salesAmounts);
    return 0;
}