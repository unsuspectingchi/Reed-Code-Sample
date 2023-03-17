#include "Perceptron.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

INeuron::INeuron(float weight)
: weight(weight) {}

float INeuron::Act(float x)
{
  return x * weight;
}

void ONeuron::Activation(float *inputVec, INeuron *neurons)
{
  activation = 0;
  for (int i = 0; i < 4; ++i)
  {
    std::cout << "\n Weight " << i << " is " << neurons[i].weight;
    neurons[i].activation = neurons[i].Act(inputVec[i]);
    std::cout << "   IN Activation is " << neurons[i].activation;
    activation += neurons[i].activation;
  }
  std::cout << "\n\n ON Activation is " << activation << std::endl;
}

int ONeuron::Outvalue(float threshold)
{
  if (activation >= threshold)
  {
    std::cout << "\n Threshold value has been exceeded by activation." << std::endl;
    output = 1;
  }
  else
  {
    std::cout << "\n Threshold value has not been exceeded by activation." << std::endl;
    output = 0;
  }
  std::cout << "\n Output value is " << output << std::endl;
  return output;
}

Network::Network(float a, float b, float c, float d)
{
  ineuron[0] = INeuron(a);
  ineuron[1] = INeuron(b);
  ineuron[2] = INeuron(c);
  ineuron[3] = INeuron(d);

  oneuron = ONeuron();

  oneuron.activation = 0;
  oneuron.output = 0;
}

int main(int argc, char **argv)
{
  float inputVec[4];
  float weights[4];
  FILE *wFile;
  FILE *inFile;
  float threshold;

  if (argc < 2)
  {
    std::cerr << "Invalid number of arguments provided." << 
    "Please provide a weights and inputs file." << std::endl;
    exit(1);
  }
  wFile = fopen(argv[1], "r");
  inFile = fopen(argv[2], "r");

  if ((wFile == NULL) || (inFile == NULL))
  {
    std::cerr << "Unable to open file." << std::endl;
    exit(1);
  }
  fscanf(wFile, "%f %f %f %f\n", &weights[0], &weights[1], &weights[2], &weights[3]);
  Network network{weights[0], weights[1], weights[2], weights[3]};
  fscanf(inFile, "%f %f %f %f\n", &inputVec[0], &inputVec[1], &inputVec[2], &inputVec[3]);
  std::cout << "\n\nPlease enter threshold value:" << std::endl;
  std::cin >> threshold;
  network.oneuron.Activation(inputVec, network.ineuron);
  network.oneuron.Outvalue(threshold);
  fclose(wFile);
  fclose(inFile);

  return 0;
}