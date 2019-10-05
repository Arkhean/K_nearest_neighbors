#ifndef KNN_H
#define KNN_H

#include <iostream> // size_t
#include <vector>   // vector
#include <queue>    // priority_queue
#include <cmath>    // sqrt

class KNN{
    private :
        int k;
        int nb_labels;      // number of different labels
    public :
        // default value of k
        KNN(int nb_labels, int k = 3);
        // predict using the k specified or the last k stored
        int predict(std::vector<float> data,
				std::vector<std::vector<float>> features,
                std::vector<int> labels, int k = 3);
};

class Neighbor{
    public :
        int label;
        float dist;
        Neighbor(int l, float d) : label(l), dist(d) {};
        friend bool operator<(const Neighbor a, const Neighbor b){
            return a.dist >= b.dist;    // le but est de trier à l'envers
        }
};


#endif
