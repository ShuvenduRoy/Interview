#include <iostream>
#include <map>

class Integer{
public:
    Integer(int i) {
        val = i;
    }

    int val;
};

class Index{
public:
    int remainingWeight;
    int remainingItmes;

public: bool equals(Index index){
        if(this->remainingItmes==index.remainingItmes && this->remainingWeight==index.remainingWeight)
            return true;

        if(remainingWeight != index.remainingWeight)
            return false;

        return remainingWeight== index.remainingWeight;

    }

public: int hashCode(){
        int result = remainingWeight;
        result = 31 * result * remainingWeight;
        return  result;
    }
};


int top_down_recursive(int values[], int weights[], int weight);

int top_down_recursive_Util(int *values, int *weights, int remaining_weight, int total_items, int current_item,
                            std::map<Index, Integer> map);


using  namespace std;


int main() {

    int weights[] = {2,2,3,5};
    int values[] = {2,4,6,9};
    int totalWeight =8;

    int ans = top_down_recursive(values, weights, totalWeight);
    cout<<ans<<endl;

    return 0;
}

int top_down_recursive(int values[], int weights[], int weight) {
    map<Index, Integer> mapVal;
    return top_down_recursive_Util(values, weights, weight, 4 ,0, mapVal);
}

int top_down_recursive_Util(int *values, int *weights, int remaining_weight, int total_items, int current_item,
                            map<Index, Integer> map) {
    if(current_item>= total_items || remaining_weight <=0)
        return 0;

    Index key = Index();
    key.remainingItmes = total_items - current_item;
    key.remainingWeight = remaining_weight;

    if(map.find(key) != map.end()){
        return map.find(key)->second.val;
    }

    int maxValue;

    if(remaining_weight<weights[current_item]){
        maxValue = top_down_recursive_Util(values, weights, remaining_weight, total_items, current_item + 1, map);
    } else{
        maxValue = max(values[current_item] + top_down_recursive_Util(values, weights, remaining_weight - weights[current_item], total_items, current_item+1, map),
        top_down_recursive_Util(values, weights, remaining_weight, total_items, current_item+1, map));
    }

    map[key] = Integer(maxValue);
    return maxValue;
}



