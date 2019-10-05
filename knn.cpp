#include "knn.hpp"

// calculate euclidean distance for vector of size n
float distance(std::vector<float> v1, std::vector<float> v2){
    float d = 0.0;
    for(size_t i = 0; i < v1.size(); i++){
        float tmp = v1[i] - v2[i];
        d += (tmp * tmp);
    }
    return sqrt(d);
}

KNN::KNN(int nb_labels, int k){
    this->nb_labels = nb_labels;
    this->k = k;
}

int KNN::predict(std::vector<float> data, std::vector<std::vector<float>> features,
                        std::vector<int> labels, int k_test){
    std::priority_queue<Neighbor> neighbors;
    for(size_t i = 0; i < features.size(); i++){
        Neighbor n(labels[i], distance(features[i], data));
        neighbors.push(n);
    }
    int votes[nb_labels] = {0};
    for(int i = 0; i < k_test; i++){
        Neighbor n = neighbors.top();
        neighbors.pop();
        votes[n.label]++;
    }
    int label_max = 0;
    for(int i = 0; i < nb_labels; i++){
        if (votes[i] > votes[label_max]){
            label_max = i;
        }
    }
    return label_max;
}
