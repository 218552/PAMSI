#ifndef ineuralnetwork_hh
#define ineuralnetwork_hh
#include <fstream>
#include <vector>

class INeuralNetwork {

public:

virtual void load_training_set(std::vector<std::string> input_data_file_names, std::vector<std::string> output_data_file_names, std::vector<std::string> test_data_file_names)=0;

virtual void learn()=0;

virtual void forward_pass(int pattern)=0;

virtual void backward_pass(int pattern)=0;

virtual bool check_if_answer_is_correct()=0;

virtual void recognize()=0;

virtual ~INeuralNetwork() {}

};

#endif
