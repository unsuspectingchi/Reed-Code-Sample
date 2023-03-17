#pragma once

class INeuron
{
public:
  INeuron() {};
  INeuron(float weight);

  float Act(float x);

protected:
  float activation;
  float weight;
  friend class ONeuron;
};

class ONeuron
{
public:
  ONeuron() {};

  void Activation(float *inputVec, INeuron *neurons);
  int Outvalue(float j);

protected:
  int output;
  float activation;
  friend class Network;
};

class Network
{
public:
  Network(float a, float b, float c, float d);

  INeuron ineuron[4];
  ONeuron oneuron;
};