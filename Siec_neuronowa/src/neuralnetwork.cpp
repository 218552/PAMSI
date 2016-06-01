#include "neuralnetwork.hh"

#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX_ERROR 0.2
#define INPUT_LENGTH 49
#define OUTPUT_LENGTH 10
#define TRAINING_SET_SIZE 10

NeuralNetwork::NeuralNetwork(int size_of_input_layer, int size_of_hidden_layer, int size_of_output_layer) {

input_layer = new float* [TRAINING_SET_SIZE];
output_layer = new float* [TRAINING_SET_SIZE];
hidden_layer = new float [size_of_hidden_layer];

bias = new float [size_of_hidden_layer+size_of_output_layer];

number_of_biases=size_of_hidden_layer+size_of_output_layer;

for(int i=0; i<size_of_hidden_layer+size_of_output_layer; i++)
bias[i]=(((rand() % 1000000) / 1700.0) - 9.8)*0.0015;

input_patterns = new float* [TRAINING_SET_SIZE];
output_patterns = new float* [TRAINING_SET_SIZE];
test_patterns = new float* [TRAINING_SET_SIZE];

hidden_errors = new float [size_of_hidden_layer];
output_errors = new float [size_of_output_layer];

for(int i=0; i<TRAINING_SET_SIZE; i++) {

    input_layer[i] = new float [INPUT_LENGTH];
    output_layer[i] = new float [OUTPUT_LENGTH];

}

for(int i=0; i<TRAINING_SET_SIZE; i++) {

    input_patterns[i] = new float [INPUT_LENGTH];
    output_patterns[i] = new float [OUTPUT_LENGTH];
    test_patterns[i] = new float [INPUT_LENGTH];

}


eta=0.02;

tmp1 = tmp2 = 0.0;

layer_sizes[0] = size_of_input_layer;
layer_sizes[1] = size_of_hidden_layer;
layer_sizes[2] = size_of_output_layer;

weight_i_h = new float * [size_of_input_layer];

for(int i=0; i<size_of_input_layer; i++) {

weight_i_h[i] = new float [size_of_hidden_layer];

}

weight_h_o = new float * [size_of_hidden_layer];

for(int i=0; i<size_of_hidden_layer; i++) {

weight_h_o[i] = new float [size_of_output_layer];

}

for(int i=0; i<size_of_input_layer; i++) {

    for(int j=0; j<size_of_hidden_layer; j++) {

    weight_i_h[i][j]=(((rand() % 1000000) / 1700.0) - 9.8)*0.0015;
    if(weight_i_h[i][j]==0)
    weight_i_h[i][j]=0.0124;

    }
}

for(int i=0; i<size_of_hidden_layer; i++) {

    for(int j=0; j<size_of_output_layer; j++) {

    weight_h_o[i][j]=(((rand() % 1000000) / 1700.0) - 9.8)*0.0015;
    if(weight_h_o[i][j]==0)
    weight_h_o[i][j]=0.0124;

    }
}

}


NeuralNetwork::~NeuralNetwork() {

for(int i=0; i<TRAINING_SET_SIZE; i++) {

    delete []input_patterns[i];
    delete []output_patterns[i];

}

for(int i=0; i<TRAINING_SET_SIZE; i++) {

    delete []input_layer[i];
    delete []output_layer[i];

}

delete []input_layer;
delete []output_layer;

delete []bias;

delete []input_patterns;
delete []output_patterns;

delete []output_errors;
delete []hidden_errors;

for(int i=0; i<layer_sizes[0]; i++) {

delete []weight_i_h[i];

}

for(int i=0; i<layer_sizes[1]; i++) {

delete []weight_h_o[i];

}

delete []weight_i_h;
delete []weight_h_o;

}

void NeuralNetwork::load_training_set(std::vector<std::string> input_data_file_names, std::vector<std::string> output_data_file_names, std::vector<std::string> test_data_file_names) {

std::ifstream input_data;
std::ifstream output_data;
std::ifstream test_data;

float input_value = 0.0;
float output_value = 0.0;
float test_value = 0.0;

for(int f=0; f<TRAINING_SET_SIZE; f++) {

    input_data.open(input_data_file_names.at(f), std::ios::in);
    output_data.open(output_data_file_names.at(f), std::ios::in);
    test_data.open(test_data_file_names.at(f), std::ios::in);

    if(input_data.good() && output_data.good() && test_data.good()) {

        for(unsigned int i=0; i<INPUT_LENGTH; i++) {

            input_data>>input_value;

            input_patterns[f][i]=input_value;
            input_layer[f][i]=input_value;

        }

        for(unsigned int i=0; i<INPUT_LENGTH; i++) {

            test_data>>test_value;

            test_patterns[f][i]=test_value;

        }

        for(unsigned int i=0; i<OUTPUT_LENGTH; i++) {

            output_data>>output_value;
            output_patterns[f][i] = output_value;

        }

    input_data.close();
    output_data.close();
    test_data.close();

    }
    else
    std::cout<<"Nie uzyskano dostępu do zestawu uczącego, przerwano odczyt danych"<<std::endl;

}

std::cout<<"Wczytano dane treningowe."<<std::endl;

}


