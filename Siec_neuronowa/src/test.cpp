#include "test.hh"
#include "neuralnetwork.hh"
#define SIZE_OF_INPUT_LAYER 49
#define SIZE_OF_HIDDEN_LAYER 130
#define SIZE_OF_OUTPUT_LAYER 10
#include <vector>
#include <iostream>

void Test::run(int argc, char *argv[]) {

NeuralNetwork *ann = new NeuralNetwork(SIZE_OF_INPUT_LAYER, SIZE_OF_HIDDEN_LAYER, SIZE_OF_OUTPUT_LAYER);

std::vector<std::string> input_files;
std::vector<std::string> output_files;
std::vector<std::string> test_files;

int state;

input_files.push_back("pliki/0.dat");
input_files.push_back("pliki/1.dat");
input_files.push_back("pliki/2.dat");
input_files.push_back("pliki/3.dat");
input_files.push_back("pliki/4.dat");
input_files.push_back("pliki/5.dat");
input_files.push_back("pliki/6.dat");
input_files.push_back("pliki/7.dat");
input_files.push_back("pliki/8.dat");
input_files.push_back("pliki/9.dat");


output_files.push_back("pliki/out0.dat");
output_files.push_back("pliki/out1.dat");
output_files.push_back("pliki/out2.dat");
output_files.push_back("pliki/out3.dat");
output_files.push_back("pliki/out4.dat");
output_files.push_back("pliki/out5.dat");
output_files.push_back("pliki/out6.dat");
output_files.push_back("pliki/out7.dat");
output_files.push_back("pliki/out8.dat");
output_files.push_back("pliki/out9.dat");

test_files.push_back("pliki/0t.dat");
test_files.push_back("pliki/1t.dat");
test_files.push_back("pliki/2t.dat");
test_files.push_back("pliki/3t.dat");
test_files.push_back("pliki/4t.dat");
test_files.push_back("pliki/5t.dat");
test_files.push_back("pliki/6t.dat");
test_files.push_back("pliki/7t.dat");
test_files.push_back("pliki/8t.dat");
test_files.push_back("pliki/9t.dat");

while(1) {

if(state==4)
break;

std::cout<<"Co robimy?"<<std::endl<<std::endl;

std::cout<<"1. Wczytanie plików uczących."<<std::endl;
std::cout<<"2. Uczenie sieci."<<std::endl;
std::cout<<"3. Rozpoznawanie przykładowego zbioru 0-9"<<std::endl;
std::cout<<"4. Wyjście."<<std::endl;
std::cout<<"Twój wybór: ";

std::cin>>state;

    switch(state) {
        case 1:
        ann->load_training_set(input_files, output_files, test_files);
        break;
        case 2:
        ann->learn();
        break;
        case 3:
        ann->recognize();
        break;
        case 4:
        delete ann;
        break;
        default:
        std::cout<<"Zły wybór."<<std::endl;
        break;

    }

}

}
