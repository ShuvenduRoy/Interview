#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int test_case;
    int number_of_object;
    const int MAX_WEIGHT = 31;
    int bestForWeight[MAX_WEIGHT];

    cin>>test_case;


    for(int j=0; j<test_case; j++){
        cin>>number_of_object;
        // Re-setting the variable
        memset(bestForWeight, 0, sizeof(bestForWeight));

        int prices[number_of_object];
        int weights[number_of_object];

        for(int i=0; i<number_of_object; i++){
            cin>>prices[i]>>weights[i];

            for(int weight=MAX_WEIGHT-1; weight>=weights[i]; weight--){
                bestForWeight[weight] = max(bestForWeight[weight], bestForWeight[weight-weights[i]]+prices[i]);
            }
        }

        int numberOfPeople;
        cin>>numberOfPeople;

        int total =0;
        int maxWeight[numberOfPeople];
        for(int i=0; i<numberOfPeople; i++){
            cin>>maxWeight[i];
            total += bestForWeight[maxWeight[i]];
        }
        cout<<total<<endl;
    }
}