void NeuralNetwork::learn() {

int epochs=0;

std::cout<<"Trwa uczenie..."<<std::endl;

while(!check_if_answer_is_correct()) {

for(int i=0; i<TRAINING_SET_SIZE; i++) {
			forward_pass(i);
			backward_pass(i);
		}
		epochs++;
		std::cout<<"Epoki: "<<epochs<<std::endl;
}


		if(check_if_answer_is_correct())
			std::cout<<"Nauka została zakończona"<<std::endl;

    std::cout<<"Wyjścia sieci: "<< std::endl;
	for(int i=0; i<layer_sizes[2]; i++)
		std::cout<<output_layer[1][i] <<"   ";
}


void NeuralNetwork::forward_pass(int pattern) {

	float tmp=0.0;

    /* Propagacja w przód z warstwy wejściowej do warstwy ukrytej */
	for(int i=0; i<layer_sizes[1]; i++) {
		for(int j=0; j<layer_sizes[0]; j++) {
			tmp += (input_layer[pattern][j] * weight_i_h[j][i]);
		}
		hidden_layer[i] = activation_function(tmp + bias[i]);
		tmp = 0.0;
	}

    /* Propagacja w przód z warstwy ukrytej do warstwy wyjściowej */
	for(int i=0; i<layer_sizes[2]; i++) {
		for(int j=0; j<layer_sizes[1]; j++) {
			tmp += (hidden_layer[j] * weight_h_o[j][i]);
		}
		output_layer[pattern][i] = activation_function(tmp + bias[i + layer_sizes[1]]);
		tmp = 0.0;
	}

}

void NeuralNetwork::backward_pass(int pattern) {

	float tmp = 0;

    /* Wyliczanie błędów na wyjściu */
	for(int i=0; i<layer_sizes[2]; i++)
		output_errors[i] = (output_patterns[pattern][i] - output_layer[pattern][i]);

    /* Wyliczanie błędów na warstwie ukrytej */
	for(int i=0; i<layer_sizes[1]; i++) {
		for(int j=0; j<layer_sizes[2]; j++) {
			tmp += (output_errors[j] * weight_h_o[i][j]);
		}
	hidden_errors[i] = hidden_layer[i] * (1-hidden_layer[i]) * tmp;
	tmp = 0.0;
	}

    /* Dostosowywanie wag warstw ukrytej i wyjściowej */
	float length = 0.0;
	for (int i=0; i<layer_sizes[1]; i++)
		length += hidden_layer[i]*hidden_layer[i];

	if (length<=0.1)
        length = 0.1;

	for(int i=0; i<layer_sizes[1]; i++) {
		for(int j=0; j<layer_sizes[2]; j++) {
			weight_h_o[i][j] += (eta * output_errors[j] * hidden_layer[i] / length);
		}
	}

    /* Dostosowywanie biasów warstwy ukrytej */
	for(int i=layer_sizes[1]; i<number_of_biases; i++)
		bias[i] += (eta * output_errors[i] / length);


    /* Dostosowywanie wag warstw wejściowej i ukrytej */
	length = 0.0;
	for (int i=0; i<layer_sizes[0]; i++)
		length += input_layer[pattern][i]*input_layer[pattern][i];

	if (length<=0.1)
        length = 0.1;

	for(int i=0; i<layer_sizes[0]; i++) {
		for(int j=0; j<layer_sizes[1]; j++) {
			weight_i_h[i][j] += (eta * hidden_errors[j] * input_layer[pattern][i] / length);
		}
	}

    /* Dostosowywanie biasów warstwy wyjściowej */
	for(int i=0; i<layer_sizes[1]; i++)
		bias[i] += (eta * hidden_errors[i] / length);

}

bool NeuralNetwork::check_if_answer_is_correct() {

	float tmp, error = 0.0;
	tmp = output_patterns[tmp1][tmp2] - output_layer[tmp1][tmp2];
	if (tmp<0)
        error -= tmp;
	else
        error += tmp;

    std::cout<<error<<" "<<std::endl;

	if(error > MAX_ERROR)
	return 0;

	error = 0.0;
	for(int i=0; i<TRAINING_SET_SIZE; i++) {
		for(int j=0; j<layer_sizes[2]; j++) {
			tmp = output_patterns[i][j] - output_layer[i][j];
			if (tmp<0)
                error -= tmp;
			else
                error += tmp;
            std::cout<<error<<" "<<std::endl;
			if(error>MAX_ERROR) {
				tmp1 = i;
				tmp2 = j;
				return 0;
			}
			error = 0.0;
		}
	}
	return 1;

}

void NeuralNetwork::recognize() {

for(int i=0; i<TRAINING_SET_SIZE; i++) {
    for(int j=0; j<INPUT_LENGTH; j++) {
        input_layer[i][j]=test_patterns[i][j];
        }
}
int element;

std::cout<<"Wybierz element zbioru walidacyjnego w celu sprawdzenia sieci (0-9): ";
std::cin>>element;

    forward_pass(element);

	std::cout<<"Wyjścia sieci: "<< std::endl;
	for(int i=0; i<layer_sizes[2]; i++)
		std::cout<<i<<": "<<output_layer[element][i] <<"  ";

}

float NeuralNetwork::activation_function(float input) {
  return 1.0/(1.0+exp(((-1)*input)));
}
