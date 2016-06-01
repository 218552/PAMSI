#ifndef neuralnetwork_hh
#define neuralnetwork_hh
#include "ineuralnetwork.hh"
#include <vector>

class NeuralNetwork : public INeuralNetwork {

private:

int layer_sizes[3];

float learning_rate;

float **weight_i_h, **weight_h_o;

float eta;

int tmp1, tmp2;

float **input_layer, **output_layer, *hidden_layer, *bias;

int number_of_biases;

float **input_patterns, **output_patterns, **test_patterns;

float *hidden_errors, *output_errors;

float *test;

public:

void load_training_set(std::vector<std::string> input_data_file_names, std::vector<std::string> output_data_file_names, std::vector<std::string> test_data_file_names);

void learn();

void forward_pass(int pattern);

void backward_pass(int pattern);

bool check_if_answer_is_correct();

void recognize();

float activation_function(float input);

NeuralNetwork(int size_of_input_layer, int size_of_hidden_layer, int size_of_output_layer);

~NeuralNetwork();

};

#endif
