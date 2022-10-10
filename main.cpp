#include <iostream>
//
using namespace std;

int max(int a, int b);
int knapsack(int Bag_weith, int weith[], int values[],int n);


int main()
{
    int values[] = { 60, 100, 120 }; // la valeur des objects a ajouter
    int weiths[] = { 10, 20, 30 }; // le poids des objects a ajouter
    int W = 50; // la poid du sac
    int n = (sizeof(values)/sizeof(*values));

    cout << knapsack(W, weiths, values, n) << endl;

    return 0;
}

int max(int a, int b){
    /* params: a integer value
       params: b integer value
       return the max between a and b
       */
    return (a>b) ? a:b;
}

int knapsack(int bag_weith, int weith[], int values[],int n){

    int bag_profit [n+1][bag_weith+1];


    for(int i = 0; i<=n; i++ ){

        for (int w=0; w<=bag_weith; w++){
               if (i == 0 || w == 0) {
                    bag_profit[i][w] = 0;
                }
               else if(weith[i-1] <= w){
                    bag_profit[i][w] = max(
                    values[i-1] + bag_profit[i-1][w - weith[i-1]], bag_profit[i-1][w]);
                }
                else{
                    bag_profit[i][w] = bag_profit[i-1][w];
                }
        }

    }

    return bag_profit[n][bag_weith];


}


