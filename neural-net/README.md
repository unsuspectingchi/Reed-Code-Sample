# Perceptron Project Info

#### Purpose

This project was meant to showcase a basic 4-input-weight perceptron neural network. While not being necessary very complex nor lengthy, I thought it might be an interesting addition that connected to some of the technologies Emerald uses.

#### Running

Upon running the program, an inputs file url and weights file url are required to be passed in the command line arguments. Both files should have 4 floating point values listed as the only values in the file. After executing the program, the user will be prompted with a prompt wherein they are able to determine the step-function threshold for the network. After the output of the network has been calculated, the program will exit. I have included a sample weights file and input file, as well as the Makefile that will compile the program for macOS.

#### Code

The code follows a fairly simple architecture comprised of an overarching `Network` containing 4 `INeurons` _(input neurons)_ and 1 `ONeuron` _(output neuron)_. Each `INeuron` is initialized with a weight from the weights file, and maintains an `Act` method that is passed an input onto which it will apply its weight. It maintains each affected input in its `Activation` property. Each `ONeuron` then receives in its `Activation` method an _inputVec_ as well as an array of input _neurons_, calling upon each's activation and in turn, incrementing its own activation sum. At this point, the user's `Threshold` can be applied, and tested through the _ONeuron's_ `Outvalue` method. The _ONeuron_ will then respond with either a `1` signifying that the activation exceeded the threshold, or with a `0` denoting that it did not.
