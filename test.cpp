#include <iostream>
#include "knn.hpp"


int main(int argc, char * argv[]){

    std::vector<std::vector<float>> x = {{0.2, 0.3, 0.1}, {0.1, 0.4, 0.1},
                    {0.2, 0.1, 0.25}, {0.8, 0.9, 0.5}, {0.7, 0.9, 0.6},
                    {0.85, 0.74, 0.63}, {0.8, 0.72, 0.6}, {0.59, 0.84, 0.654},
                    {0.2, 0.1, 0.25}, {0.8, 0.9, 0.5}, {0.7, 0.9, 0.6},
                    {0.75, 0.74, 0.63}, {0.8, 0.69, 0.78}, {0.49, 0.94, 0.8},
                    {0.21, 0.18, 0.255}, {0.82, 0.92, 0.51}, {0.74, 0.91, 0.67},
                    {0.15, 0.24, 0.44}, {0.1, 0.12, 0.02}, {0.17, 0.32, 0.321},
                    {0.2, 0.1, 0.25}, {0.88, 0.92, 0.52}, {0.71, 0.96, 0.65},
                    {0.67, 0.95, 0.67}, {0.43, 0.25, 0.4}, {0.2, 0.1, 0.154}};
    std::vector<int> y = {0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,0,0,0,1,1,1,0,0};

    KNN classifier(2, 3);
    for(int k = 1; k < 9; k++){
        std::cout << "k = " << k <<
        " prediction : " << classifier.predict({0.5, 0.5, 0.5}, x, y, k) << '\n';
    }

    return 0;
}